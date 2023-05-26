#pragma once
class Monster : public Unit
{
private:
    int att;
    float attSpeed;
    float velocity; //�̵��ӵ� 

public:
    Monster();
    ~Monster();
    virtual void Init(Vector2 spawn);
    void Update() override;
    void Render() override;
    void Control();
    int getAtt() { return att; }
};

