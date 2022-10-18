#pragma once

#include "vector3f.hpp"
#include <string.h>

namespace acm
{
    class matrix3f
    {
    public:
        matrix3f(float matrix[3][3])
        {
            for (unsigned char row = 0; row < 3; ++row)
            {
                for (unsigned char col = 0; col < 3; ++col)
                {
                    setData(row, col, matrix[row][col]);
                }
            }
        };

        matrix3f()
        {
            memset(m_data, 0, 36);
        }

        ~matrix3f(){};

        inline static vector3f multiplyVector(const matrix3f &m, const vector3f &v)
        {
            return vector3f(
                m.m11() * v.x() + m.m12() * v.y() + m.m13() * v.z(),
                m.m21() * v.x() + m.m22() * v.y() + m.m23() * v.z(),
                m.m31() * v.x() + m.m32() * v.y() + m.m33() * v.z());
        }

        inline static matrix3f multiplyScalar(const matrix3f &m, double scalar)
        {
            float newData[3][3];
            for (unsigned char row = 0; row < 3; ++row)
            {
                for (unsigned char col = 0; col < 3; ++col)
                {
                    newData[row][col] = m.getData(row, col) * scalar;
                }
            }
            return matrix3f(newData);
        }

        inline static matrix3f addMatrix(const matrix3f &m1, const matrix3f &m2)
        {
            float newData[3][3];
            for (unsigned char row = 0; row < 3; ++row)
            {
                for (unsigned char col = 0; col < 3; ++col)
                {
                    newData[row][col] = m1.getData(row, col) + m2.getData(row, col);
                }
            }
            return matrix3f(newData);
        }

        inline void print() const
        {
            std::cout << "--Matrix--" << std::endl;
            for (unsigned char row = 0; row < 3; ++row)
            {
                for (unsigned char col = 0; col < 3; ++col)
                {
                    std::cout << " " << getData(row, col) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "----------" << std::endl;
        }

        inline float getData(unsigned char row, unsigned char col) const
        {
            return m_data[row][col];
        }

        inline float setData(unsigned char row, unsigned char col, float data)
        {
            m_data[row][col] = data;
        }

        inline float m11() const
        {
            return getData(0, 0);
        }
        inline float m12() const
        {
            return getData(0, 1);
        }
        inline float m13() const
        {
            return getData(0, 2);
        }
        inline float m21() const
        {
            return getData(1, 0);
        }
        inline float m22() const
        {
            return getData(1, 1);
        }
        inline float m23() const
        {
            return getData(1, 2);
        }
        inline float m31() const
        {
            return getData(2, 0);
        }
        inline float m32() const
        {
            return getData(2, 1);
        }
        inline float m33() const
        {
            return getData(2, 2);
        }

        friend vector3f operator*(const matrix3f &m, const vector3f &v);
        friend matrix3f operator*(double scalar, const matrix3f &m);
        friend matrix3f operator*(const matrix3f &m, double scalar);
        friend matrix3f operator+(const matrix3f &m1, const matrix3f &m2);
        friend matrix3f operator-(const matrix3f &m1, const matrix3f &m2);

    private:
        float m_data[3][3];
    };

    vector3f operator*(const matrix3f &m, const vector3f &v)
    {
        return matrix3f::multiplyVector(m, v);
    }

    matrix3f operator*(double scalar, const matrix3f &m)
    {
        return matrix3f::multiplyScalar(m, scalar);
    }

    matrix3f operator*(const matrix3f &m, double scalar)
    {
        return matrix3f::multiplyScalar(m, scalar);
    }

    matrix3f operator+(const matrix3f &m1, const matrix3f &m2)
    {
        return matrix3f::addMatrix(m1, m2);
    }

    matrix3f operator-(const matrix3f &m1, const matrix3f &m2)
    {
        return matrix3f::addMatrix(m1, -1 * m2);
    }
}