#include <iostream>
#include <stdio.h>

using namespace std;

int n;

void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int l, int r) {
    int p = a[l];
    int i = l;
    
    for (int j = l+1; j <= r; j++) {
        if (a[j] < p) { 
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[l], &a[i]);
    return i;
}

void quickSort(int a[],int l,int r){
	if (l<r){
		int p = partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
	}
}

int main(){
	cin >> n;
	int f[n];
	for (int i=0;i<n;i++){
		cin >> f[i];
	}
	
	quickSort(f,0,n-1);
	int sum = 0;
	for (int i=0;i<n;i++)
		sum+=f[i]*(n-i);
	printf("%.2f",(double)sum/n);
	
}
