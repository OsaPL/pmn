#include <iostream>
#include <cmath>
#define _F cos(x)-x
#define _D -sin(x)-1
#define delta 0.0001
using namespace std;
int bstep=0;
int nstep=0;
double der(double x){
	return _D;
}
double fun(double x){
	return _F;
}
void Newton(double *x0){
	*x0=*x0-(fun(*x0)/der(*x0));
	cout<<"(Newton)Our aproximation atm is "<<x0<<endl;
	nstep++;
	system("pause");
	}
void Bisection(double *l,double *p){
	double mid=(*l+*p)/2;
	if(fun(*l)*fun(mid)>0){
		*l=mid;
	}
	else{
		*p=mid;
	}
	cout<<"(Bisection)Our aproximation atm is "<<(*l+*p)/2<<endl;
	bstep++;
	system("pause");
}
int main(){
	double left,right,x0,x1;
	cin>>left;
	cin>>right;
	x0=left;
	x1=x0*0.5;
	while (fabs((x1-x0)/x1)>delta){
		cout<<"Bsteps:"<<bstep<<" Nsteps:"<<nstep<<endl;
		x0=x1;
		if(der(x0)>0){
			if(((x0-left)*der(x0)-fun(x0)>=0) && (0>=(x0-right)*der(x0)-fun(x0))){
				x1=left;
			}
			else{
				Bisection(&left,&right);
				x1=(left+right)/2;
			}
		}
		else{
			if(((x0-left)*der(x0)-fun(x0)<=0) && (0<=(x0-right)*der(x0)-fun(x0))){
				Newton(&left);
				x1=left;
			}
			else{
				Bisection(&left,&right);
				x1=(left+right)/2;
			}
		}
		
	}
	system("pause");
}
