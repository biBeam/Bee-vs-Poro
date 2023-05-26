#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
	scale.x = 20.0f;
	scale.y = 20.0f;

	isFire = false;
}

Bullet::~Bullet()
{
}

void Bullet::Fire(GameObject* shooter)
{
	SetWorldPos(shooter->GetWorldPos());
	fireDir = shooter->GetRight();
}

void Bullet::Update()
{
	if (not isFire) return;

	MoveWorldPos(fireDir * 100.0f * DELTA);

	ObRect::Update();

	if (GetWorldPos().x >= 600) isFire = false;
}

void Bullet::Render()
{
	if (not isFire) return;

	ObRect::Render();

}
