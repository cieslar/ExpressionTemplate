#pragma once
#include<cstdlib>

//Based on
//https://en.wikipedia.org/wiki/Expression_templates
template <typename E> class TECartesianExpression 
{
public:
	double operator[](size_t i) const { return static_cast<E const&>(*this)[i];     }

	operator E&()             { return static_cast<      E&>(*this); }
	operator E const&() const { return static_cast<const E&>(*this); }
};


class TECartesian : public TECartesianExpression<TECartesian>
{
public:
	double fX;
	double fY;
	double fZ;

	TECartesian()
	{
		fX=fY=fZ=0.;
	}

	double& operator[](size_t i)       
	{ 
		if (i==0) return fX;
		if (i==1) return fY;
		if (i==2) return fZ;
		//return *pData[i]; 
	}
	double  operator[](size_t i) const 
	{
		if (i==0) return fX;
		if (i==1) return fY;
		if (i==2) return fZ;
	}


	template <typename E> TECartesian(TECartesianExpression<E> const& Cart)
	{
		for(size_t i(3);i--;) (*this)[i] = Cart[i];
	}

	template <typename E> TECartesian operator=(TECartesianExpression<E> const& Cart)
	{
		for(size_t i(3);i--;) (*this)[i] = Cart[i];
		return *this;
	}
};

template <typename E1, typename E2> class TECartesianSum : public TECartesianExpression<TECartesianSum<E1, E2> > 
{
protected:
	E1 const& _u;
	E2 const& _v;

public:
	TECartesianSum(TECartesianExpression<E1> const& u, TECartesianExpression<E2> const& v) : _u(u), _v(v) {};
	double operator[](size_t i) const { return _u[i] + _v[i]; }
};
 

template <typename E1, typename E2> TECartesianSum<E1,E2> const operator+(TECartesianExpression<E1> const& u, TECartesianExpression<E2> const& v) 
{
   return TECartesianSum<E1, E2>(u, v);
}


template <typename E1, typename E2> class TECartesianSub : public TECartesianExpression<TECartesianSub<E1, E2> > 
{
protected:
	E1 const& _u;
	E2 const& _v;

public:
	TECartesianSub(TECartesianExpression<E1> const& u, TECartesianExpression<E2> const& v) : _u(u), _v(v) {};
	double operator[](size_t i) const { return _u[i] - _v[i]; }
};
 

template <typename E1, typename E2> TECartesianSub<E1,E2> const operator-(TECartesianExpression<E1> const& u, TECartesianExpression<E2> const& v) 
{
   return TECartesianSub<E1, E2>(u, v);
}



template <typename E1, typename E2> class TECartesianMulLeft : public TECartesianExpression<TECartesianMulLeft<E1, E2> > 
{
protected:
	E1 const& _mul;///<multiplication element
	E2 const& _cart;///<cartesian element

public:
	TECartesianMulLeft(E1 const& u, TECartesianExpression<E2> const& v) : _mul(u), _cart(v) {};
	double operator[](size_t i) const { return _mul*_cart[i]; }
};

template <typename E1, typename E2> TECartesianMulLeft<E1,E2> const operator*(E1 const& u, TECartesianExpression<E2> const& v) 
{
   return TECartesianMulLeft<E1, E2>(u, v);
}


template <typename E1, typename E2> class TECartesianMulRight : public TECartesianExpression<TECartesianMulRight<E1, E2> > 
{
protected:
	E1 const& _cart;///<cartesian element
	E2 const& _mul;///<multiplication element

public:
	TECartesianMulRight(TECartesianExpression<E1> const& v, E2 const& u) : _mul(u), _cart(v) {};
	double operator[](size_t i) const { return _mul*_cart[i]; }
};

template <typename E1, typename E2> TECartesianMulRight<E1,E2> const operator*(TECartesianExpression<E1> const& v, E2 const& u) 
{
   return TECartesianMulRight<E1, E2>(v, u);
}

template <typename E> class TECartesianInv : public TECartesianExpression<TECartesianInv<E> > 
{
protected:
	E const& _u;

public:
	TECartesianInv(TECartesianExpression<E> const& u) : _u(u) {};
	double operator[](size_t i) const { return -_u[i]; }
};
 

template <typename E> TECartesianInv<E> const operator-(TECartesianExpression<E> const& u)
{
   return TECartesianInv<E>(u);
}







