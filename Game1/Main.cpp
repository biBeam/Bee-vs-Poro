#include "stdafx.h"
#include "Bullet.h"
#include "Main.h"

Main::Main()
{


	for (int i = 0; i < 30; i++) {
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
	ui->collider = COLLIDER::RECT;

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
	//스테이지별 타워설치가능한 맵개방
	if (stage == 1)
	{
		for (int i = 0; i < 9;i++)
		{
			map[0][i].isUse = false;
			map[4][i].isUse = false;
		}
		for (int j = 1; j < 4; j++)
		{
			for (int k = 6; k < 9; k++)
			{
				map[j][k].isUse = false;
			}
		}
	}
	if (stage == 2)
	{
		for (int i = 0; i < 9; i++)
		{
			map[0][i].isUse = false;
		}
	}
	if (stage == 3)
	{
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 9; j++) {
				map[i][j].isUse = true;
			}
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
	for (int i = 0; i < 30; i++) {
		//타워 UI 클릭했을 때, 마우스 따라오기
		if (not tower[i]->isClick) continue;
		else {
			tower[i]->SetWorldPos(INPUT->GetWorldMousePos());
		}

		//설치할 곳에 클릭했을 때, 타워 설치되고 bullet 쏘기 시작
		if (INPUT->KeyDown(VK_LBUTTON)) {
			tower[i]->isClick = false;
			tower[i]->isFire = true;

			//타일 경계면에 마우스 클릭하면 중앙에 빨려들어가서 설치
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 10; k++) {
					if (tower[i]->Intersect(&map[j][k])) {
						tower[i]->SetParentRT(map[j][k]);
						tower[i]->SetLocalPos(Vector2 (0, 0));
						//tower[i]->SetWorldPos(map[j][k].GetWorldPos());

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
	//Vector2 m = INPUT->GetWorldMousePos();
	//if (m.x >= -530 && m.x <= -470 && m.y >= 220 && m.y <= 280)
	//좌상단 타워 UI
	if (ui->Intersect(INPUT->GetWorldMousePos())) {
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