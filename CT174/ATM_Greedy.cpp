//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct{
//	char tenTien[25];
//	int MG,PA;
//}Tien;
//
//Tien* readFile(int *n){
//	FILE *f = fopen("ATM.txt","r");
//	if(f==NULL){
//		printf("loi mo file");
//	}
//	Tien *dslt = (Tien*)malloc(sizeof(Tien));
//	int i = 0;
//	while(!feof(f)){
//		fscanf(f,"%d%[^\n]",&dslt[i].MG,&dslt[i].tenTien);
//		dslt[i++].PA = 0;
//		dslt=(Tien*)realloc(dslt, sizeof(Tien)*(i+1));
//	}
//	*n = i;
//	fclose(f);
//	return dslt;
//}
//
//void swap(Tien *x,Tien *y){
//	Tien temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//void bubbleSort(Tien *dslt,int n){
//	for(int i = 0; i <= n-2; i++){
//		for(int j = n-1; j >= i+1; j--){
//			if(dslt[j].MG > dslt[j-1].MG){
//				swap(&dslt[j],&dslt[j-1]);
//			}
//		}
//	}
//}
//
//void greedy(Tien *dslt, int n, int tienCanRut){
//	bubbleSort(dslt,n);
//	int i = 0;
//	//khi tien can rut <= 0 hoac khong tim thay to tien phu hop thi ket thuc
//	while(i < n && tienCanRut > 0){
//		dslt[i].PA = tienCanRut/dslt[i].MG;               //xac dinh so to
//		tienCanRut = tienCanRut - dslt[i].PA*dslt[i].MG;  //xac dinh lai tien can rut
//		i++;
//	}
//	
//}
//
//void print(Tien *dslt,int n,int tienCanRut){
//	int tongTienTra = 0;
//	 printf("|%-3s|%-25s|%-9s|%-9s|%-10s|\n", "STT", "   Loai tien ","Menh Gia", "So to","Thanh tien");
//	 printf("|---|-------------------------|---------|---------|----------|\n");
//	for(int i = 0; i < n; i++){
//		if(dslt[i].PA!=0){
//			printf("|%-3d|%-25s|%-9d|%-9d|%-10d|\n",i+1,dslt[i].tenTien,dslt[i].MG,dslt[i].PA,dslt[i].MG*dslt[i].PA);
//			tongTienTra += dslt[i].MG*dslt[i].PA;
//		}
//	}
//	printf("\nSo tien can rut: %d\n",tienCanRut);
//	printf("So tien da tra: %d\n",tongTienTra);
//}
//int main(){
//	Tien *dslt;
//	int n,tienCanRut;
//	printf("Nhap so tien can rut: ");
//	scanf("%d",&tienCanRut);
//	dslt = readFile(&n);
//	greedy(dslt,n,tienCanRut);
//	print(dslt,n,tienCanRut);
//}
//Nhap so tien can rut: 1259000
//|STT|   Loai tien             |Menh Gia |So to    |Thanh tien|
//|---|-------------------------|---------|---------|----------|
//|1  | Nam tram ngan dong      |500000   |2        |1000000   |
//|2  | Hai tram ngan dong      |200000   |1        |200000    |
//|4  | Nam muoi ngan dong      |50000    |1        |50000     |
//|7  | Nam ngan dong           |5000     |1        |5000      |
//|8  | Hai ngan dong           |2000     |2        |4000      |
//
//So tien can rut: 1259000
//So tien da tra: 1259000
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct {
	char tenTien[25];
	int MG,PA;
}Tien;

Tien *readFile(int *n){
	FILE *f = fopen("ATM.txt","r");
	if(f==NULL) printf("Loi mo file");
	Tien *dslt = (Tien*)malloc(sizeof(Tien));
	int i = 0;
	while(!feof(f)){
		fscanf(f,"%d%[^\n]",&dslt[i].MG,&dslt[i].tenTien);
		dslt[i].PA = 0;
		i++;
		dslt = (Tien*)realloc(dslt,sizeof(Tien)*(i+1));
	}
	*n=i;
	fclose(f);
	return dslt;
}

void swap(Tien *x,Tien *y){
	Tien temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(Tien *dslt,int n){
	for(int i = 0; i <= n-2; i++){
		for(int j = n-1; j >= i+1; j--){
			if(dslt[j].MG > dslt[j-1].MG){
				swap(&dslt[j],&dslt[j-1]);
			}
		}
	}
}

void greedy(Tien *dslt,int n,int TienCanRut){
	for(int i = 0; i < n; i++){
		dslt[i].PA = TienCanRut / dslt[i].MG;
		TienCanRut = TienCanRut - dslt[i].PA * dslt[i].MG;
	}
}

void inDS(Tien *dslt,int n,int TienCanRut){
	printf("Bai toan tra tien may ATM thuat toan tham:\n");
	int TongTienTra = 0;
	for(int i = 0; i < n; i++){
		if(dslt[i].PA !=0){
		printf("- STT: %d\n",i+1);
		printf("- Loai tien: %s\n",dslt[i].tenTien);
		printf("- Menh gia: %d\n",dslt[i].MG);
		printf("- So to: %d\n",dslt[i].PA);
		printf("- Thanh tien: %d\n",dslt[i].PA*dslt[i].MG);
		printf("-------------------------------------\n");
		TongTienTra += dslt[i].PA*dslt[i].MG;
	    } 
	}
	printf("So tien rut: %d\n",TienCanRut);
	printf("Tong tien tra: %d\n",TongTienTra);
}

int main(){
	int n;
	Tien *dslt = readFile(&n);
	int TienCanRut;
	printf("Nhap so tien can rut: ");
	scanf("%d",&TienCanRut);
	bubbleSort(dslt,n);
	greedy(dslt,n,TienCanRut);
	inDS(dslt,n,TienCanRut);
	free(dslt);
	return 0;
}
