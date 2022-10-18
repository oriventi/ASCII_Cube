#pragma once

#include "vector.hpp"

namespace acm
{
    class vector2f : public vector
    {
    public:
        vector2f(float x, float y)
            : vector(2, new float[2]{x, y}) {}

        vector2f()
            : vector(2, new float[2]{0.f, 0.f}) {}

        ~vector2f() {}

        inline float x() const
        {
            return getComponent(0);
        }

        inline float y() const
        {
            return getComponent(1);
        }

        inline static double dotProduct(const vector2f &v1, const vector2f &v2)
        {
            return v1.x() * v2.x() + v1.y() * v2.y();
        }

        inline static vector2f multiplyScalar(const vector2f &v1, float scalar)
        {
            return vector2f(scalar * v1.x(), scalar * v1.y());
        }

        inline static vector2f add(const vector2f &v1, const vector2f &v2)
        {
            return vector2f(v1.x() + v2.x(), v1.y() + v2.y());
        }

        inline double distanceTo(const vector2f &v1) const
        {
            return sqrt((x() - v1.x()) * (x() - v1.x()) +
                        (y() - v1.y()) * (y() - v1.y()));
        }

        friend vector2f operator+(const vector2f &v1, const vector2f &v2);
        friend vector2f operator*(double scalar, const vector2f &v1);
        friend vector2f operator*(const vector2f &v1, double scalar);
        friend vector2f operator/(const vector2f &v1, double scalar);
        friend vector2f operator-(const vector2f &v1, const vector2f &v2);
    };

    vector2f operator+(const vector2f &v1, const vector2f &v2)
    {
        return vector2f::add(v1, v2);
    }

    vector2f operator*(double scalar, const vector2f &v1)
    {
        return vector2f::multiplyScalar(v1, scalar);
    }

    vector2f operator*(vector2f &v1, double scalar)
    {
        return vector2f::multiplyScalar(v1, scalar);
    }

    vector2f operator-(const vector2f &v1, const vector2f &v2)
    {
        return vector2f::add(v1, -1 * v2);
    }

    vector2f operator/(vector2f &v1, double scalar)
    {
        return vector2f::multiplyScalar(v1, 1 / scalar);
    }
}