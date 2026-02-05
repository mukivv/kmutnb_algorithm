#include <iostream>

using namespace std;

void print(int w[],int v[],int x[],int n,int total[]){
	int sumW = 0 , sumV = 0;
	for (int i=1;i<=n;i++){
		if (x[i] == 1){
			sumW += w[i-1];
			sumV += v[i-1];
		}
	}
	
	if (sumV > total[1] && sumW < total[0]){
		total[1] = sumV;
	}
}

void knapsack(int w[],int v[],int x[],int l,int r,int total[]){
	if (l==r){
		print(w,v,x,r,total);
	} else {
		x[l+1] = 1;
		knapsack(w,v,x,l+1,r,total);
		x[l+1] = 0;
		knapsack(w,v,x,l+1,r,total);
	}
}

int main(){
	int total[2] ; //0 = maxW , 1 = maxV we want
	cin >> total[0]; //maxW
	
	int n = 4, w[n] , v[n] , x[n+1];
	
	for (int i=0;i<n;i++){
		cin >> v[i];
	}
	for (int i=0;i<n;i++){
		cin >> w[i];
	}

	knapsack(w,v,x,0,n,total);
	
	cout << total[1] << endl; //maxV
}
