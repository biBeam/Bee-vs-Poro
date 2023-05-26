#pragma once
class Map : public ObRect
{
	bool isBuild;

public:
	Map();
	~Map();
	void Init(Vector2 spawn);
	void Update() override;
	void Render() override;


};

