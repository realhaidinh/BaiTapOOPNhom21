#pragma once
#include "Entity.h"
#include "Classes.h"
class Player : public Entity{
private:
	EClassID m_eClass;
public:
	Player();
	Player(unsigned int level, EClassID classID, std::string Name);

	void info();
	unsigned int getDamageDealtTo(const Entity& enemy);
	~Player();
};

