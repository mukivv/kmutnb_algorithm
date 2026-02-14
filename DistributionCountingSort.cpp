#include <iostream>

using namespace std;

const int n = 8;
int a[n] = {2,3,49,48,50,30,44,8};

void countingSort(int a[],int n,int S[]){
	int u=0; // u= max
	for (int i=0;i<n;i++){
		if (a[i] > u) u=a[i];
	}
	int l=u; // l = min
	for (int i=0;i<n;i++){
		if (a[i] < l) l=a[i];
	}
	
	int dn = u-l; // like n
	int D[dn+1] = {0};
	for (int i=0;i<n;i++){
		D[a[i]-l]++;
	}
	for (int i=1;i<=dn;i++){
		D[i]+=D[i-1];
	}
	for (int i=n-1;i>=0;i--){
		int index = a[i]-l;
		S[D[index]-1] = a[i];
		D[index]--;
	}
}

int main(){
	int S[n];
	countingSort(a,n,S);
	for (int i=0;i<n;i++){
		cout << S[i] << " " ;
	}
}
