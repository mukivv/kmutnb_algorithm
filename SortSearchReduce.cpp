#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void merge(int a[],int l,int m,int r){
	int lnum = m-l+1 ,rnum = r-m;
	int L[lnum], R[rnum];
	
	for (int i=0;i<lnum;i++) L[i] = a[l+i];
	for (int i=0;i<rnum;i++) R[i] = a[m+1+i];
	
	int i=0,j=0,k=l;
	while(i<lnum && j<rnum){
		if (L[i] <= R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}
	
	while(i<lnum) a[k++] = L[i++];
	while(j<rnum) a[k++] = R[j++];
}

void mergeSort(int a[],int l,int r){
	if (l<r){
		int m = l + (r-l)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i=0;i<n;i++) cin >> a[i];
	mergeSort(a,0,n-1);
	stringstream ss;
	for (int i=0;i<n;i++){
		cout << a[i];
		ss << a[i]; //join num to string
	}
	cout << endl;
	string num = ss.str();
	
	int count[10] = {0};  // sum (0-9) not nub first
	for (int i=0;i<num.length()-1;i++){
		if (num[i] == num[i+1]){
			int digit = num[i] - '0';
			count[digit]++;
		}
	}
	
	int max = 0;
	for (int i=0;i<10;i++){
		if (count[i] >= max) max = count[i];
	}
	
	for (int i=0;i<10;i++){
		if (count[i] == max) cout << i << " ";
	}
	cout << endl;
	
	cout << num[0];
	for (int i=1;i<num.length();i++){
		if (num[i-1] == num[i]){
			continue;
		}
		else {
			cout << num[i];
		}
	}
}
