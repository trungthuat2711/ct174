//#include<stdio.h>
//typedef int keytype;
//typedef float othertype;
//
//typedef struct {
//	keytype key;
//	othertype otherfields;
//}recordtype;
//
//void readFile(recordtype a[],int *n){
//	FILE *f = fopen("sapxep.txt","r");
//	if(f==NULL){
//		printf("Loi mo file!");
//		return;
//	}
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
//int findPivot(recordtype a[],int i, int j){
//	int k = i+1;
//	while(k <= j && a[k].key==a[i].key){
//		k++;
//	}
//	if(k > j) return -1;
//	if(a[k].key > a[i].key) return k;
//	else return i;
//}
//
//int partition(recordtype a[],keytype pivot, int i, int j){
//	int L = i;
//	int R = j;
//	while(L<=R){
//		while(a[L].key < pivot){
//			L++;
//		}
//		while(a[R].key >= pivot){
//			R--;
//		}
//		if(L<R){
//			swap(&a[L],&a[R]); 
//		}
//	}
//	return L;	
//}
//
//void quickSort(recordtype a[],int i,int j){
//	int pivot = findPivot(a,i,j);
//	if(pivot == -1) return;
//	int k = partition(a,a[pivot].key,i,j);
//	quickSort(a,i,k-1);
//	quickSort(a,k,j);	
//} 
//
//void print(recordtype a[],int n){
//	for(int i = 0; i < n ; i++){
//		printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].otherfields);
//	} 	 
//} 
//int main(){
//	recordtype a[100];
//	int n;
//	readFile(a,&n);
//	print(a,n); 
//	printf("\n\n");
//	quickSort(a,0,n-1);
//	print(a,n); 
//} 




#include<stdio.h>
#include<string.h>
typedef int keytype;
typedef float othertype;

typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void readFile(recordtype a[],int *n){
	FILE *f = fopen("sapxep.txt","r");
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

int findPivot(recordtype a[],int i,int j){
	int first = i;
	int k = i+1;
	while(k <= j && a[k].key == a[first].key){
		k++;
	}
	if(k > j) return -1;
	if(a[k].key > a[first].key) return k;
	else return first;
}

int partition(recordtype a[],int pivot,int i,int j){
	int L = i;
	int R = j;
	while(L <= R){
		while(a[L].key < pivot) L++;
		while(a[R].key >= pivot) R--;
		if(L < R){
			swap(&a[L],&a[R]);
		}
	}
	return L;
}

void quickSort(recordtype a[],int i,int j){
	int pivot = findPivot(a,i,j);
	if(pivot == -1) return;
	else{
		int k = partition(a,a[pivot].key,i,j);
		quickSort(a,i,k-1);
		quickSort(a,k,j);
	}
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
	printf("\n");
	printf("Thuat toan quick sort\n\n");
	quickSort(a,0,n-1);
	print(a,n);
	return 0;
}
