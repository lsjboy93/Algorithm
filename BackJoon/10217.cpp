#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 0x4fffffff
using namespace std;

vector<pair<int, pair<int, int>>> mat[101];

int N, M, K;
int dp[101][10001];


void init()
{
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= M; j++)
			dp[i][j] = INF;
	for (int i = 1; i <= N; i++)
		mat[i].clear();
}

void dijk()
{
	dp[1][0] = 0;
	priority_queue<pair<pair<int, int>, int >> pq;
	pq.push({ {0,0 }, 1 });
	while (!pq.empty())
	{
		int num = pq.top().second;
		int t = -pq.top().first.first;
		int c = -pq.top().first.second;
		pq.pop();

		if (c > M)
			continue;
		for (int i = 0; i < mat[num].size(); i++)
		{
			int next, nc, nt;
			next = mat[num][i].first;
			nc = mat[num][i].second.first + c;
			nt = mat[num][i].second.second + t;

			if (nc > M)
				continue;
			if (nt < dp[next][nc])
			{
				dp[next][nc] = nt;
				pq.push({ {-nt, -nc},next });
			}

		}
	}
}

int main()
{
	int T;
	int u, v, c, d;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M >> K;
		init();
		if (N == 1)
		{
			cout << "0" << endl;
			continue;
		}
		if (K == 0)
		{
			cout << "Poor KCM" << endl;
			continue;
		}
		for (int i = 0; i < K; i++)
		{
			cin >> u >> v >> c >> d;
			mat[u].push_back({ v ,{c,d} });
		}

		dijk();
		int answer = INF;
		for (int i = 0; i <= M; i++)
			answer = answer < dp[N][i] ? answer : dp[N][i];
		if (answer == INF)
			cout << "Poor KCM" << endl;
		else
			cout << answer << endl;
	}





	return 0;
}