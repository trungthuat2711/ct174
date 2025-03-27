//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct{
//	char tenDV[25];
//	float TL,GT,DG;
//	int SL,PA;
//}DoVat;
//
//DoVat*readFile(int *n, float *W){
//	FILE *f = fopen("CaiBalo2.txt","r");
//	if(f==NULL) printf("Loi mo file");
//	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
//	fscanf(f,"%f",W);
//	int i = 0;
//	while(!feof(f)){
//		fscanf(f,"%f%f%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].tenDV);
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
//void swap(DoVat *x, DoVat *y){
//	DoVat temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void bubbleSort(DoVat *dsdv, int n){
//	for(int i = 0; i <= n - 2; i++){
//		for(int j = n - 1; j >= i+1; j--){
//			if(dsdv[j].DG > dsdv[j-1].DG){
//				swap(&dsdv[j],&dsdv[j-1]);
//			}
//		}
//	}
//}
//
//void greedy(DoVat *dsdv, int n, float W ){
//	for(int i = 0; i < n; i++){
//		int pa = W / dsdv[i].TL;
//		if(pa>=dsdv[i].SL){
//			dsdv[i].PA = dsdv[i].SL;
//		}
//		else{
//			dsdv[i].PA = pa;
//		}
//		W -= dsdv[i].TL * dsdv[i].PA;
//	}
//}
//
//
//void print(DoVat *dsdv, int n, float W){
//	float TongTL = 0, TongGT = 0;
//	printf("Phuong an Cai ba lo 2 thuat toan tham an:\n");
//	printf("Trong luong cua cai balo: %.2f\n",W);
//	for(int i = 0; i < n; i++){
//		printf("- STT: %d\n",i+1);
//		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
//		printf("- Trong luong: %.2f\n",dsdv[i].TL);
//		printf("- Gia tri: %.2f\n",dsdv[i].GT);
//		printf("- So luong: %d\n",dsdv[i].SL);
//		printf("- Don gia: %.1f\n",dsdv[i].DG);
//		printf("- Phuong an: %d\n",dsdv[i].PA);
//		printf("-------------------------------\n");
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
//
//Phuong an Cai ba lo 2 thuat toan tham an:
//Trong luong cua cai balo: 47.00
//- STT: 1
//- Ten do vat:  Gao ST25
//- Trong luong: 8.00
//- Gia tri: 24.00
//- So luong: 2
//- Don gia: 3.0
//- Phuong an: 2
//-------------------------------
//- STT: 2
//- Ten do vat:  Nep cai hoa vang
//- Trong luong: 10.00
//- Gia tri: 25.00
//- So luong: 1
//- Don gia: 2.5
//- Phuong an: 1
//-------------------------------
//- STT: 3
//- Ten do vat:  Gao Mot bui
//- Trong luong: 15.00
//- Gia tri: 30.00
//- So luong: 5
//- Don gia: 2.0
//- Phuong an: 1
//-------------------------------
//- STT: 4
//- Ten do vat:  Gao Tai nguyen
//- Trong luong: 4.00
//- Gia tri: 6.00
//- So luong: 2
//- Don gia: 1.5
//- Phuong an: 1
//-------------------------------
//- STT: 5
//- Ten do vat:  Gao Nang huong
//- Trong luong: 2.00
//- Gia tri: 2.00
//- So luong: 3
//- Don gia: 1.0
//- Phuong an: 1
//-------------------------------
//Phuong an theo don gia giam dan: X(2,1,1,1,1)
//Tong trong luong: 47.00
//Tong gia tri: 111.00

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	char tenDV[25];
	float TL,GT,DG;
	int SL,PA;
}DoVat;

DoVat *readFile(int *n,float *W){
	FILE *f = fopen("Caibalo2.txt","r");
	if(f==NULL) printf("Loi mo file");
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	fscanf(f,"%f",W);
	int i = 0;
	while(!feof(f)){
		fscanf(f,"%f%f%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].tenDV);
		dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void swap(DoVat *x,DoVat *y){
	DoVat temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(DoVat *dsdv,int  n){
	for(int i = 0; i <= n-2; i++){
		for(int j = n-1; j>=i+1;j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}
}

int min(int a,int b){
	return a <b ? a: b;
}

void greedy(DoVat *dsdv,int n,float W){
	for(int i = 0; i < n; i++){
		dsdv[i].PA = min(dsdv[i].SL,W/dsdv[i].TL);
		W = W - dsdv[i].PA * dsdv[i].TL;
	}
}

void inDS(DoVat *dsdv,int n,float W){
	float TongTL = 0, TongGT = 0;
	printf("Phuong an Cai ba lo 2 thuat toan tham an:\n");
	printf("Trong luong cua cai balo: %.2f\n",W);
	for(int i = 0; i < n; i++){
		printf("- STT: %d\n",i+1);
		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
		printf("- Trong luong: %.2f\n",dsdv[i].TL);
		printf("- Gia tri: %.2f\n",dsdv[i].GT);
		printf("- So luong: %d\n",dsdv[i].SL);
		printf("- Don gia: %.1f\n",dsdv[i].DG);
		printf("- Phuong an: %d\n",dsdv[i].PA);
		printf("-------------------------------\n");
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
	return 0;
}
