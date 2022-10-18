#pragma once

#include "vector2f.hpp"
#include <string.h>

namespace acm
{
    class matrix2f
    {
    public:
        matrix2f(float matrix[2][2])
        {
            for (unsigned char row = 0; row < 2; ++row)
            {
                for (unsigned char col = 0; col < 2; ++col)
                {
                    setData(row, col, matrix[row][col]);
                }
            }
        };

        matrix2f()
        {
            memset(m_data, 0, 16);
        }

        ~matrix2f(){};

        inline static vector2f multiplyVector(const matrix2f &m, const vector2f &v)
        {
            return vector2f(
                m.m11() * v.x() + m.m12() * v.y(),
                m.m21() * v.x() + m.m22() * v.y());
        }

        inline static matrix2f multiplyScalar(const matrix2f &m, double scalar)
        {
            float newData[2][2];
            for (unsigned char row = 0; row < 2; ++row)
            {
                for (unsigned char col = 0; col < 2; ++col)
                {
                    newData[row][col] = m.getData(row, col) * scalar;
                }
            }
            return matrix2f(newData);
        }

        inline static matrix2f addMatrix(const matrix2f &m1, const matrix2f &m2)
        {
            float newData[2][2];
            for (unsigned char row = 0; row < 2; ++row)
            {
                for (unsigned char col = 0; col < 2; ++col)
                {
                    newData[row][col] = m1.getData(row, col) + m2.getData(row, col);
                }
            }
            return matrix2f(newData);
        }

        inline void print() const
        {
            std::cout << "-Matrix-" << std::endl;
            for (unsigned char row = 0; row < 2; ++row)
            {
                for (unsigned char col = 0; col < 2; ++col)
                {
                    std::cout << " " << getData(row, col) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << "-------" << std::endl;
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
        inline float m21() const
        {
            return getData(1, 0);
        }
        inline float m22() const
        {
            return getData(1, 1);
        }

        friend vector2f operator*(const matrix2f &m, const vector2f &v);
        friend matrix2f operator*(double scalar, const matrix2f &m);
        friend matrix2f operator*(const matrix2f &m, double scalar);
        friend matrix2f operator+(const matrix2f &m1, const matrix2f &m2);
        friend matrix2f operator-(const matrix2f &m1, const matrix2f &m2);

    private:
        float m_data[2][2];
    };

    vector2f operator*(const matrix2f &m, const vector2f &v)
    {
        return matrix2f::multiplyVector(m, v);
    }

    matrix2f operator*(double scalar, const matrix2f &m)
    {
        return matrix2f::multiplyScalar(m, scalar);
    }

    matrix2f operator*(const matrix2f &m, double scalar)
    {
        return matrix2f::multiplyScalar(m, scalar);
    }

    matrix2f operator+(const matrix2f &m1, const matrix2f &m2)
    {
        return matrix2f::addMatrix(m1, m2);
    }

    matrix2f operator-(const matrix2f &m1, const matrix2f &m2)
    {
        return matrix2f::addMatrix(m1, -1 * m2);
    }
}