//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct {
//	char tenDV[25];
//	int TL,GT,SL,PA;
//}DoVat;
//
//typedef int bang[50][100];
//
//DoVat*readFile(int *n,int *W){
//	FILE *f = fopen("CaiBalo2_QHD.txt","r");
//	if(f==NULL) printf("Loi mo file");
//	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
//	fscanf(f,"%d",W);
//	int i = 0;
//	while(!feof(f)){
//		fscanf(f,"%d%d%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].tenDV);
//		dsdv[i].PA = 0;
//		i++;
//		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
//	}
//	*n = i;
//	fclose(f);
//	return dsdv;
//}
//
//void inDS(DoVat *dsdv,int n,int W){
//	printf("Phuong an cai balo 2 thuat toan QHD:\n");
//	int TongTL=0,TongGT=0;
//	
//	for(int i = 0; i < n; i++){
//		printf("- STT: %d\n",i+1);
//		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
//		printf("- Trong Luong: %d\n",dsdv[i].TL);
//		printf("- Gia tri: %d\n",dsdv[i].GT);
//		printf("- So luong: %d\n",dsdv[i].SL);
//		printf("- Phuong an: %d\n",dsdv[i].PA);
//		printf("----------------------------\n");
//		TongTL += dsdv[i].PA * dsdv[i].TL;
//		TongGT += dsdv[i].PA * dsdv[i].GT;
//	}
//	printf("Trong luong cai balo: %d\n",W);
//	printf("Tong Trong luong: %d\n",TongTL);
//	printf("Tong gia tri: %d\n",TongGT);
//}
//
//int min(int a,int b){
//	return a < b ? a : b;
//}
//void tao_bang(DoVat *dsdv,int n,int W,bang F, bang X){
//	int xk,yk,k;
//	int Fmax,Xmax,V;
//	
//	for(V = 0; V <= W; V++){
//		X[0][V] = V / dsdv[0].TL;
//		F[0][V] = X[0][V] * dsdv[0].GT;
//	}
//	
//	for(k = 1; k < n; k++){
//		for(V = 0; V <= W; V++){
//			Fmax = F[k-1][V];
//			Xmax = 0;
//			yk = min(dsdv[k].SL,V/dsdv[k].TL);
//			for(xk = 1; xk <= yk; xk++){
//				if(F[k-1][V-xk*dsdv[k].TL] + xk*dsdv[k].GT > Fmax){
//					Fmax = F[k-1][V-xk*dsdv[k].TL] + xk*dsdv[k].GT;
//					Xmax = xk;
//				}
//			}
//			F[k][V] = Fmax;
//			X[k][V] = Xmax;
//		}
//	}
//}
//
//void inBang(int n,int W,bang F,bang X){
//	for(int k = 0; k < n; k++){
//		for(int V = 0; V <= W; V++){
//			printf("|%4d%2d",F[k][V],X[k][V]);
//		}
//		printf("\n");
//	}
//}
//
//void tra_bang(DoVat *dsdv,int n,int W,bang X){
//	int k,V;
//	V = W;
//	for(k = n-1; k >= 0; k--){
//		dsdv[k].PA = X[k][V];
//		V = V - dsdv[k].PA * dsdv[k].TL;
//	}
//}
//
//int main(){
//	int n,W;
//	bang F,X;
//	DoVat *dsdv = readFile(&n,&W);
//	tao_bang(dsdv,n,W,F,X);
//	inBang(n,W,F,X);
//	tra_bang(dsdv,n,W,X);
//	inDS(dsdv,n,W);
//	free(dsdv);
//	return 0;
//}
//|   0 0|   0 0|   0 0|   4 1|   4 1|   4 1|   8 2|   8 2|   8 2|  12 3
//|   0 0|   0 0|   0 0|   4 0|   5 1|   5 1|   8 0|   9 1|  10 2|  12 0
//|   0 0|   0 0|   0 0|   4 0|   5 0|   6 1|   8 0|   9 0|  10 0|  12 0
//|   0 0|   0 0|   3 1|   4 0|   6 2|   7 1|   8 0|  10 2|  11 1|  12 0
//|   0 0|   1 1|   3 0|   4 0|   6 0|   7 0|   8 0|  10 0|  11 0|  12 0
//Phuong an cai balo 2 thuat toan QHD:
//- STT: 1
//- Ten do vat:  Gao Mot bui
//- Trong Luong: 3
//- Gia tri: 4
//- So luong: 1
//- Phuong an: 3
//----------------------------
//- STT: 2
//- Ten do vat:  Nep cai hoa vang
//- Trong Luong: 4
//- Gia tri: 5
//- So luong: 3
//- Phuong an: 0
//----------------------------
//- STT: 3
//- Ten do vat:  Gao Nang huong
//- Trong Luong: 5
//- Gia tri: 6
//- So luong: 2
//- Phuong an: 0
//----------------------------
//- STT: 4
//- Ten do vat:  Gao Tai nguyen
//- Trong Luong: 2
//- Gia tri: 3
//- So luong: 2
//- Phuong an: 0
//----------------------------
//- STT: 5
//- Ten do vat:  Gao ST25
//- Trong Luong: 1
//- Gia tri: 1
//- So luong: 2
//- Phuong an: 0
//----------------------------
//Trong luong cai balo: 9
//Tong Trong luong: 9
//Tong gia tri: 12

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	char tenDV[25];
	int TL,GT,SL,PA;
}DoVat;

typedef int bang[50][100];

DoVat *readFile(int *n,int *W){
	FILE*f = fopen("CaiBalo2_QHD.txt","r");
	if(f==NULL) printf("Loi mo file");
	fscanf(f,"%d",W);
	int i = 0 ;
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	while(!feof(f)){
		fscanf(f,"%d%d%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].tenDV);
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n=i;
	fclose(f);
	return dsdv;
}

int min(int a,int b){
	return a < b ? a : b;
}
void Tao_bang(DoVat *dsdv,int n,int W,bang F,bang X){
	int xk,yk,k;
	int Fmax,Xmax,V;
	
	for(V = 0; V<=W; V++){
		X[0][V] = V / dsdv[0].TL;
		F[0][V] = X[0][V] * dsdv[0].GT;
	}
	
	for(k = 1; k < n; k++){
		for(V=0; V <=W; V++){
			Fmax = F[k-1][V];
			Xmax = 0;
			yk = min(dsdv[k].SL,V/dsdv[k].TL);
			for(xk = 1; xk <= yk ;xk++){
				if(F[k-1][V-xk*dsdv[k].TL] + xk*dsdv[k].GT > Fmax){
					Fmax = F[k-1][V-xk*dsdv[k].TL] + xk*dsdv[k].GT;
					Xmax = xk;
				}
			}
			F[k][V] = Fmax;
			X[k][V] = Xmax;
		}
	}
}

void in_Bang(int n,int W,bang F,bang X){
	for(int k= 0; k < n; k++){
		for(int V = 0; V <= W; V++){
			printf("|%4d%2d",F[k][V],X[k][V]);
		}
		printf("\n");
	}
}

void tra_Bang(DoVat *dsdv,int n,int W,bang X){
	int V = W;
	for(int k = n-1; k >= 0; k--){
		dsdv[k].PA = X[k][V];
		V = V - X[k][V] * dsdv[k].TL;
	}
}

void inDS(DoVat *dsdv,int n,int W){
	printf("\nCai balo 2 QHD:\n");
	int TongTL = 0;
	int TongGT = 0;
	for(int i = 0; i < n ;i++){
		printf("- STT: %d\n",i+1);
		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
		printf("- Trong Luong: %d\n",dsdv[i].TL);
		printf("- Gia tri: %d\n",dsdv[i].GT);
		printf("- So luong: %d\n",dsdv[i].SL);
		printf("- Phuong an: %d\n",dsdv[i].PA);
		printf("----------------------------\n");
		TongTL += dsdv[i].PA * dsdv[i].TL;
		TongGT += dsdv[i].PA * dsdv[i].GT;
	}
	printf("Trong luong balo: %d\n",W);
	printf("Tong TL: %d\n",TongTL);
	printf("TongGT: %d\n",TongGT);
}
int main(){
	int n,W;
	bang F,X;
	DoVat *dsdv = readFile(&n,&W);
	Tao_bang(dsdv,n,W,F,X);
	in_Bang(n,W,F,X);
	tra_Bang(dsdv,n,W,X);
	inDS(dsdv,n,W);
	free(dsdv);
	return 0;
}
