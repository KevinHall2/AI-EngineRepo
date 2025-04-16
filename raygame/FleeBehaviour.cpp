#include "FleeBehaviour.h"

bool FleeBehaviour::Update(Agent* agent, float deltaTime, Agent* target)
{
	if (!target)
		return false;

	Vector2 v = Vector2Subtract(agent->GetPosition(), target->GetPosition());

	float distance = Vector2Length(v);
	if (distance > m_fleeRadius)
	{
		//agent->AddForce({ -agent->GetVelocity().x, -agent->GetVelocity().y });
		return false;
	}

	if (distance == 0)	// on top of destination
		v = { 1,0 };	// avoid errors when attempting to normalize a 0 vector

	Vector2 desiredVelocity = Vector2Scale(Vector2Normalize(v), agent->GetMaxSpeed());
	Vector2 steeringForce = Vector2Subtract(desiredVelocity, agent->GetVelocity());

	agent->AddForce(steeringForce);

	return true;
}