#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[6];
int status=0;
void* play(void *arg)
{
    pthread_t id=pthread_self();
    if(pthread_equal(id,tid[0]))//thread untuk play
    {
        status=0;
        system("mpg123 Akad.mp3");
	status=1;
    }
    else if(pthread_equal(id,tid[1])) //thread untuk stop
    {
	//while (status!=1){
	//}
        system("pkill mpg123");
    }
    else if(pthread_equal(id,tid[2])) //thread untuk list
    {
        //while (status!=1){
        //}
        system("ls");
    }
    else if(pthread_equal(id,tid[3])) //thread untuk help
    {
        printf("------HELP------\n");
        printf("1. play [nama file]\n");
        printf("2. pause [berapa detik]\n");
        printf("3. continue [berapa detik]\n");
        printf("4. stop [berapa detik]\n");
        printf("5. list\n");
        printf("6. help\n");
        printf("7. exit\n");    
    }
    else if(pthread_equal(id,tid[4])) //thread untuk list
    {
        //while (status!=1){
        //}
        system("pkill -STOP mpg123");
    }
    else if(pthread_equal(id,tid[5])) //thread untuk list
    {
        //while (status!=1){
        //}
        system("pkill -CONT mpg123");
    }
    return NULL;
}

int main() {
	char perintah[100];
	char nama[100];
	int t;
	chdir("/home/arleqouix/Music");
	/*while(i<6)//looping membuat thread 2x
    	{
        	pthread_create(&(tid[i]),NULL,&menyalin,NULL);
        	i++;
    	}*/
	while(1){
		scanf("%s",&perintah);
		if(strcmp("play",perintah)==0){
			//scanf("%s",&nama);
			//system("mpg123 Akad.mp3");
			pthread_create(&(tid[0]),NULL,&play,NULL);
		}
		else if(strcmp("list",perintah)==0){
                        pthread_create(&(tid[2]),NULL,&play,NULL);
                }
		else if(strcmp("pause",perintah)==0){
                        //scanf("%d",&t);
			pthread_create(&(tid[4]),NULL,&play,NULL);
                }
		else if(strcmp("continue",perintah)==0){
                        //scanf("%d",&t);
                        pthread_create(&(tid[5]),NULL,&play,NULL);
                }
		else if(strcmp("stop",perintah)==0){
                        //scanf("%d",&t);
                        //system("pkill mpg123");
			pthread_create(&(tid[1]),NULL,&play,NULL);
                }
		else if(strcmp("help",perintah)==0){
                        /*printf("------HELP------\n");
			printf("1. play [nama file]\n");
			printf("2. pause [berapa detik]\n");
			printf("3. continue [berapa detik]\n");
			printf("4. stop [berapa detik]\n");
			printf("5. list\n");
			printf("6. help\n");
			printf("7. exit\n");*/
			pthread_create(&(tid[3]),NULL,&play,NULL);
                }
		else if(strcmp("exit",perintah)==0){
                        break;
                }
		else{
			printf("ketik help untuk info lebih lanjut\n");
		}
	}
	return 0;
}
