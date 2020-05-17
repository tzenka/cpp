#import <iostream>
#import <cmath>

using namespace std;

drukuj(float tab[], int n, string opis){
	cout<<opis;
	for (int i=0; i<n; i++) {
		cout<<tab[i];
		if (i<n-1) {
			cout<<", ";
		}
	}
	cout<<endl;
}

int main() {
	int n;
	cout<<"Podaj n:";
	cin>>n;
	
	float tabelaa[n], tabelab[n]; 
	
	cout<<"TabelaA"<<endl;
	for (int i=0; i<n; i++) {
		cout<<"Podaj element nr "<<i<<": ";
		cin>>tabelaa[i];
	}
	cout<<"TabelaB"<<endl;
	for (int i=0; i<n; i++) {
		cout<<"Podaj element nr "<<i<<": ";
		cin>>tabelab[i];
	}
	float suma[n], roznica[n], iloczyn[n], iloraz[n];
	for (int i=0; i<n; i++) {
		suma[i]=tabelaa[i]+tabelab[i];
		roznica[i]=tabelaa[i]-tabelab[i];
		iloczyn[i]=tabelaa[i]*tabelab[i];
		iloraz[i]=tabelaa[i]/tabelab[i];
	}
	
	drukuj(suma, 	n, "Suma:    ");	
	drukuj(roznica, n, "Roznica: ");	
	drukuj(iloczyn, n, "Iloczyn: ");	
	drukuj(iloraz, 	n, "Iloraz:  ");	
	
	cout<<sqrt(4);
	return 0;
}
