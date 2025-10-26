#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct BigInt
{
    vector<int> digits;

    BigInt(long long num = 0)
    {
        if (num == 0)
        {
            digits.push_back(0);
            return;
        }

        while (num > 0)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
    }

    BigInt operator+(const BigInt& other) const
    {
        BigInt res;
        res.digits.clear();
        int carry = 0;
        int i = 0;

        while (i < digits.size() && i < other.digits.size())
        {
            int sum = digits[i] + other.digits[i] + carry;
            res.digits.push_back(sum % 10);
            carry = sum / 10;
            i++;
        }

        while (i < digits.size())
        {
            int sum = digits[i] + carry;
            res.digits.push_back(sum % 10);
            carry = sum / 10;
            i++;
        }

        while (i < other.digits.size())
        {
            int sum = other.digits[i] + carry;
            res.digits.push_back(sum % 10);
            carry = sum / 10;
            i++;
        }

        if (carry > 0)
        {
            res.digits.push_back(carry);
        }

        return res;
    }

    BigInt operator*(const BigInt& other) const
    {
        BigInt res(0);
        res.digits.assign(digits.size() + other.digits.size(), 0);

        for (int i = 0; i < digits.size(); i++)
        {
            int carry = 0;

            for (int j = 0; j < other.digits.size() || carry > 0; j++)
            {
                int mul = res.digits[i + j] + digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                res.digits[i + j] = mul % 10;
                carry = mul / 10;
            }
        }

        while (res.digits.size() > 1 && res.digits.back() == 0)
        {
            res.digits.pop_back();
        }

        return res;
    }

    void print() const
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            cout << digits[i];
        }
        cout << endl;
    }
};

BigInt catalan(int n)
{
    vector<BigInt> c(n + 1);
    c[0] = BigInt(1);

    for (int i = 1; i <= n; i++)
    {
        BigInt sum(0);
        for (int j = 0; j < i; j++)
        {
            sum = sum + c[j] * c[i - 1 - j];
        }
        c[i] = sum;
    }

    return c[n];
}

int main()
{
    int n;
    cin >> n;
    BigInt res = catalan(n);
    res.print();
    return 0;
}
