#include <stdio.h>

int inp;

struct file {
  int id, nim;
  char nama[100];
};

void new(){
    FILE* fptr;
    printf("Selamat datang ke program File Handling kelompok kami! \n");
    printf("Input 1 untuk melanjutkan program, 2 untuk menghentikan program. : ");
    scanf("%d", &inp);

    if(inp == 1){
      fptr = fopen("data.txt", "w");
      printf("Selamat memulai perjalanan anda di program File Handling. \n");
      fclose(fptr);
    }

    else if(inp == 2){
      fptr = fopen("data.txt", "r");
      printf("Berikut adalah data mahasiswa.\n");
      fclose(fptr);
    }

    else{
             printf("Baik, sampai jumpa lain kali");
    }
}

void add(){
  FILE* fptr;
  fptr = fopen("data.txt", "a");
  struct file add;
  printf("===========================================================================================================================================\n");

  printf("Input id :");
  scanf("%d", &add.id);
  fprintf(fptr, "%d ^ ", add.id);

  printf("Input nama :");
  scanf(" %s", &add.nama);
  fprintf(fptr, "%s ^ ", add.nama);

  printf("Input nim :");
  scanf("%d", &add.nim);
  fprintf(fptr, "%d ^ \n", add.nim);
}

void read()
{   
    FILE * fptr;
    struct file read;
    char mhs[100];

    fptr = fopen("data.txt","r");
    printf("DATA MAHASISWA\n");
    printf("===================================================================================================================================\n");
    while (fgets (mhs, sizeof(mhs), fptr) != NULL){
    sscanf(mhs, "%d ^ %s ^ %d\n", &read.id, read.nama, &read.nim);
    printf("ID : %d\n", read.id);
    printf("Nama : %s\n", read.nama);
    printf("NIM : %d\n", read.nim);
    printf("====================================================================================================================================\n");
    }
    fclose(fptr);
}

int main(){
  FILE * fptr;
  fptr = fopen("data.txt", "r");
  if(fptr != NULL)
    printf("Selamat datang kembali ke TUBES File Handling.\n");
  else new();
  fclose(fptr);

  printf("===========================================================================================================================================\n");
  printf("1. Menambah informasi ke dalam program.\n");
  printf("2. Tampilkan informasi yang ada di dalam program.\n");
  printf("Apa yang ingin anda lakukan? ");
  scanf("%d", &inp);
  
  if(inp == 1)
    add();

  else if(inp == 2)    
    read();

  else 
    printf("Maaf, pilihan anda tidak ada di opsi.");
}
