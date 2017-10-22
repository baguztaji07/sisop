#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int status;

void* menyalin(void *arg)
{
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {
        status=0;
        system("cp baca.txt salin1.txt");
        printf("salin1 sukses\n");
	status=1;
    }
    else if(pthread_equal(id,tid[1]))
    {
	while (status!=1){
	}
        system("cp salin1.txt salin2.txt");
        printf("salin2 sukses\n");
    }
    return NULL;
}
int main(void){
    int i=0;
    int err;
    chdir("/home/arleqouix/Modul3");
    while(i<2)//looping membuat thread 2x
    {
        pthread_create(&(tid[i]),NULL,&menyalin,NULL);
        i++;
    }
    pthread_join(tid[1],NULL);
    pthread_join(tid[0],NULL);
    return 0;
}
