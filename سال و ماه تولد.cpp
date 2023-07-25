# include <stdio.h>
int main() {
	int D,M,Y;
	scanf("%d", &D);
	M = D % 100;
	Y= (D - (D % 100)) / 100;
	printf("saal:%02d", Y);
	printf("\nmaah:%02d",M);

	return 0;

 }