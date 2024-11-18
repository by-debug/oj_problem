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

int maxn, nown, n, m;
vvi graph;
v<string> graph_s;

int DFS(int i, int j)
{
    int x = 0;
    if (graph_s[i][j]!='J'||graph[i][j])
        return 0;
    graph[i][j] = nown;
    if (i != 0)
        x+=DFS(i-1,j);
    if (i != n-1)
        x+=DFS(i+1,j);
    if (j != 0)
        x+=DFS(i, j-1);
    if (j != m-1)
        x+=DFS(i, j+1);
    return x+1;
}

signed main()
{
	settings();
    while(cin >> n >> m)
    {
        graph.assign(n, vi(m));
        maxn = 0;
        nown = 1;
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            graph_s.pb(s);
        }
        for (int i = 0; i < n; ++i )
        {
            for (int j = 0; j < m; j++) 
            {
                if (graph_s[i][j] == 'J' && !graph[i][j] )
                {
                    maxn = max(maxn,DFS(i,j));
                    ++ nown;
                }
            }
        }
        cout << nown-1 << ' ' << maxn << '\n';
        graph.clear();
        graph_s.clear();
    }
	return 0;
}
