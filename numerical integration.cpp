#include <iostream>
#include <cmath>
#define fx sin(x)
using namespace std;
double function(double x){
	return fx;
}
double f1(double x){
	return cos(x);
}
double f3(double x){
	return -1*cos(x);
}
void trapezoid(){
	double h=3.14/1024;
	double dx=function(0)/2;
	int i=0;
	while(i*h<3.14){
		dx+=function(i*h);
		i++;
		cout<<"i="<<i<<endl;
	}
	dx+=function(3.14)/2;
	dx*=h;
	cout<<"trapezoid aproximation: " << dx <<endl;
}
void simpson(){
	double h=3.14/512;
	double dx=function(0);
	int i=0;
	while(i*h<3.14){
		if(i%2==0)
			dx+=4*function(i*h);
		else
			dx+=2*function(i*h);
		i++;
		cout<<"i="<<i<<endl;
	}
	dx+=function(3.14);
	dx*=h/3;
	cout<<"simpson aproximation: " << dx <<endl;
}
void boole(){
	double h=3.14/256;
	double dx=7*function(0);
	int i=0;
	while(i*h<3.14){
		if(i%4==0||i%4==2)
			dx+=32*function(i*h);
		if(i%4==1)
			dx+=12*function(i*h);
		if(i%4==3)
			dx+=14*function(i*h);
		i++;
		cout<<"i="<<i<<endl;
	}
	dx+=7*function(3.14);
	dx*=(2*h)/45;
	cout<<"boole aproximation: " << dx <<endl;
}
void eulermacla(){
	double h=3.14/1024;
	double dx=function(0)/2;
	int i=0;
	while(i*h<3.14){
		dx+=function(i*h);
		i++;
		cout<<"i="<<i<<endl;
	}
	dx+=function(3.14)/2;
	dx*=h;
	
	dx+=((h*h)/12)*(f1(0)-f1(3.14))*((h*h)/12)-((h*h*h*h)/720)*(f3(0)-f3(3.14));
	
	cout<<"euler-macla: " << dx <<endl;
}
int main(){
	trapezoid();
	simpson();
	boole();
	eulermacla();
}
