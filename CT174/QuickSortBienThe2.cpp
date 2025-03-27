//  1    0   14.12
//  2   10   20.50
//  3   10    4.22
//  4   10   30.50
//  5   20    1.84
//  6   30    0.75
//  7   50    9.30
//  8   90   26.40
//  9   90   56.70
// 10  120    9.90
// 11  140   12.15
// 12  143    3.28


#include<stdio.h>
typedef int keytype;
typedef float othertype;

typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void readFile(recordtype a[],int *n){
	FILE *f = fopen("sapxep.txt","r");
	if(f==NULL) return;
	int i = 0;
	while(!feof(f)){
		fscanf(f,"%d%f",&a[i].key,&a[i].otherfields);
		i++;
	}
	fclose(f);
	*n = i;
}

void swap(recordtype *x,recordtype *y){
	recordtype temp = *x;
	*x = *y;
	*y = temp;
}

void print(recordtype a[],int n ){
	for(int i = 0; i < n; i++){
		printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].otherfields);
	}
}

int partition(recordtype a[],int i ,int j){
	int L = i + 1;
	int R = j;
	int p = a[i].key;
	while(L<=R){
		while(L<=R && a[L].key<=p){
			L++;
		}
		while(L<=R && a[R].key>=p){
			R--;
		}
		if(L<R) swap(&a[L],&a[R]);
	}
	swap(&a[R],&a[i]);
	return R;
}

void quickSort(recordtype a[],int i, int j){
	if(i<j){
	int k = partition(a,i,j);
	quickSort(a,i,k-1);
	quickSort(a,k+1,j);
    }
}

int main(){
	recordtype a[100];
	int n;
	readFile(a,&n);
	printf("Quick sort bien the\n\n");
	print(a,n);
	printf("\n\n\n");
	quickSort(a,0,n-1);
	print(a,n);
	return 0;
}
