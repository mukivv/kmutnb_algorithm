#include <stdio.h>

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_sol(int X[], int start,int end){
	int count=0;
	
	for (int i=1;i<end;i++){ //check 1&3 tid gun - check start & next until end-1 & end
		if ( (X[i] == 1 && X[i+1]==3) || (X[i] == 3 && X[i+1]==1) ){
			count++;
		}
	}
	
	if (count == 0){ // if mai tid gun = print
		for (int i=1;i<=end;i++){
			printf("%d",X[i]);
		}
		printf("\n");
		X[0]++;
	}
}

void permute(int X[], int start,int end){
	if (start == end){
		print_sol(X,start,end);
		return;
	}
	
	for (int i=start;i<= end;i++){
		swap(&X[start],&X[i]);
		permute(X,start+1,end);
		swap(&X[start],&X[i]);
	}
}

int main(){
	int n=5;
	int X[] = {0 , 1 , 2 , 3 , 4,5};
	
	permute(X,1,n);
	printf("\ncount = %d",X[0]);
	return 0;
}
