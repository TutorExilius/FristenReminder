#include <memory>
#include <unordered_map>
#include <functional>

#include "fieldParser.h"

namespace {

using ParserColdStorage = ::std::shared_ptr<FieldParserBase>;
template<typename T>
struct Identity { using type = T; };
template<typename T>
using ParserStorage = typename Identity<::std::shared_ptr<FieldParser<T>>>::type;
}

using FieldId = std::string;

template<typename T>
class Field {
public:
    Field(FieldId fieldID)
    : fieldID( fieldID )
    {}

    const FieldId& getFieldID() const {
        return fieldID;
    }
private:
    // Not the name
    FieldId fieldID;
};

template<typename U, typename T>
class ReflectableField : public Field<T> {
    using FieldAccessor = std::function<const T&(const U&)>;
    using ConstMemAccessor = const U&(U::*)();
public:
    ReflectableField(FieldId fieldID, FieldAccessor accessor)
    : Field<T>( fieldID )
    , accessor( accessor )
    {}
    ReflectableField(FieldId fieldID, ConstMemAccessor accessor)
    : ReflectableField(fieldID, [=](const U& val){ return (val.*accessor)(); })
    {}

    const T& getFieldValue(const U& value) const {
        return accessor(value);
    }
private:
    FieldAccessor accessor;
};

class FieldDict {
public:
    FieldDict() = default;
    ~FieldDict() = default;
    FieldDict(const FieldDict&) = default;
    FieldDict(FieldDict&&) = default;

    template<typename T>
    void put(const Field<T>& field, ParserStorage<T> parser)
    {
        auto& fieldID = field.getFieldID();
        fields[fieldID] = std::static_pointer_cast<FieldParserBase>( parser );
    }
    template<typename T>
    T& operator[](const Field<T>& field)
    {
        auto& fieldID = field.getFieldID();
        auto ptr = find(fieldID);
        // TODO: assert(ptr != nullptr);
        auto parser = std::static_pointer_cast<FieldParser<T>>( ptr );
        return parser->getValue();
    }

    inline ParserColdStorage find(std::string fieldID)
    {
        auto it = fields.find(fieldID);
        if(it == fields.end()) {
            return nullptr;
        }
        return it->second;
    }
    inline size_t size() const
    {
        return fields.size();
    }
private:
    std::unordered_map<FieldId, ParserColdStorage> fields;
};