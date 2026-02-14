#include <iostream>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};

void merge(int a[],int l,int m,int r){
	int lnum = m-l +1; //5-2 = 3 - 2 3 4 5 (+1 = +m) = 4
	int rnum = r-m; // 10-5 = 5 - 6 7 8 9 10 (dont need m)
	int L[lnum] , R[rnum];
	
	for (int i=0;i<lnum;i++)
		L[i] = a[l+i];
	for (int j=0;j<rnum;j++)
		R[j] = a[m+1+j];
	
	int i = 0, j = 0 , k = l; //k = l start point to merge
	while (i<lnum && j<rnum){
		if (L[i] <= R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}
	
	while (i<lnum){ a[k++] = L[i++];}
	while (j<rnum){ a[k++] = R[j++];}
}

void mergeSort(int l,int r){
	if (l < r){
		int m = l + (r-l) /2 ; //miss boi
		mergeSort(l,m);
		mergeSort(m+1,r);
		merge(a,l,m,r);
	}
}

int main(){
	mergeSort(0,n-1);
	
	for (int i=0;i<n;i++){
		cout << a[i] << " ";
	}
}
