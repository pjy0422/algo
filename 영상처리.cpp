#include<bits/stdc++.h>
using namespace std;


int m, n;
int board[1001][1001];
int visited[1001][1001];
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n>> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '.') {
				board[i][j] = 0;
			}
			else {
				board[i][j] = 1;
			}
		}
	}
	int cnt = 0;
	int mx = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 or visited[i][j] == 1)
				continue;
			int width = 1;
			cnt++;
			queue<pair<int, int>>q;
			q.push({ i,j });
			visited[i][j] = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 or nx >= m or ny < 0 or ny >= n)
						continue;
					if (visited[nx][ny] == 1 or board[nx][ny] == 0)
						continue;
					visited[nx][ny] = 1;
					q.push({ nx,ny });
					width++;
				}
			}
			mx = max(mx, width);
		}
	}
	cout << cnt << '\n';
	cout << mx << '\n';
}
