#include <stdio.h>
int main() {
	float pi, d, s, p;
	scanf("%f %f",&pi, &d);
	p = pi * d;
	s = pi * (d * d) / 4;
	printf("%.3f %.3f",p,s);
	return 0;
}