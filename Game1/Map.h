#pragma once
class Map : public ObRect
{
	bool isBuild; //Ÿ�� ��ġ�� ������ �Ǻ�
	bool isUse; //���������� �ر��� Ǯ�������� �Ǻ�
public:
	Map();
	~Map();
	void Init(Vector2 spawn);
	void Update() override;
	void Render() override;


};

