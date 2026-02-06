#include <stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

int a[] = {25,10,6,4};
int k = 10 , count = 0;

void print_sol(int x[], int n){
	for (int i=1;i<=n;i++){
		if (x[i] == 1){
			cout << a[i-1] << " ";
		}
	}
	cout << endl;
}

void subset1(int x[],int l,int r,int sum){

	if (sum == k){
		print_sol(x,r);
		return;
	}
	
	if (l==r) return;
	
	count++;
	
	if (sum > k) return;
	
	x[l+1] = 1;
	sum += a[l];
	subset1(x,l+1,r,sum);
	x[l+1] = 0;
	sum -= a[l];
	subset1(x,l+1,r,sum);
}

int main(){
	int n=4;
	int x[n+1];
	subset1(x,0,n,0);
	cout << "count = "<< count << endl; //6
	return 0;
}
