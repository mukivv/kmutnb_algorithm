#include <iostream>
#include <vector>

using namespace std;

vector<int> memo(10000,-1);

int g(int n){
	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 1;
	for (int i=3;i<=n;i++){
		memo[i] = memo[i-1] + memo[i-2] - memo[i-3];
	}
	return memo[n];
}

int main(){
	int n;
	cin >> n;
	cout << g(n);
}
