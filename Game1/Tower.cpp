#include "stdafx.h"
#include "Tower.h"

Tower::Tower(int towerName) {
	switch (towerName) {
	case 1:
		scale.x = 60.0f;
		scale.y = 60.0f;

		att = 0;
		attSpeed = 0;

		isBuild = false;
		isClick = false;
		isFire = false;
		break;

	case 2:
		scale.x = 60.0f;
		scale.y = 60.0f;

		att = 10;
		attSpeed = 1;

		isBuild = false;
		isClick = false;
		isFire = false;
		break;

	case 3:
		scale.x = 60.0f;
		scale.y = 60.0f;

		att = 20;
		attSpeed = 1;

		isBuild = false;
		isClick = false;
		isFire = false;
		break;
	}

}
Tower::Tower()
{
}
Tower::~Tower()
{
}

void Tower::Init(Vector2 spawn)
{
	SetWorldPos(spawn);
}

void Tower::Update()
{
	if (not isBuild) return;

	ObRect::Update();



	/*for (int i = 0; i < 10; i++) {
		bullet[i]->Update();
	}*/

}

void Tower::Render()
{
	ObRect::Render();

	/*for (int i = 0; i < 10; i++) {
		bullet[i]->Render();

	}*/

}

void Tower::Control()
{
	if (not isFire) return;

	/*for (int i = 0; i < 10; i++) {
		bullet[i]->isFire = true;
		bullet[i]->Fire(this);
	}*/
}



Ui::Ui()
{
	scale.x = 60.0f;
	scale.y = 60.0f;
	isBuild = true;
}

Ui::~Ui()
{
}

void Ui::Init()
{
	SetWorldPos(Vector2(-500, 250));
}
