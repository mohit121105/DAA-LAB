#include <stdio.h>

int count = 0;

void solve(int n, int row, int cols, int diag1, int diag2) {
	if (row == n) {
		count++;
		return;
	}

	int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);

	while (available) {
		int bit = available & -available;
		available -= bit;
		solve(n, row + 1, cols | bit, (diag1 | bit) << 1, (diag2 | bit) >> 1);
	}
}

int nQueen(int n) {
	count = 0;
	solve(n, 0, 0, 0, 0);
	return count;
}

int main() {
	int n;
	scanf("%d", &n);

	if (n < 2 || n > 32) {
		printf("0\n");
		return 0;
	}

	printf("%d\n", nQueen(n));
	return 0;
}


