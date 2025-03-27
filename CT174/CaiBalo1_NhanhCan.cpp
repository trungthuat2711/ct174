/*-nut goc: TGT = 0.0
            CT = W * don gia lon nhat

 -nut trong: – TGT = TGT (nút cha) + so do vat dc chon *gia tri
             – W = W (nút cha) - so do vat dc chon * trong luong.
             – CT = TGT + W * don gia vat xet ke tiep
*/

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
//	FILE *f = fopen("CaiBalo1.txt","r");
//	if(f==NULL) printf("Loi mo file!");
//	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
//	fscanf(f,"%f",W);
//	int i  = 0;
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
//void swap(DoVat *x,DoVat*y){
//	DoVat temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void bubbleSort(DoVat *dsdv,int n){
//	for(int i = 0; i <= n-2; i++){
//		for(int j = n - 1; j >= i+1; j--){
//			if(dsdv[j].DG > dsdv[j-1].DG){
//				swap(&dsdv[j],&dsdv[j-1]);
//			}
//		}
//	}
//}
//
//void tao_nut_goc(float W,float *TLconlai,float *CT,float *GLNTT,float *TGT,float DG_Max){
//	*TGT = 0.0;
//	*TLconlai = W;
//	*CT = *TLconlai*DG_Max;
//	*GLNTT = 0.0;
//}
//
////phuong an tot nhat tam thoi 
//void cap_nhat_glntt(float TGT,float *GLNTT,int x[],DoVat *dsdv,int n){
//	if(*GLNTT < TGT){
//		*GLNTT = TGT;
//		for(int i = 0; i < n; i++){
//			dsdv[i].PA = x[i];  // cap nhat phuong an 
//		} 
//	} 
//} 
//
////i do vat dang xet 
//void nhanh_can(int i,float *TGT, float *CT,float *GLNTT,float *TLconlai,int x[],DoVat *dsdv,int n){
//	int j; // j la so do vat dc chon 
//	
//	int So_Do_Vat_Lon_Nhat_Co_The_Chon = *TLconlai / dsdv[i].TL;
//	for(int j = So_Do_Vat_Lon_Nhat_Co_The_Chon; j >= 0; j--){
//		*TGT = *TGT + j* dsdv[i].GT ;               // TGT nut cha + so do vat dc chon * GT
//		*TLconlai = *TLconlai - j *dsdv[i].TL;     // TLconlai = TLconlai - so do dc chon *TL 
//		*CT = *TGT + *TLconlai * dsdv[i+1].DG;     // TGT + TLconlai * Don gia vat ke
//		
//		if(*CT > *GLNTT){                 //CT <= GLNTT thi cat tia  
//			x[i] = j;
//			if( i==n-1 || *TLconlai==0 ){ // Da xet het tat ca cac do vat hoac ba lo da day
//				cap_nhat_glntt(*TGT,GLNTT,x,dsdv,n); 
//			} 
//			else{
//				nhanh_can(i+1,TGT,CT,GLNTT,TLconlai,x,dsdv,n);  //Xet nut con cua nut i
//			} 	 
//		}
//		//quay lui  
//	    x[i] = 0; 
//		*TGT = *TGT - j*dsdv[i].GT;   //tra lai TGT 
//		*TLconlai = *TLconlai + j *dsdv[i].TL;    //tra lai TLconlai 
//	} 
//}
//
//void inDS(DoVat *dsdv,int n, float W){
//	float TongTL =0.0,TongGT = 0.0; 
//	printf("Phuong an Cai ba lo 1 thuat toan nhanh can:\n");
//	printf("Trong luong cai balo: %.2f\n",W);
//	
//	for(int i = 0; i < n; i++){
//		printf("- STT: %d\n",i+1);
//		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
//		printf("- Trong luong: %.2f\n",dsdv[i].TL);
//		printf("- Gia tri: %.2f\n",dsdv[i].GT);
//		printf("- Don gia: %.1f\n",dsdv[i].DG);
//		printf("- Phuong an: %d\n",dsdv[i].PA);
//		printf("------------------------------\n");
//		
//		TongTL += dsdv[i].TL*dsdv[i].PA;
//		TongGT += dsdv[i].GT*dsdv[i].PA; 
//	}
//	printf("Tong trong luong: %.2f\n",TongTL);
//	printf("Tong gia tri: %.2f\n",TongGT);
//} 
//
//int main(){
//	int n;
//	float W,TGT,CT,GLNTT,TLconlai;
//	DoVat *dsdv = readFile(&n,&W);
//	int x[n]; //phuong an tot nhat tam thoi  
//	bubbleSort(dsdv,n);
//	tao_nut_goc(W,&TLconlai,&CT,&GLNTT,&TGT,dsdv[0].DG);
//	nhanh_can(0,&TGT,&CT,&GLNTT,&TLconlai,x,dsdv,n); 
//	inDS(dsdv,n,W);
//	free(dsdv); 
//	return 0; 
//} 







//Phuong an Cai Ba lo 1 dung thuat toan NHANH CAN nhu sau:
//|---|--------------------|---------|---------|---------|---------|-----------|
//|STT|     Ten Do Vat     |T. Luong | Gia Tri |So luong | Don gia | Phuong an |
//|---|--------------------|---------|---------|---------|---------|-----------|
//| 1 | Nep cai hoa vang   |    10.00|    25.00|         |     2.50|     3     |
//| 2 | Gao Mot bui        |    15.00|    30.00|         |     2.00|     0     |
//| 3 | Gao Tai nguyen     |     4.00|     6.00|         |     1.50|     1     |
//| 4 | Gao Nang huong     |     2.00|     2.00|         |     1.00|     1     |
//|---|--------------------|---------|---------|---------|---------|-----------|
//Trong luong cua ba lo = 37.00
//Tong trong luong = 36.00
//Tong gia tri = 83.00

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct{
	char tenDV[25];
	float TL,GT,DG;
	int PA;
}DoVat;

DoVat *readFile(int *n,float *W){
	FILE *f = fopen("CaiBalo1.txt","r");
	if(f==NULL) printf("Loi mo file");
	fscanf(f,"%f",W);
	int i = 0;
	DoVat *dsdv = (DoVat*)malloc(sizeof(DoVat));
	while(!feof(f)){
		fscanf(f,"%f%f%[^\n]",&dsdv[i].TL,&dsdv[i].GT,&dsdv[i].tenDV);
		dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n = i;
	return dsdv;
}

void swap(DoVat *x,DoVat *y){
	DoVat temp = *x;
	*x = *y;
	*y = temp;
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

void tao_nut_goc(float *TGT,float W, float *TLconlai,float *CT,float *GLNTT,float DG_Max){
	*TGT = 0.0;
	*TLconlai = W;
	*CT = *TLconlai * DG_Max;
	*GLNTT = 0.0;
}

void cap_nhap_glntt(float TGT, float*GLNTT,int x[],DoVat *dsdv,int n){
	if(TGT > *GLNTT){
		*GLNTT = TGT;
		for(int i = 0; i < n; i++){
			dsdv[i].PA = x[i];
		}
	}
}

void nhanh_can(int i,float *TGT,float *CT,float *GLNTT,float *TLconlai,int x[],DoVat *dsdv,int n){
	int j;
	int so_do_lon_nhat_duoc_chon = *TLconlai / dsdv[i].TL;
	for(j = so_do_lon_nhat_duoc_chon; j >= 0; j--){
		*TGT = *TGT + j * dsdv[i].GT;
		*TLconlai = *TLconlai - j * dsdv[i].TL;
		*CT = *TGT + *TLconlai * dsdv[i+1].DG;
		if(*CT > *GLNTT){
			x[i] = j;
			if(i ==n-1 || *TLconlai==0 ){
				cap_nhap_glntt(*TGT,GLNTT,x,dsdv,n);
			}else{
				nhanh_can(i+1,TGT,CT,GLNTT,TLconlai,x,dsdv,n);
			}
		}
		*TGT = *TGT - j * dsdv[i].GT;
		*TLconlai = *TLconlai + j * dsdv[i].TL;
		x[i] = 0;
	}
}

void print(DoVat *dsdv,int n,float W){
	float TongTL = 0.0,TongGT = 0.0;
	printf("Phuong an Cai Ba lo 1 dung thuat toan NHANH CAN nhu sau:\n");
		for(int i = 0; i < n; i++){
		printf("- STT: %d\n",i+1);
		printf("- Ten do vat: %s\n",dsdv[i].tenDV);
		printf("- Trong luong: %.2f\n",dsdv[i].TL);
		printf("- Gia tri: %.2f\n",dsdv[i].GT);
		printf("- Don gia: %.1f\n",dsdv[i].DG);
		printf("- Phuong an: %d\n",dsdv[i].PA);
		printf("------------------------------\n");
		
		TongTL += dsdv[i].TL*dsdv[i].PA;
		TongGT += dsdv[i].GT*dsdv[i].PA; 
	}
	printf("Trong luong cai balo: %.2f\n",W);
	printf("Tong trong luong: %.2f\n",TongTL);
	printf("Tong gia tri: %.2f\n",TongGT);
}
int main(){
	int n;
	float W,TGT,CT,GLNTT,TLconlai,DG_Max;
	int x[n];
	DoVat *dsdv = readFile(&n,&W);
	bubbleSort(dsdv,n);
	tao_nut_goc(&TGT,W,&TLconlai,&CT,&GLNTT,dsdv[0].DG);
	nhanh_can(0,&TGT,&CT,&GLNTT,&TLconlai,x,dsdv,n);
	print(dsdv,n,W);
	free(dsdv);
	return 0;
}
