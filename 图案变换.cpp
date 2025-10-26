/*#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//90°函数
void rotate_90_cw(std::vector<std::string>& pattern)
{
	int n = pattern.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			std::swap(pattern[i][j], pattern[j][i]);
		}
	}
	for (auto& row : pattern)
	{
		std::reverse(row.begin(), row.end());
	}
}
//主程序
int main()
{
	int T;
	cin >> T;//输入测试用例个数
	
	for (int k = 0; k < T; k++)
	{
		int n;
		cin >> n; // 输入矩阵大小（行数/列数）
		vector<string> concret_pattern; // 定义容器存储二维数据
		vector<string> compared_pattern;//定义对比数据容器
		// 通过 cin 输入 n 行数据，存入容器
		for (int i = 0; i < n; ++i)
		{
			string row1;
			cin >> row1; // 输入一行字符串
			concret_pattern.push_back(row1); // 将每行数据添加到容器
		}

		for (int i = 0; i < n; ++i)
		{
			string row2;
			cin >> row2; // 输入一行字符串
			compared_pattern.push_back(row2); // 将每行数据添加到容器
		}
		
		//分条件
		if(auto case1 = rotate_90_cw(concret_pattern) == compared_pattern)
		{
			cout << "1" << endl;
		}
		
		
		
		
		//输出操作后的数组
		for (const string& row : concret_pattern)
		{
			cout << row << endl;
		}
	}

	return 0;
}*/
//以上尝试过于繁琐，放弃编写，借鉴朋友思路有以下编写
#include<iostream>
using namespace std;

int T, n;
const int MAX = 100;
char fir[MAX][MAX], sec[MAX][MAX];

void rot90cw(char a[MAX][MAX], char b[MAX][MAX])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = a[j][n - 1 - i];
		}
	}
}

void reflect(char a[MAX][MAX], char b[MAX][MAX])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = a[i][n - 1 - j];
		}
	}
}

bool same(char a[MAX][MAX], char b[MAX][MAX])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] != a[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> fir[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> sec[i][j];
			}
		}

		char temp1[MAX][MAX], temp2[MAX][MAX];

		rot90cw(fir, temp1);
		if (same(temp1, sec))
		{
			cout << "1" << endl;
			continue;
		}

		rot90cw(temp1, temp2);
		if (same(temp2, sec))
		{
			cout << "2" << endl;
			continue;
		}

		rot90cw(temp2, temp1);
		if (same(temp1, sec))
		{
			cout << "3" << endl;
			continue;
		}

		reflect(fir, temp1);
		if (same(temp1, sec))
		{
			cout << "4" << endl;
			continue;
		}

		rot90cw(temp1, temp2);
		if (same(temp2, sec))
		{
			cout << "5" << endl;
			continue;
		}

		rot90cw(temp2, temp1);
		if (same(temp1, sec))
		{
			cout << "5" << endl;
			continue;
		}

		rot90cw(temp1, temp2);
		if (same(temp2, sec))
		{
			cout << "5" << endl;
			continue;
		}

		if (same(fir, sec))
		{
			cout << "6" << endl;
			continue;
		}

		cout << "7" << endl;
	}
	return 0;
}