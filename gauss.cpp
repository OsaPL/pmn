#include <iostream>
#include <cmath>
using namespace std;
#define size 5

int main(){
	double table[size][size];
	
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
		cout<<"Enter elem ["<<i<<"]["<<j<<"] in."<<endl;
		cin>>table[i][j];
		}
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
		cout<<"Elem ["<<i<<"]["<<j<<"] = "<<table[i][j]<<endl;
		}
	
}
