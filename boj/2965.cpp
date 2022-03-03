#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int maxv = b - a;
	if (maxv < c - b) maxv = c - b;

	printf("%d", maxv - 1);
	return 0;
}