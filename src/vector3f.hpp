#pragma once

#include "vector.hpp"

namespace acm
{
    class vector3f : public vector
    {
    public:
        vector3f(float x, float y, float z)
            : vector(3, new float[3]{x, y, z}) {}

        vector3f()
            : vector(3, new float[3]{0.f, 0.f, 0.f}) {}

        ~vector3f() {}

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

        inline static vector3f crossProduct(const vector3f &v1, const vector3f &v2)
        {
            float new_x = v1.y() * v2.z() - v1.z() * v2.y();
            float new_y = v1.z() * v2.x() - v1.x() * v2.z();
            float new_z = v1.x() * v2.y() - v1.y() * v2.x();
            return vector3f(new_x, new_y, new_z);
        }

        inline static double dotProduct(const vector3f &v1, const vector3f &v2)
        {
            return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
        }

        inline static vector3f multiplyScalar(const vector3f &v1, float scalar)
        {
            return vector3f(scalar * v1.x(), scalar * v1.y(), scalar * v1.z());
        }

        inline static vector3f add(const vector3f &v1, const vector3f &v2)
        {
            return vector3f(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
        }

        inline double distanceTo(const vector3f &v1) const
        {
            return sqrt((x() - v1.x()) * (x() - v1.x()) +
                        (y() - v1.y()) * (y() - v1.y()) +
                        (z() - v1.z()) * (z() - v1.z()));
        }

        friend vector3f operator+(const vector3f &v1, const vector3f &v2);
        friend vector3f operator*(double scalar, const vector3f &v1);
        friend vector3f operator*(const vector3f &v1, double scalar);
        friend vector3f operator-(const vector3f &v1, const vector3f &v2);
        friend vector3f operator/(const vector3f &v1, double scalar);
    };

    vector3f operator+(const vector3f &v1, const vector3f &v2)
    {
        return vector3f::add(v1, v2);
    }

    vector3f operator*(double scalar, const vector3f &v1)
    {
        return vector3f::multiplyScalar(v1, scalar);
    }

    vector3f operator*(vector3f &v1, double scalar)
    {
        return vector3f::multiplyScalar(v1, scalar);
    }

    vector3f operator-(const vector3f &v1, const vector3f &v2)
    {
        return vector3f::add(v1, -1 * v2);
    }

    vector3f operator/(vector3f &v1, double scalar)
    {
        return vector3f::multiplyScalar(v1, 1 / scalar);
    }
}