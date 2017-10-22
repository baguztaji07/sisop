#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char perintah[100];
	char nama[100];
	int t;
	while(1){
		scanf("%s",&perintah);
		if(strcmp("play",perintah)==0){
			scanf("%s",&nama);
			//system("play nama");
		}
		else if(strcmp("list",perintah)==0){
                        //system("playlist");
                }
		else if(strcmp("pause",perintah)==0){
                        scanf("%d",&t);
			system("pause");
                        //system("pause ...");
                }
		else if(strcmp("continue",perintah)==0){
                        scanf("%d",&t);
                        //system("continue ");
                }
		else if(strcmp("stop",perintah)==0){
                        scanf("%d",&t);
                        //system("stop nama");
                }
		else if(strcmp("help",perintah)==0){
                        printf("------HELP------\n");
			printf("1. play [nama file]\n");
			printf("2. pause [berapa detik]\n");
			printf("3. continue [berapa detik]\n");
			printf("4. stop [berapa detik]\n");
			printf("5. list\n");
			printf("6. help\n");
			printf("7. exit\n");
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
