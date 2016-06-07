#include <iostream>
#include <iomanip>  //setprecision
#include <cmath>	//cos, sin and whatnot
#define f cos(x)-x


double delta=0.00000001;
using namespace std;
double y(double x){
	return f;
}

int main(){
	double l,p,mid;
	int i=0;
	cout<<"Input range (left,right)"<<endl;
	cin>>l;
	cin>>p;
	mid=(l+p)/2;
	if(y(l)*y(p)<0){
		while(delta<p-l){
			i++;
			mid=(l+p)/2;
			if(y(l)*y(mid)>0){
				l=mid;
			}
			else{
				p=mid;
			}
			cout<<"Iteration:"<<i<<endl;
			cout<<"Our aproximation atm is "<<(l+p)/2<<endl;
			//system("pause");
		}
		setprecision(6);
		cout<<"Our final root is "<<(l+p)/2<<endl;
	}
	else{
		cout<<"No root in given range"<<endl;
	}
	}
	
