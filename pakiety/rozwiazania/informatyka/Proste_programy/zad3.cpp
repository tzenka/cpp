#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

/*
	Napisz program, który dla danej liczby naturalnej n (n >= 2) 
	wypisze wszystkie liczby pierwsze znajduj¹ce siê w przedziale <2,n>.	
*/

bool sprawdzCzyPierwsza(int a) {
	int sqr=round(sqrt(a));
	for (int i=2; i<=sqr; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;	
}

int main() {
	cout<<"Podaj n (n >= 2): ";
	int n;
	cin>>n;
	if (n < 2) {
		return 0;
	}
	
	for (int x=2; x<=n; x++) {
		if (sprawdzCzyPierwsza(x)) {
			cout<<x<<endl;
		}	
	}
	
	return 0;
}

