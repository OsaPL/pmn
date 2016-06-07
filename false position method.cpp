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
	double xl,xr,x0;
	cin>>xl;
	cin>>xr;
	do{
		/*
		double p1a,p1b,p2a,p2b, psum; //p(x)=(p1a+p1b*x)*f(xl) + (p2a+p2b*x)*f(xr)
		double fl,fr;
		fl=function(xl);
		fr=function(xr);
		p1a=(-xr)/(xl-xr);  //this is stupid, really really stupid, but hey, it'll work.
		p1b=1/(xl-xr);
		p2a=(-xl)/(xr-xl);
		p2b=1/(xr-xl);
		*/
		x0=(xl*function(xr) - xr*function(xl))/(function(xr)-function(xl));
		if(function(x0)>0){//for decreasing function
			xl=x0;
		}
		else{
			xr=x0;
		}
	}while(xr-xl>delta);
	cout<<endl<<"x0="<<x0;
}
