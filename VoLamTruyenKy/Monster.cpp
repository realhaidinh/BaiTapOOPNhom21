#include "Monster.h"
#include<iostream>
Monster::Monster(){
	m_bIsBoss = 0;
}

Monster::Monster(unsigned int level, EElementsID elementID, bool isBoss, std::string Name): Entity{level, elementID}{
	m_bIsBoss = isBoss;
	m_iBaseAttackDamage = (3 + 4 * m_bIsBoss) * m_iLevel;
	m_sName = Name;
}


void Monster::info(){
	std::cout << "\tTen quai vat: " << m_sName <<'\n';
	if (m_bIsBoss) {
		std::cout << "\tLa quai dau linh.\n";
	}
	else {
		std::cout << "\tLa quai thong thuong.\n";
	}
	Entity::info();
}

void Monster::setBoss(bool isBoss){
	m_bIsBoss = isBoss;
}

unsigned int Monster::getDamageDealtTo(const Entity& enemy)
{
	return (unsigned int)(m_iBaseAttackDamage * getDamageMultiplierTo(enemy));
}

Monster::~Monster(){
}
