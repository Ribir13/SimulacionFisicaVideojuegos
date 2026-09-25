#include "Vector3D.h"


float Vector3D::magnitude() const {
	return sqrt(x * x + y * y + z * z);
}

Vector3D Vector3D::normalize() const {
	int mag = magnitude();

	if (mag > 0.0f)
		return Vector3D(x / mag, y / mag, z / mag);
	else
		return Vector3D(x, y, z);
}

Vector3D Vector3D::cross(const Vector3D& v) const {
	return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

Vector3D Vector3D::operator =(Vector3D& other) {
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3D Vector3D::operator +(Vector3D& other) {
	return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator -(Vector3D& other) {
	return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::operator *(float val) {
	return Vector3D(x * val, y * val, z * val);
}

Vector3D Vector3D::operator +=(Vector3D& other) {
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}