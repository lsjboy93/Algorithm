#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int mat[1000000];
int answer[1000000];
typedef pair<int, int> ii;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(mat, 0, sizeof(mat));
	memset(mat, 0, sizeof(mat));
	int  N;
	cin >> N;
	priority_queue<ii> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> mat[i];
		while (!pq.empty())
		{
			if (-pq.top().first < mat[i])
			{
				answer[pq.top().second] = mat[i];
				pq.pop();
			}
			else
				break;
		}
		pq.push({ -mat[i], i });
	}
	while (!pq.empty())
	{
		answer[pq.top().second] = -1;
		pq.pop();
	}

	for (int i = 0; i < N; i++)
		cout << answer[i] << " ";
	cout << endl;

	return 0;
}