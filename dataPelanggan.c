#include <stdio.h>
#include <stdlib.h>
#define max 100
#define hargatiket 50000
#include <time.h>

struct dataPelanggan
{
    int kode;
    char nama[max];
    char film[max];
    int kursi_dipesan[30];
    int harga;
    int waktu;
    char notelp[15];
    int tanggal;
} data[90];

void add(int n)
{
    int kursi;
    puts("INPUT");
    printf("MASUKKAN KODE:");
    scanf("%d", &data[n].kode);

    printf("MASUKKAN NAMA:");
    fflush(stdin);
    gets(data[n].nama);

    printf("MASUKKAN NO TELP:");
    fflush(stdin);
    gets(data[n].notelp);
    struct tm *Sys_T;

    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);
    data[n].tanggal = asctime(Sys_T);

    printf("MASUKKAN FILM:");
    fflush(stdin);
    gets(data[n].film);

    printf("BANYAK PESAN KURSI:");
    scanf("%d", &kursi);
    for (int i = 1; i <= kursi; i++)
    {
        printf("MASUKKAN KURSI %d: \n", i);
        scanf("%d", &data[n].kursi_dipesan[i]);
    }
    data[n].harga = hargatiket * kursi;
    n++;
}

void display()
{
    for (int i = 1; i <= 90; i++)
    {
        if (data[i].kode == 0)
        {
            break;
        }
        printf("\nKODE: %d\n", data[i].kode);
        printf("NAMA: %s\n", data[i].nama);
        printf("NO TELP: %s\n", data[i].notelp);
        printf("TANGGAL: %s", data[i].tanggal);
        printf("FILM: %s\n", data[i].film);
        printf("KURSI: ");
        for (int j = 1; j <= 30; j++)
        {
            if (data[i].kursi_dipesan[j] == 0)
                break;
            printf("%d ", data[i].kursi_dipesan[j]);
        }
        puts("");
        printf("HARGA: %d\n", data[i].harga);
    }
}

void search()
{
    char cari[100];
    printf("MASUKKAN NAMA: ");
    fflush(stdin);
    gets(cari);
    for(int i=1; i<=90; i++)
    {
        if(strcmp(data[i].nama, cari) == 0)
        {
            printf("\nKODE: %d\n", data[i].kode);
            printf("NAMA: %s\n", data[i].nama);
            printf("NO TELP: %s\n", data[i].notelp);
            printf("TANGGAL: %s", data[i].tanggal);
            printf("FILM: %s\n", data[i].film);
            printf("KURSI: ");
            for (int j = 1; j <= 30; j++)
            {
                if (data[i].kursi_dipesan[j] == 0)
                    break;
                printf("%d ", data[i].kursi_dipesan[j]);
            }
            puts("");
            printf("HARGA: %d\n", data[i].harga);
        }
    }
}

int main()
{
    int pilih, n =1;
    do
    {
        puts("================================");
        puts("         Data Pelanggan         ");
        puts("================================");
        puts("        1. Insert data          ");
        puts("        2. Display data         ");
        puts("        3. Find data            ");
        puts("================================");
        printf("MASUKKAN PILIHAN: ");
        scanf("%d", &pilih);
        switch(pilih)
        {
        case 1:
            add(n);
            n++;
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        }
    }
    while(pilih!=0);
}