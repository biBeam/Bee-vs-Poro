#pragma once
class Bullet : public ObRect
{
protected:
	Vector2 fireDir;


public:
	bool      isFire;
	Bullet();
	virtual ~Bullet();
	void Fire(GameObject* shooter);
	void Update() override;
	void Render() override;



};



