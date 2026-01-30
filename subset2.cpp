#include <stdio.h>

void print_sol(int a[],int x[], int l,int target){
	int sum=0;
	for (int i=1;i<=l;i++){
		sum += a[x[i]-1]; //x[i] = index
	}
	if (sum == target){
	
		for (int i=1;i<=l;i++){
			printf("%d ",a[x[i]-1]);
			if (i != l) printf("+ ");
		}
		printf("= %d",sum);
	}
}

void subset2(int a[],int x[],int l,int n,int target){
	print_sol(a,x,l,target);
	int j;
	if (l==0)
		j=1;
	else
		j = x[l]+1;
		
	for (int i=j;i<=n;i++){
		x[l+1] = i;
		subset2(a,x,l+1,n,target);
	}
}

int main(){
	int n=3;
	int a[n] = {25,9,6};
	int x[n+1];
	
	subset2(a,x,0,n,15);
	return 0;
}
