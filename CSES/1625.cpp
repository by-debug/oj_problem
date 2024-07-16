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

int ans=0;
bool visited[7][7];
string s;

void dfs(int x,int y,int level)
{
    if (x < 0 || x >= 7 || y < 0 || y >= 7)
        return;
    if (visited[x][y])
        return;
    if (x == 0 && y == 6)
    {
        if (level == 48)
            ++ans;
        return;
    }
    visited[x][y] = 1;
    switch(s[level])
    {
        case 'U':
            dfs(x, y-1, level+1);
            break;
        case 'D':
            dfs(x, y+1, level+1);
            break;
        case 'L':
            dfs(x-1, y, level+1);
            break;
        case 'R':
            dfs(x+1, y, level+1);
            break;
        case '?':
            dfs(x, y-1, level+1);
            dfs(x, y+1, level+1);
            dfs(x-1, y, level+1);
            dfs(x+1, y, level+1);
            break;
    }
    visited[x][y] = 0;
}

signed main()
{
	settings();
    cin >> s;
    dfs(0, 0, 0);
    cout << ans << '\n';
	return 0;
}
