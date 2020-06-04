#include <cstdio>
#include <iostream>

using namespace std;

/*
	Napisz program który bêdzie odczytywa³ z klawiatury kolejne liczby, 
	sumowa³ je i wyœwietla³ bie¿¹ca sumê a¿ do momentu gdy przekroczy 
	ona wartoœæ 1000. Wartoœæ graniczn¹ zapamiêtaj w sta³ej.(const).
*/

int main() {
	const int MAX=1000;
	
	int suma=0;
	do {
		cout<<"Podaj liczbe: ";
		int a;
		cin>>a;
		suma+=a;
		cout<<"Aktualna suma: "<<suma<<endl;		
	} while (suma<=MAX);
	
	return 0;
}
