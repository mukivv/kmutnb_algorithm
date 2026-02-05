#include <stdio.h>
#include <iostream>
using namespace std;

int rope;
int mincut = 999999;

void print(int a[],int x[], int l){
	int cut = 0 ;
	int r = rope;
	for (int i=l; i>=1 && r>=0 ;){
		if (r - a[x[i]-1] < 0) i--;
		else {
			r -= a[x[i]-1];
			cut++;
		}
	}
	
	if (r == 0 && cut < mincut) mincut = cut;
}

void subset2(int a[],int x[],int l,int n){
	print(a,x,l);
	int j;
	if (l==0)
		j=1;
	else
		j = x[l]+1;
		
	for (int i=j;i<=n;i++){
		x[l+1] = i;
		subset2(a,x,l+1,n);
	}
}

int main(){
	int n=3;
	int a[n],x[n+1];
	cin >> rope;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	
	subset2(a,x,0,n);
	cout << mincut << endl;
	return 0;
}
