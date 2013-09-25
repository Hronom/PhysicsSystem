#include "PhysicsUtils.h"

#include <QDebug>

void PhysicsUtils::updateSpeed(b2Body *par_body, const float &par_speedDirX, const float &par_speedDirY)
{
    float speedX;
    speedX = par_body->GetLinearVelocity().x;

    float speedY;
    speedY = par_body->GetLinearVelocity().y;

    if(speedX != par_speedDirX || speedY != par_speedDirY)
        par_body->SetLinearVelocity(b2Vec2(par_speedDirX, par_speedDirY));
}
