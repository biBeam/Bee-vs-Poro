#pragma once
class Map : public ObRect
{
	bool isBuild; //타워 설치된 곳인지 판별
public:
	bool isUse; //스테이지별 해금이 풀린땅인지 판별
public:
	Map();
	~Map();
	void Init(Vector2 spawn);
	void Update() override;
	void Render() override;


};

