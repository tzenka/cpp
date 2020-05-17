#include <cstdio>
#include <iostream>

using namespace std;

float wielomian(float x) {
	return x*(x*(1*x+1)-16)-16;
}

float szukanie(float start, float koniec, float roznica) {
	float ystart=wielomian(start);
	if (ystart==0.00) return start;
	
	float ykoniec=wielomian(koniec);
	if (ykoniec==0.00) return koniec;	
	if (ystart*ykoniec>0) return NULL; //ten sam znak na poczatku i koncu przedzialu - brak miejsc zerowych
	float polowa = (koniec+start) / 2;	
	if (koniec-start<roznica) 
	  return polowa;
	float ypolowa=wielomian(polowa);
	if (ypolowa==0.0)
	  return polowa;		
	if (ystart*ypolowa < 0)
		return szukanie(start, polowa, roznica);
	return szukanie(polowa, koniec, roznica);
}



int main(int argc, char** args) {
	float roznica=0.001; 
	float deltaX = 0.5;
	float xp=-10;
	float xk=-xp;
	
	int numer=1;
	
	for (float i=xp; i<=xk; i+=deltaX) {
		float mz = szukanie(i+roznica, i+deltaX, roznica);
		if (mz!=NULL) {
			cout<<"mz."<<numer<<": "<<mz<<endl;
			numer++;
		}
	}
	cout<<"Znaleziono "<<numer-1<<" m.zerowych"<<endl;
	return 0;
}
