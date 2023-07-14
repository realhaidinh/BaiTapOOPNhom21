#include "Classes.h"


std::string getClassName(EClassID ClassID){
	switch (ClassID){
	case ThieuLam: {
		return "Thieu Lam";
		break;
	}
	case ThienVuong: {
		return "Thien Vuong Bang";
		break;
	}
	case NguDoc: {
		return "Ngu Doc Giao";
		break;
	}
	case DuongMon: {
		return "Duong Mon";
		break;
	}
	case NgaMy: {
		return "Nga My";
		break;
	}
	case ThuyYen: {
		return "Thuy Yen";
		break;
	}
	case CaiBang: {
		return "Cai Bang";
		break;
	}
	case ThienNhan: {
		return "Thien Nhan Giao";
		break;
	}
	case ConLon: {
		return "Con Lon";
		break;
	}
	case VoDang: {
		return "Vo Dang";
		break;
	}
	default:
		break;
	}
	return "";
}
