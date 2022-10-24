#include<stdio.h>
#include<string.h>
int i = 0, y = 0, x;
char nim['0'][20],nama['0'][64],kelas['0'][20],dosen['0'][64];

int main(){
    int pilih;

    backMenu :
    printf("\nSistem Pendataan Akun I-Lab Infotech\n\n");
    printf("===PILIH MENU===\n\n");
    printf("1.Create data\n");
    printf("2.Show data\n");
    printf("3.Update data\n");
    printf("4.Delete data\n");
    printf("5.Search data\n");
    printf("6.Exit\n");

    printf("MASUKKAN MENU PILIHAN ANDA : ");
    scanf("%d", &pilih);

    system ("cls");
    switch(pilih){
        case 1 : 
        create_data();
        goto backMenu;
        break;

        case 2 : 
        read_data();
        goto backMenu;
        break;

        case 3 :
        update_data();
        goto backMenu;
        break;

        case 4 :
        delete_data();
        goto backMenu;
        break;
        
        case 5 :
        search_data();
        goto backMenu;
        break;

        case 6 :
        goto Exit;
        break;

        default : 
        printf("Pilihan Yang Anda Masukkan Tidak Tersdia, Silahkan Pilih Kembali ");
        goto backMenu;
        break;
    }
    goto backMenu;
Exit:
printf("\nTerima Kasih QAQA ");
}

int create_data(){
    int p;
    
    backMenu :
    printf("\nMasukan NIM Praktikan : ");
    scanf("%s", &nim[i]);
    printf("Masukan Nama Praktikan : ");
    scanf(" %[^\n]s", &nama[i]);
    printf("Masukan Kelas Pemerograman Dasar : ");
    scanf(" %[^\n]s", &kelas[i]);
    printf("Masukan Nama Dosen : ");
    scanf(" %[^\n]s", &dosen[i]);

    int q;
    if(strlen(nim[i]) == 10){
        if(i == 0){
            printf("Data Awal Berhasil Ditambah");
            i += 1;
        }
        else{
            for(q = 0; q < i; q++){
            if(strcmp(nim[q], nim[i]) == 0){
                printf("Nim Anda Terduplikasi atau Sudah Pernah Dibuat ");
                return 0;
            }
           
           
        }
        printf("Data Berhasil Ditambah");
            i += 1;
            return 0;
        }
        
    }
    else{
        printf("Nim Anda Kurang Atau Lebih Dari");
    }
}

int read_data(){
    int p, q = 1;

    if(i == 0){
        printf("Data Tidak Tersedia\n");
    }
    else{
    for(p = 0; p < i; p++){
        printf("\nData Ke-%i\n", q);
        printf("Nim Mahasiswa : %s\n", nim[p]);
        printf("Nama Mahasiswa : %s\n", nama[p]);
        printf("Kelas Mahasiswa : %s\n", kelas[p]);
        printf("Nama Dosen Mahasiswa : %s\n", dosen[p]);
        q++;
    }
    
    }
    
}
int search_data(){
    char find[20];
    int p;
    printf("Masukkan NIM Yang Akan Dicari : ");
    scanf("%s", &find);
    for(p = 0; p < i; p++)
    {
        if (strcmp(find, nim[p]) == 0)
        {
        printf("NIM = %s\n", nim[p]);
        printf("Nama = %s\n", nama[p]);
        printf("Kelas = %s\n", kelas[p]);
        printf("Dosen = %s\n", dosen[p]);
        return 0;
        }      
    }
 printf("Data Yang Anda Cari Tidak Tersedia ");
}

int update_data(){
    char find[20];
    int p;
    printf("Masukkan NIM Data Yang akan Dirubah : ");
    scanf("%s", &find);
    for(p = 0; p < i; p++)
    {
        if (strcmp(find, nim[p]) == 0)
        {
        printf("Nama Yang Akan Diganti = " );
        scanf(" %[^\n]s", &nama[p]);
        printf("Kelas Yang Akan Diganti = ");
        scanf(" %[^\n]s", &kelas[p]);
        printf("Nama Dosen Yang Akan Diganti = ");
        scanf(" %[^\n]s", &dosen[p]);
        return 0;
        }      
    }
 printf("Data Yang Anda Cari Tidak Tersedia ");
}

int delete_data(){
    char find[20];
    int p;
    int q;
    printf("Masukkan Data Yang Akan Dihapus Dengan NIM : ");
    scanf("%s", &find);
    for(p = 0; p < i; p++)
    {
        if (strcmp(find, nim[p]) == 0)
        {
            for(q = p; q < (i -1); q++){
                strcpy(nim[q], nim[q+1]);
                strcpy(nama[q], nama[q+1]);
                strcpy(kelas[q], kelas[q+1]);
                strcpy(dosen[q], dosen[q+1]);

            }
            
            i = i-1;
            printf("Data Berhasil Dihapus ");
            return 0;

        }
    }
    printf("Data Tidak Ditemukan ");
}