#include <iostream>

using namespace std;

void print(int A[],int x[],int n,int total){
	int sum = 0;
	for (int i=1;i<=n;i++){
		if (x[i] == 1){
			sum += A[i-1];
		}
	}
	
	if (sum == total){
		for (int i=1;i<=n;i++){
			if (x[i] == 1)
				cout << A[i-1] << " ";
		}
		cout << endl;
	}
}

void subset(int A[],int x[],int l, int r, int total){
	if (l==r) {
		print(A,x,r,total);
	} else {
		x[l+1] = 1;
		subset(A,x,l+1,r,total);
		x[l+1] = 0;
		subset(A,x,l+1,r,total);
	}
}

int main(){
	int total;
	cin >> total;
	
	int n = 5 , A[n] , x[n+1];
	for (int i=0;i<n;i++){
		cin >> A[i];
	}

	subset(A,x,0,n,total);
	
}
