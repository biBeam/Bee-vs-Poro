#include "stdafx.h"
#include "Bullet.h"
#include "Main.h"

Main::Main()
{
	quantity = 0;

	for (int i = 0; i < 10; i++) {
		tower[i] = new Tower();
	}

	ui = new Ui();

	map = new Map * [stageR];
	for (int i = 0; i < stageR; i++) {
		map[i] = new Map[stageC];
	}

	bg = new ObImage(L"map.png");
	
	for (int i = 0; i < 10; i++) {
		bee[i] = new ObImage(L"normal.png");
		bee[i]->SetParentRT(*tower[i]);
	}
	
}

Main::~Main()
{
	for (int i = 0; i < 10; i++) {
		delete tower[i];
	}

	delete ui;

	for (int i = 0; i < stageR; i++) {
		delete[] map[i];
	}
	delete[] map;

	delete bg;
	for (int i = 0; i < 10; i++) {
		delete bee[i];
	}
}

void Main::Init()
{
	ui->Init();

	for (int i = 0; i < 10; i++) {
		tower[i]->collider = COLLIDER::RECT;
		bee[i]->scale.x = 80.0f;
		bee[i]->scale.y = 80.0f;
	}

	for (int i = 0; i < stageR; i++) {
		for (int j = 0; j < stageC; j++) {
			map[i][j].Init(Vector2((j - 1.5) * 120, (i - 1) * 120));
			map[i][j].collider = COLLIDER::RECT;
		}
	}

	bg->scale.x = app.GetWidth();
	bg->scale.y = app.GetHeight();
}

void Main::Release()
{

}

void Main::Update()
{


	for (int i = 0; i < 10; i++) {
		if (not tower[i]->isClick) continue;
		else {
			tower[i]->SetWorldPos(INPUT->GetWorldMousePos());
		}

		if (INPUT->KeyDown(VK_LBUTTON)) {
			tower[i]->isClick = false;
			tower[i]->isFire = true;

			for (int j = 0; j < stageR; j++) {
				for (int k = 0; k < stageC; k++) {
					if (tower[i]->Intersect(map[j][k].GetWorldPos())) {
						tower[i]->SetWorldPos(map[j][k].GetWorldPos());

					}
				}
			}
		}
	}


	


	for (int i = 0; i < 10; i++) {
		tower[i]->Update();
		bee[i]->Update();
	}


	ui->Update();

	for (int i = 0; i < stageR; i++) {
		for (int j = 0; j < stageC; j++) {
			map[i][j].Update();
		}
	}


	bg->Update();
}

void Main::LateUpdate()
{
	Vector2 m = INPUT->GetWorldMousePos();
	if (m.x >= -530 && m.x <= -470 && m.y >= 220 && m.y <= 280) {
		if (INPUT->KeyUp(VK_LBUTTON)) {
			tower[quantity]->isBuild = true;
			tower[quantity]->isClick = true;
			quantity++;
		}
	}

}

void Main::Render()
{

	bg->Render();


	ui->Render();

	for (int i = 0; i < stageR; i++) {
		for (int j = 0; j < stageC; j++) {
			map[i][j].Render();
		}
	}

	for (int i = 0; i < 10; i++) {
		tower[i]->Render();
		bee[i]->Render();
	}

}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	app.SetAppName(L"Game1");
	app.SetInstance(instance);
	app.InitWidthHeight(1200.0f, 700.0f);
	app.background = Color(1, 1, 1);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();

	return wParam;
}