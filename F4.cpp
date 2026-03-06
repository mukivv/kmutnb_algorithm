#include <iostream>
#include <vector>

using namespace std;

struct F4 {
	vector<int> memo;
	
	F4(int n){
		memo.assign(n+1,-1); //n+1 for 0-n
	}
	
	int ref(int n){
		if (n==0) return 1;
		return ref(n-1)+ ref(n/2);
	}

	int tdf(int n){ //1
		if (n==0) return 1;
		if (memo[n] != -1) return memo[n];
		return memo[n] = tdf(n-1) + tdf(n/2);
	}

	int buf(int n){ //2
		memo[0] = 1;
		for (int i=1;i<n;i++)
			memo[i] = memo[i-1] + memo[i/2];
		return memo[n];
	}
	
};

int main(){
	int n=20;
	F4 f(n);
	cout << f.ref(n) << endl;
	cout << f.tdf(n) << endl;
	cout << f.buf(n);
}
