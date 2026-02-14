#include <iostream>
#include <algorithm>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};
int k = 50;

int main(){
	for (int i=0;i<n-1;i++){
		int min = i;
		for (int j=i+1;j<n;j++){
			if (a[j] < a[min]) min = j;
		}
		swap(a[min],a[i]);
	}
	
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}
