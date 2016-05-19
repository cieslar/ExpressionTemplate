#include<Coordinates.hpp>

Cartesian operator+(const Cartesian &c1, const Cartesian &c2)
{
	Cartesian Result;
	Result.fZ=c1.fZ+c2.fZ;
	Result.fX=c1.fX+c2.fX;
	Result.fY=c1.fY+c2.fY;
    	return Result;
}

Cartesian operator-(const Cartesian &c1, const Cartesian &c2)
{
	Cartesian Result;
	Result.fX=c1.fX-c2.fX;
	Result.fY=c1.fY-c2.fY;
	Result.fZ=c1.fZ-c2.fZ;
    	return Result;
}

Cartesian operator-(const Cartesian &c1)
{
	Cartesian Result;
	Result.fX=-c1.fX;
	Result.fY=-c1.fY;
	Result.fZ=-c1.fZ;
    	return Result;
}

Cartesian operator*(const double &c1, const Cartesian &c2)
{
	Cartesian Result;
	Result.fX=c1*c2.fX;
	Result.fY=c1*c2.fY;
	Result.fZ=c1*c2.fZ;
    	return Result;
}

Cartesian operator*(const Cartesian &c2, const double &c1)
{
	Cartesian Result;
	Result.fX=c1*c2.fX;
	Result.fY=c1*c2.fY;
	Result.fZ=c1*c2.fZ;
    	return Result;
}



