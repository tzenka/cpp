a#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int wie,kol;
	cout<<"Podaj liczbe wierszy i kolumn tablicy: ";
	cin>>wie>>kol;
	
	srand(time(NULL));
	
	int **tab;
	try {
		tab = new int*[wie];
	}
	catch (bad_alloc) {
		cout<<"blad";
		return 1;
	}

	for (int i=0; i<wie; i++) {
		try {
			tab[i] = new int[kol];
		}
		catch (bad_alloc) {
			cout<<"blad";
			return 1;
		}
	}
	
	for (int i=0; i<wie; i++) {
		for (int j=0; j<kol; j++) {
			int a=rand()%101;
			*(*(tab+i)+j)=a;
		}
	}
	
	for (int i=0; i<wie; i++) {
		for (int j=0; j<kol; j++) {
			cout<<setw(4)<<*(*(tab+i)+j);
			
		}
		delete [] tab[i];
		cout<<endl;
	}
	delete [] tab;

	return 0;
}
