#include <iostream>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "piszczytaj.cpp"

using namespace std;

void quicksort(int *t, int l, int p) {
	if (p-l<=1) {
		return ;
	} else {
		for (
		
	}
}

int main() {
	int tab[100];
	int n=20;
	losujTablice(n, tab, 10, 99);
	
	quicksort(tab, 0, 20);	
	drukujTablice(n, tab);
	
	return 0;
}
