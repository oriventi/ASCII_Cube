#pragma once

#include "vector.hpp"

namespace acm
{
    class vector4f : public vector
    {
    public:
        vector4f(float x, float y, float z, float w)
            : vector(4, new float[4]{x, y, z, w}) {}

        vector4f()
            : vector(4, new float[4]{0.f, 0.f, 0.f, 0.f}) {}

        ~vector4f() {}

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

        inline float w() const
        {
            return getComponent(3);
        }

        inline static double dotProduct(const vector4f &v1, const vector4f &v2)
        {
            return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z() + v1.w() * v2.w();
        }

        inline static vector4f multiplyScalar(const vector4f &v1, float scalar)
        {
            return vector4f(scalar * v1.x(), scalar * v1.y(), scalar * v1.z(), scalar * v1.w());
        }

        inline static vector4f add(const vector4f &v1, const vector4f &v2)
        {
            return vector4f(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z(), v1.w() + v2.w());
        }

        inline double distanceTo(const vector4f &v1) const
        {
            return sqrt((x() - v1.x()) * (x() - v1.x()) +
                        (y() - v1.y()) * (y() - v1.y()) +
                        (z() - v1.z()) * (z() - v1.z()) +
                        (w() - v1.w()) * (w() - v1.w()));
        }

        friend vector4f operator+(const vector4f &v1, const vector4f &v2);
        friend vector4f operator-(const vector4f &v1, const vector4f &v2);
        friend vector4f operator*(double scalar, const vector4f &v1);
        friend vector4f operator*(const vector4f &v1, double scalar);
        friend vector4f operator/(const vector4f &v1, double scalar);
    };

    vector4f operator+(const vector4f &v1, const vector4f &v2)
    {
        return vector4f::add(v1, v2);
    }

    vector4f operator-(const vector4f &v1, const vector4f &v2)
    {
        return vector4f::add(v1, v2 * -1);
    }

    vector4f operator*(double scalar, const vector4f &v1)
    {
        return vector4f::multiplyScalar(v1, scalar);
    }

    vector4f operator*(vector4f &v1, double scalar)
    {
        return vector4f::multiplyScalar(v1, scalar);
    }

    vector4f operator/(vector4f &v1, double scalar)
    {
        return vector4f::multiplyScalar(v1, 1 / scalar);
    }
}