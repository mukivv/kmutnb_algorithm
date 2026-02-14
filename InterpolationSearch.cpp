#include <iostream>
#include <cmath>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};
int k = 50;

int inter(int a[],int l,int r,int k){
	if (l>r || k > a[r] || k < a[l]) return -1;
	// k gun out of range a[l] - a[r]
	
	if (a[r] == a[l]){ 
		if (k == a[l]) return l;
		else return -1;
	} // gun case(1 number) l == r & a[l] == a[r] so (divide 0)
	
	int x = l + (k-a[l]) * (r-l) / (a[r]-a[l]);
	// no need to use "floor" pud long int pud hai la
	
	if (k == a[x]) return x;
	else if (k < a[x]) return inter(a,l,x-1,k);
	else if (k > a[x]) return inter(a,x+1,r,k); 
	// use else d kwa else if
}
int main(){
	//sort asc
	inter(a,0,n-1,k);
}
