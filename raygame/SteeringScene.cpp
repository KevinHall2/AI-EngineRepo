#include "SteeringScene.h"


void SteeringScene::start()
{
	Engine::getSceneCount();
	
	m_patrolAgent->SetPosition(m_patrolPosition);
	//patrolAgentBehavior->SetDestination(firstPatrolTarget);
	m_patrolAgent->AddBehaviour(m_patrolAgentBehavior);
	addActor(m_patrolAgent);
	m_patrolAgent->addComponent(new SpriteComponent(m_patrolAgent, "Images/player.png"));
	m_patrolAgent->getTransform()->setScale({ 50, 50 });

	m_goblinAgent->SetPosition(m_goblinPosition);
	m_goblinAgent->AddBehaviour(m_goblinWanderBehavior);
	m_goblinAgent->AddBehaviour(m_goblinFleeBehavior);
	m_goblinAgent->AddBehaviour(m_goblinArriveBehavior);
	addActor(m_goblinAgent);
	m_goblinAgent->addComponent(new SpriteComponent(m_goblinAgent, "Images/enemy.png"));
	m_goblinAgent->getTransform()->setScale({ 50, 50 });
	

	m_peasantAgent->SetPosition(m_peasantPosition);
	m_peasantAgent->AddBehaviour(m_peasantWanderBehavior);
	m_peasantAgent->AddBehaviour(m_peasantArriveBehavior);
	addActor(m_peasantAgent);
	m_peasantAgent->addComponent(new SpriteComponent(m_peasantAgent, "Images/bullet.png"));
	m_peasantAgent->getTransform()->setScale({ 50, 50 });
}

void SteeringScene::update(float deltaTime)
{
	Scene::update(deltaTime);

}

void SteeringScene::end()
{
	Scene::end();
}
