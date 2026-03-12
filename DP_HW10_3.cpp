#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > memo(10000,vector<int>(10000,-1));

int p(int m,int n){
	if (m<1 || n<1) return 0;
	if (m==1 && n==1) return 1;
	if (memo[m][n] != -1) return memo[m][n];
	return memo[m][n] = p(m-1,n) + p(m,n-1);
}

int main(){
	int m,n;
	cin >> m >> n;
	cout << p(m,n);
}
