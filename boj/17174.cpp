#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int sum = 0;
	while (n >= m) {
		sum += n;
		n /= m;
	}
	printf("%d", sum + n);

	return 0;
}