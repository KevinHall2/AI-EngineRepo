#include "SampleScene.h"
#include "SpriteComponent.h"
#include "Transform2D.h"
#include "Pathfinding/Pathfinding.h"

void SampleScene::start()
{

	Scene::start();

    m_nodeMap.cellSize = 32;
    std::vector<std::string> asciiMap;
    asciiMap.push_back("000000000000000");
    asciiMap.push_back("010111011101010");
    asciiMap.push_back("011101110111110");
    asciiMap.push_back("010100000100010");
    asciiMap.push_back("011111111111110");
    asciiMap.push_back("010001001000100");
    asciiMap.push_back("011111111110000");
    asciiMap.push_back("000000000000000");
    m_nodeMap.Initialise(asciiMap);

    m_pathAgent = new pathfinding::PathAgent();
    m_pathAgent->SetNode(m_nodeMap.GetNode(1, 1));
    m_pathAgent->speed = 64;


	//This is a better comment
	Actor* test = new Actor(50, 50, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->getTransform()->setScale({ 50, 50 });

	addActor(test);
	addActor(m_pathAgent);
}

void SampleScene::update(float deltaTime)
{
    Scene::update(deltaTime);
    bool drawNodeMap = true;
    Color lineColor = { 255, 255, 255, 255 };
    m_nodeMap.Draw(true);
    pathfinding::DrawPath(m_pathAgent->path, lineColor);

    // read mouseclicks, left for start node, end for right node
    if (IsMouseButtonPressed(0))
    {
        Vector2 mousePos = GetMousePosition();
        pathfinding::Node* end = m_nodeMap.GetClosestNode(mousePos);
        m_pathAgent->GoToNode(end);
    }


    m_pathAgent->Update(deltaTime);
    m_pathAgent->Draw();
}

void SampleScene::end()
{
    Scene::end();
}