#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define length(x) (sizeof(x) / sizeof(*(x)))

struct element_listy {
	int liczba;
	element_listy* nastepny;
};

void usun(element_listy *el) {
	if (el==NULL)
	  return;
	if (el->nastepny==NULL) {
		delete el;
	}
	else 
		usun(el->nastepny);
}

void drukuj(element_listy *el) {
	if (el!=NULL) {
		drukuj(el->nastepny);
		cout<<el->liczba;
	}
}

int main() {
	element_listy *glowa = NULL;
	element_listy *nowy;
	char odp;
	
	int d;
	
	cout << "czy chcesz podac element listy? t/n:";
	cin >> odp;
	
	while (odp!='n') {
		cout<<"Podaj dane: ";
		cin>>d;
		try {
			nowy = new element_listy;
		} catch (bad_alloc) {
			cout<<"blad";
			break;
		}
		nowy->nastepny=glowa;
		nowy->liczba=d;
		glowa=nowy;
		cout << "czy chcesz podac element listy? t/n:";
		cin >> odp;
	}
		
	cout<<endl<<"druk"<<endl;
	drukuj(glowa);
	cout<<endl<<"porzadki"<<endl;
	usun(glowa);
	
	int w=5;
	int k=3;
		srand(time(NULL));

	int **tab = new int*[w];
	
	for (int i=0; i<w; i++) {
		tab[i] = new int[k];
	}

	for (int i=0; i<w; i++) {
		for (int j=0; j<k; j++) {
			int a=rand()%101;
			*(*(tab+i)+j)=a;
			//tab[i][j]=a;
		}
	}

	for (int i=0; i<w; i++) {
		for (int j=0; j<k; j++) {
			//cout<<setw(4)<<*(*(tab+i)+j);
		}
		int *t=tab[i];
		int s=*(&t+1)-t;
		cout<<s<<endl;
		//cout<<endl;
	}
	
	int *arr = new int[10];
	arr[0]=5;
	
	
   	int len = *(&arr + 1) - arr;
   	cout << "The length of the array is: " << length(arr);
	
	delete[] tab;	

	return 0;
}
