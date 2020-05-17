#include <iostream>
#include <cstdio>

using namespace std;

//liniowa
float funkcja1(float x) 
{
	return x+10;
}

//kwadratowa
float funkcja2(float x) 
{
	return -1*(x-1)*(x-10);
}

//wielomian 3-go stopnia
float funkcja3(float x) 
{
	return (x-3)*(x-5)*(x-8);
}

float funkcja(float x) 
{
	return funkcja3(x);
}


float wart_bezwzgledna(float x) {
	if (x>0)
		return x;
	return -x;
}


int main() 
{
	int xp=5;
	int xk=8;
	int n=10;
	double dx=1.0*(xk-xp)/n;
	double d=dx/2;
	double calka_prostokat_pocz=0;
	double calka_prostokat_srod=0;
	double calka_prostokat_konc=0;
	double calka_trapez=0;
	
	double calka_simpsona=0;
	//zmienne do calki simpsona
	double st=0;
	double s=0;
	
	double cs=0;
	
	for (int i=1; i<=n; i++) {
		double x0=xp+(i-1)*dx;
		double y0=funkcja(x0);
		
		double x1=x0+dx/2; 
		double y1=funkcja(x1);
		
		double x2=x0+dx;
		double y2=funkcja(x2);
		
		calka_prostokat_pocz+=wart_bezwzgledna(y0*dx);
		calka_prostokat_srod+=wart_bezwzgledna(y1*dx);
		calka_prostokat_konc+=wart_bezwzgledna(y2*dx);
		
		calka_trapez+=wart_bezwzgledna(0.5*(y0+y2)*dx);	
		
		//metoda simpsona
		st+=y1;
		if (i<n) {
			s+=y2;
		}
		cs+=6.0*d*y1+d*d/x1*(y0-2*y1+y2);
	}
	calka_simpsona=dx/6.0*(funkcja(xp)+funkcja(xk)+2*s+4*st);
	

	cout<<"CalkaP_pocz = "<<calka_prostokat_pocz<<endl;
	cout<<"CalkaP_srod = "<<calka_prostokat_srod<<endl;
	cout<<"CalkaP_konc = "<<calka_prostokat_konc<<endl;	
	cout<<"CalkaT = "<<calka_trapez<<endl;
	cout<<"CalkaS = "<<calka_simpsona<<endl;
	cout<<"CalkaS1 = "<<cs/3<<endl;
	
	
	return 0;
}
