#include <iostream>
#include <cmath>
#include <iomanip>  //setprecision

using namespace std;
#define _F cos(x)-x
#define _d -sin(x)-1
#define delta 0.00000001

double derivate(double x){
	return _d;
}
double function(double x){
	return _F;
}
int main(){
	double x0,x1;
	double der,fun;
	int i=0;
	cin>>x0;
	x1=x0*0.5;//example data, can be anything BUT 0
	setprecision(6);
	while (fabs((x1-x0)/x1)>delta){
		x0=x1;
		i++;
		der=derivate(x0);
		fun=function(x0);
		x1=x0-(fun/der);
		cout<<"Iteration:"<<i<<endl;
		cout<<"Our aproximation atm is "<<x1<<endl;
		//system("Pause");
	}	
	cout<<"Our final root is "<<x1<<endl;
}
