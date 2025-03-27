#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef int keytype;
typedef float othertype;

typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void readFile(recordtype a[],int *n){
	FILE *f;
	f = fopen("sapxep.txt","r");
	if(f==NULL){
		printf("LOI MO FILE!");
		return;
	}
	int i = 0;
	while(!feof(f)){
		fscanf(f,"%d%f",&a[i].key,&a[i].otherfields);
		i++;
	}
	fclose(f);
	*n = i;
	printf("%d\n\n",*n); 
} 

void swap(recordtype *x,recordtype *y){
	recordtype temp = *x;
    *x = *y;
	*y = temp;	
}


void insertionSort(recordtype a[],int n){
	for(int i = 1; i < n ; i++){
		int j = i;
		while(j>0 && a[j].key < a[j-1].key){
			swap(&a[j],&a[j-1]);
			j--;
		}
	}	
}

void print(recordtype a[],int n){
	printf("|-----|-----|-------------|\n");
	printf("| STT | Key | Otherfields |\n");
	printf("|-----|-----|-------------|\n");
	for(int i = 0; i < n; i++){
		printf("|%3d  |%4d |%8.2f     |\n",(i+1),a[i].key,a[i].otherfields);
	}
	printf("|-----|-----|-------------|\n");
}

int main(){
	recordtype a[100];
	int n;
	readFile(a,&n);
	printf("-------------------- Thuat toan insertion sort -------------------\n\n");
	printf("Du lieu truoc khi sap xep:\n");
	print(a,n);
	printf("\n\n");
	insertionSort(a,n);
	printf("Du lieu sau khi sap xep:\n");
	print(a,n);
	return 0;
}



//#include<stdio.h>
//#include<string.h>
//typedef int keytype;
//typedef float othertype;
//typedef struct{
//	keytype key;
//	othertype otherfields;
//}recordtype;
//
//void readFile(recordtype a[],int *n){
//	FILE *f = fopen("sapxep.txt","r");
//	if(f == NULL) printf("Loi mo file");
//	int i = 0 ;
//	while(!feof(f)){
//		fscanf(f,"%d%f",&a[i].key,&a[i].otherfields);
//		i++;
//	}
//	*n = i;
//    fclose(f);
//}
//
//void swap(recordtype *x,recordtype *y){
//	recordtype temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void insertionSort(recordtype a[],int n){
//	for(int i = 1; i < n; i++){
//		int j = i;
//		while(j > 0 && a[j].key < a[j-1].key ){
//			swap(&a[j],&a[j-1]);
//			j--;
//		}
//	}
//}
//
//void print(recordtype a[],int n){
//	for(int i = 0; i < n; i++){
//		printf("%4d%8.2f\n",a[i].key,a[i].otherfields);
//	}
//}
//
//int main(){
//	recordtype a[100];
//	int n;
//	readFile(a,&n);
//	print(a,n);
//	printf("\n");
//	insertionSort(a,n);
//	printf("Thuat toan insertion sort\n\n");
//	print(a,n);
//	return 0;
//}
