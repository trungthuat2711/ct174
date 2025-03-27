//  1    0   14.12
//  2   10   20.50
//  3   10   30.50
//  4   10    4.22
//  5   20    1.84
//  6   30    0.75
//  7   50    9.30
//  8   90   56.70
//  9   90   26.40
// 10  120    9.90
// 11  140   12.15
// 12  143    3.28


//#include<stdio.h>
//typedef int keytype;
//typedef float othertype;
//
//typedef struct{
//	keytype key;
//	 othertype otherfields;
//}recordtype;
//
//void readFile(recordtype a[],int*n){
//	FILE *f = fopen("sapxep.txt","r");
//	if(f==NULL) return;
//	int i = 0;
//	while(!feof(f)){
//		fscanf(f,"%d%f",&a[i].key,&a[i].otherfields);
//		i++;
//	}
//	fclose(f);
//	*n = i;
//} 
//
//void swap(recordtype *x,recordtype *y){
//	recordtype temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void print(recordtype a[],int n){
//	for(int i = 0; i < n; i++){
//		printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].otherfields);
//	}
//}
//
//int findPivot(recordtype a[],int i, int j){
//	int k = i + 1;
//	while(k <= j && a[k].key == a[i].key){
//		k++;
//	}
//	if(k>j) return -1;
//	if(a[k].key < a[i].key) return k;
//	else return i;
//}
//
//int partition(recordtype a[],keytype pivot,int i, int j){
//	int L = i;
//	int R = j;
//	while(L<=R){
//		while(a[L].key <= pivot) L++;
//		while(a[R].key > pivot) R--;
//		if(L<R) swap(&a[L],&a[R]);
//	}
//	return L;
//}
//
//void quickSort(recordtype a[],int i, int j){
//	int pivotIndex = findPivot(a,i,j);
//	if(pivotIndex==-1) return;
//	int k = partition(a,a[pivotIndex].key,i,j);
//	quickSort(a,i,k-1);
//	quickSort(a,k,j);
//}
//
//int main(){
//	recordtype a[100];
//	int n;
//	readFile(a,&n);
//	printf("quick sort bien the\n\n");
//	print(a,n);
//	printf("\n\n");
//	quickSort(a,0,n-1);
//	print(a,n);
//	return 0;
//}

#include<stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void readFile(recordtype a[],int *n){
	FILE*f = fopen("sapxep.txt","r");
	if(f==NULL) printf("Loi mo file");
	int i = 0;
	while(!feof(f)){
		fscanf(f,"%d%f",&a[i].key,&a[i].otherfields);
		i++;
	}
	*n = i;
	fclose(f);
}

void swap(recordtype *x,recordtype *y){
	recordtype temp = *x;
	*x = *y;
	*y = temp;
}

int findPivot(recordtype a[],int i ,int j){
	int first = i;
	int k = first +1;
	while(k <= j && a[k].key == a[first].key){
		k++;
	}
	if(k>j) return -1;
	if(a[k].key < a[first].key) return k;
	else return first;
}

int partition(recordtype a[],int pivot,int i,int j){
	int L = i;
	int R = j;
	while(L<=R){
		while(a[L].key <= pivot) L++;
		while(a[R].key > pivot) R--;
		if(L < R) swap(&a[L],&a[R]);
	}
	return L;
}

void quickSort(recordtype a[],int i,int j){
	int pivot = findPivot(a,i,j);
	if(pivot == -1) return;
	int k = partition(a,a[pivot].key,i,j);
	quickSort(a,i,k-1);
	quickSort(a,k,j);
}

void print(recordtype a[],int n){
	for(int i = 0; i < n; i++){
		printf("%5d%8.2f\n",a[i].key,a[i].otherfields);
	}
}

int main(){
	recordtype a[100];
	int n;
	readFile(a,&n);
	print(a,n);
	printf("\nThuat toan quick sort bien the\n");
	quickSort(a,0,n-1);
	print(a,n);
	return 0;	
}
