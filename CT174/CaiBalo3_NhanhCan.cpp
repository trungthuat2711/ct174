#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct {
	char tenDV[25];
	float TL,GT,DG;
	int PA;
}DoVat;

DoVat *readFile(int *n,float *W){
	FILE *f = fopen("CaiBalo3.txt","r");
	if(f==NULL) printf("Loi mo file!");
	fscanf(f,"%f",W);
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i  = 0 ;
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

void swap(DoVat *x,DoVat*y){
	DoVat temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(DoVat *dsdv,int n){
	for(int i = 0; i <= n-2; i++){
		for(int j = n-1; j >= i+1; j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}
}

int min(int a, int b){
	return a < b ? a : b;
}

void tao_nut_goc(float W,float *TLconlai,float *TGT,float *GLNTT,float *CT,float DG_Max){
	*TGT = 0.0;
	*TLconlai = W;
	*CT = *TLconlai * DG_Max;
    *GLNTT = 0.0;	
}

void cap_nhat_glntt(float TGT,float *GLNTT,DoVat *dsdv,int x[],int n){
	if(TGT > *GLNTT){
		*GLNTT = TGT;
		for(int i = 0; i < n; i++){
			dsdv[i].PA = x[i];
		}
	}
}
// i do vat dang xet
void nhanh_can(int i, float *TGT,float *CT,float *GLNTT,float *TLconlai,int x[],DoVat *dsdv,int n){
	int j ; // so do vat duoc chon
	int so_do_vat_lon_nhat_duoc_chon = min(1, *TLconlai / dsdv[i].TL);
	for(int j = so_do_vat_lon_nhat_duoc_chon; j >= 0 ;j--){
		*TGT = *TGT + j * dsdv[i].GT;
		*TLconlai = *TLconlai - j * dsdv[i].TL;
		*CT = *TGT + *TLconlai * dsdv[i+1].DG;
		if(*CT > *GLNTT){
			x[i] = j;
			if(i == n-1 || *TLconlai == 0){
				cap_nhat_glntt(*TGT,GLNTT,dsdv,x,n);
			}
			else{
				nhanh_can(i+1,TGT,CT,GLNTT,TLconlai,x,dsdv,n);
			}
		}
		*TGT = *TGT - j * dsdv[i].GT;
		*TLconlai = *TLconlai + j * dsdv[i].TL;
		x[i] = 0;
	}
	
}

void inDS(DoVat *dsdv,int n,float W){
	float TongGT = 0.0, TongTL = 0.0;
	printf("Phuong an cai balo 3 thuat toan nhanh can:\n");
	printf("Trong luong cua cai balo: %.2f\n",W);
	for(int i = 0; i < n; i++){
		printf("- STT: %d\n",i+1);
		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
		printf("- Trong luong: %.2f\n",dsdv[i].TL);
		printf("- Gia tri: %.2f\n",dsdv[i].GT);
		printf("- Don gia: %.1f\n",dsdv[i].DG);
		printf("- Phuong an: %d\n",dsdv[i].PA);
		printf("----------------------------\n");
		TongTL += dsdv[i].PA * dsdv[i].TL;
		TongGT += dsdv[i].PA * dsdv[i].GT;
	}
	printf("Tong trong luong: %.2f\n",TongTL);
	printf("Tong gia tri: %.2f\n",TongGT); 
}

int main(){
	int n;
    float W,TGT,CT,TLconlai,GLNTT;
    DoVat *dsdv = readFile(&n,&W);
    int x[n];
    bubbleSort(dsdv,n);
    tao_nut_goc(W,&TLconlai,&TGT,&GLNTT,&CT,dsdv[0].DG);
    nhanh_can(0,&TGT,&CT,&GLNTT,&TLconlai,x,dsdv,n);
    inDS(dsdv,n,W);
    free(dsdv);
    return 0;
}
