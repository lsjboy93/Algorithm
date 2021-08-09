#include <iostream>

using namespace std;

int n, m;
int mat[8];
void func(int bit, int idx, int mini)
{
    if (mini + m - idx - 1 >= n)
    {
        return;
    }

    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << mat[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = mini; i < n; i++)
    {
        if ((bit & 1 << i) == 0)
        {
            mat[idx] = i + 1;
            func(bit |= (1 << i), idx + 1, i + 1);
            mat[idx] = 0;
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);


    cin >> n >> m;

    func(0, 0, 0);





    return 0;
}