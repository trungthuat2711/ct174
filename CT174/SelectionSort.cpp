//#include<stdio.h>
//#include<malloc.h>
//
//
//typedef int keytype;    
//typedef float othertype;
//
//typedef struct{
//	keytype key;
//	othertype otherfields;
//}recordtype;
//
//
//void Swap(recordtype *x, recordtype *y){
//	recordtype temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void SelectionSort(recordtype a[], int n){
//	for(int i = 0; i <= n - 2; i++){
//		int lowindex = i;
//		int lowkey = a[i].key;
//		for(int j = i + 1; j <= n - 1; j++){
//			if(a[j].key < lowkey){
//				lowkey = a[j].key;
//				lowindex = j;
//			}
//		}
//		Swap(&a[i],&a[lowindex]);
//	}
//}
//
//
//void read_file(recordtype a[], int *n){
//	FILE *f;
//	int i = 0;
//	f = fopen("sapxep.txt","r");   
//	if(f==NULL){
//		printf("Loi mo file");
//	}
//	else{
//		while(!feof(f)){
//			
//			fscanf(f,"%d%f",&a[i].key,&a[i].otherfields);
//			i++;
//		}
//	}
//	fclose(f); 
//	
//	*n = i; 
//}
//
// 
//void print_data(recordtype a[], int n){
//	for(int i = 0; i < n; i++){
//		printf("%d%5d%8.2f\n",(i+1),a[i].key,a[i].otherfields);
//	}
//}
//
//int main()
//    recordtype a[100];
//	int n;
//	printf("--------------------Thuat toan selection sort--------------------\n\n");
//	printf("Du lieu ban dau\n");
//	read_file(a,&n);
//	print_data(a,n);
//	printf("\n"); 
//	printf("Du lieu sau khi sap xep\n");
//	SelectionSort(a,n);
//	print_data(a,n);
//	return 0;
//}





#include<stdio.h>
#include<string.h>

typedef int keytype;
typedef float othertype;

typedef struct {
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

void selectionSort(recordtype a[],int n){
	for(int i = 0 ; i <= n-2; i++){
		int lowindex = i;
		int lowvalue = a[i].key;
		for(int j = i+1; j <= n-1; j++){
			if(a[j].key < lowvalue){
				lowvalue = a[j].key;
				lowindex = j;
			}
		}
		swap(&a[i],&a[lowindex]);
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
	printf("Thuat toan selection sort\n\n");
	print(a,n);
	printf("\n");
	selectionSort(a,n);
	print(a,n);
	return 0;
}
