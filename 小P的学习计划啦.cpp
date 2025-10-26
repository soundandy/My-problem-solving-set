#include<iostream>
using namespace std;

int main()
{
	int d;
	cin >> d;
	int b[26];
	int a[365][26];

	for (int i = 0; i < 26; i++)
	{
		cin >> b[i];
	}

	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			cin >> a[i][j];
		}
	}

	int last[26] = { 0 };
	int act[365];
	long long P = 0;

	for (int t = 0; t < d; t++)
	{
		long long S = 0;
		for (int i = 0; i < 26; i++)
		{
			S += b[i] * (t+1 - last[i]);
		}

		int good_i = 0;
		long long good_choice = a[t][0] + b[0] * (t+1 - last[0]);
		for (int i = 1; i < 26; i++)
		{
			long long cur_choice = a[t][i] + b[i] * (t +1- last[i]);
			if (cur_choice > good_choice)
			{
				good_choice = cur_choice;
				good_i = i;
			}
			
		}
		P += a[t][good_i] - S + b[good_i] * (t +1- last[good_i]);
		last[good_i] = t+1;
		act[t] = good_i;
	}

	cout << P << endl;
	for (int i = 0; i < d; i++)
	{
		cout << act[i]+1 << endl;
	}
	return 0;
}