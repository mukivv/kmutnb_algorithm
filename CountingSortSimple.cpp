#include <iostream>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};

void countingSort(int a[],int n,int S[]){
	int max = 0;
	for (int i=0;i<n;i++){
		if (a[i] > max) max = a[i];
	}
	
	int C[max+1] = {0};
	for (int i=0;i<n;i++){
		C[a[i]]++;
	}
	
	for (int i=1; i<=max; i++){
		C[i] += C[i-1];
	}
	
	for (int i=n-1;i>=0;i--){
		int index = C[a[i]]-1;
		S[index] = a[i];
		C[a[i]]--;
	}
}

int main(){
	int S[n];
	countingSort(a,n,S);
	for (int i=0;i<n;i++){
		cout << S[i] << " ";
	}
}
