//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct {
//	char tenDV[25];
//	float TL,GT,DG;
//	int PA;
//}DoVat;
//
//DoVat *readFile(int *n,float *W){
//	FILE *f = fopen("CaiBalo3.txt","r");
//	if(f==NULL) printf("Loi mo file");
//	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
//	int i = 0;
//	fscanf(f,"%f",W);
//	while(!feof(f)){
//		fscanf(f,"%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDV);
//		dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
//		dsdv[i].PA = 0;
//		i++;
//		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
//	}
//	*n = i;
//	fclose(f);
//	return dsdv;
//}
//
//void swap(DoVat *x,DoVat *y){
//	DoVat temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void bubbleSort(DoVat *dsdv, int n){
//	for(int i = 0; i <= n-2; i++){
//		for(int j = n-1; j >= i+1; j--){
//			if(dsdv[j].DG> dsdv[j-1].DG){
//				swap(&dsdv[j],&dsdv[j-1]);
//			}
//		}
//	}
//}
//
//void print(DoVat *dsdv, int n, float W){
//	float TongTL, TongGT;
//	printf("Cai Balo 3 thuat toan tham an:\n");
//	printf("Trong luong cua cai balo: %.2f\n",W);
//	for(int i = 0; i < n; i++){
//		printf("STT: %d\n",i+1);
//		printf("Ten do vat: %s\n",dsdv[i].tenDV);
//		printf("Trong luong: %.2f\n",dsdv[i].TL);
//		printf("Gia tri: %.2f\n",dsdv[i].GT);
//		printf("Don Gia: %.1f\n",dsdv[i].DG);
//		printf("Phuong an: %d\n",dsdv[i].PA);
//		printf("---------------------------\n");
//		TongTL += dsdv[i].TL * dsdv[i].PA;
//		TongGT += dsdv[i].GT * dsdv[i].PA;
//	}
//	printf("Phuong an theo don gia giam dan: X(");
//	for(int i = 0; i < n-1; i++){
//		printf("%d,",dsdv[i].PA);
//	}
//	printf("%d)\n",dsdv[n-1].PA);
//	printf("Tong trong luong: %.2f\n",TongTL);
//	printf("Tong gia tri: %.2f\n",TongGT);
//}
//
//void greedy(DoVat *dsdv, int n,float W){
//	for(int i = 0; i < n; i++){
//		int pa = W / dsdv[i].TL;
//		if(pa > 0) dsdv[i].PA = 1;
//		else dsdv[i].PA = pa;
//		W -= dsdv[i].TL * dsdv[i].PA;
//	}
//}
//
//int main(){
//	int n;
//	float W;
//	DoVat *dsdv = readFile(&n,&W);
//	bubbleSort(dsdv,n);
//	greedy(dsdv,n,W);
//	print(dsdv,n,W);
//	free(dsdv);
//	return 0;
//}
//Cai Balo 3 thuat toan tham an:
//Trong luong cua cai balo: 30.00
//STT: 1
//Ten do vat:  Gao ST25
//Trong luong: 8.00
//Gia tri: 24.00
//Don Gia: 3.0
//Phuong an: 1
//---------------------------
//STT: 2
//Ten do vat:  Nep cai hoa vang
//Trong luong: 10.00
//Gia tri: 25.00
//Don Gia: 2.5
//Phuong an: 1
//---------------------------
//STT: 3
//Ten do vat:  Gao Mot bui
//Trong luong: 15.00
//Gia tri: 30.00
//Don Gia: 2.0
//Phuong an: 0
//---------------------------
//STT: 4
//Ten do vat:  Gao Tai nguyen
//Trong luong: 4.00
//Gia tri: 6.00
//Don Gia: 1.5
//Phuong an: 1
//---------------------------
//STT: 5
//Ten do vat:  Gao Nang huong
//Trong luong: 2.00
//Gia tri: 2.00
//Don Gia: 1.0
//Phuong an: 1
//---------------------------
//Phuong an theo don gia giam dan: X(1,1,0,1,1)
//Tong trong luong: 24.00
//Tong gia tri: 57.00

#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct{
	char tenDV[25];
	float TL,GT,DG;
	int PA;
}DoVat;

DoVat *readFile(int *n,float *W){
	FILE *f =fopen("CaiBalo3.txt","r");
	if(f==NULL) printf("Loi mo file");
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	fscanf(f,"%f",W);
	int i =0;
	while(!feof(f)){
		fscanf(f,"%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDV);
		dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n=i;
	fclose(f);
	return dsdv;
}

void swap(DoVat *x,DoVat *y){
	DoVat temp = *x;
	*x =  *y;
	*y= temp;
}

void bubbleSort(DoVat *dsdv,int n){
	for(int i = 0; i <= n-2; i++){
		for(int j = n-1; j >=i+1; j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}
}

int min(int a,int b){
	return a < b ?a:b;
}

void greedy(DoVat *dsdv,int n ,float W){
	for(int i = 0; i < n; i++){
		dsdv[i].PA = min(1,W/dsdv[i].TL);
		W = W - dsdv[i].PA * dsdv[i].TL;
	}
}

void inDS(DoVat *dsdv,int n,float W){
	float TongTL, TongGT;
	printf("Cai Balo 3 thuat toan tham an:\n");
	printf("Trong luong cua cai balo: %.2f\n",W);
	for(int i = 0; i < n; i++){
		printf("STT: %d\n",i+1);
		printf("Ten do vat: %s\n",dsdv[i].tenDV);
		printf("Trong luong: %.2f\n",dsdv[i].TL);
		printf("Gia tri: %.2f\n",dsdv[i].GT);
		printf("Don Gia: %.1f\n",dsdv[i].DG);
		printf("Phuong an: %d\n",dsdv[i].PA);
		printf("---------------------------\n");
		TongTL += dsdv[i].TL * dsdv[i].PA;
		TongGT += dsdv[i].GT * dsdv[i].PA;
	}
	printf("Phuong an theo don gia giam dan: X(");
	for(int i = 0; i < n-1; i++){
		printf("%d,",dsdv[i].PA);
	}
	printf("%d)\n",dsdv[n-1].PA);
	printf("Tong trong luong: %.2f\n",TongTL);
	printf("Tong gia tri: %.2f\n",TongGT);
}

int main(){
	int n;
	float W;
	DoVat *dsdv = readFile(&n,&W);
	bubbleSort(dsdv,n);
	greedy(dsdv,n,W);
	inDS(dsdv,n,W);
	free(dsdv);
	return 0;
}
