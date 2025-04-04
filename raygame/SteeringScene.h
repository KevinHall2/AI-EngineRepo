#pragma once
#include "Scene.h"
#include "Agent.h"

class SteeringScene : public Scene
{
public:
    void start() override;
    void update(float deltaTime) override;
    void end() override;

    int m_patrolState = 0;

private:

};

