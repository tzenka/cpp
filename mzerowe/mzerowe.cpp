#include <cstdio>
#include <iostream>

using namespace std;

float g(float x) {
	// wielomian: g(x)=x^4 + x^3 - 35x^2 - 57x + 90;
	// liczenie wg schematu hornera:
	return  x*(x*(x*(x+1)-35)-57)+90; 
}

float znajdz(float xp, float xk, float precyzjaX) {
	float yp=g(xp);
	if (yp==0.00) return xp;
	
	float yk=g(xk);
	if (yk==0.00) return xk;	
	if (yp*yk>0) return NULL; //ten sam znak na poczatku i koncu przedzialu - brak miejsc zerowych

	float xh; 
	while (xk-xp > precyzjaX) {
		xh = (xk+xp) / 2;
		float yh=g(xh);
		if (yh==0.0)
		  return xh;		
		if (yp*yh < 0)
			xk = xh; // miejsce zerowe w lewym przedziale
		else
			xp = xh;  // miejsce zerowe w prawym przedziale
	}	
	return (xp+xk)/2;
}

int main(int argc, char** args) {
	float deltaX = 0.1;
	float dokladnosc=0.03; 
	
	for (float i=-10; i<=10; i+=deltaX) {
		float mz = znajdz(i, i+deltaX, dokladnosc);
		if (mz!=NULL)
			cout<<mz<<endl;
	}
	
	return 0;
}
