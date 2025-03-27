//#include<stdio.h>
//#define size 30
//
//typedef struct{
//	float do_dai;
//	int dau,cuoi;
//}Canh;
//
//void readFile(Canh a[],int *n){
//	FILE *f =fopen("TSP.txt","r");
//	
//	if(f==NULL){
//		printf("loi mo file");
//		return; 
//	}
//	
//	int k=0;
//	float temp = 0.0;   //luu cac so duoi duong cheo chinh 
//	
//	fscanf(f,"%d",n); //doc so dinh cua do thi
//	
//	for(int i = 0; i < *n; i++){
//		
//		for(int j = i; j < *n; j++){
//			 
//			if(i == j){
//				for(int t = 0; t <= j; t++){
//					fscanf(f,"%f",&temp);   // doc bo qua cac so duoi dung cheo chinh 
//				} 
//			}
//			else{
//				fscanf(f,"%f",&a[k].do_dai); // doc cac so tren duong cheo chinh 
//				a[k].dau = i;
//				a[k].cuoi = j;
//				k++; 
//			} 
//		} 
//	}
//	fclose(f); 
//}
//
//void swap(Canh *x,Canh *y){
//	Canh temp = *x;
//	*x = *y;
//	*y = temp;
//} 
//
//void bubbleSort(Canh a[],int n){
//	for(int i = 0; i <= n-2; i++){
//		for(int j = n - 1; j >= i+1; j--){
//			if(a[j].do_dai < a[j-1].do_dai){
//				swap(&a[j],&a[j-1]);
//			}
//		}
//	}
//}
//int dinhCap3(Canh PA[],int k,Canh moi) {
//	//kiem tra canh moi them vao co tao thanh dinh cap 3 khong
//	int i = 0;
//	int dem = 0; // dem so lan xuat hien cua 1 dinh
//	
//	//kiem tra dinh dau cua canh moi co trung 2 lan voi dinh dau hoac cuoi cua cac canh trong PA
//	    while(i < k && dem < 2){
//		if(moi.dau == PA[i].dau || moi.dau == PA[i].cuoi){
//			dem++;
//		}
//		i++;
//	  }
//	if(dem==2) return 1; // co tao thanh dinh cap 3
//	
//    i = 0;
//    dem = 0;
//    //kiem tra dinh cuoi cua canh moi co trung 2 lan voi dinh dau hoac dinh cuoi cua cac canh trong PA
//        while(i < k && dem < 2){
//    	if(moi.cuoi == PA[i].dau || moi.cuoi == PA[i].cuoi){
//    		dem++;
//		}
//		i++;
//}
//	return dem == 2; //neu co tao dinh cap 3 tra ve 1
//	
//}
//
//
////// khoi tao rung
//void init_forest(int parent[],int n){
//	for(int i = 0; i < n; i++){
//		parent[i] = i;
//	}
//}
//
////// tim goc , tim tu cha ve to tien
//int find_Root(int parent[],int u){
//	while(u != parent[u]){
//		u = parent[u];
//	}
//	return u;
//}
//
////// kiem tra chu trinh thieu, canh moi co 2 dinh cung 1 goc
//int chu_trinh(int r_dau,int r_cuoi){
//	 return (r_dau == r_cuoi);
//}
//
// hop nhat 2 cay, cho nut goc cua 1 nut lam cha cua nut goc nut con lai
//void update_forest(int parent[],int r1,int r2){
//	parent[r2] = r1;
//}
//
//void greedy(Canh a[],int n,Canh PA[]){
//	int parent[n];
//	init_forest(parent,n);
//	int r_dau,r_cuoi;
//	int i,j = 0;
//	// chon n-1 canh k tao thanh chu trinh
//    for(i = 0; i < n*(n-1)/2 && j < n-1;i++){
//    	r_dau = find_Root(parent,a[i].dau);
//    	r_cuoi = find_Root(parent,a[i].cuoi);
//    	//kiem tra k tao thanh dinh cap 3 va k tao chu trinh thieu
//    	if(!dinhCap3(PA,j,a[i]) && !chu_trinh(r_dau,r_cuoi)){
//    		PA[j] = a[i];
//    		j++;
//    		update_forest(parent,r_dau,r_cuoi); // hop nhat 2 cay
//		}
//	}
//	
////	// chon 1 canh cuoi de tao thanh chu trinh du va k tao thanh dinh cap 3
////	// chon tu cac canh con lai chua xet
//	for(; i < n*(n-1)/2; i++){
//		r_dau = find_Root(parent,a[i].dau);
//    	r_cuoi = find_Root(parent,a[i].cuoi);
//    	if(!dinhCap3(PA,n-1,a[i]) && chu_trinh(r_dau,r_cuoi)){
//    		PA[n-1] = a[i]; // dua canh cuoi vao PA de tao chu trinh du
//    		break;          //Ket thuc vi PA da co du n canh, tao thanh chu trinh
//		}
//	}	
//}
// // m = so phan tu , la_PA : cac canh cua phuong an
//void print(Canh a[],int m, int la_PA){
//	float tong = 0.0;
//	for(int i = 0; i < m; i++){
//		printf("%3d %c%c=%8.2f\n",i+1,a[i].dau+97,a[i].cuoi+97,a[i].do_dai);
//		if(la_PA){
//			tong+=a[i].do_dai;
//		}
//	}
//	if(la_PA){
//		printf("Tong do dai = %8.2f\n",tong);
//	}
//}
//
//
//int main(){
//	Canh ds_canh[size];
//	int n;
//	readFile(ds_canh,&n);
//	printf("Phuong an TSP dung thuat toan THAM AN:\n");
//	printf("Danh sach cac canh cua do thi:\n");
//	print(ds_canh,n*(n-1)/2,0);
//	
//	
//	bubbleSort(ds_canh,n*(n-1)/2);
//	printf("Danh sach cac canh cua do thi sau khi sap xep:\n");
//	print(ds_canh,n*(n-1)/2,0);
//	
//    Canh PA[n];
//	greedy(ds_canh, n, PA);
//	
//	printf("\nphuong an: \n");
//	print(PA,n,1);
//	return 0;
//
//}
//Phuong an TSP dung thuat toan THAM AN:
//Danh sach cac canh cua do thi:
//  1 ab=    5.00
//  2 ac=    7.07
//  3 ad=   16.55
//  4 ae=   15.52
//  5 af=   18.00
//  6 bc=    5.00
//  7 bd=   11.70
//  8 be=   11.05
//  9 bf=   14.32
// 10 cd=   14.00
// 11 ce=   14.32
// 12 cf=   18.38
// 13 de=    3.00
// 14 df=    7.62
// 15 ef=    5.00
//Danh sach cac canh cua do thi sau khi sap xep:
//  1 de=    3.00
//  2 ab=    5.00
//  3 bc=    5.00
//  4 ef=    5.00
//  5 ac=    7.07
//  6 df=    7.62
//  7 be=   11.05
//  8 bd=   11.70
//  9 cd=   14.00
// 10 bf=   14.32
// 11 ce=   14.32
// 12 ae=   15.52
// 13 ad=   16.55
// 14 af=   18.00
// 15 cf=   18.38
//
//phuong an:
//  1 de=    3.00
//  2 ab=    5.00
//  3 bc=    5.00
//  4 ef=    5.00
//  5 cd=   14.00
//  6 af=   18.00
//Tong do dai =    50.00

#include<stdio.h>
#define size 30

typedef struct{
	float do_dai;
	int dau,cuoi;
}Canh;

void readFile(Canh a[],int *n){
	FILE *f = fopen("TSP.txt","r");
	if(f==NULL) printf("Loi moi file");
	fscanf(f,"%d",n);
	int k = 0;
	float temp = 0;
	for(int i = 0; i < *n; i++){
		for(int j = i; j < *n; j++){
			if(j==i){
				for(int t = 0; t <= j; t++){
					fscanf(f,"%f",&temp);
				}
			}else{
				fscanf(f,"%f",&a[k].do_dai);
				a[k].dau = i;
				a[k].cuoi = j;
				k++;
			}
		}
	}
	fclose(f);
}

void swap(Canh *x,Canh *y){
	Canh temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(Canh a[],int n){
	for(int i = 0; i <= n-2;i++){
		for(int j = n-1; j>=i+1;j--){
			if(a[j].do_dai < a[j-1].do_dai){
				swap(&a[j],&a[j-1]);
			}
		}
	}
}

void init_forest(int parent[],int n){
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
}

int find_root(int parent[],int u){
	while(u!=parent[u]){
		u = parent[u];
	}
	return u;
}

void update_forest(int parent[],int r1,int r2){
	parent[r2] = r1;
}

int chu_trinh(int r_dau,int r_cuoi){
	return r_dau == r_cuoi;
}

int dinhCap3(Canh PA[],int k,Canh moi){
	int i = 0;
	int dem = 0;
	while(i < k && dem < 2){
		if(moi.dau == PA[i].dau || moi.dau == PA[i].cuoi){
			dem++;
		}
		i++;
	}
	if(dem == 2) return 1;
	i = 0;
	dem = 0;
	while(i < k && dem < 2){
		if(moi.cuoi == PA[i].dau || moi.cuoi == PA[i].cuoi){
			dem++;
		}
		i++;
	}
	return dem == 2;
}

void greedy(Canh a[],int n,Canh PA[]){
	int parent[n];
	init_forest(parent,n);
	int i, j = 0;
	int r_dau,r_cuoi;
	for(i = 0; i < n*(n-1)/2 && j < n-1; i++){
		r_dau = find_root(parent,a[i].dau);
		r_cuoi = find_root(parent,a[i].cuoi);
		if(!dinhCap3(PA,j,a[i]) && !chu_trinh(r_dau,r_cuoi)){
			PA[j] = a[i];
			j++;
			update_forest(parent,r_dau,r_cuoi);
		}
	}
	for(;i< n*(n-1)/2;i++){
		r_dau = find_root(parent,a[i].dau);
		r_cuoi = find_root(parent,a[i].cuoi);
		if(!dinhCap3(PA,n-1,a[i]) && chu_trinh(r_dau,r_cuoi)){
			PA[n-1] = a[i];
			break;
		}
	}
}

void print(Canh a[],int n ,int la_PA){
	float tong = 0.0;
	for(int i = 0; i < n; i++){
		printf("%d %c%c = %.2f\n",i+1,a[i].dau+97,a[i].cuoi+97,a[i].do_dai);
		if(la_PA) tong+=a[i].do_dai;
	}
	if(la_PA) printf("Tong do dai: %.2f\n",tong);
}

int main(){
	int n;
	Canh ds_canh[size];
	readFile(ds_canh,&n);
	printf("Phuong an TSP thuat toan tham an\n\n");
	printf("Danh sach cac canh cua do thi:\n");
	print(ds_canh,n*(n-1)/2,0);
	
	bubbleSort(ds_canh,n*(n-1)/2);
	printf("\nDanh sach cac canh cua do thi da sap xep\n");
	print(ds_canh,n*(n-1)/2,0);
	
	Canh PA[n];
	printf("\nPhuong an\n");
	greedy(ds_canh,n,PA);
	print(PA,n,1);
	return 0;
}
