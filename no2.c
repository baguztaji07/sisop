#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int bawah;
	int atas;
} batas;

int N,T;
//pthread_t tid[3];

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
//	pthread_t id=pthread_self();
//	printf("a\n");
	batas *bagian = jum;
	//int angka= *((int*)jum);
//	printf ("angka: %d\n", angka);
//	if (pthread_equal(id,tid[count])){
	for (int i=bagian->bawah;i<=bagian->atas;i++){
//		printf ("cek bagian bawah & atas:%d , %d\n", bagian->bawah, bagian->atas);
		int temp=0;
		if (cek(i)) printf ("%d\n", i);
	}
	/*	for (int j=2;j<=i;j++){
			if (i%j==0){
			temp++;
			}
		}
	if (temp==1) printf ("prima : %i\n",i);
		}*/
//	count++;
//	angka++;
//	}
	return 0;
}

int main(){
	int err;
	printf ("input N: ");
	scanf ("%d", &N);
	printf ("input T: ");
	scanf ("%d", &T);
	batas bagian;
//	N=10;
	int jum=0;
	int counter=1;
	pthread_t tid[T+1];
	while (jum<T)
	{
		if (jum==T-1){
			bagian.bawah=counter;
			bagian.atas=N;}
		else {
			bagian.bawah=counter;
			bagian.atas= counter + (N/T) - 1;
			counter = counter +(N/T);}
		printf ("counter nya: %d\n", counter);
		err=pthread_create( &(tid[jum]), NULL, print_prime,(void*)&bagian);
//	print_prime();
	if (err!=0){
	printf ("cant create\n");}
	else printf ("success\n");
	jum++;
//	getchar();
	}
//	getchar();
	for (int x=0;x<T;x++){
	pthread_join (tid[x], NULL);
	}
}
