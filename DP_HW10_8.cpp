#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<vector<int> > memo;

int sum(int n,int k){
	if (k == 0) return 1;
	if (n<0 || k<0) return 0;
	if (memo[n][k] != -1) return memo[n][k];
    return memo[n][k] = sum(n,k-a[n]) + sum(n-1,k);
}


int main(){
	int n,k;
	cin >> n >> k;
	a.resize(k);
	memo.assign(k,vector<int>(n+1,-1));
	for (int i=0;i<k;i++){
		cin >> a[i];
	}
	cout << sum(k-1,n);
}
