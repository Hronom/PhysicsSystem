#ifndef PHYSICSUTILS_H
#define PHYSICSUTILS_H

#include <Box2D/Dynamics/b2Body.h>

class PhysicsUtils
{
private:
    PhysicsUtils() {}
    ~PhysicsUtils() {}

public:
    static void updateSpeed(b2Body *par_body, const float &par_speedDirX, const float &par_speedDirY);
    static float toMeters(const float &par_pixels);
    static float toPixels(const float &par_meters);
};

#endif
