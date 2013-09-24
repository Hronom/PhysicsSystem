#include "PhysicsSystem.h"

#include <QDebug>

PhysicsSystem* PhysicsSystem::m_instance = 0;

bool PhysicsSystem::initialize(const float &par_gravityX, const float &par_gravityY)
{
    if(m_instance == 0)
    {
        qDebug()<<"Initialize:"<<"PhysicsSystem";
        m_instance = new PhysicsSystem(par_gravityX, par_gravityY);
        return true;
    }
    else
    {
        qDebug()<<"PhysicsSystem already initialized";
        return false;
    }
}

void PhysicsSystem::shutdown()
{
    if(m_instance != 0)
    {
        qDebug()<<"Shutdown:"<<"PhysicsSystem";
        delete m_instance;
        m_instance = 0;
    }
    else
    {
        qDebug()<<"PhysicsSystem not initialized or already destroyed";
    }
}

PhysicsSystem* PhysicsSystem::instance()
{
    return m_instance;
}

PhysicsSystem::PhysicsSystem(const float &par_gravityX, const float &par_gravityY)
{
    /*b2AABB worldAABB;
    worldAABB.lowerBound.Set(-200, -100);
    worldAABB.upperBound.Set(200, 500);*/

    b2Vec2 gravity(par_gravityX, par_gravityY);
    bool doSleep = true;
    m_world = new b2World(gravity);
    m_world->SetAllowSleeping(doSleep);
}

PhysicsSystem::~PhysicsSystem()
{
    delete m_world;
}

void PhysicsSystem::injectUpdate(const float &par_timeSinceLastUpdate)
{
    Q_UNUSED(par_timeSinceLastUpdate);

    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    m_world->Step(par_timeSinceLastUpdate, velocityIterations, positionIterations);
}

b2World* PhysicsSystem::getWorld()
{
    return m_world;
}
