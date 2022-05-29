#pragma once
#include"Entity.h"
#include"Monster.h"
#include"Player.h"
#include<vector>
class World{
private:
	std::vector<Entity* > m_vEntity;
public:
	World();

	void AddPlayer();
	void AddMonster();
	void DisplayEntityInformation();
	void DisplayAllInformation();
	void Comparison();
	void DisplayHighestDamage();
	void Init();

	~World();
};

