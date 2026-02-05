#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;


void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int X[], int end){
	for (int i=1;i<=end;i++){
		for (int j=1;j<=end;j++){
			if (X[i] == j) cout << " Q ";
			else cout << " . ";
		}
		cout << endl;
	}
	cout << "-----------" << endl;
}

bool safe(int X[], int row){
	
	for (int i=1;i < row;i++){ 
		if ( abs(i-row) == abs(X[i] - X[row]) 
			|| X[row] == X[i]){
			return false;
		}
	}
	return true;
	
}

void permute(int X[], int start,int end){
	if (start > end){
		print(X,end);
		return;
	}
	
	for (int i=start ; i<=end; i++){
		swap(&X[start],&X[i]);
		if (safe(X,start)) permute(X,start+1,end);
		swap(&X[start],&X[i]);
	}
}

int main(){
	int n=4;
	int X[n+1];
	for (int i=1;i<=n;i++){
		X[i] = i;
	}
	
	permute(X,1,n);

	return 0;
}
