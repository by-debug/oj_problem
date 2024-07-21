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

vvi graph, graph_reverse;
vi lp, reverse_lp;// 紀錄最長路徑
int n,m;

int dp(int x) // 以x為起點的最長路徑
{
    if (lp[x])
        return lp[x];
    int ret = 0;
    for (auto i:graph[x])
        ret = max(ret, dp(i)+1);
    return lp[x] = ret;
}

int reverse_dp(int x) // 以x為中點的最長路徑
{
    if (reverse_lp[x])
        return reverse_lp[x];
    int ret = 0;
    for (auto i:graph_reverse[x])
        ret = max(ret, reverse_dp(i)+1);
    return reverse_lp[x] = ret;
}

signed main()
{
	settings();
    cin >> n >> m;
    graph.assign(n, vi());
    graph_reverse.assign(n, vi());
    lp.assign(n, 0);
    reverse_lp.assign(n, 0);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        graph[x].pb(y);
        graph_reverse[y].pb(x);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, dp(i) + reverse_dp(i));
    cout << ans << '\n';
	return 0;
}
