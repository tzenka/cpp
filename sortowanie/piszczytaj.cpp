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

