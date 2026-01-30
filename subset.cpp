#include <stdio.h>

void print_sol(int a[],int x[], int n,int target){
	int sum=0;
	for (int i=1;i<=n;i++){
		if (x[i] == 1){
			sum += a[i-1];
		}
	}
	if (sum == target){
		for (int i=1;i<=n;i++){
			if (x[i] == 1){
				printf("%d ",a[i-1]);
				if (i != n) printf("+ ");
			}
		}
		printf("= %d",sum);
	}
}

void subset1(int a[],int x[],int l,int r,int target){
	if (l==r){
		print_sol(a,x,r,target);
	} else {
		x[l+1] = 1;
		subset1(a,x,l+1,r,target);
		x[l+1] = 0;
		subset1(a,x,l+1,r,target);
	}
}

int main(){
	int n=3;
	int a[n] = {25,9,6};
	int x[n+1];
	
	subset1(a,x,0,n,15);
	return 0;
}
