#include<Coordinates.hpp>
#include<TECartesian.hpp>

#include<iostream>
#include<time.h>
#include <sys/time.h>




typedef unsigned long long TTimestamp;

inline TTimestamp GetTimestamp()
{
        struct timeval now;
        gettimeofday (&now, NULL);
        return  now.tv_usec + static_cast<TTimestamp>(now.tv_sec) * 1000000;
}







TTimestamp TestStruct(int nNum)
{
	TTimestamp Ta, Tb;
        Cartesian A,B,C,D;
        A.fX=1.;
        A.fY=2.;
        A.fZ=3.;
        B=C=D=A;

	Ta=GetTimestamp();        
	for(int i(nNum);i--;) 
	{
		A= -(2.*(2*B + C*i - D*3.4));
	}
	Tb=GetTimestamp();

	return Tb-Ta;
}

TTimestamp TestTemplate(int nNum)
{
        TTimestamp Ta, Tb;
        TECartesian A,B,C,D;
        A.fX=1.;
        A.fY=2.;
        A.fZ=3.;
        B=C=D=A;

        Ta=GetTimestamp();
        for(int i(nNum);i--;) 
        {
                A= -(2.*(2*B + C*i - D*3.4));
        }
        Tb=GetTimestamp();

        return Tb-Ta;
}









int main()
{
	TTimestamp TStruct, TTempl;
	TStruct=TestStruct(1000000);
	TTempl =TestTemplate(1000000);
	std::cout<<"Structure: "<<TStruct<<std::endl;
	std::cout<<"Expression template: "<<TTempl<<std::endl;
	std::cout<<"TStruct/TTempl: "<<TStruct/static_cast<double>(TTempl)<<std::endl<<std::endl;
        return 0;

}


