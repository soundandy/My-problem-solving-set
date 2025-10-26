#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> fake_sheets(n, vector<int>(k + 1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k + 1; ++j)
        {
            cin >> fake_sheets[i][j];
        }
    }

    vector<int> a(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        int p = fake_sheets[i][0] - 1;
        vector<int>& b = fake_sheets[i];
        if (b[p + 1] > a[p]) {
            for (int j = 0; j < k; ++j)
            {
                a[j] = b[j + 1];

            }
        }
    }

    for (int i = 0; i < k; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}