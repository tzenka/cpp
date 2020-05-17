#include <iostream>
#include <cstdio>
using namespace std;
float f1(float x){return x+10;}
float f2(float x){return -1*(x-1)*(x-10);}
float f3(float x){return (x-3)*(x-5)*(x-8);}
float f(float x){return f2(x);}
float wb(float x){return (x>0?x:-x);}
int main(){
float a[7];
int n=10;
float p=3,k=5;
float d=(k-p)/n;
float s=0,t=0;
for (int i=1;i<=n;i++){
float x0=p+(i-1)*d;
float x1=x0+d/2; 
float x2=x0+d;
a[0]+=wb(f(x0)*d);
a[1]+=wb(f(x1)*d);
a[2]+=wb(f(x2)*d);
a[3]+=wb(f(x0)+f(x2))*d/2;	
a[4]+=f(x1);
if (i<n) a[5]+=f(x2);
}
a[6]=d/6.0*(f(p)+f(k)+2*a[5]+4*a[4]);
cout<<"p_pocz:"<<a[0]<<endl;
cout<<"p_srod:"<<a[1]<<endl;
cout<<"p_konc:"<<a[2]<<endl;	
cout<<"t:"<<a[3]<<endl;
cout<<"s:"<<a[6]<<endl;
return 0;
}
