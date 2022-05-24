#pragma once
#include<string>
enum EElementsID {
	HE_KIM = 0,
	HE_MOC,
	HE_THUY,
	HE_HOA,
	HE_THO
};

const double g_fDamageMultiplier[5][5] =
 {{1, 1.2, 1.1, 0.8, 1},
  {0.8, 1, 1, 1.1, 1.2},
  {1, 1.1, 1, 1.2, 0.8},
  {1.2, 1, 0.8, 1, 1.1},
  {1.1, 0.8, 1.2, 1, 1}};

std::string getElementType(EElementsID element);