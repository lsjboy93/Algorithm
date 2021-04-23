#include <iostream>
#include <cstring>
using namespace std;

int best = 0;
typedef pair<int, int> ii;

int dir[9][2] = { {},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };

bool isin(int r, int c)
{
	if (r >= 0 && r < 4 && c >= 0 && c < 4)
		return true;
	return false;
}

void dfs(int r, int c, ii mat[4][4], ii fishes[17], int sum)
{
	ii newmat[4][4], newfishes[17];
	for (int i = 0; i < 16; i++)
	{
		newmat[i / 4][i % 4] = mat[i / 4][i % 4];
		newfishes[i + 1] = fishes[i + 1];
	}

	int cr, cc, nr, nc, d;
	for (int i = 1; i <= 16; i++)
	{
		if (newfishes[i].first != -1)
		{
			cr = newfishes[i].first;
			cc = newfishes[i].second;
			d = newmat[cr][cc].second;
			while (1)
			{
				nr = cr + dir[d][0];
				nc = cc + dir[d][1];
				if (isin(nr, nc) && pair<int,int>(nr, nc) != pair<int, int>(r, c))
				{
					newmat[cr][cc].second = d;
					ii tmp = newmat[nr][nc];
					newmat[nr][nc] = newmat[cr][cc];
					newmat[cr][cc] = tmp;

					newfishes[newmat[nr][nc].first] = { nr, nc };
					newfishes[newmat[cr][cc].first] = { cr, cc };
					break;
				}
				else
				{
					d = d % 8 + 1;
				}
			}
		}
	}


	d = newmat[r][c].second;
	newmat[r][c].first = 0;
	for (int i = 1; i <= 3; i++)
	{
		nr = r + dir[d][0] * i;
		nc = c + dir[d][1] * i;;
		if (isin(nr, nc) && newmat[nr][nc].first != 0)
		{
			int tmpn = newmat[nr][nc].first;
			ii tmpfish = newfishes[tmpn];
			newmat[nr][nc].first = -1;
			newfishes[tmpn] = { -1,-1 };

			dfs(nr, nc, newmat, newfishes, sum + tmpn);
			newmat[nr][nc].first = tmpn;
			newfishes[tmpn] = tmpfish;
		}
	}

	if (sum > best)
		best = sum;

	return;
}


int main()
{
	int n, d;
	ii mat[4][4], fishes[17];


	for (int i = 0; i < 16; i++)
	{
		cin >> n >> d;
		mat[i / 4][i % 4] = { n , d };
		fishes[n] = { i / 4, i % 4 };
	}

	int num = mat[0][0].first;
	fishes[num] = { -1, -1 };
	mat[0][0].first = -1;

	dfs(0, 0, mat, fishes, num);

	cout << best << endl;
}