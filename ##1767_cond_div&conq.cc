#include <cstdio>
#include <cmath>
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
int t, ans, ansCnt, limit, n;
int arr[12][12], idxArr[12][2];
void solve(int idx, int cnt, int len) {
	if (idx == limit) {
		if (ansCnt < cnt) {
			ansCnt = cnt;
			ans = len;
		}
		else if (ansCnt == cnt)
			ans = ans < len ? ans : len;
		return;
	}
	int y = idxArr[idx][0];
	int x = idxArr[idx][1];
	int tx, ty;
	solve(idx + 1, cnt, len);
	for (int dir = 0; dir < 4; dir++) {
		bool flag = true;
		ty = y; tx = x;
		// fill
		while (ty > 0 && tx > 0 && ty < n - 1 && tx < n - 1) {
			ty += dy[dir]; tx += dx[dir];
			if (arr[ty][tx] > 0) { // Line or Core
				flag = false;
				break;
			}
			arr[ty][tx] = 2;
		}
		// recurse
		if (flag) solve(idx + 1, cnt + 1, len + std::abs(ty - y) + std::abs(tx - x));

		// restore
		if (flag) arr[ty][tx] = 0;
		while (ty != y || tx != x) {
			ty += dy[(dir + 2) % 4]; tx += dx[(dir + 2) % 4];
			arr[ty][tx] = 0;
		}
		arr[y][x] = 1;
	}
}
int main() {
	scanf("%d", &t);
	for (int k = 1; k <= t; k++) {
		ansCnt = limit = 0;
		ans = 145;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < n - 1; j++)
				if (arr[i][j]) {
					idxArr[limit][0] = i;
					idxArr[limit][1] = j;
					limit++;
				}
		solve(0, 0, 0);
		printf("#%d %d\n", k, ans);
	}
}