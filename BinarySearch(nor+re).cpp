#include <iostream>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};
int k = 50;

int binary(){
	int l=0,r=n-1;
	
	while (l <= r){ // have = for check last (ex. have l=r=0 should check k==a[0]? )
		int mid = (l + r)/2;
		if (k == a[mid]) return mid;
		else if (k < a[mid]) r = mid-1; // k noi cut right
		else if (k > a[mid]) l = mid+1; // k mak cut left
	}
	return -1;
}

int b(int a[],int l,int r,int k){
	
	if (l > r) return -1;
	int mid = (l + r)/2;
	
	if (k == a[mid]) return mid;
	else if (k < a[mid]) return b(a,l,mid-1,k); // k noi cut right
	else if (k > a[mid]) return b(a,mid+1,r,k); // k mak cut left
}

int main(){
	//sort asc
	binary();
	b(a,0,n-1,k);
}
