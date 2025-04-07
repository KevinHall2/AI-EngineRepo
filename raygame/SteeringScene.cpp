#include "SteeringScene.h"
#include "Engine.h"
#include "raylib.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"
#include "FleeBehaviour.h"
#include "ArriveBehaviour.h"
#include "Agent.h"

void SteeringScene::start()
{
	Engine::getSceneCount();
	
	m_patrolAgent->SetPosition({ (float)(Engine::m_screenWidth >> 1), (float)(Engine::m_screenHeight >> 1) });
	//patrolAgentBehavior->SetDestination(firstPatrolTarget);
	m_patrolAgent->AddBehaviour(m_patrolAgentBehavior);
	addActor(m_patrolAgent);

	
	m_goblinAgent->SetPosition(m_goblinPosition);
	m_goblinAgent->AddBehaviour(m_goblinWanderBehavior);
	m_goblinAgent->AddBehaviour(m_goblinFleeBehavior);
	m_goblinAgent->AddBehaviour(m_goblinArriveBehavior);
	addActor(m_goblinAgent);


	//Agent* peasantAgent = new Agent();
	m_peasantAgent->SetPosition(m_peasantPosition);
	m_peasantAgent->AddBehaviour(m_peasantWanderBehavior);
	m_peasantAgent->AddBehaviour(m_peasantArriveBehavior);
	addActor(m_peasantAgent);
}

void SteeringScene::update(float deltaTime)
{
	Scene::update(deltaTime);
	Scene::draw();
	m_peasantAgent->Actor::draw();
}

void SteeringScene::end()
{
	Scene::end();
}
