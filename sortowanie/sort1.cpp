#include <iostream>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	int n;
	do {
		cout<<"Podaj n: ";
		cin>>n;
	} while (!(n>=0 && n<=100));
	srand(time(NULL));

	int min, max;
	do {
		cout<<"Podaj min: ";
		cin>>min;
	} while (!(min>=0 && min<1000));
	
	do {
		cout<<"Podaj max: ";
		cin>>max;
	} while (!(max>=0 && max<=1000 && min<max));
	
	ofstream wy("dane.txt");
	if(!wy)
	{
		cout << "Nie mozna otworzyc do zapisu";
		cin.ignore();
		getchar();
		return 1;
	}
	
	for (int i=0; i<n; i++) {
		wy<<min+rand()%(max-min+1)<<endl;
	}
	wy.close();
	
	return 0;
}
