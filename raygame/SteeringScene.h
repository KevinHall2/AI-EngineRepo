#pragma once
#include "Scene.h"
#include "Agent.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"
#include "FleeBehaviour.h"
#include "ArriveBehaviour.h"
#include "Engine.h"
#include "raylib.h"
#include "SpriteComponent.h"
#include "Transform2D.h"

class SteeringScene : public Scene
{
public:
    void start() override;
    void update(float deltaTime) override;
    void end() override;


private:
    int m_patrolState = 0;

	Agent* m_patrolAgent = new Agent();

	Agent* m_goblinAgent = new Agent();

    Agent* m_peasantAgent = new Agent();

	Vector2 m_firstPatrolTarget = { (float)(Engine::m_screenWidth - 100), (float)(Engine::m_screenHeight - 500) };
	Vector2 m_secondPatrolTarget = { (float)(Engine::m_screenWidth - 500), (float)(Engine::m_screenHeight - 100) };

	Vector2 m_patrolPosition = { (float)350,(float)400 };

	Vector2 m_goblinPosition = { (float)300,(float)350 };

	Vector2 m_peasantPosition = { (float)400,(float)450 };

	SeekBehaviour* m_patrolAgentBehavior = new SeekBehaviour();

	WanderBehaviour* m_goblinWanderBehavior = new WanderBehaviour();
	FleeBehaviour* m_goblinFleeBehavior = new FleeBehaviour();
	ArriveBehaviour* m_goblinArriveBehavior = new ArriveBehaviour();

	WanderBehaviour* m_peasantWanderBehavior = new WanderBehaviour();
	ArriveBehaviour* m_peasantArriveBehavior = new ArriveBehaviour();
};

