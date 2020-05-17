#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main ( ) {
	float a;
	ifstream we("liczby.txt");
	if(!we)
	{
		cout << "Nie mozna otworzyc do odczytu";
		cin.ignore();
		getchar();
		return 1;
	}
	
	ofstream wy("liczby2.txt");
	if(!wy)
	{
		cout << "Nie mozna otworzyc do zapisu";
		cin.ignore();
		getchar();
		return 1;
	}
	while (!we.eof()) {
		we>>a;
		if(we) {
			wy<<a<<endl;
		}
	}	
	
	we.close();
	wy.close();
	return 0;
}
