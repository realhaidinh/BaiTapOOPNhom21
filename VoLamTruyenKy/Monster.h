#pragma once
#include "Entity.h"
class Monster : public Entity{
private:
	bool m_bIsBoss;
public:
	Monster();
	Monster(unsigned int level, EElementsID elementID, bool isBoss, std::string Name);

	void info();
	void setBoss(bool isBoss);
	unsigned int getDamageDealtTo(const Entity& enemy);
	
	~Monster();
};

