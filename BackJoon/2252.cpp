#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[32001];
vector<int> answer;
bool visit[32001];

void use(int n)
{
	visit[n] = true;
	for (int e : vec[n])
		if (!visit[e])
			use(e);
	answer.push_back(n);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, f, b;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> f >> b;
		vec[f].push_back(b);
	}

	for(int i=1;i<= n;i++)
	{
		if (!visit[i])
			use(i);
	}

	//for (vector<int>::iterator it = answer.begin(); it != answer.end(); it++)
	//	cout << *it << endl;

	for (vector<int>::reverse_iterator iter = answer.rbegin(); iter != answer.rend(); iter++)
		cout << *iter << ' ';

	return 0;
}