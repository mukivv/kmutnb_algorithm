#include <iostream>

using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};
int k = 50;

void shellSort(){
	for (int k=n/2;k>=1;k=k/2){
		for (int i=k;i<n;i++){
			int value = a[i];
			int j=i;
			for (;j>=k && a[j-k]>value;j-=k)
				a[j] = a[j - k];
			a[j] = value;
		}
	}
}

void reShell(int a[], int n, int k) {
    if (k == 0) return;
    for (int i = k; i < n; i++) {
        int value = a[i];
        int j=i;
        for (;j>=k && a[j-k]>value;j-=k)
            a[j] = a[j-k];
        a[j] = value;
    }
    reShellSort(a,n,k/2);
}

int main(){
	shellSort();
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}
