#include <iostream>
#define size 4
#define f. 1/(1+x*x)
#define f' -2*x/(x*x+1)*(x*x+1)
#define f'' (6*(x*x)-2)/(x*x+1)*(x*x+1)*(x*x+1)
using namespace std;

double fs(double x){
	return  f. ;
}
double fs1(double x){
	return f' ;
}
double fs2(double x){
	return f'' ;
}
double p(double x,double le,double pr,double h){
	double p1,p2,p3;
	p1=(fs(pr)-fs(le))/h - h*
}
double gauss(double a[][],double r[]){
	//double a[size][size],r[size];
	double beta[size],ro[size],x[size];
	for(int i=1;i<size;i++){
		beta[i]=a[i][i]-(a[i][i-1]/beta[i-1])*a[i-1][i];
		ro[i]=r[i]-(a[i][i-1]/beta[i-1])*ro[i-1];
	}
	x[size-1]=ro[size-1]/beta[size-1];
	for(int i=size-2;i>-1;i--){
		x[i]=(ro[i]-a[i][i+1]*x[i+1])/beta[i];
	}
	for(int i=0;i<size;i++){
		cout<<"x"<<i<<"="<<x[i]<<endl;
	}
}

int main(){
	double x[11],fx[11];h=0.1;
	x[0]=-5;	fx[0]=fs(x[0]);
	x[1]=-4;	fx[1]=fs(x[1]);
	x[2]=-3;	fx[2]=fs(x[2]);
	x[3]=-2;	fx[3]=fs(x[3]);
	x[4]=-1;	fx[4]=fs(x[4]);
	x[5]=0;		fx[5]=fs(x[5]);
	x[6]=1;		fx[6]=fs(x[6]);
	x[7]=2;		fx[7]=fs(x[7]);
	x[8]=3;		fx[8]=fs(x[8]);
	x[9]=4;		fx[9]=fs(x[9]);
	x[10]=5;	fx[10]=fs(x[10]);
	
}
