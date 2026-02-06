#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int count = 0;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int X[], int end){
	bool flag = true;
	
	for (int i=1;i<=end;i++){
		for (int j=1;j < i;j++){ 
			if ( abs(i-j) == abs(X[i] - X[j]) 
				|| X[j] == X[i]) flag=false;
		}
	}
	
	if (flag) cout << "******* ";
	
	for (int i=1;i<=end;i++){
		cout << X[i]-1 << " ";
	}
	cout << endl;
	
	count++;
}

void permute(int X[], int start,int end){
	if (start > end){
		print(X,end);
		return;
	}
	
	for (int i=start ; i<=end; i++){
		swap(&X[start],&X[i]);
		permute(X,start+1,end);
		swap(&X[start],&X[i]);
	}
}

int main(){
	int n=4 , X[n+1];

	for (int i=1;i<=n;i++){
		X[i] = i;
	}
	
	permute(X,1,n);
	cout << endl;
	cout << count << endl;
	return 0;
}
