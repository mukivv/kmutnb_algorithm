#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > memo;
int maxW = 7,num = 4;
int w[5] = {-1,1,3,4,5};
int v[5] = {-1,1,4,5,7};

int sum(int n,int W){
	if (n==0 || W==0) return 0;
	if (memo[n][W] != -1) return memo[n][W];
	
	if (W < w[n]) memo[n][W] = sum(n-1,W); //no
	else memo[n][W] = max(v[n] + sum(n-1,W-w[n]) , sum(n-1,W)); //y or n
	return memo[n][W];
}

int main(){
	memo.assign(num+1,vector<int>(maxW+1,-1));
	cout << sum(num,maxW);
}
