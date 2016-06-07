#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
double randomize(double seed){
	return fmod(((seed*19879)/time(0)+223)+(time(0)/123456*seed),1);
}
int main(){
	double seed;
	while(true){
		seed=rand();
		cout<<randomize(seed)<<endl;
		system("Pause");
	}
}
