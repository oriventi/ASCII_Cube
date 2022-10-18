#pragma once

#include "vector4f.hpp"
#include <string.h>

namespace acm
{
    class matrix4f
    {
    public:
        matrix4f(float matrix[4][4])
        {
            for (unsigned char row = 0; row < 4; ++row)
            {
                for (unsigned char col = 0; col < 4; ++col)
                {
                    setData(row, col, matrix[row][col]);
                }
            }
        };

        matrix4f()
        {
            memset(m_data, 0, 64);
        }

        ~matrix4f(){};

        inline static vector4f multiplyVector(const matrix4f &m, const vector4f &v)
        {
            return vector4f(
                m.m11() * v.x() + m.m12() * v.y() + m.m13() * v.z() + m.m14() * v.w(),
                m.m21() * v.x() + m.m22() * v.y() + m.m23() * v.z() + m.m24() * v.w(),
                m.m31() * v.x() + m.m32() * v.y() + m.m33() * v.z() + m.m34() * v.w(),
                m.m41() * v.x() + m.m42() * v.y() + m.m43() * v.z() + m.m44() * v.w());
        }

        inline static matrix4f multiplyScalar(const matrix4f &m, double scalar)
        {
            float newData[4][4];
            for (unsigned char row = 0; row < 4; ++row)
            {
                for (unsigned char col = 0; col < 4; ++col)
                {
                    newData[row][col] = m.getData(row, col) * scalar;
                }
            }
            return matrix4f(newData);
        }

        inline static matrix4f addMatrix(const matrix4f &m1, const matrix4f &m2)
        {
            float newData[4][4];
            for (unsigned char row = 0; row < 4; ++row)
            {
                for (unsigned char col = 0; col < 4; ++col)
                {
                    newData[row][col] = m1.getData(row, col) + m2.getData(row, col);
                }
            }
            return matrix4f(newData);
        }

        inline void print() const
        {
            std::cout << "---Matrix---" << std::endl;
            for (unsigned char row = 0; row < 4; ++row)
            {
                for (unsigned char col = 0; col < 4; ++col)
                {
                    std::cout << " " << getData(row, col) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "------------" << std::endl;
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
        inline float m14() const
        {
            return getData(0, 3);
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
        inline float m24() const
        {
            return getData(1,3);
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
        inline float m34() const
        {
            return getData(2, 3);
        }
        inline float m41() const
        {
            return getData(3, 0);
        }
        inline float m42() const
        {
            return getData(3,1);
        }
        inline float m43() const
        {
            return getData(3,2);
        }
        inline float m44() const
        {
            return getData(3,3);
        }

        friend vector4f operator*(const matrix4f &m, const vector4f &v);
        friend matrix4f operator*(double scalar, const matrix4f &m);
        friend matrix4f operator*(const matrix4f &m, double scalar);
        friend matrix4f operator+(const matrix4f &m1, const matrix4f &m2);
        friend matrix4f operator-(const matrix4f &m1, const matrix4f &m2);

    private:
        float m_data[4][4];
    };

    vector4f operator*(const matrix4f &m, const vector4f &v)
    {
        return matrix4f::multiplyVector(m, v);
    }

    matrix4f operator*(double scalar, const matrix4f &m)
    {
        return matrix4f::multiplyScalar(m, scalar);
    }

    matrix4f operator*(const matrix4f &m, double scalar)
    {
        return matrix4f::multiplyScalar(m, scalar);
    }

    matrix4f operator+(const matrix4f &m1, const matrix4f &m2)
    {
        return matrix4f::addMatrix(m1, m2);
    }

    matrix4f operator-(const matrix4f &m1, const matrix4f &m2)
    {
        return matrix4f::addMatrix(m1, -1 * m2);
    }
}