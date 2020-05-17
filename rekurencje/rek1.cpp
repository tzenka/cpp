#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int potega(int x, int n) {
	if (n<=0) 
		return 1;
	else 
		return x*potega(x, n-1);
}

void reverse(int n) {
	if (n==1)
	  cout<<n*n;
	else {
	   reverse(n-1);
	   cout<<setw(5)<<n*n;
	}
}

int main() {
	cout<<potega(2,6)<<endl;
	
	reverse(5);

	return 0;
}
