#pragma once

#include <iostream>
#include <stdexcept>

const static float min = 0.00005f;

class vector
{
public:
    explicit vector(std::size_t size, float data[])
        : m_size(size)
    {
        m_data = data;
    }

    virtual ~vector()
    {
        delete[] m_data;
        m_data = NULL;
    };

    inline double getLength() const
    {
        double sum = 0;
        for (std::size_t i = 0; i < m_size; ++i)
        {
            sum += m_data[i] * m_data[i];
        }
        return sqrt(sum);
    }

    void print() const
    {
        std::cout << "--Vector--" << std::endl;
        for (std::size_t i = 0; i < m_size; ++i)
        {
            std::cout << "x" << i + 1 << ": " << m_data[i] << std::endl;
        }
        std::cout << "----------" << std::endl;
    }

    inline bool isNull() const
    {
        for (std::size_t i = 0; i < m_size; ++i)
        {
            if (abs(m_data[i]) >= min)
                return false;
        }
        return true;
    }

    void normalize()
    {
        double length = getLength();
        for (std::size_t i = 0; i < m_size; ++i)
        {
            m_data[i] /= length;
        }
    }

    static bool isEqual(const vector &v1, const vector &v2)
    {
        if (v1.getDimension() != v2.getDimension())
            return false;

        for (std::size_t i; i < v1.getDimension(); ++i)
        {
            if(v1.getComponent(i) != v2.getComponent(i))
                return false;
        }
        return true;
    }

    friend bool operator==(const vector &v1, const vector &v2);
    friend bool operator!=(const vector &v1, const vector &v2);

protected:

    inline float getComponent(std::size_t index) const
    {
        return m_data[index];
    }

    inline std::size_t getDimension() const
    {
        return m_size;
    }

    const std::size_t m_size;
    float *m_data;
};

bool operator==(const vector &v1, const vector &v2)
{
    return vector::isEqual(v1, v2);
}

bool operator!=(const vector &v1, const vector &v2)
{
    return !vector::isEqual(v1, v2);
}
