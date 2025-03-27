//#include<stdio.h>
//typedef int keytype;
//typedef float othertype;
//
//typedef struct{
//	keytype key;
//	othertype otherfields;
//}recordtype;
//
//void readFile(recordtype a[],int *n){
//	FILE *f = fopen("sapxep.txt","r");
//	if(f==NULL){
//		printf("loi mo file!");
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
//void bubbleSort(recordtype a[],int n){
//	for(int i = 0; i <= n - 2; i++){
//		for(int j = n-1; j > i; j--){
//			if(a[j].key < a[j-1].key){
//				swap(&a[j], &a[j-1]);
//			}
//		}
//	}
//}
//
//void print(recordtype a[],int n ){
//	printf("|---|-----|--------------------|\n");
//	printf("|STT| KEY |    otherfields     |\n");
//	printf("|---|-----|--------------------|\n");
//	for(int i = 0 ; i < n; i++ ){
//		printf("|%2d |%4d |%12.2f        |\n",(i+1),a[i].key,a[i].otherfields);
//	}	
//	printf("|---|-----|--------------------|\n");
//}
//int main(){
//	recordtype a[100];
//	int n;
//	readFile(a,&n);
//	printf("-------------------- Thuat toan Bubble sort --------------------\n\n");
//	printf("Du lieu truoc khi sap xep:\n");
//	print(a,n);
//	printf("\n\n");
//	printf("Du lieu sau khi sap xep:\n");
//	bubbleSort(a,n);
//	print(a,n);
//	return 0;
//}
//
//
//    0   14.12
//   10   20.50
//   10   30.50
//   10    4.22
//   20    1.84
//   30    0.75
//   50    9.30
//   90   56.70
//   90   26.40
//  120    9.90
//  140   12.15
//  143    3.28
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

void swap(recordtype *x, recordtype *y){
	recordtype temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(recordtype a[],int n){
	for(int i = 0; i <= n-2; i++){
		for(int j = n-1; j >= i+1; j--){
			if(a[j].key < a[j-1].key){
				swap(&a[j],&a[j-1]);
			}
		}
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
	printf("\nThuat Toan Bubble Sort\n");
	bubbleSort(a,n);
	print(a,n);
	return 0;
}
