#include <bits/stdc++.h>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};
int k = 50;

int main(){
	for (int i=1;i<n;i++){
		int value = a[i];
		int j = i-1;
		while (j>=0 && a[j] > value){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = value;
	}
	
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}
