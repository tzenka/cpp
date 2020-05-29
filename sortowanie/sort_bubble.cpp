#include <iostream>
#include <ctime>
#include <cstdlib>
#include "piszczytaj.cpp"

using namespace std;

int main () {
	int tab[100];
	int n=20;
	losujTablice(n, tab, 10, 99);
	//drukujTablice(n, tab);
	
	int i, j, k;
	for (int i=1; i<n; i++) {
	//drukujTablice(n, tab);
		for (int j=n-1; j>=i; j--) {
			drukujTablice(n, tab);
			if (tab[j-1]<tab[j]) {
				k=tab[j-1];
				tab[j-1]=tab[j];
				tab[j]=k;
			}
		}
	drukujTablice(n, tab);
	cout<<endl;
	}
	drukujTablice(n, tab);
	
	
	
	return 0;
}
