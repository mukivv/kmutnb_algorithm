#include <stdio.h>

void print_sol(int w[],int v[],int x[], int n,int total[]){
	int sumW=0 , sumV = 0;
	for (int i=1;i<=n;i++){
		if (x[i] == 1){
			sumW += w[i-1];
			sumV += v[i-1];
		}
	}
	
	if (sumV > total[0] && sumW < 13){ //max kanpsack = 13
 		for (int i=1;i<=n;i++){
			if (x[i] == 1){
				printf("(%d,%d) ",w[i-1],v[i-1]);
			}
		}
		printf("=> (%d,%d)\n",sumW,sumV);
		
		total[0] = sumV;
		total[1] = sumW;
	}
}

void subset1(int w[],int v[],int x[],int l,int r,int total[]){
	if (l==r){
		print_sol(w,v,x,r,total);
	} else {
		x[l+1] = 1;
		subset1(w,v,x,l+1,r,total);
		x[l+1] = 0;
		subset1(w,v,x,l+1,r,total);
	}
}

int main(){
	int n=4;
	int w[n] = {5,3,8,4};
	int v[n] = {10,20,25,8};
	int x[n+1],total[2];
	
	subset1(w,v,x,0,n,total);
	printf("BestValue = %d , BestWeight = %d ",total[0],total[1]); // 0 value , 1 weight
	return 0;
}
