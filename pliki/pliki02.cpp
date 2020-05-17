#include <iostream>
#include <fstream>

using namespace std;

int main ( ) {
	ofstream zapis("wyjscie.txt");
	//zapis << 3 << " " << -20;
	for (int i=0; i<100; i++) {
		zapis << i << endl;
	}
	zapis.close();
	
	return 0;
}
