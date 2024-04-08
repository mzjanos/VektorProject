#pragma once

#ifndef M_VECTOR
#define M_VECTOR

template <typename T>
class m_vector {
private:
	T x; 
	T y; 
	T z;
public:
	m_vector(T x, T y ,T z) : x(x), y(y), z(z){ }
	T getX() const {
		return x;
	}
	T getY() const {
		return y;
	}
	T getZ() const {
		return z;
	}
	void setZ(T z) {
		this->z = z;
	}

	m_vector operator -(m_vector b) {
		return m_vector(this->x - b.getX(), this->y - b.getY(), this->z - b.getZ());
	}
};

#endif