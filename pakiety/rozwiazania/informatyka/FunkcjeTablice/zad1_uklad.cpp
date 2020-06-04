#include <cstdio>
#include <iostream>

using namespace std;

/*
Rozwi¹zanie uk³adu dwóch równañ liniowych, (metod¹ wyznaczników) 
funkcja ma zwracaæ obliczon¹ wartoœæ wyznacznika 
U¿ytkownik podaje wspó³czynniki wyrazów wolnych w równaniach
a1, b1,c1, a2, b2, c2
Koniecznie uwzglêdnij warunki rozwi¹zania uk³adu równañ 
(brak rozwi¹zañ, uk³ad ma wiele rozwi¹zañ)
Proszê pamiêtaæ o algorytmie (konieczny warunek)
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
