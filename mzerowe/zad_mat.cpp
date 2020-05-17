#include <iostream>
#include <cmath> // potrzebujemy wartosci bezwzglednej - abs
#include <iomanip>

using namespace std;

float funkcja2(float x) {//horner
	float a=0,b=0,c=1,d=1,e=-17,f=15;	
	return x*(x*(x*(x*(x*a+b)+c)+d)+e)+f;
}

float funkcja1(float x) {// m.zerowe: -3, 0, 1, 2.01, 2.02, 4, 50
	return x*(x-1)*(x-2.02)*(x-2.01)*(x-4)*(x-50)*(x+3);
}

float funkcja(float x){// pomocnicze, zeby zmieniac sobie miedzy funkcja1 a funkcja2
	return funkcja1(x);
}

void szukaj(float xp, float xk, float dokladnosc) {//funkcja rekurencyjna
	float yp=funkcja(xp); //wartosc na poczatku przedzialu
	float yk=funkcja(xk); //wartosc na koncu przedzialu
	if(yp==0)
		cout<<"m. zerowe dla: f("<<fixed<<setprecision(5)<<xp<<")="<<fixed<<setprecision(5)<<yp<<endl;
	if (yp*yk<0) {// przeciwne znaki 
		float xs=(xp+xk)/2; // nowe x na srodku przedzialu
		if (abs(yk-yp)<dokladnosc) {
			cout<<"m. zerowe dla: f("<<fixed<<setprecision(5)<<xs<<")="<<fixed<<setprecision(5)<<abs(yp-yk)<<endl;
		} else {
			float ys=funkcja(xs);// wartosc w srodku przedzialu
			if (yp*ys<0) {// przeciwne znaki na poczatku i srodku
				szukaj(xp, xs, dokladnosc);//rekurencja - szukamy w pierwszym przedziale
			} else {// przeciwne znaki na srodku i koncu
				szukaj(xs, xk, dokladnosc);//rekurencja - szukamy w drugim przedziale
   			}
		}
	}
}

int main() {
	float xp=-10, xk=50; //poczatek i koniec przedzialu w ktorym szukamy
	float deltaX=(xk-xp)/1000; // poczatkowe deltaX
							   //jezeli m.zerowe sa polozone blizej siebie niz ta wartosc, 
							   //to mozemy ich nie znalezc
	float bladY=0.001;	// kiedy uznajemy ze to jest miejsce zerowe
	for (float x=xp; x<=xk; x=x+deltaX) {
		szukaj(x, x+deltaX, bladY);
	}
	
	return 0;
}
