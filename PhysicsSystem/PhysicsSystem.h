#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "Box2D/Dynamics/b2World.h"

class PhysicsSystem
{
private:
    static PhysicsSystem *m_instance;

    b2World *m_world;

public:
    static bool initialize();
    static void shutdown();
    static PhysicsSystem* instance();

private:
    PhysicsSystem();
    ~PhysicsSystem();

public:
    void injectPreUpdate(const float& par_timeSinceLastUpdate);
    void injectPostUpdate(const float& par_timeSinceLastUpdate);
};

#endif
