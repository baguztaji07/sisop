#include <pthread.h>
#include <stdio.h>

int N,T;

void *print_prime(void *ptr){
	int i=1;
//	printf("a\n");
	for (int i=2;i<=N;i++){
//		printf ("cek angka %d\n", i);
		int temp=0;
		for (int j=2;j<=i;j++){
			if (i%j==0){
			temp++;
			}
		}
	if (temp==1) printf ("prima : %i\n",i);
	}
	return NULL;
}

int main(){
	int err;
	printf ("input N: ");
	scanf ("%d", &N);
	printf ("input T: ");
	scanf ("%d", &T);
//	N=10;
	int jum=0;
	pthread_t thread1;
//	while (jum<T)
//	{
	err=pthread_create( &thread1, NULL, print_prime, NULL);
//	print_prime();
	if (err!=0){
	printf ("cant create\n");}
	else printf ("success\n");
//	jum++;
//	}
	getchar();
	pthread_join (thread1, NULL);
}
