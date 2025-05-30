#pragma once
#include "Component.h"
class Transform2D;
class Collider;
class Component;

class Actor
{
public:
    Actor();
    ~Actor();

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="name">The name of this actor.</param>
    Actor(float x, float y, const char* name);

    /// <summary>
    /// </summary>
    /// <returns>If the actors start function has been called.</returns>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor.</returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider
    /// </summary>
    /// <param name="collider">The new collider to attach to the actor</param>
    void setCollider(Collider* collider) { m_collider = collider; }

    /// <summary>
    /// Gets the name of this actor
    /// </summary>
    /// <returns></returns>
    const char* getName() { return m_name; }

    int iD;

    /// <summary>
    /// Iterates through all components in the component array to find one
    /// that matches the given name.
    /// </summary>
    /// <param name="componentName">The name of the component to search for.</param>
    /// <returns>A pointer to the component if a match was found.
    /// Returns nullptr if a match wasn't found.</returns>
    
    template<typename T>
    T* getComponent(const T* componentName)
    {
        //Iterate through all of the components in the array.
        for (int i = 0; i < m_componentCount; i++)
        {
            //If the component name matches the name given...
            if (m_components[i]->getName() == componentName)
            {
                //...return the component.
                return m_components[i];
            }
        }

        //Return null by default.
        return nullptr;
    }


    Component* addComponent(Component* component)
    {
        //If this actor doesn't own this component...
        Actor* owner = component->getOwner();
        if (owner && owner != this)
        {
            //...return nullptr to prevent it from being added.
            return nullptr;
        }

        //Create a new array that has a size that is greater than the original by one.
        Component** tempArray = new Component * [m_componentCount + 1];

        //Copy all values from the old array to the temp array.
        for (int i = 0; i < m_componentCount; i++)
        {
            tempArray[i] = m_components[i];
        }

        //Delete the old array.
        delete m_components;

        //Set the last index in the temp array to be the component we want to add.
        tempArray[m_componentCount] = component;

        //Set the original array to be the temp array.
        m_components = tempArray;
        //Increment the component count.
        m_componentCount++;

        //Return the new component that was added.
        return component;
    }

    template<typename T>
    T removeComponent(const T* componentName)
    {
        //If the component name is null..
        if (!componentName)
        {
            //...return false.
            return false;
        }

        //Create a new variable to store whether or not the component was removed.
        bool componentRemoved = false;

        //Create a new temporary array to copy the values over to.
        Component** tempArray = new Component * [m_componentCount - 1];

        //Copy all values except for the one to remove.
        int j = 0;
        for (int i = 0; i < m_componentCount; i++)
        {
            //If this component doesn't match the name given...
            if (componentName != m_components[i]->getName())
            {
                //...copy the value from the original to the temp array.
                tempArray[j] = m_components[i];
                j++;
            }
            //Otherwise...
            else
            {
                //...mark that the component was removed.
                componentRemoved = true;
            }
        }

        //If the component was removed...
        if (componentRemoved)
        {
            //...delete the old array and set it to the new array.
            delete m_components;
            m_components = tempArray;
            m_componentCount--;
        }
        //Otherwise...
        else
        {
            //...delete the new array.
            delete[] tempArray;
        }

        return componentRemoved;
    }

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame
    /// </summary>
    /// <param name="deltaTime">The time that has passed from the previous frame to the current</param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed 
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another
    /// </summary>
    /// <param name="other">The actor to check collision against</param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param name="other">The actor this actor collided with.</param>
    virtual void onCollision(Actor* other);

protected:
    const char* m_name;

private:
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    Component** m_components;
    int m_componentCount;
};

