#include <stdio.h>
#include <stdlib.h>

int main(){
    // input
    int jmlProses,kuantum;
    
    printf("Round Robin Schedulling\n");
    printf("Masukkan jumlah proses yang akan dilakukan: ");
    scanf("%d",&jmlProses);

    int datang[jmlProses-1], eksekusi[jmlProses-1];
    int i = 0;

    while (i < jmlProses){
        printf("Waktu kedatangan proses ke %d: ",i);
        scanf("%d",&datang[i]);
        printf("Waktu eksekusi proses ke %d: ",i);
        scanf("%d",&eksekusi[i]);
        i++;
    }
    printf("Masukkan waktu kuantum: ");
    scanf("%d",&kuantum);

    //proses masuk antrian
    int proses1 = 0, proses2 = 0, n = 1;
    int urutan = 0;
    int proses3 = 0, proses4 = 0, flag = 0, o = 0, q = 2;
    int urutanproses[jmlProses];
    int* waktuproses = (int*)calloc(jmlProses-1, sizeof(int));

    for (int waktu = 0; datang[jmlProses-1] >= waktu; waktu++){
        if (datang[proses1] == waktu){
            printf("\n----------------------------------\n");
            printf("Waktu : %d ms\n", waktu);
            printf("Proses ke %d masuk ke antrian\n",proses1);
            urutanproses[urutan] = urutan;
            urutan++;
            for (int k = 0; k < proses1 + 1; k++){
                printf("P[%d]\t",urutanproses[k]);
            }
            printf("\n");
            waktuproses[proses3] = waktu - (o * kuantum);
            if ((waktuproses[proses3] >= eksekusi[proses3]) || (eksekusi[proses3] <= kuantum)){
                waktuproses[proses3] = 0;
                waktuproses[proses4] += waktu - (o * kuantum); 
                if (waktuproses[proses4] >= q * kuantum){
                    waktuproses[proses3] = waktuproses[proses4] - q * kuantum;
                    waktuproses[proses4] = q * kuantum;
                    q++;
                    proses4++;  
                }
            }
            else if (waktuproses[proses3] >= kuantum){
                waktuproses[proses3] = kuantum;
                o++;
                waktuproses[proses3 + 1] = waktu - (o * kuantum);
                proses3++;
                }
            for (int p = 0; p < jmlProses; p++){
                printf("P[%d]: %d ms\t", p, waktuproses[p]);
            }
            proses1++;
        }
        else if ((kuantum * n) == waktu){
            printf("\n----------------------------------\n");
            printf("Waktu : %d ms\n", waktu);
            proses2 = urutanproses[0];
            printf("Proses ke %d diantrikan kembali\n",proses2);
            for (int m = 0; m <= proses1; m++){
                urutanproses[m] = urutanproses[m + 1];
                if (urutanproses[m] == urutanproses[proses1]){
                    urutanproses[m] = proses2;
                }
            }
            for (int l = 0; l < proses1; l++){
                printf("P[%d]\t",urutanproses[l]);
            }
            n++;
            proses2++;
        }
    }

    // proses penyelesaian
    printf("\n\n--Semua proses sudah masuk antrian--");

}
