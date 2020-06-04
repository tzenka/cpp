#include <cstdio>
#include <iostream>

using namespace std;

/*
Rozwi�zanie uk�adu dw�ch r�wna� liniowych, (metod� wyznacznik�w) 
funkcja ma zwraca� obliczon� warto�� wyznacznika 
U�ytkownik podaje wsp�czynniki wyraz�w wolnych w r�wnaniach
a1, b1,c1, a2, b2, c2
Koniecznie uwzgl�dnij warunki rozwi�zania uk�adu r�wna� 
(brak rozwi�za�, uk�ad ma wiele rozwi�za�)
Prosz� pami�ta� o algorytmie (konieczny warunek)
*/

int main() {
	float a1,b1,c1,a2,b2,c2;
	
	float w, wx, wy;
	
	cout<<"Podaj a1: "; 
	cin>>a1;
	cout<<"Podaj b1: "; 
	cin>>b1;
	cout<<"Podaj c1: "; 
	cin>>c1;
	
	cout<<"Podaj a2: "; 
	cin>>a2;
	cout<<"Podaj b2: "; 
	cin>>b2;
	cout<<"Podaj c2: "; 
	cin>>c2;
	
	w = a1*b2-b1*a2;
	wx= c1*b2-b1*c2;
	wy= a1*c2-b1*c2;
	
	if (w==0 && wx==0) {
		cout<<"Nieskonczenie wiele rozwiazan."<<endl;
	} else {
		if (w==0) {
			cout<<"Brak rozwiazan."<<endl;
		} else {
			cout<<"x = "<<wx/w<<endl;
			cout<<"y = "<<wy/w<<endl;
		}
	}
	return 0;
}
