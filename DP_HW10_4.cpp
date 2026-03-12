#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

int sum(int n,int k){
	int s[n+1][k+1];
	for (int i=0;i<=n;i++){
		s[i][0] = 0;
	}
	
	for (int i=1;i<=k;i++){
		s[0][i] = 0;
	}
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k;j++){
			if (j < a[i]) s[i][j] = s[i-1][j]; //no
			else s[i][j] = max(s[i-1][j] , s[i-1][j-a[i]]+1); //no or yes
		}
	}
	
	return s[n][k];
}

int main(){
	int n,k;
	cin >> n >> k;
	a.resize(n+1);
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout << sum(n,k);
}
