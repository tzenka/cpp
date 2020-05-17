 #include <iostream>
using namespace std;
/* 
1. wczytaj liczby a1,b1,c1,a2,b2,c2
2. oblicz wyznacznik W dla a1,b1,a2,b2
3. oblicz wyznacznik Wa dla 
4. jezeli W=0 oraz Wa=0 to drukuj "nieskonczenie wiele rozwiazan" i zakoncz dzialanie
5. jezeli W=0 oraz Wa<>0



*/

int delta(int a, int b, int c) {
	return b*b-4*a*c;
}

int wyznacznik(int a, int b, int c, int d) {
	return a*d-b*c;
}

int main() {
	//1
	int a1=1, b1=1, c1=-2,
		a2=2, b2=-1,c2=5;
	
	//2
	int w=wyznacznik(a1,b1,a2,b2);
	int wa=wyznacznik(c1,b1,c2,b2);
	
	cout<<w<<endl<<wa<<endl;

	return 0;
}
