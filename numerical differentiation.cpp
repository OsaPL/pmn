#include <iostream>
#include <iomanip>  //setprecision
#include <cmath>	//cos, sin and whatnot
using namespace std;
int main(){
	float h[10];
	h[0]=0.5;
	for(int i=1;i<10;i++){
		h[i]=h[i-1]+0.5;
	}
	
}
