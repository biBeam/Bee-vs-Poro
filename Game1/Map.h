#pragma once
class Map : public ObRect
{
	bool isBuild;
public:
	bool isUse; //���������� �ر��� Ǯ�������� �Ǻ�
	int stage;
public:
	Map();
	~Map();
	void Init(Vector2 spawn);
	void Update() override;
	void Render() override;


};

