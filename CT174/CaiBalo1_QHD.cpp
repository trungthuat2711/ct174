//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct{
//	char tenDV[25];
//	int TL,GT,PA;
//}DoVat;
//
//typedef int bang[50][100] ;//Ba lo co trong luong toi da 99 va co toi da 50 do vat
//
//DoVat *readFile(int *n,int *W){
//	FILE *f = fopen("CaiBalo13_QHD.txt","r");
//	if(f==NULL) printf("Loi mo file");
//	fscanf(f,"%d",W); // lay trong luong balo
//	
//	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
//	int i = 0;
//	while(!feof(f)){
//		fscanf(f,"%d%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDV);
//		dsdv[i].PA = 0;
//		i++;
//		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
//	}
//	*n = i;
//	fclose(f);
//	return dsdv;
//}
//
//
//void tao_bang(DoVat *dsdv,int n,int W,bang F,bang X){
//	//k:do vat      V:trong luong con lai
//	int xk,yk,k;
//	int Fmax,Xmax,V;  
//	
//	//dong dau tien
//	for(V = 0; V <= W; V++){
//		X[0][V] = V / dsdv[0].TL;
//		F[0][V] = X[0][V] * dsdv[0].GT;
//	}
//	
//	//cac dong con lai
//	for(k = 1; k < n; k++){
//		for(V = 0; V <= W; V++){
//			Fmax = F[k-1][V];
//			Xmax = 0;
//			yk = V / dsdv[k].TL; //balo 2 yk = min(sl,V/dsdv[k].TL) balo 3 yk = min(1,V/dsdv[k].TL)
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
//void inBang(int n, int W, bang F,bang X){
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
//	for(k = n-1; k >= 0; k-- ){
//		dsdv[k].PA = X[k][V];
//		V = V - X[k][V] * dsdv[k].TL;
//	}
//}
//
//void inDS(DoVat *dsdv,int n,int W){
//	int TongGT=0,TongTL=0;
//	printf("Phuong an cai balo1 thuat toan QHD:\n");
//	for(int i = 0; i < n; i++){
//		printf("- STT: %d\n",i+1);
//		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
//		printf("- Trong luong: %d\n",dsdv[i].TL);
//		printf("- Gia tri: %d\n",dsdv[i].GT);
//		printf("- Phuong an: %d\n",dsdv[i].PA);
//		printf("------------------------\n");
//		TongTL += dsdv[i].PA *dsdv[i].TL;
//		TongGT += dsdv[i].PA *dsdv[i].GT;
//	}
//	printf("Trong luong cua balo: %d\n",W);
//	printf("Tong tong luong: %d\n",TongTL);
//	printf("Tong gia tri: %d\n",TongGT);
//}
//int main(){
//	int n,W;
//	bang X,F;
//	DoVat *dsdv = readFile(&n,&W);
//	tao_bang(dsdv,n,W,F,X);
//	inBang(n,W,F,X);
//	printf("\n");
//	tra_bang(dsdv,n,W,X);
//	inDS(dsdv,n,W);
//	
//	free(dsdv);
//	return 0;
//}
//
//|   0 0|   0 0|   0 0|   4 1|   4 1|   4 1|   8 2|   8 2|   8 2|  12 3
//|   0 0|   0 0|   0 0|   4 0|   5 1|   5 1|   8 0|   9 1|  10 2|  12 0
//|   0 0|   0 0|   0 0|   4 0|   5 0|   6 1|   8 0|   9 0|  10 0|  12 0
//|   0 0|   0 0|   3 1|   4 0|   6 2|   7 1|   9 3|  10 2|  12 4|  13 3
//|   0 0|   1 1|   3 0|   4 0|   6 0|   7 0|   9 0|  10 0|  12 0|  13 0
//
//Phuong an cai balo1 thuat toan QHD:
//- STT: 1
//- Ten do vat:  Gao Mot bui
//- Trong luong: 3
//- Gia tri: 4
//- Phuong an: 1
//------------------------
//- STT: 2
//- Ten do vat:  Nep cai hoa vang
//- Trong luong: 4
//- Gia tri: 5
//- Phuong an: 0
//------------------------
//- STT: 3
//- Ten do vat:  Gao Nang huong
//- Trong luong: 5
//- Gia tri: 6
//- Phuong an: 0
//------------------------
//- STT: 4
//- Ten do vat:  Gao Tai nguyen
//- Trong luong: 2
//- Gia tri: 3
//- Phuong an: 3
//------------------------
//- STT: 5
//- Ten do vat:  Gao ST25
//- Trong luong: 1
//- Gia tri: 1
//- Phuong an: 0
//------------------------
//Trong luong cua balo: 9
//Tong tong luong: 9
//Tong gia tri: 13

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	char tenDV[25];
	int TL,GT,PA;
}DoVat;

typedef int bang[50][100];

DoVat *readFile(int *n,int *W){
	FILE *f = fopen("CaiBalo13_QHD.txt","r");
	if(f==NULL) printf("Loi mo file");
	fscanf(f,"%d",W);
	int i = 0;
	DoVat *dsdv = (DoVat *)malloc(sizeof(DoVat));
	while(!feof(f)){
		fscanf(f,"%d%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDV);
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat *)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void tao_bang(DoVat *dsdv,int n,int W,bang F,bang X){
	int xk,yk,k;
	int Fmax,Xmax,V;
	
	for(V=0; V <= W; V++){
		X[0][V] = V / dsdv[0].TL;
		F[0][V] = X[0][V] * dsdv[0].GT;
	}
	
	for(k = 1; k < n; k++){
		for(V = 0; V <= W; V++){
			Fmax = F[k-1][V];
			Xmax = 0;
			yk = V / dsdv[k].TL;
			for(xk = 1; xk <=yk; xk++){
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

void in_bang(int n,int W,bang F,bang X){
	for(int k = 0; k < n; k++){
		for(int V = 0; V <=W; V++){
			printf("|%4d%2d",F[k][V],X[k][V]);
		}
		printf("\n");
	}
}

void tra_bang(DoVat *dsdv,int n,int W,bang X){
	int k,V = W;
	for(k = n-1; k >= 0; k--){
		dsdv[k].PA = X[k][V];
		V = V - X[k][V] * dsdv[k].TL;
	}
}

void inDS(DoVat *dsdv,int n,int W){
	int TongTL =0,TongGT = 0;
	printf("Phuong an cai balo1 thuat toan QHD:");
	for(int i = 0; i < n; i++){
		printf("- STT: %d\n",i+1);
		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
		printf("- Trong luong: %d\n",dsdv[i].TL);
		printf("- Gia tri: %d\n",dsdv[i].GT);
		printf("- Phuong an: %d\n",dsdv[i].PA);
		printf("------------------------\n");
		TongTL += dsdv[i].PA *dsdv[i].TL;
		TongGT += dsdv[i].PA *dsdv[i].GT;
	}
	printf("Trong luong balo: %d\n",W);
	printf("Tong trong luong: %d\n",TongTL);
	printf("Tong gia tri: %d\n",TongGT);
}
int main(){
	int n,W;
	DoVat *dsdv = readFile(&n,&W);
	bang F,X;
	tao_bang(dsdv,n,W,F,X);
	in_bang(n,W,F,X);
	tra_bang(dsdv,n,W,X);
	printf("\n");
	inDS(dsdv,n,W);
	free(dsdv);
	return 0;
}
