#include "SteeringScene.h"


void SteeringScene::start()
{
	Engine::getSceneCount();
	
	m_patrolAgent->SetMaxSpeed(1650);
	m_patrolAgent->SetPosition(m_patrolPosition);
	m_patrolAgent->AddBehaviour(m_patrolAgentBehavior);
	addActor(m_patrolAgent);
	m_patrolAgent->addComponent(new SpriteComponent(m_patrolAgent, "Images/player.png"));
	m_patrolAgent->getTransform()->setScale({ 50, 50 });

	m_goblinAgent->SetMaxSpeed(1650);
	m_goblinAgent->SetPosition(m_goblinPosition);
	m_goblinAgent->AddBehaviour(m_goblinWanderBehavior);
	m_goblinAgent->AddBehaviour(m_goblinFleeBehavior);
	m_goblinAgent->AddBehaviour(m_goblinArriveBehavior);
	addActor(m_goblinAgent);
	m_goblinAgent->addComponent(new SpriteComponent(m_goblinAgent, "Images/enemy.png"));
	m_goblinAgent->getTransform()->setScale({ 50, 50 });
	
	m_peasantAgent->SetMaxSpeed(1650);
	m_peasantAgent->SetPosition(m_peasantPosition);
	m_peasantAgent->AddBehaviour(m_peasantWanderBehavior);
	m_peasantAgent->AddBehaviour(m_peasantArriveBehavior);
	addActor(m_peasantAgent);
	m_peasantAgent->addComponent(new SpriteComponent(m_peasantAgent, "Images/bullet.png"));
	m_peasantAgent->getTransform()->setScale({ 50, 50 });
}

void SteeringScene::update(float deltaTime)
{
	Vector2 patrolStateDeterminer = m_patrolAgent->GetPosition();

	DrawLine(m_firstPatrolTarget.x - 5, m_firstPatrolTarget.y, m_firstPatrolTarget.x + 5, m_firstPatrolTarget.y, BLUE);
	DrawLine(m_firstPatrolTarget.x, m_firstPatrolTarget.y - 5, m_firstPatrolTarget.x, m_firstPatrolTarget.y + 5, BLUE);

	DrawLine(m_secondPatrolTarget.x - 5, m_secondPatrolTarget.y, m_secondPatrolTarget.x + 5, m_secondPatrolTarget.y, BLUE);
	DrawLine(m_secondPatrolTarget.x, m_secondPatrolTarget.y - 5, m_secondPatrolTarget.x, m_secondPatrolTarget.y + 5, BLUE);

	//clamp if statement in case of overflow
	if (m_patrolState > 1 || m_patrolState < 0)
	{
		m_patrolState = 0;
	}

	//if statement to adjust patrol agent target depending on proximity
	if (patrolStateDeterminer.x == m_firstPatrolTarget.x && patrolStateDeterminer.y == m_firstPatrolTarget.y)
	{
		m_patrolState++;
	}
	else if (patrolStateDeterminer.x == m_secondPatrolTarget.x && patrolStateDeterminer.y == m_secondPatrolTarget.y)
	{
		m_patrolState--;
	}

	switch (m_patrolState)
	{
	case 0:
		m_patrolAgentBehavior->SetDestination(m_firstPatrolTarget);
		break;
	case 1:
		m_patrolAgentBehavior->SetDestination(m_secondPatrolTarget);
		break;
	default:
		m_patrolAgentBehavior->SetDestination(m_patrolPosition);
		break;
	}

	Vector2 goblinScreenWrapper = m_goblinAgent->GetPosition();
	if (goblinScreenWrapper.y < 0)
		goblinScreenWrapper.y = Engine::m_screenHeight;
	if (goblinScreenWrapper.y > Engine::m_screenHeight)
		goblinScreenWrapper.y = 0;
	if (goblinScreenWrapper.x < 0)
		goblinScreenWrapper.x = Engine::m_screenWidth;
	if (goblinScreenWrapper.x > Engine::m_screenWidth)
		goblinScreenWrapper.x = 0;
	m_goblinAgent->SetPosition(goblinScreenWrapper);

	m_patrolAgent->update(deltaTime);
	m_goblinAgent->update(deltaTime);
	m_peasantAgent->update(deltaTime);
	Scene::update(deltaTime);

}

void SteeringScene::end()
{
	Scene::end();
}
