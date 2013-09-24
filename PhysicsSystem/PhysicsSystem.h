#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "Box2D/Dynamics/b2World.h"

class PhysicsSystem
{
private:
    static PhysicsSystem *m_instance;

    b2World *m_world;

public:
    static bool initialize(const float &par_gravityX, const float &par_gravityY);
    static void shutdown();
    static PhysicsSystem* instance();

private:
    PhysicsSystem(const float &par_gravityX, const float &par_gravityY);
    ~PhysicsSystem();

public:
    void injectUpdate(const float &par_timeSinceLastUpdate);

    b2World* getWorld();
};

#endif
