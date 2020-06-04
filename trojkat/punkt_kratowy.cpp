#include <cstdio>
#include <iostream>
#include <cmath>
/*
  wypisujemy wszystkie punkty kratowe (o wspolrzednych bedacymi liczbami calkowitymi)
  lezaca wewnatrz kola o podanym promieniu
  przyklady
	  R=1 N=1
	  R=2 N=9
	  R=5 N=69
*/

using namespace std;

int main() {
	cout<<"Podaj r: ";
	float r;
	cin>>r;
	
	int r1=round(r);
		
	int ile=0;
	for (int x=-r1; x<=r1; x++) {
		for (int y=-r1; y<=r1; y++) {
			if (x*x + y*y < r*r) {
				//cout<<x<<", "<<y<<endl;
				ile++;
			}
		}
	}

	cout<<"Znaleziono "<<ile<<" punktow kratowych"<<endl;
	
	return 0;
}
