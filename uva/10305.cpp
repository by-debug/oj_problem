#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

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
int n, m, ncount;
vi visited,tasks;
int dependency[101][101];

bool isordered(int task)
{
    visited[task] = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (dependency[task][i])
        {
            if (visited[i] < 0)
                return false;
            else if (!visited[i] && !isordered(i))
                return false;
        }
    }
    debug(ncount);
    debug(task);
    tasks[--ncount] = task;
    visited[task] = 1;
    return true;
}

signed main()
{
	settings();
    while(cin >> n >> m, n != 0 || m != 0)
    {
        visited.resize(n+1);
        tasks.resize(n);
        ncount = n;
        memset(dependency, 0, sizeof(dependency) );
        for (int i = 0; i < m; ++i)
        {
            int a,b;
            cin >> a >> b;
            dependency[a][b] = 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
                isordered(i);
        }
        for (int i = 0; i < n; ++i)
            cout << tasks[i] << ( (i == n-1) ? '\n' : ' ');
        visited.clear();
        tasks.clear();
    }
	return 0;
}
