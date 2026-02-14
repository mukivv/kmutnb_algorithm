#include <iostream>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
//slide code
int partition(int a[],int l,int r){
	int i=l+1,j=r;
	int p = a[l];
	do {
		while (a[i] <= p) i++;
		while (a[j] > p) j--;
		if (i < j) swap(&a[i],&a[j]);
	} while (i < j);
	swap(&a[l],&a[j]);
	return j;
}
//homework code
int partition2(int a[],int l,int r){
	int i=l,j=r+1;
	int p = a[l];
	do {
		do{ ++i; } while (a[i] <= p);
		do{ --j; } while (a[j] > p);
		swap(&a[i],&a[j]);
	} while (i < j);
	swap(&a[i],&a[j]); //undo last swap
	swap(&a[l],&a[j]);
	return j;
}

void quickSort(int a[],int l,int r){
	if (l < r){
		int p = partition2(a,l,r);
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
