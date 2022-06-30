#include"vec.h"

Vec::Vec(double x, double y, double z)
{
	e[0] = x;
	e[1] = y;
	e[2] = z;
}

double Vec::operator[](int i) const
{
	return e[i];
}

double& Vec::operator[](int i)
{
	return e[i];
}

Vec& Vec::operator+=(const Vec& v2)
{
	this->e[0] += v2.e[0];
	this->e[1] += v2.e[1];
	this->e[2] += v2.e[2];
	return *this;
}

Vec& Vec::operator-=(const Vec& v2)
{
	this->e[0] -= v2.e[0];
	this->e[1] -= v2.e[1];
	this->e[2] -= v2.e[2];
	return *this;
}

Vec& Vec::operator*=(const Vec& v2)
{
	this->e[0] *= v2.e[0];
	this->e[1] *= v2.e[1];
	this->e[2] *= v2.e[2];
	return *this;
}

Vec& Vec::operator/=(const Vec& v2)
{
	this->e[0] /= v2.e[0];
	this->e[1] /= v2.e[1];
	this->e[2] /= v2.e[2];
	return *this;
}

Vec& Vec::operator*=(const double t)
{
	this->e[0] *= t;
	this->e[1] *= t;
	this->e[2] *= t;
	return *this;
}

Vec& Vec::operator/=(const double t)
{
	this->e[0] /= t;
	this->e[1] /= t;
	this->e[2] /= t;
	return *this;
}

double Vec::Length() const
{
	return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}

double Vec::squared_Length() const
{
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

void Vec::unit()
{
	*this /= this->Length();
}


double dot(const Vec& v1, const Vec& v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

Vec cross(const Vec& v1, const Vec& v2)
{
	Vec temp;
	temp.e[0] = v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1];
	temp.e[1] = -(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0]);
	temp.e[2] = v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0];
	return temp;
}

std::ostream& operator<<(std::ostream& cout, const Vec& v1)
{
	cout << "(" << v1[0] << "," << v1[1] << "," << v1[2] << ")"<<std::endl;
	return cout;
}

Vec operator+(const Vec& v1, const Vec& v2)
{
	Vec temp;
	temp.e[0] = v1.e[0] + v2.e[0];
	temp.e[1] = v1.e[1] + v2.e[1];
	temp.e[2] = v1.e[2] + v2.e[2];
	return temp;
}

Vec operator-(const Vec& v1, const Vec& v2)
{
	Vec temp;
	temp.e[0] = v1.e[0] - v2.e[0];
	temp.e[1] = v1.e[1] - v2.e[1];
	temp.e[2] = v1.e[2] - v2.e[2];
	return temp;
}

Vec operator*(const Vec& v1, const Vec& v2)
{
	Vec temp;
	temp.e[0] = v1.e[0] * v2.e[0];
	temp.e[1] = v1.e[1] * v2.e[1];
	temp.e[2] = v1.e[2] * v2.e[2];
	return temp;
}

Vec operator*(double k, const Vec& v2)
{
	Vec temp;
	temp.e[0] = k * v2.e[0];
	temp.e[1] = k * v2.e[1];
	temp.e[2] = k * v2.e[2];
	return temp;
}

Vec operator/(const Vec& v2, double k)
{
	Vec temp;
	temp.e[0] = v2.e[0] / k;
	temp.e[1] = v2.e[1] / k;
	temp.e[2] = v2.e[2] / k;
	return temp;
}

Vec unitVec(const Vec& v)
{
	Vec temp = v;
	temp /= v.Length();
	return temp;
}

bool operator==(const Vec& v1, const Vec& v2)
{
	if (v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2])
		return true;
	return false;
}