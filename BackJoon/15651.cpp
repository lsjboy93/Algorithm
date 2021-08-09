#include <iostream>

using namespace std;

int n, m;
int mat[8];
void func(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
            cout << mat[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        mat[idx] = i + 1;
        func(idx + 1);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);


    cin >> n >> m;

    func(0);



    

    return 0;
}