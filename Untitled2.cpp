#include <iostream>
#include <cmath>
using namespace std;
#define size 5
#define sizemultiplayer 4
#define newsize size*sizemultiplayer

double linear(double x, double*table) {
	int x1 = x/1;
	int x2 = x1+1;
	double y1 = table[x1];
	double y2 = table[x2];
	return ((y2 - y1) / (x2 - x1))*(x - x1) + y1;
}

int main(){

double xhue[size][size];

for(int i=0;i<size;i++)
	for(int j=0;j<size;j++){
		xhue[j][i]=fmod((i+1)*(15-j)*19,6);
	}

double xres[newsize][newsize];
int tempj,tempi;
for(int i=0;i<newsize;i++){
	for(int j=0;j<newsize;j++){
		tempi=i/sizemultiplayer;
		tempj=j/sizemultiplayer;
		xres[i][j]=xhue[tempj][tempi];
		cout<<xres[i][j]<<" ";
	}
	cout<<endl;
}
	cout<<endl;
	cout<<endl;
	
for(int i=0;i<newsize;i++){
	for(int j=0;j<newsize;j++){
		tempi=i/sizemultiplayer;
		tempj=j/sizemultiplayer;
		xres[i][j]=linear(i,&xhue[tempj][tempi]);
		cout<<xres[i][j]<<" ";
	}
	cout<<endl;
}


}
