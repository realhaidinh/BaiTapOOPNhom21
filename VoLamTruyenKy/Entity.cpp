#include "Entity.h"
#include<iostream>

Entity::Entity(){
	m_iLevel = 0;
	m_iBaseAttackDamage = 0;
	m_eElementID = HE_KIM;
}

Entity::Entity(unsigned int level){
	m_iLevel = level;
	m_iBaseAttackDamage = 0;
	m_eElementID = HE_KIM;
}

Entity::Entity(unsigned int level, EElementsID elementID){
	m_iLevel = level;
	m_iBaseAttackDamage = 0;
	m_eElementID = elementID;
}

Entity::Entity(unsigned int level, EElementsID elementID, std::string Name){
	m_iLevel = level;
	m_iBaseAttackDamage = 0;
	m_eElementID = elementID;
	m_sName = Name;
}

void Entity::setLevel(unsigned int lv){
	m_iLevel = lv;
}

void Entity::setBaseAttackDamage(unsigned int baseAttackDamage){
	m_iBaseAttackDamage = baseAttackDamage;
}

void Entity::setElement(EElementsID elementID){
	m_eElementID = elementID;
}

void Entity::info(){
	std::cout << "\tCap do: " << m_iLevel << '\n';
	std::cout << "\tMuc sat thuong co ban: " << m_iBaseAttackDamage << '\n';
	std::cout << "\tHanh: " << getElementType(m_eElementID) << '\n';
}

double Entity::getDamageMultiplierTo(const Entity& enemy)
{
	return g_fDamageMultiplier[m_eElementID][enemy.m_eElementID];
}

unsigned int Entity::getBaseAttackDamage()
{
	return m_iBaseAttackDamage;
}

Entity::~Entity(){
}
