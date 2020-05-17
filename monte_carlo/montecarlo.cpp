#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

 using namespace std;
 
 int main() {
 	float a,r;
 	long n, n_in;
 	
 	cout<<"Podaj bok kwadratu: ";
 	a=10.0;
	//cin>>a;

 	r=a/2;
	 
	cout<<"\nPodaj liczbe punktow do wylosowania: ";
	cin>>n;
	
	n_in=0;
	float r2=r*r;
	
	srand(time(NULL));
	for (long i=0; i<n; i++) {
		double x=a*(rand()%1001)/1000.0;
		double y=a*(rand()%1001)/1000.0;
		
		if ((x-a/2)*(x-a/2)+(y-a/2)*(y-a/2)<=r2) {
			n_in++;
			//cout<<x<<"\t"<<y<<endl;
		}
	}
	
	cout<<"Obliczone pi: "<<1.0*n_in*a*a/(r2*n);
 	
 	
 	return 0;
 }
