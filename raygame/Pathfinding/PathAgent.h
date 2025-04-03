#pragma once
#include "raylib.h"
#include "pathfinding.h"
#include "raymath.h"
#include <vector>
#include "../Actor.h"

namespace pathfinding
{

	class Behaviour;

	class PathAgent : public Actor
	{
	public:
		Vector2 position;

		std::vector<Node*> path;
		int currentIndex;
		Node* currentNode;

		float speed;

		void SetNode(Node* node);
		virtual void Update(float deltaTime);
		void GoToNode(Node* node);

		void AddBehavior(Behaviour* behavior);

		void Draw();

	protected:
		std::vector<Behaviour*> m_behaviourList;
	};


}
