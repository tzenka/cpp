#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main ( ) {
	ofstream wyniki("out.txt");
	if(!wyniki) {
		cout << "pliku nie mozna utworzyc";
		getchar();
		return 1;
	}
	wyniki.close();
	return 0;
	
	
}
