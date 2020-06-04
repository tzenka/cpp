#include <cstdio>
#include <iostream>

using namespace std;

/*
	Napisz program wyœwietlaj¹cy na ekranie sekwencje kolejnych liczb ca³kowitych
	najpierw od 1 do 10, a nastêpnie od 10 do 1. do spowolnienia operacji wypisywania 
	dowolna dodatkowa pêtla. na zakoñczenie jeszcze jedna pêtla, która spowoduje, ¿e 
	ca³y proces odliczania powtórzy siê trzy razy
*/

czekaj() {
	for (long i=0; i<100000000; i++){
		1.0*i/(i+1);
	}
}

int main() {	
	for (int k=0; k<3; k++) {
		for (int i=1; i<=10; i++) {
			cout<<i<<" ";
			czekaj();
		}	
		for (int i=10; i>=1; i--) {
			cout<<i<<" ";
			czekaj();		
		}
		cout<<endl;
	}
	
	return 0;
}
