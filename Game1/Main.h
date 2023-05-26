#pragma once

class Main : public Scene
{
private:

	Tower* tower[10];
	Map** map;

	Ui* ui;
	ObImage* bg;
	ObImage* bee[10];
	
public:
	Main();
	~Main();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;

public:
	int quantity;
	int stageR = 3;
	int stageC = 5;
};
