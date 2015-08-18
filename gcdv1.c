#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdint.h>

int findGCDv1(int a, int b) {
	while (1) {
		if (a > b) a -= b;
		else if (a < b) b -= a;
		else return a;
	}
}

int findGCDv2(int a, int b) {
	while (1) {
		a %= b;
		if (a == 0) return b;
		if (a == 1) return 1;
		b %= a;
		if (b == 0) return a;
		if (b == 1) return 1;
	}
}

int findGCDv3(int a, int b) {
	while (1) {
		if (a > (b * 4)) {
			a %= b;
			if (a == 0) return b;
			if (a == 1) return 1;
		} else if (a >= b) {
			a -= b;
			if (a == 0) return b;
			if (a == 1) return 1;
		}
		if (b > (a * 4)) {
			b %= a;
			if (b == 0) return a;
			if (b == 1) return 1;
		} else if (b >= a) {
			b -= a;
			if (b == 0) return a;
			if (b == 1) return 1;
		}
	}
}

int main(void)
{
	struct timespec t_start, t_end;

	int i,j;
	int gcd1;
	double test_time = 0;
	uint64_t nsec1 = 0;	
	uint64_t nsec2 = 0;

	clock_gettime(CLOCK_MONOTONIC, &t_start);
	nsec1 = ((uint64_t)(t_start.tv_sec) * 1000000000LL + t_start.tv_nsec);
	for(i=2;i<=9999;i++){
		for(j=2;j<i;j++){
			gcd1 = findGCDv1(i,j);
			//gcd2 = findGCDv2(i,j);
			//gcd3 = findGCDv3(i,j);
		}
	}

	clock_gettime(CLOCK_MONOTONIC, &t_end);
	nsec2 = (uint64_t)(t_end.tv_sec) * 1000000000LL + t_end.tv_nsec;
	test_time  = nsec2 - nsec1;

	printf("v1 test_time = %f secconds \n", test_time/1000000000);

	return 0;
}

