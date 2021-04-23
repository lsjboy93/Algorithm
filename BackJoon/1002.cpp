#include <iostream>

using namespace std;

int main()
{
    int T;
    int x1, x2, y1, y2, r1, r2;
    int dx, dy, l, L;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2 && r1 == r2)
            cout << -1 << endl;
        else
        {
            dx = x1 - x2;
            dx = dx * dx;
            dy = y1 - y2;
            dy = dy * dy;
            l = r1 - r2;
            l = l * l;
            L = r1 + r2;
            L = L * L;
            if (l < dx+dy &&dx + dy < L)
            {
                cout << 2 << endl;
            }
            else if (l == dx + dy || L == dx + dy)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }



    return 0;
}