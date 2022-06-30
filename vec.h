#pragma once
#include<iostream>
#include<math.h>
#include<stdlib.h>

class Vec
{
public:
	double e[3];
	Vec() {};
	Vec(double x, double y, double z);
	~Vec() {}
	inline double x() const
	{
		return e[0];
	}
	inline double y() const
	{
		return e[1];
	}
	inline double z() const
	{
		return e[2];
	}
	inline double r() const
	{
		return e[0];
	}
	inline double g() const
	{
		return e[1];
	}
	inline double b() const
	{
		return e[2];
	}
	inline const Vec& operator+() const
	{
		return *this;
	}
	inline Vec operator-() const
	{
		Vec temp(-e[0], -e[1], -e[2]);
		return temp;
	}
	double operator[](int i) const;
	double& operator[](int i);
	Vec& operator+=(const Vec& v2);
	Vec& operator-=(const Vec& v2);
	Vec& operator*=(const Vec& v2);
	Vec& operator/=(const Vec& v2);
	Vec& operator*=(const double t);
	Vec& operator/=(const double t);
	double Length() const;
	double squared_Length() const;
	void unit();
};

double dot(const Vec& v1, const Vec& v2);
Vec cross(const Vec& v1, const Vec& v2);
std::ostream& operator<<(std::ostream& cout, const Vec& v1);
Vec operator+(const Vec& v1, const Vec& v2);
Vec operator-(const Vec& v1, const Vec& v2);
Vec operator*(const Vec& v1, const Vec& v2);
Vec operator*(double k, const Vec& v2);
Vec operator/(const Vec& v2, double k);
bool operator==(const Vec& v1, const Vec& v2);
Vec unitVec(const Vec& v);