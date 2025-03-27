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

    DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    fscanf(f,"%d",W);
    while(!feof(f)){
    	fscanf(f,"%d%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDV);
    	dsdv[i].PA = 0;
    	i++;
    	dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void inDS(DoVat *dsdv, int n, int W){
	printf("Phuong an cai balo 3 thuat toan QHD:\n");
	int TongTL = 0, TongGT = 0;
	for(int i = 0; i < n; i++){
		printf("- STT: %d\n",i+1);
		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
		printf("- Trong luong: %d\n",dsdv[i].TL);
		printf("- Gia tri: %d\n",dsdv[i].GT);
		printf("- Phuong an: %d\n",dsdv[i].PA);
		printf("-------------------------\n");
		TongTL += dsdv[i].PA * dsdv[i].TL;
		TongGT += dsdv[i].PA * dsdv[i].GT;
	}
	printf("Trong luong cai balo %d\n",W);
	printf("Tong trong luong: %d\n",TongTL);
	printf("Tong gia tri: %d\n",TongGT);
}

int min(int a,int b){
	return a < b ? a : b;
}
void tao_bang(DoVat *dsdv,int n,int W,bang F,bang X){
	int xk,yk,k;
	int Fmax,Xmax,V;
	
	for(V = 0; V <= W; V++){
		X[0][V] = V / dsdv[0].TL;
		F[0][V] = X[0][V] * dsdv[0].GT;
	}
	
	for(k = 1; k < n; k++){
		for(V = 0; V <= W; V++){
			Fmax = F[k-1][V];
			yk = min(1,V/dsdv[k].TL);
			Xmax = 0;
			for(xk = 1; xk <= yk; xk++){
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

void inBang(int n,int W,bang F,bang X){
	for(int k = 0; k < n ;k++){
		for(int V = 0; V <= W; V++){
			printf("|%4d%2d",F[k][V],X[k][V]);
		}
		printf("\n");
	}
}

void tra_bang(DoVat *dsdv,int n ,int W,bang X){
	int V = W;
	for(int k = n-1; k >= 0; k--){
		dsdv[k].PA = X[k][V];
		V = V - dsdv[k].PA * dsdv[k].TL;
	}
}

int main(){
	int n,W;
	bang F,X;
	DoVat *dsdv = readFile(&n,&W);
	tao_bang(dsdv,n,W,F,X);
	inBang(n,W,F,X);
	tra_bang(dsdv,n,W,X);
	inDS(dsdv,n,W);
	free(dsdv);
	return 0;
}

