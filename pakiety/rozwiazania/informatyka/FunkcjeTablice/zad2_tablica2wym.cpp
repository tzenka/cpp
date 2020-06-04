#include <cstdio>
#include <iostream>

using namespace std;

/*
Napisz program który czyta(tworzy) n elementow¹ tablicê dwuwymiarow¹: 
-oblicza sumê elementów; 
-znajduje el. max i min; 
-wyœwietla tablicê i wyniki.
N podaje u¿ytkownik
*/

int main() {
	int n;
	
	cout<<"Podaj n: ";
	cin>>n;

	float tab[n][n];
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout<<"Podaj element ["<<i<<","<<j<<"]: ";
			cin>>tab[i][j];			
		}
	}

	float suma=0;
	float min=tab[0][0];
	float max=min;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {			
			suma+=tab[i][j];			
			if (tab[i][j]<min)
			  min = tab[i][j];
			if (tab[i][j]>max)
			  max = tab[i][j];
		}
	}
	
	cout<<"Suma elementow: "<<suma<<endl;
	cout<<"Element min: "<<min<<endl;
	cout<<"Element max: "<<max<<endl;

	cout<<"Tablica: "<<endl;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {			
			cout<<tab[i][j]<<"\t";			
		}
		cout<<endl;
	}
	
	return 0;
}
