#include<stdio.h>
#define size 30

//7
//5 4
//8 9 7
//5 1 7 6
//8 4 5 3 7
void readFile(int a[][size], int *n){
	FILE *f;
	f=fopen("tam_giac_so.txt", "r");
	if(f==NULL){
		printf("Loi mo file!!!\n");
		return;
	}
	int i=0, j;	
	while (!feof(f)){
		for(j=0; j<=i; j++)
			fscanf(f, "%d", &a[i][j]); 
		i++;
		}
	*n=i;
	fclose(f);
}

void printData(int a[][size],int n){
	printf("\nTAM GIAC SO da cho\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}

int CS_max(int F[][size],int i,int j){
	if(j == 0) return F[i-1][0] > F[i-1][1] ? 0 : 1;
	
	if(j == i) return i-1;
	
	if(j == i-1) return F[i-1][i-2] > F[i-1][i-1] ? i-2 : i-1;
	
	if(F[i-1][j-1] > F[i-1][j] && F[i-1][j-1] > F[i-1][j+1]) return j-1;
	if(F[i-1][j] > F[i-1][j-1] && F[i-1][j] > F[i-1][j+1]) return j;
	if(F[i-1][j+1] > F[i-1][j-1] && F[i-1][j+1] > F[i-1][j]) return j+1;
}

//dung cong thuc truy hoi de tao bang F
void tao_bang(int a[][size],int n,int F[][size]){
	//2 dong dau tien xac dinh cu the 0 1
	F[0][0] = a[0][0];
	F[1][0] = F[0][0] + a[1][0];
	F[1][1] = F[0][0] + a[1][1];
	
	//tu dong thu 3   i = 2
	for(int i = 2; i < n; i++){
		for(int j = 0; j <= i; j++){
			int k = CS_max(F,i,j);
			F[i][j] = a[i][j] + F[i-1][k];
		}
	}
}

void inBang(int F[][size],int n){
	printf("\nBang F\n");
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j <= i; j++){
			printf("%5d",F[i][j]);
		}
		printf("\n");
	}
}

int CS_max_dong_cuoi(int F[],int j){
    int max = F[0];
	int maxIndex = 0;
	for(int i = 1; i <= j; i++){
		if(F[i] > max){
			max = F[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

void Tra_Bang(int a[][size], int n, int F[][size], int PA[]){
	int j;
	j=CS_max_dong_cuoi(F[n-1],n-1);
	
	PA[n-1]=a[n-1][j];
	
	for(int i=n-1; i>=1; i--){
		
		j=CS_max(F,i,j);
		
		PA[i-1]=a[i-1][j];
	}
}


int giaPA(int PA[],int n){
	int tong = 0;
	for(int i = 0; i < n; i++){
		tong += PA[i];
	}
	return tong;
}

void PrintPA(int PA[], int n){
	int i;
	printf("\nPhuong an la duong di qua cac so : ");
	printf("\%d", PA[0]);
	for(i=1; i<n; i++)	printf(" => %d", PA[i]);
	printf("\n\nTong cac so tren duong di la %d\n", giaPA(PA,n));
}



int main(){
	int a[size][size];
	int n;
	readFile(a,&n);
	printf("\nBai toan TAM GIAC SO dung thuat toan QUY HOACH DONG\n");
	printData(a,n);
	
	int F[n][size];
	int PA[n];
	tao_bang(a,n,F);
	inBang(F,n);
	Tra_Bang(a,n,F,PA);
	PrintPA(PA,n);
	return 0;
}
//TAM GIAC SO da cho
//    7
//    5    4
//    8    9    7
//    5    1    7    6
//    8    4    5    3    7
//
//Bang F
//    7
//   12   11
//   20   21   18
//   26   22   28   24
//   34   32   33   31   31
//
//Phuong an la duong di qua cac so : 7 => 5 => 9 => 5 => 8
//
//Tong cac so tren duong di la 34

