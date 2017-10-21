#include <pthread.h>
#include <stdio.h>

int x;

void print_prime(){
	int i=1;
	for (int i=2;i<=x;i++){
		int temp=0;
		for (int j=2;j<=i;j++){
			if (i%j==0){
			temp++;
			}
		}
	if (temp==1) printf ("%d ",i);
	}
}

int main(){
	printf ("input angka: ");
	scanf ("%d", &x);
	print_prime();
}
