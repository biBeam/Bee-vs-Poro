#pragma once
class Tower : public ObRect
{
protected:
	int	hp;
	int att;
	int	attSpeed;
	int	price;
private:
	class Bullet* bullet[10];
	
public:
	bool isBuild;
	bool isClick;
	bool isFire;
	Tower();
	~Tower();
	virtual void Init(Vector2 spawn);
	void Update() override;
	void Render() override;
	void Control();
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

