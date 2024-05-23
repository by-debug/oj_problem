#include<cstdio>
#include<cstring>
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
int n,ans,cases;
int bit[(int)1e5+1];
v< pair<int,int> > b;

void modify(int pos, int val)
{
    while (pos <= n)
    {
        bit[pos] += val;
        pos += lowbit(pos);
    }
}

int sum(int pos)
{
    int ret = 0;
    while (pos >= 1)
    {
        ret += bit[pos];
        pos -= lowbit(pos);
    }
    return ret;
}

signed main()
{
    cases = 1;
    while(scanf("%lld",&n), n != 0)
    {
        memset(bit,0,sizeof(bit));
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int val;
            scanf("%lld",&val);
            b.pb(pair<int,int>(val,i));
        }
        sort(all(b));
        for (auto i:b)
        {
            ans += sum(n) - sum(i.second);
            modify(i.second, 1);
        }
        printf("Case #%lld: %lld\n", cases, ans);
        ++cases;
        b.clear();
    }
	return 0;
}
