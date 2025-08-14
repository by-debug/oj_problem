#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdint>

using namespace std;

#define int long long
#define ld long double

#ifdef ONLINE_JUDGE
	#define settings() ios::sync_with_stdio(0);cin.tie(0)
#elif defined(sublime)
	#include <cstdio>
	#define settings() freopen("file.in","r",stdin) // Because Sublime Text doesn't support input from terminal.
#else
	#define settings()
#endif

#define INF INT64_MAX/100
#define all(x) x.begin(),x.end()

#ifdef ONLINE_JUDGE
    #define debug(x)
#else
    #define debug(x) cerr << #x << " = " << x << '\n'
#endif

#ifdef ONLINE_JUDGE
	#define debug_all(x)
#else
	#define debug_all(x) {cerr << #x << ": "; for (auto i:x) cerr << i << ' '; cerr << '\n';}
#endif

#ifdef ONLINE_JUDGE
	#define debug_enter()
#else
	#define debug_enter() cerr << "\n";
#endif

#define v vector
#define vi v< int >
#define vvi v< vi >

#define lowbit(x) (x)&(-x)

#define pb push_back
#define eb emplace_back

#define setpoint(x) fixed << setprecision(x)

const double eps = 1e-9;

const int mod = (int)1e9+7;

int dp[301][301];

int fpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}

class Solution {
public:
    int numberOfWays(int n, int x) {
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; fpow(i,x) <= n; ++i)
        {
            int p = fpow(i,x);
            for (int j = 0; j <= n; ++j)
            {
                for (int k = 0; k < i; ++k)
                {
                    if (j-p >= 0)
                    {
                        dp[j][i] += dp[j-p][k];
                        dp[j][i] %= mod;
                    }
                }
            }
        }
        /*
        cerr << "dp:\n";
        for (int i = 0; i <= 5; ++i)
        {
            for(int j = 0; j <= 10; ++j)
                cerr << dp[j][i] << ' ';
            cerr << '\n';
        }
        */
        for (int i = 0; i < 301; ++i)
        {
            ans += dp[n][i];
            ans %= mod;
        }
        return ans;
    }
};

signed main()
{
	settings();
    int n, x;
    cin >> n >> x;
    cout << Solution().numberOfWays(n,x) << '\n';
	return 0;
}
