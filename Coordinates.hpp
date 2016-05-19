#pragma once


struct Cartesian 
{
	double fX;
	double fY;
	double fZ;
};

Cartesian operator+(const Cartesian &c1, const Cartesian &c2);
Cartesian operator-(const Cartesian &c1, const Cartesian &c2);
Cartesian operator-(const Cartesian &c1);
Cartesian operator*(const double &c1, const Cartesian &c2);
Cartesian operator*(const Cartesian &c2, const double &c1);


