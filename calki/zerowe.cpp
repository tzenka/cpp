#include <iostream>
#include <cstdio>

using namespace std;

float funkcja(float x) 
{
	return x*(x*(x*(x*(x-1)+4)-12)-9)+15; 
}

void zerowe(float xp,float xk,float blad) 
{
	if ((funkcja(xp)>0 && funkcja(xk)>0) ||
	   (funkcja(xp)<0 && funkcja(xk)<0)) 
	{
		return; 
	}
	float srodek=0.5*(xk+xp);	
	if (xk-xp<=blad) 
	{
		cout<<srodek<<endl;
		return;
	}
	if ((funkcja(xp)>0 && funkcja(srodek)<0) ||
	   (funkcja(xp)<0 && funkcja(srodek)>0)) 
	{
		zerowe(xp,srodek,blad);
	}else 
	{
		zerowe(srodek,xk,blad);
	}
}


int main() 
{
	int zakresod=-5;
	int zakresdo=5;	
	float blad=0.001; 	
	float przedzial=0.01;
	float calka_prostokat=0;
	float calka_trapez=0;
	for (float x=zakresod;x<=zakresdo;x=x+przedzial) 
	{
		zerowe(x,x+przedzial,blad);
		calka_prostokat+=funkcja(x+przedzial/2)*przedzial;
		calka_trapez+=funkcja(x)*przedzial+0.5*(funkcja(x+przedzial)-funkcja(x))*przedzial;
				
		//metoda trapezow
		//f(a)(b-a) + 0.5*(b-a)(f(b)-f(a))
	}
	cout<<"CalkaP = "<<calka_prostokat<<endl;
	cout<<"CalkaT = "<<calka_trapez<<endl;
	return 0;
}
