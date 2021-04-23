#include <iostream>

using namespace std;

int main()
{
	int n, a = 1;
	cin >> n;
	for (int i = 1;; i++)
	{
		if (a >= n)
		{
			cout << i  << endl;
			break;
		}
		a += i * 6;
	}


	return 0;
}