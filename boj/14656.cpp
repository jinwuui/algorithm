#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int score = 1, sum = 0;
	for (int i = 0; i < n; i++) {
		int now;
		scanf("%d", &now);

		if (now == 1) {
			sum += score;
			score++;
		} else {
			score = 1;
		}
	}
	printf("%d", sum);

	return 0;
}