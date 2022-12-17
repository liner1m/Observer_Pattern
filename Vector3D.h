#pragma once

class Vector3D {
public:
	double x;
	double y;
	double z;

	Vector3D zeroVector() {
		return { 0, 0, 0 };
	}

	Vector3D operator +(const Vector3D & other) {
		return { this->x + other.x, this->y + other.y, this->z + other.z };
	}

	Vector3D &operator +=(Vector3D& other) {
		this->x = this->x + other.x;
		this->y = this->y + other.y;
		this->z = this->z + other.z;

		return *this;
	}
};