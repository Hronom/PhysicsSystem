#include "PhysicsSystem.h"

#include "Box2D/Dynamics/b2Body.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    PhysicsSystem::initialize(0.0f, 0.0f);

    PhysicsSystem::instance()->injectUpdate(1);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);

    b2Body* body;
    body = PhysicsSystem::instance()->getWorld()->CreateBody(&bodyDef);
    body->SetLinearVelocity(b2Vec2(-1,0));

    PhysicsSystem::instance()->injectUpdate(1);

    qDebug()<<body->GetPosition().x<<body->GetPosition().y;

    PhysicsSystem::instance()->injectUpdate(0.1);

    qDebug()<<body->GetPosition().x<<body->GetPosition().y;

    PhysicsSystem::shutdown();

    return 0;
}
