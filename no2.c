#include <pthread.h>
#include <stdio.h>

int N,T;
//pthread_t tid[T];

void *print_prime(void *jum){
	int count=0;
	int baginya = N/T;
	pthread_t id=pthread_self();
//	printf("a\n");
	int angka= *((int*)jum);
	printf ("angka: %d\n", angka);
//	if (pthread_equal(id,tid[count])){
	for (int i=count*baginya;i<=angka*baginya;i++){
		printf ("cek count %d\n", count);
		int temp=0;
		for (int j=2;j<=i;j++){
			if (i%j==0){
			temp++;
			}
		}
	if (temp==1) printf ("prima : %i\n",i);
//		}
	count++;
//	angka++;
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
	pthread_t tid[T];
	while (jum<T)
	{
	err=pthread_create( &tid[jum], NULL, print_prime,&jum);
//	print_prime();
	if (err!=0){
	printf ("cant create\n");}
	else printf ("success\n");
	jum++;
//	getchar();
	}
	getchar();
//	for (int x=1;x<=T;x++){
//	pthread_join (tid[x], NULL);
//	}
}
