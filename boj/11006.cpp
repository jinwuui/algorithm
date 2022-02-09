#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int leg, chicken;
		scanf("%d %d", &leg, &chicken);

		printf("%d %d\n", chicken * 2 - leg, chicken - (chicken * 2 - leg));
	}

	return 0;
}