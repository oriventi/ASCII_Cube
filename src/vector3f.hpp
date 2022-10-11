#include "vector.hpp"

class vector3f : public vector
{
    vector3f(float x, float y, float z)
        : vector(3, new float[3]{x, y, z}){}

    vector3f()
        : vector(3, new float[3]{0.f, 0.f, 0.f}){}

    ~vector3f(){}

    inline float x() const
    {
        return getComponent(0);
    }

    inline float y() const
    {
        return getComponent(1);
    }

    inline float z() const
    {
        return getComponent(2);
    }
};