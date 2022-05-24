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
	void init();
	~World();
};

