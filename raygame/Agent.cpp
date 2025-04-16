#include "Agent.h"
#include "Behaviour.h"
#include "Transform2D.h"

Agent::Agent()
{

}

Agent::~Agent()
{

}

Vector2 Agent::Truncate(Vector2 v, float max)
{
	float i = max / Vector2Length(v);
	i = i < 1.0 ? i : 1.0;
	return Vector2Scale(v, i);
}

// Update the agent and its behaviours
void Agent::update(float deltaTime)
{
	Actor::update(deltaTime);
	// Force is equal to zero
	// For each Behaviour in Behaviour list
	//	 Call the Behaviour’s Update function and add a value to Force
	// Add Force multiplied by delta time to Velocity
	// Add Velocity multiplied by delta time to Position
	m_force = { 0,0 };

	for (int i = 0; i < m_behaviourList.size(); i++)
	{
		m_behaviourList[i]->Update(this, deltaTime, m_target);
	}

	// If (velocity + steering) equals zero, then there is no movement
	m_velocity = Truncate((Vector2Add(m_velocity, Vector2Scale(m_force, deltaTime))), m_maxSpeed);
	m_position = (Vector2Add(m_position, Vector2Scale(m_velocity, deltaTime)));

	m_velocity = Vector2Scale(m_velocity, m_frictionModifier);

	getTransform()->setLocalPosition({ m_position.x,m_position.y });
}

// Draw the agent
void Agent::draw()
{
	Actor::draw();
	DrawRectangle(m_position.x, m_position.y, 10, 10, RED);
}

// Add a behaviour to the agent
void Agent::AddBehaviour(Behaviour* behaviour)
{
	m_behaviourList.push_back(behaviour);
}