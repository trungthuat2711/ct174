//#include<stdio.h>
//typedef int keytype;
//typedef float othertype;
//
//typedef struct {
//	keytype key;
//	othertype otherfields;
//}recordtype;
//
//void readFile(recordtype a[], int *n){
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
//void swap(recordtype *x, recordtype *y){
//	recordtype temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void print(recordtype a[], int n){
//	for(int i = 0 ; i < n; i++){
//		printf("%3d%5d%8.2f\n",i+1,a[i].key,a[i].otherfields);
//	}
//}
//
//void pushDown(recordtype a[],int first, int last){
//	int r = first;
//	// kiem tra la nut trong [0 - > (n-2)/2]
//	while(r <= (last-1)/2){
//		// neu co 1 con trai 
//		if(last == 2*r+1){
//			if(a[r].key > a[2*r+1].key){
//				swap(&a[r],&a[2*r+1]);
//			}
//			r = last;
//		}
//		// neu co 2 con, con trai >= con phai
//		else if(a[r].key > a[2*r+1].key && a[2*r+1].key <= a[2*r+2].key){
//			swap(&a[r],&a[2*r+1]);
//			r = 2*r+1;
//		}
//		// neu co 2 con, con phai > con trai
//		else if(a[r].key > a[2*r+2].key && a[2*r+2].key < a[2*r+1].key){
//			swap(&a[r],&a[2*r+2]);
//			r = 2*r+2;		
//		}
//		// da dung thu tu 
//		else{
//			r = last; 
//		} 
//	}
//}
//
//void heapSort(recordtype a[],int n){
//	//push down nut trong tu [(n-2)/2 -> 0]
//	for(int i = (n-2)/2; i >= 0 ; i--){
//		pushDown(a,i,n-1);
//	}
//	//day nut goc a[0] xuong nut la cuoi -> xoa nut la cuoi
//	//push down sau khi xoa nut la cuoi
//	//lap lai den khi mang con 2 phan tu a[0] a[1]
//	for(int i = n-1; i >= 2; i--){
//		swap(&a[0],&a[i]);
//		pushDown(a,0,i-1);
//	}
//	//khi con 2 phan tu a[0] a[1] thi hoan vi no
//	swap(&a[0],&a[1]);
//} 
//
//int main(){
//	recordtype a[100];
//	int n ;
//	readFile(a,&n);
//	printf("Thuat toan Heap Sort\n\n");
//	printf("truoc khi sap xep:\n");
//	print(a,n);
//	printf("\n\n");
//	printf("sau khi sap xep:\n");
//	heapSort(a,n);
//	print(a,n);
//	return 0;
//}
//
//sau khi sap xep:
//  1  143    3.28
//  2  140   12.15
//  3  120    9.90
//  4   90   56.70
//  5   90   26.40
//  6   50    9.30
//  7   30    0.75
//  8   20    1.84
//  9   10   30.50
// 10   10    4.22
// 11   10   20.50
// 12    0   14.12


#include<stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;

void readFile(recordtype a[],int *n){
	FILE *f = fopen("sapxep.txt","r");
	if(f==NULL) printf("Loi mo file");
	int i =0;
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

void print(recordtype a[],int n){
	for(int i = 0; i < n; i++){
		printf("%5d%8.2f\n",a[i].key,a[i].otherfields);
	}
}

void pushDown(recordtype a[],int first,int last){
	int r = first;
	//kiem tra r la nut trong 0 -> (n-2)/2
	while(r <= (last-1)/2){
		//r co 1 con trai
		if(last == 2*r+1){
			if(a[r].key > a[last].key){
				swap(&a[r],&a[last]);
			}
			r = last; // do r chi co 1 con trai sau khi pushdown k can ktra lai
		}
		//r co tu 2 con 
		else if(a[r].key > a[2*r+1].key && a[2*r+1].key <= a[2*r+2].key){
			swap(&a[r],&a[2*r+1]);
			r = 2*r+1; // r co 2 con nen sau khi pushdown can ktra nut con cua r.
		}
		else if(a[r].key > a[2*r+2].key && a[2*r+2].key < a[2*r+1].key){
			swap(&a[r],&a[2*r+2]);
			r = 2*r+2; // r co 2 con nen sau khi pushdown can ktra nut con cua r.
		}
		else{
			r = last; // r da dung thu tu.
		}
	}
}

void heapSort(recordtype a[],int n){
	//pushdown tu nut trong (n-2)/2 -> 0
	for(int i = (n-2)/2; i >= 0; i--){
		pushDown(a,i,n-1);
	}
	
	//sau khi cay dung thu tu hoan doi nut goc a[0] -> nut la cuoi a[n-1]
	//pushdown lai cay sau khi bo di a[n-1]
	//lap lai den khi cay con 2 nut a[0] a[1]
	for(int i = n-1; i >= 2; i--){
		swap(&a[0],&a[i]);
		//pushdown lai nut 0 -> n-1
		pushDown(a,0,i-1);
	}
	
	//doi cho 2 nut cuoi a[0] a[1]
	swap(&a[0],&a[1]);
}

int main(){
	recordtype a[100];
	int n;
	readFile(a,&n);
	print(a,n);
	printf("\nthuat toan heap sort\n");
	heapSort(a,n);
	print(a,n);
	return 0;
}
