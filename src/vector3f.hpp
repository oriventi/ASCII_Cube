#pragma once

#include <math.h>

#include <iostream>

const static float min = 0.00005f;

namespace acm
{
    class vector3f
    {
    public:
        vector3f() : x(0), y(0), z(0) {}

        vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

        inline double getLength() const
        {
            return sqrt(x * x + y * y + z * z);
        }

        inline bool isNull() const
        {
            return (abs(x) < min &&
                    abs(y) < min &&
                    abs(z) < min)
                       ? true
                       : false;
        }

        inline bool isEqual(const vector3f &v1) const
        {
            return (abs(x - v1.x) < min &&
                    abs(y - v1.y) < min &&
                    abs(z - v1.z) < min)
                       ? true
                       : false;
        }

        inline double distanceTo(const vector3f &v1) const
        {
            return sqrt((x - v1.x) * (x - v1.x) +
                        (y - v1.y) * (y - v1.y) +
                        (z - v1.z) * (z - v1.z));
        }

        void normalize()
        {
            double length = getLength();
            x /= length;
            y /= length;
            z /= length;
        }

        static float dot(const vector3f &v1, const vector3f &v2)
        {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        }

        static vector3f cross(const vector3f &v1, const vector3f &v2)
        {
            return vector3f(v1.y * v2.z - v1.z * v2.y,
                            v1.x * v2.z - v1.z * v2.x,
                            v1.x * v2.y - v1.y * v2.x);
        }

        static vector3f multiplyScalar(const vector3f &v1, float scalar)
        {
            return vector3f(v1.x * scalar, v1.y * scalar, v1.z * scalar);
        }

        static vector3f add(const vector3f &v1, const vector3f &v2)
        {
            return vector3f(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
        }

        friend vector3f operator+(const vector3f &v1, const vector3f &v2);
        friend vector3f operator-(const vector3f &v1, const vector3f &v2);
        friend vector3f operator*(const vector3f &v1, float scalar);

        bool operator==(const vector3f &v1) const
        {
            return isEqual(v1);
        }

        bool operator!=(const vector3f &v1) const
        {
            return !isEqual(v1);
        }

        void print() const
        {
            std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
        }

        float x;
        float y;
        float z;
    };

    vector3f operator+(const vector3f &v1, const vector3f &v2)
    {
        return vector3f::add(v1, v2);
    }

    vector3f operator-(const vector3f &v1, const vector3f &v2)
    {
        vector3f subtrahend = v2 * -1;
        return vector3f::add(v1, subtrahend);
    }

    vector3f operator*(const vector3f &v1, float scalar)
    {
        return vector3f::multiplyScalar(v1, scalar);
    }

    vector3f operator*(float scalar, const vector3f &v1)
    {
        return vector3f::multiplyScalar(v1, scalar);
    }
}
