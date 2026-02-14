#include <iostream>
#include <cmath>
int a[] = {10,12,15,17,18,20,25};
int M=20,k=2,n=7;
using namespace std;

int main(){
	int index=-1;
	for (int i=0;i<n;i++){
		if (a[i] == M) index = i;
	}
	if (index == -1) return 0;
	int l=index-1,r=index;
	
	while(r-l<=k){
		cout << l << " " << r << endl;
		if (abs(a[l]-M) > abs(a[r]-M))
			r++;
		else l--;
	}
	
	for (int i=l+1;i<=r;i++){
		if (i==index) continue;
		else cout << a[i] << " ";
	}
}
