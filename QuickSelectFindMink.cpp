#include <iostream>

using namespace std;

const int n = 9;
int a[n] = {1,5,10,4,8,2,6,9,20};
int k = 4;

void swap(int *a, int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int a[],int n,int l,int r){
	int m = l + (r-l)/2;
	if (a[l] > a[m]) swap(&a[l],&a[m]);
	if (a[m] > a[r]) swap(&a[m],&a[r]);
	if (a[l] > a[m]) swap(&a[l],&a[m]);
	
	swap(&a[m],&a[r]);
	//do partition of quick sort here
	//another way to partition
	int i=l,p=a[r],k=l;
	for (int j=l;j<r;j++){
		if (a[j]<=p) { // a <= p
			swap(&a[i],&a[j]); //swap to left
			i++; //move left
		}
	}
	swap(&a[r],&a[i]);
	return i;
}

int quickSelect(int a[],int l,int r,int k){
	int p = partition(a,n,l,r); //index pivot
	int L = p-l; // number of num in range L
	if (l==r) return a[l]; //have 1 num return that num
	if (k == L+1) return a[p];
	else if (k <= L) return quickSelect(a,l,p-1,k);
	else if (k > L+1) {
		k = k - (L+1);
		return quickSelect(a,p+1,r,k);
	}
}

int main(){
	cout << quickSelect(a,0,n-1,k);
}
