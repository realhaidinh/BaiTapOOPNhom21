#include "Elements.h"

std::string getElementType(EElementsID element)
{
	switch (element)
	{
	case HE_KIM:
		return "He Kim";
	case HE_MOC:
		return "He Moc";
	case HE_THUY:
		return "He Thuy";
	case HE_HOA:
		return "He Hoa";
	}
	return "He Tho";
}

