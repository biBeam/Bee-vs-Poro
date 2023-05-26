#include "stdafx.h"
#include "Bullet.h"
#include "Main.h"

Main::Main()
{
	

	for (int i = 0; i < 10; i++) {
		tower[i] = new Tower();
	}

	ui = new Ui();

	map = new Map * [5];
	for (int i = 0; i < 5; i++) {
		map[i] = new Map[9];
	}

	bg = new ObImage(L"map.png");
	
	/*for (int i = 0; i < 10; i++) {
		bee[i] = new ObImage(L"attack.png");
		bee[i]->SetParentRT(*tower[i]);
	}*/
	bee = new ObImage(L"attack.png");
	
}

Main::~Main()
{
	for (int i = 0; i < 10; i++) {
		delete tower[i];
	}

	delete ui;

	for (int i = 0; i < 5; i++) {
		delete[] map[i];
	}
	delete[] map;

	delete bg;
	/*for (int i = 0; i < 10; i++) {
		delete bee[i];
	}*/
	delete bee;
}

void Main::Init()
{
	ui->Init();

	/*for (int i = 0; i < 10; i++) {
		tower[i]->collider = COLLIDER::RECT;
		bee[i]->scale.x = 80.0f;
		bee[i]->scale.y = 80.0f;
	}*/

	

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			map[i][j].Init(Vector2((j - 2.7) * 92, (i - 2.2) * 112));
			map[i][j].isFilled = false;
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

			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 10; k++) {
					if (tower[i]->Intersect(&map[j][k])) {
						tower[i]->SetWorldPos(map[j][k].GetWorldPos());

					}
				}
			}
		}
	}


	


	/*for (int i = 0; i < 10; i++) {
		tower[i]->Update();
		bee[i]->Update();
	}*/

	bee->Update();

	ui->Update();

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
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

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			map[i][j].Render();
		}
	}

	for (int i = 0; i < 10; i++) {
		tower[i]->Render();
		//bee[i]->Render();
	}
	bee->Render();
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