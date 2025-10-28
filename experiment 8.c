#include <stdio.h>
#define MAX_N 1001
#define MAX_W 1001

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	int N, W;
	int val[MAX_N], wt[MAX_N];
	int dp[MAX_N][MAX_W];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &val[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &wt[i]);
	scanf("%d", &W);
	for (int i = 0; i <= N; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				dp[i][w] = 0;
			else if (wt[i - 1] <= w)
				dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
			else
				dp[i][w] = dp[i - 1][w];
		}
	}
	printf("%d\n", dp[N][W]);
	return 0;
}
