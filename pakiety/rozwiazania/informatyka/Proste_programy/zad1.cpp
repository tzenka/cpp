#include <cstdio>
#include <iostream>

using namespace std;

/*
	Napisz program kt�ry b�dzie odczytywa� z klawiatury kolejne liczby, 
	sumowa� je i wy�wietla� bie��ca sum� a� do momentu gdy przekroczy 
	ona warto�� 1000. Warto�� graniczn� zapami�taj w sta�ej.(const).
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
