#include <iostream>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};

void swap(int *a , int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void medianOf3(int a[],int l,int r){
	int m = (l+r)/2;
	if (a[l] > a[m]) swap(&a[l],&a[m]); // 2 >= 1
	if (a[m] > a[r]) swap(&a[r],&a[m]); //3 >= 2
	if (a[l] > a[m]) swap(&a[l],&a[m]); // 2 >= 1
	swap(&a[m],&a[r]);
}

int partition(int a[],int l,int r){
	medianOf3(a,l,r);
	int p = a[r] , i=l , j=r-1;
	do {
		while (a[i] <= p) i++;
		while (a[j] > p) j--;
		if (i<j) swap(&a[i],&a[j]);
	} while (i<j);
	swap(&a[r],&a[i]); //use a[r] use i
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
	quickSort(a,0,n-1);
	
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}

