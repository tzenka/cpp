#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main( ) {
	int n;
	cout<<"wpisz stopien wielomianu: ";
	cin>>n;
	
	float a[n+1]; //tablica ze wspolczynnikami
	float *wsk=a; //wskaznik do tablicy
	for (int i=n; i>=0; i--) {
		cout<<"Wprowadz a"<<i<<": ";
		cin>>*wsk;
		wsk++; // przechodzimy do kolejnego elementu tablicy
	}
	int k,w;
	cout<<"wpisz k: ";
	cin>>k;

	cout<<"wpisz w: ";
	cin>>w;
	
	float krok;
	cout<<"wpisz krok: ";
	cin>>krok;
	
	
	ofstream zapis("wykres.txt");
	if (!zapis) {
		cout << "blad przy zapisie";
		getchar();
		return 1;
	}

	for (float x=k; x<=w; x+=krok) {
		wsk=a; // ustawiamy sie na wspolnycznnik an
		float s=0; //poczatkowa wartosc 0
		for (int j=0; j<=n; j++) { //petla po wszystkich wspolczynnikach
			s*=x; //horner mnozenie
			s+=*wsk; // horner dodawanie
			wsk++;
		}
		zapis<<x<<"\t"<<s<<endl; // \t - tabulator
	}
	
	zapis.close();
	
	return 0;
}
