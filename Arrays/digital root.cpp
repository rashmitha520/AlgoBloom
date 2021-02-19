#include <iostream>
#include <string>
using namespace std;

bool isOdd(int sum)
{
    int ans = 0;
    if (sum < 10)
        return sum % 2 != 0;
    while (sum > 0)
    {
        ans = ans + sum % 10;
        sum /= 10;
        if (ans >= 10 && sum == 0)
        {
            sum = ans;
            ans = 0;
        }
        // if(ans<=9) return ans%2!=0;
    }
    return ans % 2 != 0;
}
int main()
{
    string s;
    cin >> s;
    int sum = 0;
    int odd = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ';')
        {
            if (isOdd(sum))
                odd++;
            sum = 0;
            i += 2;
            continue;
        }
        else if (s[i] == ',')
            continue;
        else
            sum += s[i] - '0';
    }
    //for the last no as it will not encounter ';'
    if (isOdd(sum))
        odd++;
    cout << odd << endl;
}
