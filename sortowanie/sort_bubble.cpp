#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void losujTablice(int n, int *tab, int min, int max) {
	srand(time(NULL));
	int a=max-min+1;
	for (int i=0; i<n; i++, tab++) {
		*tab = min + rand()%a;
	}
}

void drukujTablice(int n, int *tab) {
	for (int i=0; i<n; i++, tab++) {
		cout<<*tab<<" ";
	}
	cout<<endl;
}

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
