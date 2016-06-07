#include <iostream>
using namespace std;
#define size 4
//ai=a[i][i-1]
//bi=a[i][i]
//ci=a[i][i+1]
int main(){
	double a[size][size],r[size];
	
	a[0][0]=4;
	a[0][1]=-1;
	a[0][2]=0;
	a[0][3]=0;
	
	a[1][0]=-1;
	a[1][1]=4;
	a[1][2]=-1;
	a[1][3]=0;
	
	a[2][0]=0;
	a[2][1]=-1;
	a[2][2]=4;
	a[2][3]=-1;
	
	a[3][0]=0;
	a[3][1]=0;
	a[3][2]=-1;
	a[3][3]=4;
	
	r[0]=5;
	r[1]=5;
	r[2]=10;
	r[3]=23;
	
	double beta[4],ro[4],x[4];
	beta[0]=a[0][0];
	ro[0]=r[0];
	for(int i=1;i<4;i++){
		beta[i]=a[i][i]-(a[i][i-1]/beta[i-1])*a[i-1][i];
		ro[i]=r[i]-(a[i][i-1]/beta[i-1])*ro[i-1];
	}
	x[3]=ro[3]/beta[3];
	for(int i=2;i>-1;i--){
		x[i]=(ro[i]-a[i][i+1]*x[i+1])/beta[i];
	}
	for(int i=0;i<4;i++){
		cout<<"x"<<i<<"="<<x[i]<<endl;
	}
	cout<<"beta0="<<beta[0]<<endl;
	cout<<"beta1="<<beta[1]<<endl;
	cout<<"beta2="<<beta[2]<<endl;
	cout<<"beta3="<<beta[3]<<endl;
	cout<<"beta4="<<beta[4]<<endl;
	cout<<"ro0="<<ro[0]<<endl;
	cout<<"ro1="<<ro[1]<<endl;
	cout<<"ro2="<<ro[2]<<endl;
	cout<<"ro3="<<ro[3]<<endl;
	cout<<"ro4="<<ro[4]<<endl;
}
