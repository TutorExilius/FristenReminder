#include "currencyType.h"

#include <iomanip>
#include <sstream>

CurrencyType::CurrencyType( const std::string &fieldName, 
							const bool optional,
							const float &amount, 
							const CurrencyCode &currencyCode )
: FieldValue{ fieldName, optional }
, amount{ amount }
, currencyCode{ currencyCode }
{
}

CurrencyType::CurrencyType( const std::string &fieldName, 
							const bool optional,
							const float &amount,
							const std::string &currencyCodeStr )
: CurrencyType{ fieldName, optional, amount, CurrencyType::strToCurrencyCode( currencyCodeStr ) }
{
}

CurrencyCode CurrencyType::strToCurrencyCode( const std::string &currencyCodeStr )
{
    if( currencyCodeStr == "AED" ) return CurrencyCode::AED;
	if( currencyCodeStr == "AFN" ) return CurrencyCode::AFN;
	if( currencyCodeStr == "ALL" ) return CurrencyCode::ALL;
	if( currencyCodeStr == "AMD" ) return CurrencyCode::AMD;
	if( currencyCodeStr == "ANG" ) return CurrencyCode::ANG;
	if( currencyCodeStr == "AOA" ) return CurrencyCode::AOA;
	if( currencyCodeStr == "ARS" ) return CurrencyCode::ARS;
	if( currencyCodeStr == "AUD" ) return CurrencyCode::AUD;
	if( currencyCodeStr == "AWG" ) return CurrencyCode::AWG;
	if( currencyCodeStr == "AZN" ) return CurrencyCode::AZN;
	if( currencyCodeStr == "BAM" ) return CurrencyCode::BAM;
	if( currencyCodeStr == "BBD" ) return CurrencyCode::BBD;
	if( currencyCodeStr == "BDT" ) return CurrencyCode::BDT;
	if( currencyCodeStr == "BGN" ) return CurrencyCode::BGN;
	if( currencyCodeStr == "BHD" ) return CurrencyCode::BHD;
	if( currencyCodeStr == "BIF" ) return CurrencyCode::BIF;
	if( currencyCodeStr == "BMD" ) return CurrencyCode::BMD;
	if( currencyCodeStr == "BND" ) return CurrencyCode::BND;
	if( currencyCodeStr == "BOB" ) return CurrencyCode::BOB;
	if( currencyCodeStr == "BRL" ) return CurrencyCode::BRL;
	if( currencyCodeStr == "BSD" ) return CurrencyCode::BSD;
	if( currencyCodeStr == "BTN" ) return CurrencyCode::BTN;
	if( currencyCodeStr == "BWP" ) return CurrencyCode::BWP;
	if( currencyCodeStr == "BYR" ) return CurrencyCode::BYR;
	if( currencyCodeStr == "BZD" ) return CurrencyCode::BZD;
	if( currencyCodeStr == "CAD" ) return CurrencyCode::CAD;
	if( currencyCodeStr == "CDF" ) return CurrencyCode::CDF;
	if( currencyCodeStr == "CHF" ) return CurrencyCode::CHF;
	if( currencyCodeStr == "CLP" ) return CurrencyCode::CLP;
	if( currencyCodeStr == "CNY" ) return CurrencyCode::CNY;
	if( currencyCodeStr == "COP" ) return CurrencyCode::COP;
	if( currencyCodeStr == "CRC" ) return CurrencyCode::CRC;
	if( currencyCodeStr == "CUC" ) return CurrencyCode::CUC;
	if( currencyCodeStr == "CUP" ) return CurrencyCode::CUP;
	if( currencyCodeStr == "CVE" ) return CurrencyCode::CVE;
	if( currencyCodeStr == "CZK" ) return CurrencyCode::CZK;
	if( currencyCodeStr == "DJF" ) return CurrencyCode::DJF;
	if( currencyCodeStr == "DKK" ) return CurrencyCode::DKK;
	if( currencyCodeStr == "DOP" ) return CurrencyCode::DOP;
	if( currencyCodeStr == "DZD" ) return CurrencyCode::DZD;
	if( currencyCodeStr == "EGP" ) return CurrencyCode::EGP;
	if( currencyCodeStr == "ERN" ) return CurrencyCode::ERN;
	if( currencyCodeStr == "ETB" ) return CurrencyCode::ETB;
	if( currencyCodeStr == "EUR" ) return CurrencyCode::EUR;
	if( currencyCodeStr == "FJD" ) return CurrencyCode::FJD;
	if( currencyCodeStr == "FKP" ) return CurrencyCode::FKP;
	if( currencyCodeStr == "GBP" ) return CurrencyCode::GBP;
	if( currencyCodeStr == "GEL" ) return CurrencyCode::GEL;
	if( currencyCodeStr == "GGP" ) return CurrencyCode::GGP;
	if( currencyCodeStr == "GHS" ) return CurrencyCode::GHS;
	if( currencyCodeStr == "GIP" ) return CurrencyCode::GIP;
	if( currencyCodeStr == "GMD" ) return CurrencyCode::GMD;
	if( currencyCodeStr == "GNF" ) return CurrencyCode::GNF;
	if( currencyCodeStr == "GTQ" ) return CurrencyCode::GTQ;
	if( currencyCodeStr == "GYD" ) return CurrencyCode::GYD;
	if( currencyCodeStr == "HKD" ) return CurrencyCode::HKD;
	if( currencyCodeStr == "HNL" ) return CurrencyCode::HNL;
	if( currencyCodeStr == "HRK" ) return CurrencyCode::HRK;
	if( currencyCodeStr == "HTG" ) return CurrencyCode::HTG;
	if( currencyCodeStr == "HUF" ) return CurrencyCode::HUF;
	if( currencyCodeStr == "IDR" ) return CurrencyCode::IDR;
	if( currencyCodeStr == "ILS" ) return CurrencyCode::ILS;
	if( currencyCodeStr == "IMP" ) return CurrencyCode::IMP;
	if( currencyCodeStr == "INR" ) return CurrencyCode::INR;
	if( currencyCodeStr == "IQD" ) return CurrencyCode::IQD;
	if( currencyCodeStr == "IRR" ) return CurrencyCode::IRR;
	if( currencyCodeStr == "ISK" ) return CurrencyCode::ISK;
	if( currencyCodeStr == "JEP" ) return CurrencyCode::JEP;
	if( currencyCodeStr == "JMD" ) return CurrencyCode::JMD;
	if( currencyCodeStr == "JOD" ) return CurrencyCode::JOD;
	if( currencyCodeStr == "JPY" ) return CurrencyCode::JPY;
	if( currencyCodeStr == "KES" ) return CurrencyCode::KES;
	if( currencyCodeStr == "KGS" ) return CurrencyCode::KGS;
	if( currencyCodeStr == "KHR" ) return CurrencyCode::KHR;
	if( currencyCodeStr == "KMF" ) return CurrencyCode::KMF;
	if( currencyCodeStr == "KPW" ) return CurrencyCode::KPW;
	if( currencyCodeStr == "KRW" ) return CurrencyCode::KRW;
	if( currencyCodeStr == "KWD" ) return CurrencyCode::KWD;
	if( currencyCodeStr == "KYD" ) return CurrencyCode::KYD;
	if( currencyCodeStr == "KZT" ) return CurrencyCode::KZT;
	if( currencyCodeStr == "LAK" ) return CurrencyCode::LAK;
	if( currencyCodeStr == "LBP" ) return CurrencyCode::LBP;
	if( currencyCodeStr == "LKR" ) return CurrencyCode::LKR;
	if( currencyCodeStr == "LRD" ) return CurrencyCode::LRD;
	if( currencyCodeStr == "LSL" ) return CurrencyCode::LSL;
	if( currencyCodeStr == "LYD" ) return CurrencyCode::LYD;
	if( currencyCodeStr == "MAD" ) return CurrencyCode::MAD;
	if( currencyCodeStr == "MDL" ) return CurrencyCode::MDL;
	if( currencyCodeStr == "MGA" ) return CurrencyCode::MGA;
	if( currencyCodeStr == "MKD" ) return CurrencyCode::MKD;
	if( currencyCodeStr == "MMK" ) return CurrencyCode::MMK;
	if( currencyCodeStr == "MNT" ) return CurrencyCode::MNT;
	if( currencyCodeStr == "MOP" ) return CurrencyCode::MOP;
	if( currencyCodeStr == "MRO" ) return CurrencyCode::MRO;
	if( currencyCodeStr == "MUR" ) return CurrencyCode::MUR;
	if( currencyCodeStr == "MVR" ) return CurrencyCode::MVR;
	if( currencyCodeStr == "MWK" ) return CurrencyCode::MWK;
	if( currencyCodeStr == "MXN" ) return CurrencyCode::MXN;
	if( currencyCodeStr == "MYR" ) return CurrencyCode::MYR;
	if( currencyCodeStr == "MZN" ) return CurrencyCode::MZN;
	if( currencyCodeStr == "NAD" ) return CurrencyCode::NAD;
	if( currencyCodeStr == "NGN" ) return CurrencyCode::NGN;
	if( currencyCodeStr == "NIO" ) return CurrencyCode::NIO;
	if( currencyCodeStr == "NOK" ) return CurrencyCode::NOK;
	if( currencyCodeStr == "NPR" ) return CurrencyCode::NPR;
	if( currencyCodeStr == "NZD" ) return CurrencyCode::NZD;
	if( currencyCodeStr == "OMR" ) return CurrencyCode::OMR;
	if( currencyCodeStr == "PAB" ) return CurrencyCode::PAB;
	if( currencyCodeStr == "PEN" ) return CurrencyCode::PEN;
	if( currencyCodeStr == "PGK" ) return CurrencyCode::PGK;
	if( currencyCodeStr == "PHP" ) return CurrencyCode::PHP;
	if( currencyCodeStr == "PKR" ) return CurrencyCode::PKR;
	if( currencyCodeStr == "PLN" ) return CurrencyCode::PLN;
	if( currencyCodeStr == "PYG" ) return CurrencyCode::PYG;
	if( currencyCodeStr == "QAR" ) return CurrencyCode::QAR;
	if( currencyCodeStr == "RON" ) return CurrencyCode::RON;
	if( currencyCodeStr == "RSD" ) return CurrencyCode::RSD;
	if( currencyCodeStr == "RUB" ) return CurrencyCode::RUB;
	if( currencyCodeStr == "RWF" ) return CurrencyCode::RWF;
	if( currencyCodeStr == "SAR" ) return CurrencyCode::SAR;
	if( currencyCodeStr == "SBD" ) return CurrencyCode::SBD;
	if( currencyCodeStr == "SCR" ) return CurrencyCode::SCR;
	if( currencyCodeStr == "SDG" ) return CurrencyCode::SDG;
	if( currencyCodeStr == "SEK" ) return CurrencyCode::SEK;
	if( currencyCodeStr == "SGD" ) return CurrencyCode::SGD;
	if( currencyCodeStr == "SHP" ) return CurrencyCode::SHP;
	if( currencyCodeStr == "SLL" ) return CurrencyCode::SLL;
	if( currencyCodeStr == "SOS" ) return CurrencyCode::SOS;
	if( currencyCodeStr == "SPL" ) return CurrencyCode::SPL;
	if( currencyCodeStr == "SRD" ) return CurrencyCode::SRD;
	if( currencyCodeStr == "STD" ) return CurrencyCode::STD;
	if( currencyCodeStr == "SVC" ) return CurrencyCode::SVC;
	if( currencyCodeStr == "SYP" ) return CurrencyCode::SYP;
	if( currencyCodeStr == "SZL" ) return CurrencyCode::SZL;
	if( currencyCodeStr == "THB" ) return CurrencyCode::THB;
	if( currencyCodeStr == "TJS" ) return CurrencyCode::TJS;
	if( currencyCodeStr == "TMT" ) return CurrencyCode::TMT;
	if( currencyCodeStr == "TND" ) return CurrencyCode::TND;
	if( currencyCodeStr == "TOP" ) return CurrencyCode::TOP;
	if( currencyCodeStr == "TRY" ) return CurrencyCode::TRY;
	if( currencyCodeStr == "TTD" ) return CurrencyCode::TTD;
	if( currencyCodeStr == "TVD" ) return CurrencyCode::TVD;
	if( currencyCodeStr == "TWD" ) return CurrencyCode::TWD;
	if( currencyCodeStr == "TZS" ) return CurrencyCode::TZS;
	if( currencyCodeStr == "UAH" ) return CurrencyCode::UAH;
	if( currencyCodeStr == "UGX" ) return CurrencyCode::UGX;
	if( currencyCodeStr == "USD" ) return CurrencyCode::USD;
	if( currencyCodeStr == "UYU" ) return CurrencyCode::UYU;
	if( currencyCodeStr == "UZS" ) return CurrencyCode::UZS;
	if( currencyCodeStr == "VEF" ) return CurrencyCode::VEF;
	if( currencyCodeStr == "VND" ) return CurrencyCode::VND;
	if( currencyCodeStr == "VUV" ) return CurrencyCode::VUV;
	if( currencyCodeStr == "WST" ) return CurrencyCode::WST;
	if( currencyCodeStr == "XAF" ) return CurrencyCode::XAF;
	if( currencyCodeStr == "XCD" ) return CurrencyCode::XCD;
	if( currencyCodeStr == "XDR" ) return CurrencyCode::XDR;
	if( currencyCodeStr == "XOF" ) return CurrencyCode::XOF;
	if( currencyCodeStr == "XPF" ) return CurrencyCode::XPF;
	if( currencyCodeStr == "YER" ) return CurrencyCode::YER;
	if( currencyCodeStr == "ZAR" ) return CurrencyCode::ZAR;
	if( currencyCodeStr == "ZMW" ) return CurrencyCode::ZMW;
	if( currencyCodeStr == "ZWD" ) return CurrencyCode::ZWD;

	if( currencyCodeStr == "ERROR" )
		return CurrencyCode::ERROR;
	else
		return CurrencyCode::ERROR;
}

std::string CurrencyType::currencyCodeToStr( const CurrencyCode &CurrencyCode )
{
	switch( CurrencyCode )
	{
		case CurrencyCode::AED: return "AED"; 
		case CurrencyCode::AFN: return "AFN";
		case CurrencyCode::ALL: return "ALL";
		case CurrencyCode::AMD: return "AMD";
		case CurrencyCode::ANG: return "ANG";
		case CurrencyCode::AOA: return "AOA";
		case CurrencyCode::ARS: return "ARS";
		case CurrencyCode::AUD: return "AUD";
		case CurrencyCode::AWG: return "AWG";
		case CurrencyCode::AZN: return "AZN";
		case CurrencyCode::BAM: return "BAM";
		case CurrencyCode::BBD: return "BBD";
		case CurrencyCode::BDT: return "BDT";
		case CurrencyCode::BGN: return "BGN";
		case CurrencyCode::BHD: return "BHD";
		case CurrencyCode::BIF: return "BIF";
		case CurrencyCode::BMD: return "BMD";
		case CurrencyCode::BND: return "BND";
		case CurrencyCode::BOB: return "BOB";
		case CurrencyCode::BRL: return "BRL";
		case CurrencyCode::BSD: return "BSD";
		case CurrencyCode::BTN: return "BTN";
		case CurrencyCode::BWP: return "BWP";
		case CurrencyCode::BYR: return "BYR";
		case CurrencyCode::BZD: return "BZD";
		case CurrencyCode::CAD: return "CAD";
		case CurrencyCode::CDF: return "CDF";
		case CurrencyCode::CHF: return "CHF";
		case CurrencyCode::CLP: return "CLP";
		case CurrencyCode::CNY: return "CNY";
		case CurrencyCode::COP: return "COP";
		case CurrencyCode::CRC: return "CRC";
		case CurrencyCode::CUC: return "CUC";
		case CurrencyCode::CUP: return "CUP";
		case CurrencyCode::CVE: return "CVE";
		case CurrencyCode::CZK: return "CZK";
		case CurrencyCode::DJF: return "DJF";
		case CurrencyCode::DKK: return "DKK";
		case CurrencyCode::DOP: return "DOP";
		case CurrencyCode::DZD: return "DZD";
		case CurrencyCode::EGP: return "EGP";
		case CurrencyCode::ERN: return "ERN";
		case CurrencyCode::ETB: return "ETB";
		case CurrencyCode::EUR: return "EUR";
		case CurrencyCode::FJD: return "FJD";
		case CurrencyCode::FKP: return "FKP";
		case CurrencyCode::GBP: return "GBP";
		case CurrencyCode::GEL: return "GEL";
		case CurrencyCode::GGP: return "GGP";
		case CurrencyCode::GHS: return "GHS";
		case CurrencyCode::GIP: return "GIP";
		case CurrencyCode::GMD: return "GMD";
		case CurrencyCode::GNF: return "GNF";
		case CurrencyCode::GTQ: return "GTQ";
		case CurrencyCode::GYD: return "GYD";
		case CurrencyCode::HKD: return "HKD";
		case CurrencyCode::HNL: return "HNL";
		case CurrencyCode::HRK: return "HRK";
		case CurrencyCode::HTG: return "HTG";
		case CurrencyCode::HUF: return "HUF";
		case CurrencyCode::IDR: return "IDR";
		case CurrencyCode::ILS: return "ILS";
		case CurrencyCode::IMP: return "IMP";
		case CurrencyCode::INR: return "INR";
		case CurrencyCode::IQD: return "IQD";
		case CurrencyCode::IRR: return "IRR";
		case CurrencyCode::ISK: return "ISK";
		case CurrencyCode::JEP: return "JEP";
		case CurrencyCode::JMD: return "JMD";
		case CurrencyCode::JOD: return "JOD";
		case CurrencyCode::JPY: return "JPY";
		case CurrencyCode::KES: return "KES";
		case CurrencyCode::KGS: return "KGS";
		case CurrencyCode::KHR: return "KHR";
		case CurrencyCode::KMF: return "KMF";
		case CurrencyCode::KPW: return "KPW";
		case CurrencyCode::KRW: return "KRW";
		case CurrencyCode::KWD: return "KWD";
		case CurrencyCode::KYD: return "KYD";
		case CurrencyCode::KZT: return "KZT";
		case CurrencyCode::LAK: return "LAK";
		case CurrencyCode::LBP: return "LBP";
		case CurrencyCode::LKR: return "LKR";
		case CurrencyCode::LRD: return "LRD";
		case CurrencyCode::LSL: return "LSL";
		case CurrencyCode::LYD: return "LYD";
		case CurrencyCode::MAD: return "MAD";
		case CurrencyCode::MDL: return "MDL";
		case CurrencyCode::MGA: return "MGA";
		case CurrencyCode::MKD: return "MKD";
		case CurrencyCode::MMK: return "MMK";
		case CurrencyCode::MNT: return "MNT";
		case CurrencyCode::MOP: return "MOP";
		case CurrencyCode::MRO: return "MRO";
		case CurrencyCode::MUR: return "MUR";
		case CurrencyCode::MVR: return "MVR";
		case CurrencyCode::MWK: return "MWK";
		case CurrencyCode::MXN: return "MXN";
		case CurrencyCode::MYR: return "MYR";
		case CurrencyCode::MZN: return "MZN";
		case CurrencyCode::NAD: return "NAD";
		case CurrencyCode::NGN: return "NGN";
		case CurrencyCode::NIO: return "NIO";
		case CurrencyCode::NOK: return "NOK";
		case CurrencyCode::NPR: return "NPR";
		case CurrencyCode::NZD: return "NZD";
		case CurrencyCode::OMR: return "OMR";
		case CurrencyCode::PAB: return "PAB";
		case CurrencyCode::PEN: return "PEN";
		case CurrencyCode::PGK: return "PGK";
		case CurrencyCode::PHP: return "PHP";
		case CurrencyCode::PKR: return "PKR";
		case CurrencyCode::PLN: return "PLN";
		case CurrencyCode::PYG: return "PYG";
		case CurrencyCode::QAR: return "QAR";
		case CurrencyCode::RON: return "RON";
		case CurrencyCode::RSD: return "RSD";
		case CurrencyCode::RUB: return "RUB";
		case CurrencyCode::RWF: return "RWF";
		case CurrencyCode::SAR: return "SAR";
		case CurrencyCode::SBD: return "SBD";
		case CurrencyCode::SCR: return "SCR";
		case CurrencyCode::SDG: return "SDG";
		case CurrencyCode::SEK: return "SEK";
		case CurrencyCode::SGD: return "SGD";
		case CurrencyCode::SHP: return "SHP";
		case CurrencyCode::SLL: return "SLL";
		case CurrencyCode::SOS: return "SOS";
		case CurrencyCode::SPL: return "SPL";
		case CurrencyCode::SRD: return "SRD";
		case CurrencyCode::STD: return "STD";
		case CurrencyCode::SVC: return "SVC";
		case CurrencyCode::SYP: return "SYP";
		case CurrencyCode::SZL: return "SZL";
		case CurrencyCode::THB: return "THB";
		case CurrencyCode::TJS: return "TJS";
		case CurrencyCode::TMT: return "TMT";
		case CurrencyCode::TND: return "TND";
		case CurrencyCode::TOP: return "TOP";
		case CurrencyCode::TRY: return "TRY";
		case CurrencyCode::TTD: return "TTD";
		case CurrencyCode::TVD: return "TVD";
		case CurrencyCode::TWD: return "TWD";
		case CurrencyCode::TZS: return "TZS";
		case CurrencyCode::UAH: return "UAH";
		case CurrencyCode::UGX: return "UGX";
		case CurrencyCode::USD: return "USD";
		case CurrencyCode::UYU: return "UYU";
		case CurrencyCode::UZS: return "UZS";
		case CurrencyCode::VEF: return "VEF";
		case CurrencyCode::VND: return "VND";
		case CurrencyCode::VUV: return "VUV";
		case CurrencyCode::WST: return "WST";
		case CurrencyCode::XAF: return "XAF";
		case CurrencyCode::XCD: return "XCD";
		case CurrencyCode::XDR: return "XDR";
		case CurrencyCode::XOF: return "XOF";
		case CurrencyCode::XPF: return "XPF";
		case CurrencyCode::YER: return "YER";
		case CurrencyCode::ZAR: return "ZAR";
		case CurrencyCode::ZMW: return "ZMW";
		case CurrencyCode::ZWD: return "ZWD";
		
		case CurrencyCode::ERROR:
		default: return "ERROR";
	}
}

std::string CurrencyType::toString() const
{
	std::stringstream out;

	out << std::fixed << std::setprecision( 3 ) << this->amount << ' '
		<< CurrencyType::currencyCodeToStr( this->currencyCode );

	return out.str();
}