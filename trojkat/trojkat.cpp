#include <cstdio>
#include <iostream>
#include <cmath>
/*
  wczytujemy 3 liczby - boki trojkata.
  sprawdzamy czy jest to trojkat, obliczamy:
  obwod
  pole
  katy
  wypisujemy rodzaj trojkata
	
*/

using namespace std;

float kat(float a, float b, float c) {
	return acos((b*b+c*c-a*a)/(2*b*c))*360/2/M_PI;
}

int main() {
	cout<<"Podaj a: ";
	float a;
	cin>>a;

	cout<<"Podaj b: ";
	float b;
	cin>>b;
	
	cout<<"Podaj c: ";
	float c;
	cin>>c;
	
	if (a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || b+c<=a) {
		cout<<"To nie jest trojkat"<<endl;
		return 0;
	}
	
	float alfa, beta, gamma;
	
	alfa = kat(a,b,c);	
	beta = kat(b,c,a);
	gamma = kat(c,a,b);
	float p=0.5*(a+b+c);
	cout<<"Obwod: "<<2*p<<endl;
	cout<<"Pole: "<<sqrt(p*(p-a)*(p-b)*(p-c))<<endl;
	cout<<alfa<<endl;
	cout<<beta<<endl;
	cout<<gamma<<endl;
	
	if (alfa>90 || beta>90 || gamma>90) {
		cout<<"Trojkat rozwartokatny";
	} else if (alfa==90 || beta==90 || gamma==90) {
		cout<<"Trojkat prostokatny";		
	} else  {
		cout<<"Trojkat ostrokatny";		
	}
	
	if (a==b && b==c && a==c) {
		cout<<", rownoboczny"<<endl;				
	} else if (a==b || b==c || a==c) {
		cout<<", rownoramienny"<<endl;				
	}
	
	
	
	return 0;
}
