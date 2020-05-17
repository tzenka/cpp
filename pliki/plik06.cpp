#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main ( ) {
	float a, suma=0;
	char nazwa [100];
	cout << "Podaj nazwe pliku" <<endl;
	cin >> nazwa;
	ifstream we(nazwa);
	if(!we)
	{
		cout << "Nie mozna otworzyc pliku";
		cin.ignore();
		getchar();
		return 1;
	}
	while (!we.eof())
	{
		we >> a;
		if (we) {
			cout << a;
		  	suma = suma + a;
		}
	}
	we.close();
	
	cout<< "Suma: "<<suma<<endl;
	return 0;
}
