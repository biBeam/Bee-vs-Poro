#pragma once
class Main : public Scene
{
private:

	Tower* tower[30];
	Map** map;

	Ui* ui;
	ObImage* bg;
	ObImage* bee[30];

	int stage = 3; // �ӽ� �������� ���к��� Ÿ�� Ȱ��üũ��
	
public:
	Main();
	~Main();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;

public:
	int quantity = 0;
	int stageR = 3; //������
	int stageC = 5; //������
};
