#pragma once
#include "raymath.h"
#include <vector>
#include "Actor.h"

class Behaviour;



class Agent : public Actor
{
public:
	Agent();
	virtual ~Agent();

	// Update the agent and its behaviours
	virtual void update(float deltaTime) override;

	// Draw the agent
	virtual void draw() override;

	// Add a behaviour to the agent
	void AddBehaviour(Behaviour* behaviour);

	// Movement functions
	void SetPosition(Vector2 position) { m_position = position; }
	Vector2 GetPosition() { return m_position; }

	void SetVelocity(Vector2 velocity) { m_velocity = velocity; }
	Vector2 GetVelocity() { return m_velocity; }

	void SetMaxSpeed(float speed) { m_maxSpeed = speed; }
	float GetMaxSpeed() { return m_maxSpeed; }

	void AddForce(Vector2 force) { m_force = Vector2Add(force, m_force); }

	Agent* m_target = nullptr;

private:
	Vector2 Truncate(Vector2 v, float max);

protected:
	std::vector<Behaviour*> m_behaviourList;

	enum behaviorNumbers 
	{
		NONE,
		WANDER,
		ARRIVE,
		FLEE
	};

	behaviorNumbers m_behaviorState = NONE;

	Vector2 m_position = { 0, 0 };
	Vector2 m_velocity = { 0, 0 };
	float m_maxSpeed = 100;

	Vector2 m_force = { 0, 0 };

	//Keep between 0 and 1, 0 is max friction, 1 is no friction
	float m_frictionModifier = 0.99;
};

