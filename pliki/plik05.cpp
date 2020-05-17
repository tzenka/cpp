#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main ( ) {
	int a,b;

	ifstream wejscie("prostokat.txt");
	if (!wejscie) {
		cout << "Nie mozna otworzyc pliku";
		getchar();
		return 1;
	}
	wejscie >> a >> b;
	wejscie.close();
	
	cout << "Pole prostokata wynosi: " << a*b;
	getchar();
	return 0;
}
