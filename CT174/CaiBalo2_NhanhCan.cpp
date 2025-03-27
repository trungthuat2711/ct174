//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//
//typedef struct{
//	char tenDV[25];
//	float TL,GT,DG;
//	int SL,PA;
//}DoVat;
//
//DoVat*readFile(int *n,float *W){
//	FILE*f = fopen("CaiBalo2.txt","r");
//	if(f==NULL) printf("Loi mo file");
//	fscanf(f,"%f",W);
//	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
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
//void swap(DoVat *x,DoVat*y){
//	DoVat temp = *x;
//	*x = *y ;
//	*y = temp;
//}
//void bubbleSort(DoVat *dsdv,int n){
//	for(int i = 0; i <= n - 2; i++){
//		for(int j = n-1; j>=i+1; j--){
//			if(dsdv[j].DG > dsdv[j-1].DG){
//				swap(&dsdv[j],&dsdv[j-1]);
//			}
//		}
//	}
//}
//void tao_nut_goc(float W,float *TLconlai,float *CT,float *GLNTT,float *TGT,float DG_Max){
//	*TGT = 0.0;
//	*TLconlai = W;
//	*CT = *TLconlai * DG_Max;
//	*GLNTT = 0.0;
//}
//
//int min(int a,int b){
//	return  a < b ? a : b;
//}
//
//void cap_nhat_glntt(float TGT,float *GLNTT,int x[],DoVat *dsdv,int n){
//	if(TGT > *GLNTT){
//		*GLNTT = TGT;
//		for(int i = 0; i < n; i++){
//			dsdv[i].PA = x[i];
//		}
//	}
//}
//
//// i do vat dang xet, TGT,CT,GLNTT,TLconlai, x[] phuong an tam , dsdv, n so luong
//void nhanh_can(int i,float *TGT,float *CT,float *GLNTT,float *TLconlai,int x[],DoVat*dsdv,int n){
//	int j; // so do vat duoc chon
//	int so_do_vat_lon_nhat_duoc_chon = min(dsdv[i].SL,*TLconlai / dsdv[i].TL);
//	
//	for(int j = so_do_vat_lon_nhat_duoc_chon; j >= 0; j--){
//		*TGT = *TGT + j*dsdv[i].GT;
//		*TLconlai = *TLconlai - j*dsdv[i].TL;
//		*CT = *TGT + *TLconlai *dsdv[i+1].DG;
//		if(*CT  > *GLNTT){
//			x[i] = j;
//			if(i==n-1 || *TLconlai == 0){
//				cap_nhat_glntt(*TGT,GLNTT,x,dsdv,n);
//			}
//			else{
//				nhanh_can(i+1,TGT,CT,GLNTT,TLconlai,x,dsdv,n);
//			}
//		}
//		*TGT = *TGT - j*dsdv[i].GT;
//		*TLconlai = *TLconlai + j*dsdv[i].TL;
//		x[i] = 0;
//	}	
//}
//
//void inDS(DoVat *dsdv,int n,float W){
//	float TongTL=0.0,TongGT=0.0;
//	printf("Phuong an cai balo 2 dung thuat toan nhanh can: \n");
//	printf("Trong luong cua cai balo: %.2f\n",W);
//	for(int i = 0; i < n; i++){
//		printf("- STT: %d\n",i+1);
//		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
//		printf("- Trong luong: %.2f\n",dsdv[i].TL);
//		printf("- Gia tri: %.2f\n",dsdv[i].GT);
//		printf("- So luong: %d\n",dsdv[i].SL);
//		printf("- Don gia: %.1f\n",dsdv[i].DG);
//		printf("- Phuong an: %d\n",dsdv[i].PA);
//		printf("----------------------------\n");
//		TongTL += dsdv[i].PA * dsdv[i].TL;
//		TongGT += dsdv[i].PA * dsdv[i].GT;
//	}
//	printf("Tong trong luong: %.2f\n",TongTL);
//	printf("Tong gia tri: %.2f\n",TongGT);
//}
//int main(){
//	int n;
//	float W,TLconlai,TGT,CT,GLNTT;
//	DoVat *dsdv = readFile(&n,&W);
//	int x[n];
//	bubbleSort(dsdv,n);
//	tao_nut_goc(W,&TLconlai,&CT,&GLNTT,&TGT,dsdv[0].DG);
//	nhanh_can(0,&TGT,&CT,&GLNTT,&TLconlai,x,dsdv,n);
//	inDS(dsdv,n,W);
//	free(dsdv);
//	return 0;	
//}
//Phuong an cai balo 2 dung thuat toan nhanh can:
//Trong luong cua cai balo: 47.00
//- STT: 1
//- Ten do vat:  Gao ST25
//- Trong luong: 8.00
//- Gia tri: 24.00
//- So luong: 2
//- Don gia: 3.0
//- Phuong an: 2
//----------------------------
//- STT: 2
//- Ten do vat:  Nep cai hoa vang
//- Trong luong: 10.00
//- Gia tri: 25.00
//- So luong: 1
//- Don gia: 2.5
//- Phuong an: 1
//----------------------------
//- STT: 3
//- Ten do vat:  Gao Mot bui
//- Trong luong: 15.00
//- Gia tri: 30.00
//- So luong: 5
//- Don gia: 2.0
//- Phuong an: 1
//----------------------------
//- STT: 4
//- Ten do vat:  Gao Tai nguyen
//- Trong luong: 4.00
//- Gia tri: 6.00
//- So luong: 2
//- Don gia: 1.5
//- Phuong an: 1
//----------------------------
//- STT: 5
//- Ten do vat:  Gao Nang huong
//- Trong luong: 2.00
//- Gia tri: 2.00
//- So luong: 3
//- Don gia: 1.0
//- Phuong an: 1
//----------------------------
//Tong trong luong: 47.00
//Tong gia tri: 111.00

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	char tenDV[25];
	float TL,GT,DG;
	int PA,SL;
}DoVat;

DoVat *readFile(int *n,float *W){
	FILE *f = fopen("CaiBalo2.txt","r");
	if(f==NULL) printf("Loi mo file");
	fscanf(f,"%f",W);
	int i = 0;
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	while(!feof(f)){
		fscanf(f,"%f%f%d%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].SL,&dsdv[i].tenDV);
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
	*x = *y;
	*y = temp;
}

void bubbleSort(DoVat *dsdv,int n){
	for(int i = 0; i <= n-2;i++){
		for(int j = n-1; j >= i+1; j--){
			if(dsdv[j].DG > dsdv[j-1].DG){
				swap(&dsdv[j],&dsdv[j-1]);
			}
		}
	}
}

int min(int a,int b){
	return a < b ?a:b;
}
void tao_nut_goc(float *TGT,float W,float*TLconlai,float *CT,float *GLNTT,float DG_Max){
	*TGT = 0.0;
	*TLconlai = W;
	*CT = *TLconlai * DG_Max;
	*GLNTT = 0.0;
}

void cap_nhat_glntt(float TGT,float *GLNTT,int x[],DoVat *dsdv,int n){
	if(TGT > *GLNTT){
		*GLNTT = TGT;
		for(int i = 0; i < n; i++){
			dsdv[i].PA = x[i];
		}
	}
}

void nhanh_can(int i,float *TGT,float *CT,float *TLconlai,float *GLNTT,int x[],DoVat *dsdv,int n){
	int so_do_vat_lon_nhat_chon_duoc = min(dsdv[i].SL,*TLconlai / dsdv[i].TL);
	
	for(int j = so_do_vat_lon_nhat_chon_duoc; j >= 0; j--){
		*TGT = *TGT + j * dsdv[i].GT;
		*TLconlai -= j*dsdv[i].TL;
		*CT = *TGT + *TLconlai *dsdv[i+1].DG;
		
		if(*CT > *GLNTT){
			x[i] = j;
			if(i == n-1 || *TLconlai == 0){
				cap_nhat_glntt(*TGT,GLNTT,x,dsdv,n);
			}
			else{
				nhanh_can(i+1,TGT,CT,TLconlai,GLNTT,x,dsdv,n);
			}
		}
		*TGT = *TGT - j * dsdv[i].GT;
		*TLconlai += j*dsdv[i].TL;
		x[i] = 0;
	}
}

void inDS(DoVat *dsdv,int n,float W){
	float TongTL=0.0,TongGT=0.0;
	printf("Phuong an cai balo 2 dung thuat toan nhanh can: \n");
	printf("Trong luong cua cai balo: %.2f\n",W);
	for(int i = 0; i < n; i++){
		printf("- STT: %d\n",i+1);
		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
		printf("- Trong luong: %.2f\n",dsdv[i].TL);
		printf("- Gia tri: %.2f\n",dsdv[i].GT);
		printf("- So luong: %d\n",dsdv[i].SL);
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
	float W,TGT,CT,GLNTT,TLconlai,DG_Max;
	DoVat *dsdv = readFile(&n,&W);
	int x[n];
	bubbleSort(dsdv,n);
	tao_nut_goc(&TGT,W,&TLconlai,&CT,&GLNTT,dsdv[0].DG);
	nhanh_can(0,&TGT,&CT,&TLconlai,&GLNTT,x,dsdv,n);
	inDS(dsdv,n,W);
	free(dsdv);
	return 0;
}
