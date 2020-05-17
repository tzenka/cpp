#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	float* tab=NULL;
	try {
		tab= new float[5];
	}
	catch (bad_alloc) {
		cout<<"nie udalo sie"<<endl;
		return 1;
	}
	
	tab[0]=555;
	tab[1]=34234.56;
	tab[2]=9;
	
	cout<<tab<<endl;
	for (int i=0; i<3; i++)
		cout<<setw(10)<<*(tab+i);
	
	int **tab2 = new int *[3];
	for (int i=0; i<3; i++) {
		tab2[i]=new int[i+1];
	}
	
	tab2[0][0]=1;
	cout<<tab2[0][0];
	tab[0]=1;
	
	delete [] tab;
	for (int i=0; i<3; i++) {
		delete [] tab2[i];
	}
	delete [] tab2;
	
		
	
	return 0;
}
