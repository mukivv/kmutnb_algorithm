#include <iostream>

using namespace std;

void print(int a[],int n){
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}


int main(){
	int n;
	cin >> n;
	int A[n], B[n],U[n*2],I[n*2];
	
	for (int i=0;i<n;i++) cin >> A[i];
	for (int i=0;i<n;i++) cin >> B[i];
	
	//// intersection ////
	int i=0,j=0,ik=0;
	while (i < n){
		if (A[i] == B[j]){
			I[ik++] = A[i++];
			j=0;
		}
		else if (A[i] != B[j] && j == n){
			i++;
			j=0;
		}
		else j++;
	}
	
	print(I,ik); 
	cout << endl;
	//// union ////
	i=0;j=0;
	int uk=0;
	print(A,n); 
	// if want to duck A sum edit here
	// or change to CHECK code
	if (ik != n){
		while (i < n){
			if (B[i] == I[j]){
				i++;
				j=0;
			}
			else if (j==ik){
				I[ik++] = B[i]; //if B sum nai tua
				U[uk++] = B[i++];
				j=0;
			}
			else j++;
		}
		print(U,uk);
	}
}
