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

set<int> s;
vi snowflakes;
int t, n, beg, en, nsize;

signed main()
{
	settings();
    cin >> t;
    while (t--)
    {
        cin >> n;
        snowflakes.assign(n,0);
        for (auto &i: snowflakes)
            cin >> i;
        beg= 0;
        en = 1;
        nsize = 1;
        s.insert(snowflakes[beg]);
        while (en < n)
        {
            debug(en);
            debug_all(s);
            int now = snowflakes[en++];
            while (s.find(now) != s.end())
            {
                s.erase(snowflakes[beg++]);
            }
            s.insert(now);
            nsize = max(nsize, (int)s.size() );
        }
        cout << nsize << '\n';
        s.clear();
    }
	return 0;
}
