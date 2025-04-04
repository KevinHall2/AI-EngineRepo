#include "SteeringScene.h"
#include "Engine.h"
#include "raylib.h"
#include "Pathfinding/SeekBehavior/SeekBehaviour.h"
#include "Pathfinding/WanderBehavior/WanderBehaviour.h"
#include "Pathfinding/FleeBehavior/FleeBehaviour.h"
#include "Pathfinding/ArriveBehavior/ArriveBehaviour.h"

void SteeringScene::start()
{
	Engine::getSceneCount();

	Vector2 firstPatrolTarget = { (float)(Engine::m_screenWidth - 100), (float)(Engine::m_screenHeight - 500) };
	Vector2 secondPatrolTarget = { (float)(Engine::m_screenWidth - 500), (float)(Engine::m_screenHeight - 100) };

	Vector2 goblinPosition = { (float)(Engine::m_screenWidth / 2 - 5),(float)(Engine::m_screenHeight / 2 - 5) };

	Vector2 peasantPosition = { (float)(Engine::m_screenWidth / 2 + 5),(float)(Engine::m_screenHeight / 2 + 5) };

	ArriveBehaviour* patrolAgentBehavior = new ArriveBehaviour();

	WanderBehaviour* goblinWanderBehavior = new WanderBehaviour();
	FleeBehaviour* goblinFleeBehavior = new FleeBehaviour();
	ArriveBehaviour* goblinArriveBehavior = new ArriveBehaviour();

	WanderBehaviour* peasantWanderBehavior = new WanderBehaviour();
	ArriveBehaviour* peasantArriveBehavior = new ArriveBehaviour();

	Agent* patrolAgent = new Agent();
	patrolAgent->SetPosition({ (float)(Engine::m_screenWidth >> 1), (float)(Engine::m_screenHeight >> 1) });
	//patrolAgentBehavior->SetDestination(firstPatrolTarget);
	patrolAgent->AddBehaviour(patrolAgentBehavior);

	Agent* goblinAgent = new Agent();
	goblinAgent->SetPosition(goblinPosition);
	goblinAgent->AddBehaviour(goblinWanderBehavior);
	goblinAgent->AddBehaviour(goblinFleeBehavior);
	goblinAgent->AddBehaviour(goblinArriveBehavior);


	Agent* peasantAgent = new Agent();
	peasantAgent->SetPosition(peasantPosition);
	peasantAgent->AddBehaviour(peasantWanderBehavior);
	peasantAgent->AddBehaviour(peasantArriveBehavior);
}

void SteeringScene::update(float deltaTime)
{
	Scene::update(deltaTime);

}

void SteeringScene::end()
{
	Scene::end();
}
