// Problem: PRIME1 - Prime Generator
// http://www.spoj.com/problems/PRIME1/
#include <stdio.h>
#include <stdlib.h>

int sieve_size = 1000;
int last_prime = 0;
int last_prime_index = 0;
int known_primes[400000]; 

void perform_sieve(int start) {

	int *sieve = (int *) malloc(sizeof(int)*sieve_size); 
	int end = start + sieve_size;

	//initialize sieve
	for (int i=1; i<sieve_size; i++) {
		sieve[i] = 1;
	}

	//elliminate from known primes until reaching sqr_root(end)
	for (int i=0; i<last_prime_index; i++) {
		int current_prime = known_primes[i];

		//compute the index of the first number to elliminate
		//using this prime
		int first = start / current_prime * current_prime;
		if (first < start) {
			first += current_prime;
		}

		//start crossing out multiples of this prime
		for (int j=first; j<end; j+=current_prime) {
			sieve[j-start] = 0;
		}
	}

	//elliminate if there are still remaining primes
	for (int i=0; i<sieve_size; i++) {
		if (sieve[i] == 0) {
			continue;
		}

		int val = i+start;
		int multiple = val;

		//cross out multiples from the sieve
		while (val * multiple <= end) {
			sieve[(val*multiple)-start] = 0;
			multiple++;
		}
	}

	//add remaining items to prime
	for (int i=0; i<sieve_size; i++) {
		if (sieve[i] == 1) {
			printf("%d\n", i+start);
			known_primes[last_prime_index++] = i+start;
			printf("size: %i\n", last_prime_index);
		}
	}

};

int main(void) {

	for (int i=2; i<40000; i += sieve_size) {
		perform_sieve(i);
	}

	//int t;
	//scanf("%d\n", &t);

	//unsigned int m_arr[t];
	//unsigned int n_arr[t];

	//int c = 0;
	//while (c < t) {
	//	unsigned int m;
	//	unsigned int n;
	//	scanf("%du %du", &m, &n);
	//	m_arr[c] = m;
	//	n_arr[c] = n;
	//	c++;
	//}

	return 0;
}
