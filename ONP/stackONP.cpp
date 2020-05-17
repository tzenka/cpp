#include <cstdio>
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	//char* s = "2 2 2*+1 3/+=";
	string s1="";
	for (int i=0; i<200; i++) {
		s1 = s1+"1 ";	
	}
	for (int i=0; i<199; i++) {
		s1 = s1+"+ ";	
	}
	s1=s1+"=";
	cout<<"Podaj wyrazenie ONP zakonczone znakiem '=': ";
	s1="";
	char c;
	do {
		c = getch();
		if ((c>='0' && c<= '9') || c==' ' || c=='+' || c=='=' || c==27) {
			cout<<c;
			s1=s1+c;
		}
	} while (c!=13);
	cout<<endl;	
	
	char* s = &s1[0];
	//s = "1 2 3 4+++=";
	float stack[255];
	int sp=0;
	float a, b;
	bool input=false;
	while (*s!='\0') {
		//cout<<*s<<endl;
		char ch=*s;
		if (ch>=char(48)&&ch<=char(57)) {
			a=a*10+char(ch)-char(48);
			input=true;			
		} else {
			
		}
		if (ch==' '||
			ch=='-'||
			ch=='+'||
			ch=='*'||
			ch=='/') {
			if (input) {
				input=false;
				stack[sp++]=a;
				a=0;					
			} 
			if (ch!=' ') {
				b=stack[--sp];
				a=stack[--sp];
				float c;
				switch (ch) {
					case '+': c=a+b; break;
					case '-': c=a-b; break;
					case '*': c=a*b; break;
					case '/': c=a/b; break;
				}
				stack[sp++]=c;
				a=0;
			}
		}
		switch (ch) {
			case '=': cout<<"wynik: "<<stack[--sp]<<endl;				
		}
		s++;
	}
	
	return 0;
}
