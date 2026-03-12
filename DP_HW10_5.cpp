#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > memo(1000,vector<int> (1000,-1));

int p(int i,int j){
	if (i==0) return 3*j;
	if (j==0) return 2*i;
	if (memo[i][j] != -1) return memo[i][j];
	return memo[i][j] = min( p(i-1,j)+2, min(p(i,j-1)+3, p(i-1,j-1)+2*i+j));
}

int main(){
	int i,j;
	cin >> i >> j;
	cout << p(i,j);
}
