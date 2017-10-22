#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock;

typedef struct{
	int bawah;
	int atas;
} batas;

int N,T;

int cek(int N){
	int i;
	printf ("coba cek : %d\n", N);
	if (N<2) return 0;
	for (i=2;i*i<=N;i++){
		if (N%i==0) return 0;
	}
	return 1;
}

void *print_prime(void *jum){
	int count=0;
	int baginya = N/T;
//	printf("a\n");
	batas *bagian = jum;
	pthread_mutex_lock (&lock);
	printf ("batas bawah dan atas : %d, %d\n",bagian->bawah, bagian->atas);
	for (int i=bagian->bawah;i<=bagian->atas;i++){
//		printf ("cek bagian bawah & atas:%d , %d\n", bagian->bawah, bagian->atas);
		int temp=0;
		if (cek(i)) printf ("%d\n", i);
	}
	pthread_mutex_unlock (&lock);
	return 0;
}

int main(){
	int err;
	printf ("input N: ");
	scanf ("%d", &N);
	printf ("input T: ");
	scanf ("%d", &T);
	batas bagian;
	int jum=0;
	int counter=1;
	pthread_t tid[T+1];
	pthread_mutex_init (&lock, NULL);
	while (jum<T)
	{	printf ("jumnya : %d\n", jum);
		if (jum==T-1){
			bagian.bawah=counter;
			bagian.atas=N;}
		else {
			bagian.bawah=counter;
			bagian.atas= counter + (N/T) - 1;
			counter = counter +(N/T);}
		printf ("start, end nya: %d, %d \n",bagian.bawah, bagian.atas);
		err=pthread_create( &(tid[jum]), NULL, print_prime,(void*)&bagian);
	if (err!=0){
	printf ("cant create\n");}
	else printf ("success\n");
	jum++;

	}

	for (int x=0;x<T;x++){
	pthread_join (tid[x], NULL);
	}
}
