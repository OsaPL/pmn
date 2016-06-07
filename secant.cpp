#include <iostream>
#include <cmath>
#include <iomanip>  //setprecision

using namespace std;

#define _F cos(x)-x
#define delta 0.00000001

double function(double x){
	return _F;
}
int main(){
	double x0,x1,x2;
	cin>>x1;//because im changing...
	cin>>x2;
	do{
		x0=x1;//.. here
		x1=x2;//.. and here
		x2=(x0*function(x1) - x1*function(x0))/(function(x1) - function(x0));
	}while(fabs((x2-x1)/x2)>delta);
	cout<<endl<<"x0="<<x1;
}
