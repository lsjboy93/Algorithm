#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<pair<unsigned long long int, int>, unsigned long long int> iii;

int main()
{
	priority_queue<iii, vector<iii>, greater<iii>> work;	//wait, -counter num, id
	priority_queue<iii, vector<iii>, greater<iii>> free;	//wait, counter num, id
	bool ids[1000001];

	memset(ids, 0, sizeof(ids));
	int N, k, w;
	unsigned long long int id, answer = 0, out = 1;
	iii tmp;

	cin >> N >> k;
	for (int i = 0; i < k; i++)
	{
		free.push({ {0, i}, 0 });
	}

	for (int i = 0; i < N; i++)
	{
		cin >> id >>  w;

		if (free.empty())
		{
			tmp = work.top();
			//cout << tmp.second << " * " << out << endl;
			answer += out * tmp.second;
			out++;
			ids[tmp.second]++;
			free.push({ { tmp.first.first, -tmp.first.second }, tmp.second });
			work.pop();
		}
			
		while (!work.empty())
		{
			if (work.top().first.first <= free.top().first.first)
			{
				tmp = work.top();
				//cout << tmp.second << " * " << out << endl;
				answer += out * tmp.second;
				out++;
				ids[tmp.second]++;
				free.push({ { tmp.first.first, -tmp.first.second }, tmp.second });
				work.pop();
			}
			else
				break;
		}
		
		tmp = free.top();
		work.push({ {tmp.first.first + w, -tmp.first.second}, id});
		free.pop();
	}

	while(out <= N)
	{
		tmp = work.top();
		if (!ids[tmp.second])
		{
			//cout << tmp.second << " * " << out << endl;
			answer += out * tmp.second;
			out++;
		}
		work.pop();

	}


	cout << answer << endl;
	return 0;
}