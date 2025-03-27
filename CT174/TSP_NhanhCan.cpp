/* Thuat toan NHANH CAN:
- Xuat phat tu mot thanh pho nao do
- Xet het cac kha nang de di den thanh pho thu 2
- Tu thanh pho thu 2 lai xet het cac kha nang de di den thanh pho thu 3
  ...
- Khi di den thanh pho n thi quay ve thanh pho ban dau

- Cong thuc tinh can duoi: TGT + (n-i) * canh nho nhat
- TGT: Tong do dai cac canh da xet dua vao PA
- i la thanh pho chung ta di den, thanh pho ban dau ung voi i=0
- Canh nho nhat la do dai nho nhat cua cac canh chua duoc dua vao PA nao*/


#include<stdio.h>
#define size 30 

typedef struct{
	float do_dai;
	int dau,cuoi;
	int da_dung;
}canh;

void readFile(canh a[][size],int *n){
	FILE *f = fopen("TSP1.txt","r");
	if(f==NULL) printf("Loi mo file");
	fscanf(f,"%d",n);
	for(int i = 0; i < *n; i++){
		for(int j = 0; j < *n; j++){
			fscanf(f,"%f",&a[i][j].do_dai);
			a[i][j].dau = i;
			a[i][j].cuoi = j;
			a[i][j].da_dung = 0;
		}
	}
	fclose(f);
}

void in_ma_tran(canh a[][size],int n){
	printf("\nMa tran trong so cua do thi:\n");
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n; j++){
			printf(" %c%c = %.2f",a[i][j].dau+97,a[i][j].cuoi+97,a[i][j].do_dai);
		}
		printf("\n");
	}
}

float canh_NN(canh a[][size],int n){
	float cmin = 99999.0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i!=j && !a[i][j].da_dung && a[i][j].do_dai < cmin){
				cmin = a[i][j].do_dai;
			}
		}
	}
	return cmin;
}


float can_duoi(canh a[][size],float TGT, int n, int i){
	return TGT + (n-i) * canh_NN(a,n);
}


void cap_nhat_pa_tntt(canh a[][size],int n, float TGT, float *GNNTT,canh x[], canh PA[]){
	x[n-1] = a[x[n-2].cuoi][x[0].dau];
	TGT += x[n-1].do_dai;
	
	if(*GNNTT > TGT){
		*GNNTT = TGT;
		for(int i = 0; i < n; i++){
			PA[i] = x[i];
		}
	}
}

// kiem tra dinh ke tiep co trung voi dinh dau cua cac canh da xet
int co_chu_trinh(canh x[],int k, int ke_tiep){
	int i = 0;
	int co_ct = 0;
	while(i < k && !co_ct){
		if(x[i].dau == ke_tiep){
			co_ct = 1;
		}
		else{
			i++;
		}
	}
	return co_ct;
}

void nhanh_can(canh a[][size],int n, int i , int dau , float *TGT,float *CD,float *GNNTT,canh x[],canh PA[]){
	int j; //j la dinh ke tiep
	for(int j = 0; j < n; j++){
		if (dau!=j && !a[dau][j].da_dung && !co_chu_trinh(x,i,j)){
	 	 *TGT = *TGT + a[dau][j].do_dai;
		 *CD = can_duoi(a, *TGT, n, i+1);		 
		  if(*CD < *GNNTT){ 	 
		  	x[i] = a[dau][j];
		  	a[dau][j].da_dung=1;
		  	a[j][dau].da_dung=1;
		   	if(i==n-2){ //Da xet het tat ca cac dinh nhung duong di moi co n-1 canh
			   	cap_nhat_pa_tntt(a, n, *TGT, GNNTT, x, PA);
	    	}   	
		 	else{
		 		nhanh_can(a, n, i+1, j, TGT, CD, GNNTT, x, PA); 
			}
		}
	    *TGT = *TGT - a[dau][j].do_dai;
	    a[dau][j].da_dung=0;	
	    a[j][dau].da_dung=0;
       }
    }
 
}

void reset(canh a[][size], int n){
	int i,j;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			a[i][j].da_dung=0;
}

void in_PA(canh PA[], int n){
	int i;
	float sum = 0.0;
	printf("\nPHUONG AN TIM DUOC:\n");
	for(i=0; i<n; i++){
		sum+= PA[i].do_dai;
		printf(" Canh %c%c = %5.2f\n", PA[i].dau+97, PA[i].cuoi+97, PA[i].do_dai);
    }  
    printf("CHU TRINH : ");
	for(i=0; i<n; i++){
		printf("%c",PA[i].dau+97);
		printf("-> ");
    }  
	printf("%c",PA[0].dau+97);    
	printf("\nTong do dai cac canh cua chu trinh = %5.2f\n", sum);
}

int main(){
	canh a[size][size];
	int n;
	printf("\nPhuong an TSP dung thuat toan NHANH CAN:\n");
	readFile(a,&n);
	canh PA[n];
	canh x[n];
	char tpxp, yn = 'y';
	while (yn!='n' && yn!='N'){
		in_ma_tran(a,n);
		float TGT=0.0, CD = 0.0, GNNTT = 99999999.0;
		printf("\nXuat phat tu thanh pho nao? ");
		printf("\n Nhap mot trong cac thanh pho tu a den %c: ", n-1+97);
		scanf(" %c", &tpxp); /// Dau cach giúp bo qua khoang trang truoc ki tu
		nhanh_can(a, n, 0, tpxp-97, &TGT, &CD, &GNNTT, x, PA);
		in_PA(PA,n);
		
		printf("\nTiep tuc Y/N? ");
		scanf(" %c", &yn);
		if (yn == 'N' || yn == 'n')
			break;
		reset(a,n);
    }	    	
	return 0;
}


//Ma tran trong so cua do thi:
// aa = 0.00 ab = 3.00 ac = 4.00 ad = 2.00 ae = 7.00
// ba = 3.00 bb = 0.00 bc = 4.00 bd = 6.00 be = 3.00
// ca = 4.00 cb = 4.00 cc = 0.00 cd = 5.00 ce = 8.00
// da = 2.00 db = 6.00 dc = 5.00 dd = 0.00 de = 6.00
// ea = 7.00 eb = 3.00 ec = 8.00 ed = 6.00 ee = 0.00
//
//Xuat phat tu thanh pho nao?
// Nhap mot trong cac thanh pho tu a den e: a
//
//PHUONG AN TIM DUOC:
// Canh ac =  4.00
// Canh cb =  4.00
// Canh be =  3.00
// Canh ed =  6.00
// Canh da =  2.00
//CHU TRINH : a-> c-> b-> e-> d-> a
//Tong do dai cac canh cua chu trinh = 19.00
