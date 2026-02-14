#include <iostream>

using namespace std;

const int n = 8;
int a[n] = {2,3,8,40,45,45,50,60};
int k = 45;

int findFirst(int a[],int n,int l,int r,int target){
	int i=l,j=r,ans=-1;
	while (l<=r){
		int mid = (l+r)/2;
		if (a[mid] == target){
			ans = mid;
			r = mid-1; //find to left
			//cut right so ( chose this (2) | 2 2 2)
			//findLast "l=mid+1"
			// cut left so ( 2 2 2 | (2) chose this)
		}
		else if (a[mid] < target) 
			l = mid+1;
		else
			r = mid-1;
	}
	return ans;
}

int findLast(int a[],int n,int l,int r,int target){
	int i=l,j=r,ans=-1;
	while (l<=r){
		int mid = (l+r)/2;
		if (a[mid] == target){
			ans = mid;
			l = mid+1; //find to right
			// cut left so ( 2 2 2 | (2) chose this)
		}
		else if (a[mid] < target) 
			l = mid+1;
		else
			r = mid-1;
	}
	return ans;
}

int count(int a[],int n,int target){
	int first = findFirst(a,n,0,n-1,target);
	if (first == -1) return 0;
	int last = findLast(a,n,0,n-1,target);
	return last-first+1;
}

int main(){
	cout << count(a,n,k);
}
