#pragma once
class Tower : public Unit
{
protected:
	float	attSpeed;
	int		att;
	int		price;
private:
	class Bullet* bullet[10];

public:
	bool isBuild;
	bool isClick;
	bool isFire;

public:
	Tower();
	Tower(int towerName);
	~Tower();
	virtual void Init(Vector2 spawn);
	void Update() override;
	void Render() override;
	void Control();
	int getAtt() { return att; }
	float getAttSpeed() { return attSpeed; }
	int getPrice() { return price; }
};

class Ui :public Tower
{
private:
	bool isClick;

public:
	Ui();
	~Ui();
	void Init();
};

