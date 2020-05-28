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
	
	int min=tab[0], max=tab[0];
	for (int i=0; i<n; i++) {
		if (tab[i]<min) {
			min=tab[i];
		}
		if (tab[i]>max) {
			max=tab[i];
		}
	}
	
	drukujTablice(n, tab);
	cout<<"min = "<<min<<endl;
	cout<<"max = "<<max<<endl;
	
	return 0;
}
