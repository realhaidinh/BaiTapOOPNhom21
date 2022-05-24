#pragma once
#include "Elements.h"
#include<string>

class Entity{
protected:
	unsigned int m_iLevel;
	unsigned int m_iBaseAttackDamage;
	EElementsID m_eElementID;
	std::string m_sName;
public:
	
	Entity();
	Entity(unsigned int level);
	Entity(unsigned int level, EElementsID elementID);
	Entity(unsigned int level, EElementsID elementID, std::string Name);

	void setLevel(unsigned int level);
	void setBaseAttackDamage(unsigned int baseAttackDamage);
	void setElement(EElementsID elementID);
	virtual void info();
	double getDamageMultiplierTo(const Entity& enemy);
	unsigned int getBaseAttackDamage();
	virtual unsigned int getDamageDealtTo(const Entity& enemy) = 0;

	virtual ~Entity();
};
