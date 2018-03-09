#include "currencyType.h"

#include "helper.h"

#include <algorithm>
#include <iomanip>
#include <sstream>

CurrencyType::CurrencyType( const float &amount, 
							const CurrencyCode &currencyCode )
: amount{ amount }
, currencyCode{ currencyCode }
{
}

CurrencyType::CurrencyType( const float &amount,
							const std::string &currencyCodeStr )
: CurrencyType{ amount, CurrencyType::strToCurrencyCode( currencyCodeStr ) }
{
}

CurrencyCode CurrencyType::strToCurrencyCode( const std::string &currencyCodeStr )
{
	std::string currencyCodeStrUPPER = Helper::toUpper( currencyCodeStr );
	
    if( currencyCodeStrUPPER == "AED" ) return CurrencyCode::AED;
	if( currencyCodeStrUPPER == "AFN" ) return CurrencyCode::AFN;
	if( currencyCodeStrUPPER == "ALL" ) return CurrencyCode::ALL;
	if( currencyCodeStrUPPER == "AMD" ) return CurrencyCode::AMD;
	if( currencyCodeStrUPPER == "ANG" ) return CurrencyCode::ANG;
	if( currencyCodeStrUPPER == "AOA" ) return CurrencyCode::AOA;
	if( currencyCodeStrUPPER == "ARS" ) return CurrencyCode::ARS;
	if( currencyCodeStrUPPER == "AUD" ) return CurrencyCode::AUD;
	if( currencyCodeStrUPPER == "AWG" ) return CurrencyCode::AWG;
	if( currencyCodeStrUPPER == "AZN" ) return CurrencyCode::AZN;
	if( currencyCodeStrUPPER == "BAM" ) return CurrencyCode::BAM;
	if( currencyCodeStrUPPER == "BBD" ) return CurrencyCode::BBD;
	if( currencyCodeStrUPPER == "BDT" ) return CurrencyCode::BDT;
	if( currencyCodeStrUPPER == "BGN" ) return CurrencyCode::BGN;
	if( currencyCodeStrUPPER == "BHD" ) return CurrencyCode::BHD;
	if( currencyCodeStrUPPER == "BIF" ) return CurrencyCode::BIF;
	if( currencyCodeStrUPPER == "BMD" ) return CurrencyCode::BMD;
	if( currencyCodeStrUPPER == "BND" ) return CurrencyCode::BND;
	if( currencyCodeStrUPPER == "BOB" ) return CurrencyCode::BOB;
	if( currencyCodeStrUPPER == "BRL" ) return CurrencyCode::BRL;
	if( currencyCodeStrUPPER == "BSD" ) return CurrencyCode::BSD;
	if( currencyCodeStrUPPER == "BTN" ) return CurrencyCode::BTN;
	if( currencyCodeStrUPPER == "BWP" ) return CurrencyCode::BWP;
	if( currencyCodeStrUPPER == "BYR" ) return CurrencyCode::BYR;
	if( currencyCodeStrUPPER == "BZD" ) return CurrencyCode::BZD;
	if( currencyCodeStrUPPER == "CAD" ) return CurrencyCode::CAD;
	if( currencyCodeStrUPPER == "CDF" ) return CurrencyCode::CDF;
	if( currencyCodeStrUPPER == "CHF" ) return CurrencyCode::CHF;
	if( currencyCodeStrUPPER == "CLP" ) return CurrencyCode::CLP;
	if( currencyCodeStrUPPER == "CNY" ) return CurrencyCode::CNY;
	if( currencyCodeStrUPPER == "COP" ) return CurrencyCode::COP;
	if( currencyCodeStrUPPER == "CRC" ) return CurrencyCode::CRC;
	if( currencyCodeStrUPPER == "CUC" ) return CurrencyCode::CUC;
	if( currencyCodeStrUPPER == "CUP" ) return CurrencyCode::CUP;
	if( currencyCodeStrUPPER == "CVE" ) return CurrencyCode::CVE;
	if( currencyCodeStrUPPER == "CZK" ) return CurrencyCode::CZK;
	if( currencyCodeStrUPPER == "DJF" ) return CurrencyCode::DJF;
	if( currencyCodeStrUPPER == "DKK" ) return CurrencyCode::DKK;
	if( currencyCodeStrUPPER == "DOP" ) return CurrencyCode::DOP;
	if( currencyCodeStrUPPER == "DZD" ) return CurrencyCode::DZD;
	if( currencyCodeStrUPPER == "EGP" ) return CurrencyCode::EGP;
	if( currencyCodeStrUPPER == "ERN" ) return CurrencyCode::ERN;
	if( currencyCodeStrUPPER == "ETB" ) return CurrencyCode::ETB;
	if( currencyCodeStrUPPER == "EUR" ) return CurrencyCode::EUR;
	if( currencyCodeStrUPPER == "FJD" ) return CurrencyCode::FJD;
	if( currencyCodeStrUPPER == "FKP" ) return CurrencyCode::FKP;
	if( currencyCodeStrUPPER == "GBP" ) return CurrencyCode::GBP;
	if( currencyCodeStrUPPER == "GEL" ) return CurrencyCode::GEL;
	if( currencyCodeStrUPPER == "GGP" ) return CurrencyCode::GGP;
	if( currencyCodeStrUPPER == "GHS" ) return CurrencyCode::GHS;
	if( currencyCodeStrUPPER == "GIP" ) return CurrencyCode::GIP;
	if( currencyCodeStrUPPER == "GMD" ) return CurrencyCode::GMD;
	if( currencyCodeStrUPPER == "GNF" ) return CurrencyCode::GNF;
	if( currencyCodeStrUPPER == "GTQ" ) return CurrencyCode::GTQ;
	if( currencyCodeStrUPPER == "GYD" ) return CurrencyCode::GYD;
	if( currencyCodeStrUPPER == "HKD" ) return CurrencyCode::HKD;
	if( currencyCodeStrUPPER == "HNL" ) return CurrencyCode::HNL;
	if( currencyCodeStrUPPER == "HRK" ) return CurrencyCode::HRK;
	if( currencyCodeStrUPPER == "HTG" ) return CurrencyCode::HTG;
	if( currencyCodeStrUPPER == "HUF" ) return CurrencyCode::HUF;
	if( currencyCodeStrUPPER == "IDR" ) return CurrencyCode::IDR;
	if( currencyCodeStrUPPER == "ILS" ) return CurrencyCode::ILS;
	if( currencyCodeStrUPPER == "IMP" ) return CurrencyCode::IMP;
	if( currencyCodeStrUPPER == "INR" ) return CurrencyCode::INR;
	if( currencyCodeStrUPPER == "IQD" ) return CurrencyCode::IQD;
	if( currencyCodeStrUPPER == "IRR" ) return CurrencyCode::IRR;
	if( currencyCodeStrUPPER == "ISK" ) return CurrencyCode::ISK;
	if( currencyCodeStrUPPER == "JEP" ) return CurrencyCode::JEP;
	if( currencyCodeStrUPPER == "JMD" ) return CurrencyCode::JMD;
	if( currencyCodeStrUPPER == "JOD" ) return CurrencyCode::JOD;
	if( currencyCodeStrUPPER == "JPY" ) return CurrencyCode::JPY;
	if( currencyCodeStrUPPER == "KES" ) return CurrencyCode::KES;
	if( currencyCodeStrUPPER == "KGS" ) return CurrencyCode::KGS;
	if( currencyCodeStrUPPER == "KHR" ) return CurrencyCode::KHR;
	if( currencyCodeStrUPPER == "KMF" ) return CurrencyCode::KMF;
	if( currencyCodeStrUPPER == "KPW" ) return CurrencyCode::KPW;
	if( currencyCodeStrUPPER == "KRW" ) return CurrencyCode::KRW;
	if( currencyCodeStrUPPER == "KWD" ) return CurrencyCode::KWD;
	if( currencyCodeStrUPPER == "KYD" ) return CurrencyCode::KYD;
	if( currencyCodeStrUPPER == "KZT" ) return CurrencyCode::KZT;
	if( currencyCodeStrUPPER == "LAK" ) return CurrencyCode::LAK;
	if( currencyCodeStrUPPER == "LBP" ) return CurrencyCode::LBP;
	if( currencyCodeStrUPPER == "LKR" ) return CurrencyCode::LKR;
	if( currencyCodeStrUPPER == "LRD" ) return CurrencyCode::LRD;
	if( currencyCodeStrUPPER == "LSL" ) return CurrencyCode::LSL;
	if( currencyCodeStrUPPER == "LYD" ) return CurrencyCode::LYD;
	if( currencyCodeStrUPPER == "MAD" ) return CurrencyCode::MAD;
	if( currencyCodeStrUPPER == "MDL" ) return CurrencyCode::MDL;
	if( currencyCodeStrUPPER == "MGA" ) return CurrencyCode::MGA;
	if( currencyCodeStrUPPER == "MKD" ) return CurrencyCode::MKD;
	if( currencyCodeStrUPPER == "MMK" ) return CurrencyCode::MMK;
	if( currencyCodeStrUPPER == "MNT" ) return CurrencyCode::MNT;
	if( currencyCodeStrUPPER == "MOP" ) return CurrencyCode::MOP;
	if( currencyCodeStrUPPER == "MRO" ) return CurrencyCode::MRO;
	if( currencyCodeStrUPPER == "MUR" ) return CurrencyCode::MUR;
	if( currencyCodeStrUPPER == "MVR" ) return CurrencyCode::MVR;
	if( currencyCodeStrUPPER == "MWK" ) return CurrencyCode::MWK;
	if( currencyCodeStrUPPER == "MXN" ) return CurrencyCode::MXN;
	if( currencyCodeStrUPPER == "MYR" ) return CurrencyCode::MYR;
	if( currencyCodeStrUPPER == "MZN" ) return CurrencyCode::MZN;
	if( currencyCodeStrUPPER == "NAD" ) return CurrencyCode::NAD;
	if( currencyCodeStrUPPER == "NGN" ) return CurrencyCode::NGN;
	if( currencyCodeStrUPPER == "NIO" ) return CurrencyCode::NIO;
	if( currencyCodeStrUPPER == "NOK" ) return CurrencyCode::NOK;
	if( currencyCodeStrUPPER == "NPR" ) return CurrencyCode::NPR;
	if( currencyCodeStrUPPER == "NZD" ) return CurrencyCode::NZD;
	if( currencyCodeStrUPPER == "OMR" ) return CurrencyCode::OMR;
	if( currencyCodeStrUPPER == "PAB" ) return CurrencyCode::PAB;
	if( currencyCodeStrUPPER == "PEN" ) return CurrencyCode::PEN;
	if( currencyCodeStrUPPER == "PGK" ) return CurrencyCode::PGK;
	if( currencyCodeStrUPPER == "PHP" ) return CurrencyCode::PHP;
	if( currencyCodeStrUPPER == "PKR" ) return CurrencyCode::PKR;
	if( currencyCodeStrUPPER == "PLN" ) return CurrencyCode::PLN;
	if( currencyCodeStrUPPER == "PYG" ) return CurrencyCode::PYG;
	if( currencyCodeStrUPPER == "QAR" ) return CurrencyCode::QAR;
	if( currencyCodeStrUPPER == "RON" ) return CurrencyCode::RON;
	if( currencyCodeStrUPPER == "RSD" ) return CurrencyCode::RSD;
	if( currencyCodeStrUPPER == "RUB" ) return CurrencyCode::RUB;
	if( currencyCodeStrUPPER == "RWF" ) return CurrencyCode::RWF;
	if( currencyCodeStrUPPER == "SAR" ) return CurrencyCode::SAR;
	if( currencyCodeStrUPPER == "SBD" ) return CurrencyCode::SBD;
	if( currencyCodeStrUPPER == "SCR" ) return CurrencyCode::SCR;
	if( currencyCodeStrUPPER == "SDG" ) return CurrencyCode::SDG;
	if( currencyCodeStrUPPER == "SEK" ) return CurrencyCode::SEK;
	if( currencyCodeStrUPPER == "SGD" ) return CurrencyCode::SGD;
	if( currencyCodeStrUPPER == "SHP" ) return CurrencyCode::SHP;
	if( currencyCodeStrUPPER == "SLL" ) return CurrencyCode::SLL;
	if( currencyCodeStrUPPER == "SOS" ) return CurrencyCode::SOS;
	if( currencyCodeStrUPPER == "SPL" ) return CurrencyCode::SPL;
	if( currencyCodeStrUPPER == "SRD" ) return CurrencyCode::SRD;
	if( currencyCodeStrUPPER == "STD" ) return CurrencyCode::STD;
	if( currencyCodeStrUPPER == "SVC" ) return CurrencyCode::SVC;
	if( currencyCodeStrUPPER == "SYP" ) return CurrencyCode::SYP;
	if( currencyCodeStrUPPER == "SZL" ) return CurrencyCode::SZL;
	if( currencyCodeStrUPPER == "THB" ) return CurrencyCode::THB;
	if( currencyCodeStrUPPER == "TJS" ) return CurrencyCode::TJS;
	if( currencyCodeStrUPPER == "TMT" ) return CurrencyCode::TMT;
	if( currencyCodeStrUPPER == "TND" ) return CurrencyCode::TND;
	if( currencyCodeStrUPPER == "TOP" ) return CurrencyCode::TOP;
	if( currencyCodeStrUPPER == "TRY" ) return CurrencyCode::TRY;
	if( currencyCodeStrUPPER == "TTD" ) return CurrencyCode::TTD;
	if( currencyCodeStrUPPER == "TVD" ) return CurrencyCode::TVD;
	if( currencyCodeStrUPPER == "TWD" ) return CurrencyCode::TWD;
	if( currencyCodeStrUPPER == "TZS" ) return CurrencyCode::TZS;
	if( currencyCodeStrUPPER == "UAH" ) return CurrencyCode::UAH;
	if( currencyCodeStrUPPER == "UGX" ) return CurrencyCode::UGX;
	if( currencyCodeStrUPPER == "USD" ) return CurrencyCode::USD;
	if( currencyCodeStrUPPER == "UYU" ) return CurrencyCode::UYU;
	if( currencyCodeStrUPPER == "UZS" ) return CurrencyCode::UZS;
	if( currencyCodeStrUPPER == "VEF" ) return CurrencyCode::VEF;
	if( currencyCodeStrUPPER == "VND" ) return CurrencyCode::VND;
	if( currencyCodeStrUPPER == "VUV" ) return CurrencyCode::VUV;
	if( currencyCodeStrUPPER == "WST" ) return CurrencyCode::WST;
	if( currencyCodeStrUPPER == "XAF" ) return CurrencyCode::XAF;
	if( currencyCodeStrUPPER == "XCD" ) return CurrencyCode::XCD;
	if( currencyCodeStrUPPER == "XDR" ) return CurrencyCode::XDR;
	if( currencyCodeStrUPPER == "XOF" ) return CurrencyCode::XOF;
	if( currencyCodeStrUPPER == "XPF" ) return CurrencyCode::XPF;
	if( currencyCodeStrUPPER == "YER" ) return CurrencyCode::YER;
	if( currencyCodeStrUPPER == "ZAR" ) return CurrencyCode::ZAR;
	if( currencyCodeStrUPPER == "ZMW" ) return CurrencyCode::ZMW;
	if( currencyCodeStrUPPER == "ZWD" ) return CurrencyCode::ZWD;
	
	if( currencyCodeStrUPPER == "ERROR" )
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

	out << std::fixed << std::setprecision( 2 ) << this->amount << ' '
		<< CurrencyType::currencyCodeToStr( this->currencyCode );

	return out.str();
}
