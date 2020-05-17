#include <iostream>
#include <fstream>



//2bzso4@jerzysabiniewicz.pl

using namespace std;

int main() {
	fstream plik;
	plik.open( "c:/temp/hello.txt", ios::in | ios::out);
	
	if (plik.good() == true) {
		cout << "jest ok" << endl;
		
		string tekst;
//		plik >> tekst;
//		cout<<tekst;
//		
//		plik>>tekst;
//		cout<<tekst;

char temp[1024];

		plik.read(temp, 1024);
		
		for (int i=0; i<1024; i++) {
			cout<<temp[i];
		}
		
		plik.close();	
	} 
	else { 
		cout << "Brak dostepu" << endl;
	}
	
	
	return 0;
}



