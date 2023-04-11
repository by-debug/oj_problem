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

int n,q;

vi bit;

int query(int x)
{
    int ret=0;
    while (x>0)
    {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

int query(int l,int r)
{
    return query(r-1)-query(l-1);
}

void add(int x,int va)
{
    while (x<bit.size())
    {
        bit[x] += va;
        x += lowbit(x);
    }
}

struct seg
{
    int _l,_r,_t;
    seg(int l=-1,int r=-1,int t=-1):_l(l),_r(r),_t(t){}
}

struct num
{
    int _v,_t;
    num(int va,int t):_v(va),_t(t){}
}

v<num> a;

void split(v<seg> &arr,v<seg> &lv,v<seg> &rv,int k)
{
    for (auto i:arr)
    {
        int sum = 0;
        for (int j=i._l;j<i._r;++j)
        {
            if (a[j]._t<i._t)
            {
                add(a[j]._v,1);
                sum += query(1,a[j]._v+1);
            }
            if (sum >= k)
                break;
        }
        if (sum >= k)
        {
            lv.pb(i);
        }
        else
        {
            rv,pb(i);
        }
    }
    vi<seg>().swap(arr);
}

void total_bs(vi &arr,int l,int r)
{
    //整體二分搜
}

signed main()
{
	settings();
    // 輸入
	return 0;
}