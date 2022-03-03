#include <stdio.h>

int box[100];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &box[i]);
	}

	int now = 0;
	for (int i = 0; i < m && now < n; i++) {
		int book;
		scanf("%d", &book);

		while (box[now] < book) {
			now++;
		}
		box[now] -= book;
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += box[i];
	}
	printf("%d", sum);

	return 0;
}