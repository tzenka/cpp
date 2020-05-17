#include <iostream>

using namespace std;

int nwd(int a, int b) {
	cout<<"+"<<endl;
	if (a > b) {		
		return nwd(a - b, b);
	} else if (b > a) {
		return nwd(a, b - a);
	} else return a;
}

int nwd1(int a, int b) {
	cout<<"*"<<a<<";"<<b<<endl;
	if (a > 0) {
		if (a>b) return nwd1(a % b, b - (a % b));
		else return nwd1(b % a, a - (b % a));
	}
	else return b;
	  
}

int main(int argx, char** argv) {
	
	int a = 32;
	int b = 12;
	int nwd=nwd1(a,b);
	cout<<"-----"<<endl;
	nwd=nwd1(b,a);
	
	//cout<<nwd(a,b)<<endl;
	cout<<nwd<<endl;
	cout<<(a*b)/nwd<<endl;
	
/*	
	while (a!=b) {
		if (a>b) {
			a=a-b;
		} else {
			b=b-a;
		}
	}
	cout<<a<<endl;
*/	
	return 0;
}

