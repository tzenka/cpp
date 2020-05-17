#include <conio.h>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

int conv(char c) {
	return c-'0';
}


string toN(int w, int n) {
	string out="";
	while (w > 0) {
		// reszta z dzielenia
		int r = w % n;		
		w = w / n;
		char c=(char)(r<=9?r+'0':r+'a'-10);
		out=c+out;
	}	
	return out;
}

string horner(int liczba, int podstawa) {
	if (liczba==0) {
		return "";		
	} else {
		int r = liczba % podstawa;
		return horner(liczba/podstawa, podstawa) + (char)(r<=9?r+'0':r+'a'-10);
	}	
}

//100,1110


float fhorner10(string l) {
	float w=0;
	int waga=1;
	int ulamek=0;
	for (int i=0; i<l.length(); i++) {
		if (l[i]==',') {
			ulamek=1;
		} else {
			w=w*2+l[i]-'0';
			if (ulamek==1) {
				waga=waga*2;
			}
		}
	}
	return w/waga;
}

float power(float x, int m) {
	float z=x;
	int l=m;
	float y=1;
	while (l!=0) {
		if (l % 2 == 1) {
			y=y*z;
		}
		l/=2;
		z*=z;	
	}
	return y;
}

float power1(float x, int m) {
	float y=1;
	for (int i=1; i<=m; i++)
	  y=y*x;
	return y;
}

int main() {
	string l="";
	l="111010,111011";	
	string out="";
	
	char c=0;
	//cin.ignore();
//	int i=0;
	int ni=2;
	if (l=="") {
		ni=0;
		while (ni<2 || ni>11) {
			cout<<"Podaj podstawe systemu liczbowego (2-10): ";
			cin>>ni;
		}
		cout<<"Podaj liczbe w tym systemie: ";
		do {
			c = getch();
			if ((c>='0' && c<= '0'+ni-1) || c==',') {
				cout<<c;
				l=l+c;
			}
		} while (c!=13);
		cout<<endl;
		cout<<l<<"("<<ni<<")"<<endl;
	}

	for (long i=0; i<1000; i++) {
		//fhorner10(l);
	}

	cout<<"Liczba: "<<fhorner10(l)<<endl;
	
	int w=0;
	for (int i=0; i<l.length(); i++) {
		int c=conv(l[i]);
		w=w*ni+c;
	}
	
	//cout<<w<<endl;
	
	
	for (int i=2; i<=16; i++) {
		cout << i<<": "<<horner(w, i) << endl;
		
	}
	
	cout<<out<<endl;
	
//	cout<<horner(w,8)<<endl;
	for (int i=0; i<30000000; i++)
		power(2,22);
		
	//cout<<power1(2,6)<<endl;
	return 0;
}
