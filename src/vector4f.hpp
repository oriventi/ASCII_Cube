#pragma once

#include <math.h>

#include <iostream>

const static float min = 0.00005f;

namespace acm
{
    class vector4f
    {
    public:
        vector4f() : x(0.f), y(0.f), z(0.f), w(0.f) {}

        vector4f(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        inline double getLength() const
        {
            return sqrt(x * x + y * y + z * z + w * w);
        }

        inline bool isNull() const
        {
            return (abs(x) < min &&
                    abs(y) < min &&
                    abs(z) < min &&
                    abs(w) < min)
                       ? true
                       : false;
        }

        inline bool isEqual(const vector4f &v1) const
        {
            return (abs(x - v1.x) < min &&
                    abs(y - v1.y) < min &&
                    abs(z - v1.z) < min &&
                    abs(w - v1.w) < min)
                       ? true
                       : false;
        }

        inline double distanceTo(const vector4f &v1) const
        {
            return sqrt((x - v1.x) * (x - v1.x) +
                        (y - v1.y) * (y - v1.y) +
                        (z - v1.z) * (z - v1.z) +
                        (w - v1.w) * (w - v1.w));
        }

        void normalize()
        {
            double length = getLength();
            x /= length;
            y /= length;
            z /= length;
        }

        static float dot(const vector4f &v1, const vector4f &v2)
        {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
        }

        static vector4f multiplyScalar(const vector4f &v1, float scalar)
        {
            return vector4f(v1.x * scalar, v1.y * scalar, v1.z * scalar, v1.w * scalar);
        }

        static vector4f add(const vector4f &v1, const vector4f &v2)
        {
            return vector4f(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
        }

        friend vector4f operator+(const vector4f &v1, const vector4f &v2);
        friend vector4f operator-(const vector4f &v1, const vector4f &v2);
        friend vector4f operator*(const vector4f &v1, float scalar);

        bool operator==(const vector4f &v1) const
        {
            return isEqual(v1);
        }

        bool operator!=(const vector4f &v1) const
        {
            return !isEqual(v1);
        }

        void print() const
        {
            std::cout << "x: " << x << " y: " << y << " z: " << z << " w: " << w << std::endl;
        }

        float x;
        float y;
        float z;
        float w;
    };

    vector4f operator+(const vector4f &v1, const vector4f &v2)
    {
        return vector4f::add(v1, v2);
    }

    vector4f operator-(const vector4f &v1, const vector4f &v2)
    {
        vector4f subtrahend = v2 * -1;
        return vector4f::add(v1, subtrahend);
    }

    vector4f operator*(const vector4f &v1, float scalar)
    {
        return vector4f::multiplyScalar(v1, scalar);
    }

    vector4f operator*(float scalar, const vector4f &v1)
    {
        return vector4f::multiplyScalar(v1, scalar);
    }
}
