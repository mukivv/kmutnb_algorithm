#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > memo(10000,vector<int>(10000,-1));

int f(int n,int k){
	if (k < 2 || n==k) return 1;
	if (memo[n][k] != -1) return memo[n][k];
	return memo[n][k] = f(n-1,k) + f(n-1,k-2);
}

int main(){
	int n,k;
	cin >> n >> k;
	if (n>=k) cout << f(n,k);
}
