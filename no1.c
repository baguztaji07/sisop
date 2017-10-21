#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread

void* menyalin(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {
        system("cat baca.txt | awk '{ print $0 }' >> salin1.txt ");
        printf("salin1 sukses");
    }
    else if(pthread_equal(id,tid[1]))
    {
        system("cat salin1.txt | awk '{ print $0 }' >> salin2.txt");
        printf("salin2 sukses");
    }
    return NULL;
}
int main(void){
    int i=0;
    int err;
    chdir("/home/arleqouix/Modul3");
    while(i<2)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&menyalin,NULL);
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}
