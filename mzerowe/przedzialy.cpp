#include <cstdio>
#include <iostream>
#include <fstream> //operacje na plikach
#include <iomanip> //formatowanie liczb

using namespace std;

struct element {
	element* nastepny;
	double x, y;
};

//dodaje element do listy - tylko x
element* dodaj(element* glowa, double x) {
	element* e;
	try {
		e = new element;	
	} catch (bad_alloc) {
		cout<<"Blad dodawania elementu listy"<<endl;
		return NULL;
	}
	e->nastepny=glowa;
	e->x=x;
	e->y=NULL;
	return e;
}

//dodaje element do listy - x i y
element* dodaj(element* glowa, double x, double y) {
	element* e;
	try {
		e = new element;	
	} catch (bad_alloc) {
		cout<<"Blad dodawania elementu listy"<<endl;
		return NULL;
	}
	e->nastepny=glowa;
	e->x=x;
	e->y=y;
	return e;
}

//rekurencyjnie usuwamy liste
void usun(element *el) {
	if (el==NULL)
	  return;
	if (el->nastepny==NULL) {
		delete el;
	}
	else 
		usun(el->nastepny);
}

//drukowanie listy
void drukuj(element *e) {
	if (e!=NULL) {
		drukuj(e->nastepny);
		cout<<e->x;
		if (e->y!=NULL) 
		  cout<<"("<<e->y<<")";
		cout<<" ";
	}
}

//zapisuje liste do pliku
void zapiszXY(ofstream* plik, element *e) {
	if (e!=NULL) {
		zapiszXY(plik, e->nastepny);
		*plik<<fixed<<setprecision(4)<<e->x<<"\t"<<fixed<<setprecision(4)<<e->y<<endl;
	}
}
void zapiszX(ofstream* plik, element *e) {
	if (e!=NULL) {
		zapiszX(plik, e->nastepny);
		*plik<<fixed<<setprecision(4)<<e->x<<endl;
	}
}

//horner - rekurencja
double f1(double x, element* wsp) {
	if (wsp->nastepny!=NULL) {
		return x*f1(x, wsp->nastepny)+wsp->x;
	}
	return wsp->x;
}

double f(double x, element* wsp) {
	return -2*(x-3)*(x-5)*(x-5)*(x-8);
}


//to samo co f, tylko dodatkowo wyswietla kroki liczenia
double f_debug(double x, element* wsp) {
	if (wsp->nastepny!=NULL) {
		cout<<x<<"*(";
		double s=f_debug(x, wsp->nastepny);
		cout<<")"<<(wsp->x>=0?"+":"")<<wsp->x;
		return x*s+wsp->x;
	}
	cout<<(wsp->x>=0?"+":"")<<wsp->x;
	return wsp->x;
}

// szuka w podanym przedziale (xp,xk) miejsca zerowego z dokladnoscia do diff
double szukaj(element* wsp, double xp, double xk, double diff) {
	double fp=f(xp, wsp);
	if (fp==0)
	  return xp;

	double fk=f(xk, wsp);
	if (fp==0)
	  return xk;
	
	if (fp*fk>0)
	  return NULL;
	  
	double xs=(xp+xk)/2;
	if (xk-xp<diff)
	  return xs;
	double fs=f(xs, wsp);
	if (fs==0)
	  return xs;
	  
	if (fp*fs<0) //przedzial lewy
	  return szukaj(wsp, xp, xs, diff);
	else //przedzial prawy
	  return szukaj(wsp, xs, xk, diff);
}

//szuka miejsc zerowych w (xp,xk) dzielac go na male przedzialy o szerokosci deltaX
element* rozwiaz(element* wsp, double xp, double xk, double deltaX, double diff) {
	element* wynik = NULL;
	for (double x=xp; x<=xk; x=x+deltaX) {			
		double mz = szukaj(wsp, x, x+deltaX, diff);
		if (mz!=NULL) {
			wynik = dodaj(wynik, mz);
		}
	}
	return wynik;
}

//tworzy liste z wartosciami funkcji f w przedziale (xp,xk) i krokiem deltaX
element* wykres(element* wsp, double xp, double xk, double deltaX) {
	element* wynik = NULL;
	for (double x=xp; x<=xk; x=x+deltaX) {			
		double y = f(x, wsp);
		wynik = dodaj(wynik, x, y);
	}
	return wynik;
}


int main(int arc, char** args) {
	// lista ze wspolczynnikami wielomianu
	element *wsp = NULL;
	//dodajemy kolejne wspolczynniki wielomianu
	wsp = dodaj(wsp, 1);
	wsp = dodaj(wsp, 1);
	wsp = dodaj(wsp, -64);
	wsp = dodaj(wsp, -64);

	usun(wsp);
	wsp=NULL;
	wsp = dodaj(wsp, 1);
	wsp = dodaj(wsp, 0);
	wsp = dodaj(wsp, -7);
	wsp = dodaj(wsp, -6);
	
    int xp=2, xk=9;
    
	// lista z miejscami zerowymi
    element* mz =NULL;
	//szukamy miejsc zerowych
	mz = rozwiaz(wsp, xp, xk, 0.1, 0.001);

	//drukowanie
	cout<<endl<<"wspolczynniki: "<<endl;
	drukuj(wsp);
	cout<<endl<<"m. zerowe: "<<endl;
	drukuj(mz);

	//przygotowanie danych do wykresu
	cout<<endl;
	element* w = wykres(wsp, xp, xk, 0.05);
	ofstream wy("wykres.txt");
	if(!wy)
	{
		cout << "Nie mozna otworzyc do zapisu";
		cin.ignore();
		getchar();
		return 1;
	}
	//zapisujemy wykres do pliku
	zapiszXY(&wy, w);


	//porzadki przed zakonczeniem
	wy.close();	
	usun(wsp);
	usun(mz);
	usun(w);

	return 0;	
}
