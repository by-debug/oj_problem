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

//#ifdef ONLINE_JUDGE
	#define settings() ios::sync_with_stdio(0);cin.tie(0)
/*#elif defined(sublime)
	#include <cstdio>
	#define settings() freopen("file.in","r",stdin) // Because Sublime Text doesn't support input from terminal.
#else
	#define settings()
#endif*/

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

vi land, obj;
vi ans;
vi R, last;
vi farmers;
vi bit;
vi employees[100001];
int n, m, q;

struct query
{
    int _l, _r,_n, _c;
    query(int l = 0, int r = 0,int t = 0, int c = 0):_l(l),_r(r),_n(t),_c(c){}
    bool operator< (const query b) const
    {
        return this->_l < b._l;
    }
};

v<query> cameras;

void modify(int x, int val)
{
    while (x <= m)
    {
        bit[x] += val;
        x += lowbit(x);
    }
}

int  bit_query(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

static void do_things(int l, int r, vi &qry, vi &money, v<query> &now_camera, v<query> &now_query, int &now)
{
    now_camera = v<query>(cameras.begin()+l, cameras.begin()+r+1);
    for (auto i:qry)
    {
        for (auto j:employees[i])
            now_query.eb(j, R[j], 0, i);
    }
    sort(all(now_camera));
    sort(all(now_query));
    /*for (auto i:now_camera)
        cerr << i._l << ',' << i._r << ',' << i._c << ' ';
    debug_enter();
    for (auto i:now_query)
        cerr << i._l << ',' << i._r << ',' << i._c << ' ';
    debug_enter();*/
    for (auto i:now_query)
    {
        while (now < now_camera.size() && now_camera[now]._l <= i._l)
        {
            modify(now_camera[now]._r+1, now_camera[now]._c);
            ++now;
        }
        money[i._c] += bit_query(i._r) - bit_query(i._l);
    }
    //debug_all(money);
}

static void undo_things(int l, int r, v<query> &now_camera,int &now)
{
    for (int i = 0; i < now; ++i)
        modify(now_camera[i]._r+1, -now_camera[i]._c);
}

static void split(vi &old, vi &ok, vi &fail, vi &money)
{
    for (auto i:old)
    {
        if (money[i] >= obj[i])
        {
            ok.pb(i);
        }
        else
        {
            fail.pb(i);
            obj[i] -= money[i];
        }
    }
    vi().swap(old);
    vi().swap(money);
}

void total_BS(int l, int r, vi &qry)
{
    //debug(l);
    //debug(r);
    if (l == r)
    {
        for (auto i:qry)
        {
            ans[i] = l;
        }
        return;
    }
    int mid = l + (r - l)/2;
    vi tmp;
    int now = 0;
    v<query> now_camera, now_query;
    tmp.assign(n, 0);
    do_things(l, mid, qry, tmp, now_camera, now_query,now);
    //debug(now);
    vi lft, rgt;
    undo_things(l, mid, now_camera, now);
    split(qry, lft, rgt, tmp);
    //debug_enter();
    total_BS(mid + 1, r, rgt);
    total_BS(l, mid, lft);
}

signed main()
{
	settings();
    cin >> n >> m >> q;
    land.assign(m, 0);
    obj.assign(n, 0);
    cameras.assign(q, query());
    farmers.assign(n, 0);
    bit.assign(m+1, 0);
    R.assign(m+1,0);
    last.assign(n+1,m);
    ans.assign(n, 0);
    for (int i = 0; i < n; ++i)
        farmers[i] = i;
    for (int i = 0; i < m; ++i)
    {
        cin >> land[i];
        --land[i];
        employees[land[i]].pb(i);
    }
    for (int i = m-1; i >= 0; --i)
    {
        R[i] = last[land[i]];
        last[land[i]] = i;
    }
    for (auto &i:obj)
        cin >> i;
    for (int i = 0; i < q; ++i)
    {
        cin >> cameras[i]._l >> cameras[i]._r >> cameras[i]._c;
        --cameras[i]._l;
        --cameras[i]._r;
        cameras[i]._n = i;
    }
    total_BS(0, q, farmers);
    for (auto i:ans)
        cout << ((i == q)?-1:i+1) << '\n';
	return 0;
}
