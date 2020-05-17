#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int silnia(int n) {
	if (n<=1) {
		return 1;
	} else return n*silnia(n-1);
}

int potega(float x, int n) {
	if (n==0) 
		return 1;
	else
		return x*potega(x, n - 1);
}

int fibo(int n) {
	if (n<2) 
	  return n;
 	else 
 	 return fibo(n-1)+fibo(n-2);
}

float delta(float a, float b, float c){
	return b*b-4*a*c;
}

void x12(float a, float b, float c, float *x) {
	*x=(-b-sqrt(delta(a,b,c)))/(2*a);
	x++;
	*x=(-b+sqrt(delta(a,b,c)))/(2*a);
}


int main(){
	int n=5;
	
	cout<<silnia(n)<<endl;
	cout<<potega(2, 6)<<endl;
	int p=1;
	for (int i=1; i<20; i++) {
		int k = fibo(i);
		cout<<k<<"; "<<1.0*k/p<<endl;
		p=k;
	}
	cout<<endl;
	int a=1, b=2, c=-3;
	float x[2];
	float *wsk = x;
	
	x12(a,b,c,wsk);
	cout<<x[0]<<endl<<x[1]<<endl;
	
	return 0;
}
