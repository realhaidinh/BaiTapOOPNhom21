#include "Player.h"
#include<iostream>
Player::Player(){
	m_eClass = (EClassID)0;
}

Player::Player(unsigned int level, EClassID classID, std::string Name) : Entity{ level } {
	m_eClass = classID;
	m_iBaseAttackDamage = m_iLevel * 5;
	m_sName = Name;
	switch (m_eClass)
	{
	case ThieuLam:
		m_eElementID = HE_KIM;
		break;
	case ThienVuong:
		m_eElementID = HE_KIM;
		break;
	case NguDoc:
		m_eElementID = HE_MOC;
		break;
	case DuongMon:
		m_eElementID = HE_MOC;
		break;
	case NgaMy:
		m_eElementID = HE_THUY;
		break;
	case ThuyYen:
		m_eElementID = HE_THUY;
		break;
	case CaiBang:
		m_eElementID = HE_HOA;
		break;
	case ThienNhan:
		m_eElementID = HE_HOA;
		break;
	case ConLon:
		m_eElementID = HE_THO;
		break;
	case VoDang:
		m_eElementID = HE_THO;
		break;
	default:
		break;
	}
}

void Player::info(){
	std::cout << "\tTen cua nhan vat: " << m_sName << '\n';
	std::cout << "\tBang: " << getClassName(m_eClass) << '\n';
	Entity::info();
}

unsigned int Player::getDamageDealtTo(const Entity& enemy)
{
	return (unsigned int)(m_iBaseAttackDamage * getDamageMultiplierTo(enemy));
}

Player::~Player(){
}
