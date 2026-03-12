#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> memo(10000,-1);

int sum(int n){
	if (n == 0) return 0;
	if (memo[n] != -1) return memo[n];
	int maxx = -1;
    for (int i = 1; i <= n; i++) {
        maxx = max(maxx, a[i] + sum(n - i));
    }
    return memo[n] = maxx;
}


int main(){
	int L;
	cin >> L;
	a.resize(L+1);
	for (int i=1;i<=L;i++){
		cin >> a[i];
	}
	cout << sum(L);
}
