/*
  https://onlinejudge.org/external/1/100.pdf
*/
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

int fun (int a, int b)
{
    if(a == b) return 1;
    if(a & 1) return fun(3 * a + 1 , b) + 1;
    return fun(a/2, b) + 1;
}

int main()
{
    fast;

    int a, b;
    cin >> a >> b;
    int maxx = 1;
    for(int i = a; i <= b; i++)
    {
        maxx = max(maxx, fun(i, 1));
    }
    cout << a << ' ' << b << ' ' << maxx;
    return 0;
}
