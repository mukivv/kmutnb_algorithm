#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n] , sort[n];
	for (int i=0;i<n;i++) cin >> a[i];
	
	//distribution counting//
	int u = 0;
	for (int i=0;i<n;i++){
		if (a[i] > u) u = a[i];
	}
	int l = u;
	for (int i=0;i<n;i++){
		if (a[i] < l) l = a[i];
	}
	
	int dn = u-l , D[dn+1] = {0};
	for (int i=0;i<n;i++){
		D[a[i]-l]++;
	}
	for (int i=1;i<=dn;i++){
		D[i]+=D[i-1];
	}
	for (int i=n-1;i>=0;i--){
		int index = a[i]-l;
		sort[D[index]-1] = a[i];
		D[index]--;
	}
	
	for (int i=0;i<n;i++){
		a[i] = sort[i];
	}
	
	///////
	stringstream ss;
	for (int i=0;i<n;i++){
		cout << a[i];
		ss << a[i];
	}
	cout << endl;
	string s = ss.str();
	
	int freq[10] = {0}; //0-9
	for(int i=0;i<s.length()-1;i++){
		if (s[i] == s[i+1]){
			int digit = s[i]-'0';
			freq[digit]++;
		}
	}
	
	int max=0;
	for(int i=0;i<10;i++){
		if (freq[i] >= max){
			max = freq[i];
		}
	}
	
	for(int i=0;i<10;i++){
		if (freq[i] == max){
			cout << i << " ";
		}
	} cout << endl;
	
	cout << s[0];
	for (int i=1;i<s.length();i++){
		if (s[i-1] == s[i]) continue;
		else cout << s[i];
	}
}
