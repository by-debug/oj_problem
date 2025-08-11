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
#include <cmath>>

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

const int mod = 1000000000 + 7;

int test = 0;

void modify(int pos, int val, vi &bit)
{
    do
    {
        bit[pos] += val;
    }while( (pos += lowbit(pos)) < bit.size());
}

int sum(int pos, vi &bit)
{
    int ans = 1;
    do
    {
        ans += bit[pos];
    }while( (pos -= lowbit(pos)) > 0);
    return ans;
}


int fpow(int b)
{
    int ans = 1;
    int a = 2;
    while (b)
    {
        if (b & 1)
            ans = (ans*a) % mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ans;
}

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vi temp;
        vi powers;
        vi ans;
        int x = 0;
        powers.pb(0);
        do
        {
            if (n & (1<<x))
                powers.pb(x);
        }while( (1 << ++x) <= n);
        vi bit;
        bit.assign(powers.size(), 0);
        for (int i = 1; i < powers.size(); ++i)
            modify(i, powers[i], bit);
        for (int i = 0; i < queries.size(); ++i)
        {
            int begin = queries[i][0], end = queries[i][1]+1;
            ans.pb(((fpow(sum(end,bit))%mod)*(fpow(sum(begin,bit)*(mod-2))%mod))%mod);
        }
        return ans;
    }
};

signed main()
{
	settings();
    int n;
    vvi queries;
    cin >> n;
    int x,y;
    while (cin >> x >> y)
    {
        vi query;
        query.pb(x);
        query.pb(y);
        queries.pb(query);
    }
    vi ans = Solution().productQueries(n, queries);
    debug_all(ans);
	return 0;
}
