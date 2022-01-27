#include<stdio.h>  
 
int main(){

    int jmlProses, kuantum;
    printf("Program Round Robin Scheduling\n");
    printf("Masukkan jumlah proses: ");
    scanf("%d",&jmlProses);

    int datang[jmlProses-1], eksekusi[jmlProses-1], temp[jmlProses-1];
    int i = 0;
    while (i < jmlProses){
        printf("\nDetail Proses[%d]\n", i);
        printf("Waktu kedatangan: ");
        scanf("%d",&datang[i]);
        printf("Waktu eksekusi: ");
        scanf("%d",&eksekusi[i]);
        temp[i] = eksekusi[i];
        i += 1;
    }

    printf("\nMasukkan waktu kuantum: ");
    scanf("%d",&kuantum);

    printf("\n| Proses\t| Waktu masuk\t| Waktu eksekusi\t| Waktu selesai\t| Waktu tunggu\t|");
    
    int cek = jmlProses;
    int waktu = 0;
    int flag = 0;
    for (waktu = 0, i = 0; cek > 0;) {
        if (temp[i] <= kuantum && temp[i] > 0) {
            waktu += temp[i];
            temp[i] = 0;
            flag = 1;
        }
        else if (temp[i] > 0){
            waktu += kuantum;
            temp[i] -= kuantum;
        }
        if (temp[i] == 0 && flag == 1){
            printf("\n| P[%d]\t\t| %d\t\t| %d\t\t\t| %d\t\t| %d\t\t|",i,datang[i],eksekusi[i],waktu,waktu - eksekusi[i]);
            cek -= 1;
            flag = 0;
        }
        if (i == jmlProses - 1){
            i = 0;
        }
        else if (datang[i+1] <= waktu){
            i += 1;
        }
    }
    printf("\n\nProgram selesai!");
}   
