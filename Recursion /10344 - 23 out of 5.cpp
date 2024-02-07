// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1285
#include <bits/stdc++.h>
using namespace std;
#define fast cin.tie(0), ios::sync_with_stdio(false);
#define loop(b) for (ll i = 0; i < b; i++)
#define loopp(b) for (ll j = 0; j < b; j++)
#define FOR(i, a, b, c) for (ll i = a; i < b; i += c)
#define F first
#define S second
#define MP make_pair
#define PB push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef double dd;

int arr[5];
bool fun(int tot, int i)
{
    if (i == 5)
        return tot == 23;
    return fun(tot * arr[i], i + 1) || fun(tot + arr[i], i + 1) || fun(tot - arr[i], i + 1);
}

int main()
{
    fast;
    while (true)
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if(sum == 0) break;
        sort(arr, arr+5);
        bool flag = 0;
        do
        {
            flag = fun(arr[0], 1);
            if (flag)
                break;
        } while (next_permutation(arr, arr + 5));
        if (flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}
