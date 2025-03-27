//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct{
//	char tenDV[20];
//	float TL,GT,DG;
//	int PA; 
//}DoVat;
//
//DoVat *readFile(int *n,float *W){
//	FILE *f = fopen("CaiBalo1.txt","r");
//	if(f==NULL) printf("Loi mo file!");
//	
//
//	fscanf(f,"%f",W);
//	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
//	int i = 0;
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
//void swap(DoVat *x, DoVat *y){
//	DoVat temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void bubbleSort(DoVat *dsdv, int n){
//	for(int i = 0; i <= n - 2; i++){
//		for(int j = n-1; j >= i + 1; j--){
//			if(dsdv[j].DG > dsdv[j-1].DG){
//				swap(&dsdv[j],&dsdv[j-1]);
//			}
//		}
//	}
//}
//
//void greedy(DoVat *dsdv,int n,float W){
//	for(int i = 0; i < n; i++){
//		dsdv[i].PA = W / dsdv[i].TL;
//		W -= dsdv[i].TL * dsdv[i].PA;
//	}
//}
//
//void print(DoVat *dsdv, int n,float W){
//	float TongGT = 0, TongTL = 0;
//	printf("Phuong an Cai ba lo 1 thuat toan tham an:\n");
//	printf("Trong luong cua cai balo: %.2f\n",W);
//	for(int i = 0; i < n; i++){
//		printf("-STT: %d\n",i+1);
//		printf("-Ten Do Vat: %s\n",dsdv[i].tenDV);
//		printf("-Trong Luong: %.2f\n",dsdv[i].TL);
//		printf("-Gia Tri: %.2f\n",dsdv[i].GT);
//		printf("-Don Gia: %.1f\n",dsdv[i].DG);
//		printf("-Phuong an: %d\n",dsdv[i].PA);
//		printf("----------------------------\n");
//		
//		TongGT += dsdv[i].GT * dsdv[i].PA;
//		TongTL += dsdv[i].TL * dsdv[i].PA;
//	}
//	printf("Phuong an theo Don gia giam dan: X(");
//	for(int i = 0; i < n; i++){
//		if(i!= n - 1){
//			printf("%d,",dsdv[i].PA);
//		}
//		else{
//			printf("%d)\n",dsdv[i].PA);
//		}
//	}
//	printf("Tong trong luong: %.2f\n",TongTL);
//	printf("Tong gia tri: %.2f\n",TongGT);
//	
//}
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
//Phuong an Cai ba lo 1 thuat toan tham an:
//Trong luong cua cai balo: 37.00
//-STT: 1
//-Ten Do Vat:  Nep cai hoa vang
//-Trong Luong: 10.00
//-Gia Tri: 25.00
//-Don Gia: 2.5
//-Phuong an: 3
//----------------------------
//-STT: 2
//-Ten Do Vat:  Gao Mot bui
//-Trong Luong: 15.00
//-Gia Tri: 30.00
//-Don Gia: 2.0
//-Phuong an: 0
//----------------------------
//-STT: 3
//-Ten Do Vat:  Gao Tai nguyen
//-Trong Luong: 4.00
//-Gia Tri: 6.00
//-Don Gia: 1.5
//-Phuong an: 1
//----------------------------
//-STT: 4
//-Ten Do Vat:  Gao Nang huong
//-Trong Luong: 2.00
//-Gia Tri: 2.00
//-Don Gia: 1.0
//-Phuong an: 1
//----------------------------
//Phuong an theo Don gia giam dan: X(3,0,1,1)
//Tong trong luong: 36.00
//Tong gia tri: 83.00
//

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	char tenDV[25];
	float TL,GT,DG;
	int PA;
}DoVat;

DoVat*readFile(int *n,float *W){
	FILE *f = fopen("CaiBalo1.txt","r");
	if(f==NULL) printf("Loi mo file");
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	fscanf(f,"%f",W);
	int i = 0;
	while(!feof(f)){
		fscanf(f,"%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDV);
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

void bubbleSort(DoVat *dsdv,int n){
	for(int i = 0; i <=n-2; i++){
		for(int j = n-1; j >=i+1; j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}
}

void greedy(DoVat *dsdv,int n,float W){
	for(int i = 0; i < n; i++){
		dsdv[i].PA = W /dsdv[i].TL;
		W = W - dsdv[i].PA * dsdv[i].TL;
	}
}

void inDS(DoVat *dsdv,int n,float W){
	printf("Phuong an cai balo 1 thuat toan tham an\n\n");
	printf("Trong luong cai balo: %.2f\n",W);
	float TongTL=0.0,TongGT = 0.0;
	for(int i = 0; i < n; i++){
		printf("- STT: %d\n",i+1);
		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
		printf("- Trong luong: %.2f\n",dsdv[i].TL);
		printf("- Gia tri: %.2f\n",dsdv[i].GT);
		printf("- Don Gia: %.1f\n",dsdv[i].DG);
		printf("- Phuong an: %d\n",dsdv[i].PA);
		printf("---------------------------\n");
		TongTL += dsdv[i].PA * dsdv[i].TL;
		TongGT += dsdv[i].PA * dsdv[i].GT;
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
