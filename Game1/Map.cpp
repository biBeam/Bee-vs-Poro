#include "stdafx.h"
#include "Map.h"

Map::Map()
{
	scale.x = 92.0f;
	scale.y = 112.0f;

	color.x = 0.7f;
	color.y = 0.7f;
	color.z = 0.7f;
}

Map::~Map()
{
}

void Map::Init(Vector2 spawn)
{
	SetWorldPos(spawn);
}

void Map::Update()
{
	ObRect::Update();
}

void Map::Render()
{
	ObRect::Render();
}
