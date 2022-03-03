#include <stdio.h>

int arr[100];

int main() {
	int n, m, l;
	scanf("%d %d %d", &n, &m, &l);

	int cur = 1;
	while (true) {
		arr[cur]++;
		if (arr[cur] == m) break;

		cur = (cur + l - 1) % n + 1;
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += arr[i];
	}
	printf("%d", sum - 1);
	return 0;
}