#include<iostream>
using namespace std;

int main(){
	double a[5][5],b[5],x[5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<"Elem a["<<i<<"]["<<j<<"]"<<endl;
	
			cin>>a[i][j];
		}	
	}
	for(int i=0;i<5;i++){
		cout<<"Elem b["<<i<<"]"<<endl;
		cin>>b[i];
		}
		
	for(int i=0;i<5;i++){
		cout<<"wzor a["<<i<<"]="<<a[i][i-1]<<endl;
		cout<<"wzor b["<<i<<"]="<<a[i][i]<<endl;
		cout<<"wzor c["<<i<<"]="<<a[i][i+1]<<endl;
	}
	
	double beta[5],ro[5];
	beta[0]=a[0][0];
	ro[0]=b[0];
	for(int i=1;i<5;i++){
		//beta[i]=a[i][i]-(a[i][i-1]/beta[i-1])*a[i-1][i+1-1];
		//ro[i]=b[i]-(a[i][i-1]/beta[i-1])*ro[i-1];
		beta[i]=a[i][i]-(a[i][i-1]/beta[i-1])*a[i-1][i];
		ro[i]=b[i]-(a[i][i-1]/beta[i-1])*ro[i-1];
	}
	x[4]=ro[4]/beta[4];
	for(int i=3;i>=0;i--){
		//x[i]=(ro[i]-a[i][i+1]*x[i+1])/beta[i];
		x[i]=(ro[i]-a[i][i+1]*x[i+1])/beta[i];
	}
	for(int i=0;i<5;i++){
		cout<<"x"<<i<<"="<<x[i]<<endl;
		}
}
