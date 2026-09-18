#include "Vector3D.h"


float Vector3D::magnitude() const {
	return sqrt(x * x + y * y+ z * z);
}

Vector3D Vector3D::normalize() const{
	int mag = magnitude();

	return Vector3D(x / mag, y / mag, z / mag);
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

Vector3D Vector3D::operator *(float& val) {
	return Vector3D(x * val, y * val, z * val);
}

Vector3D Vector3D::operator +=(Vector3D& other) {
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}