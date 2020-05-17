#include <iostream>
#include <fstream>

using namespace std;

int main ( ) {

char nazwa[50];
cout << "Podaj nazwe pliku jaki chcesz utworzyc ";
cin >> nazwa;
ofstream wyniki(nazwa);
wyniki <<'s';
wyniki.close();
return 0;
}

