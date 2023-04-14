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

vi bit;

void add(int x,int va)
{
    while (x<bit.size())
    {
        bit[x]+=va;
        x += lowbit(x);
    }
}

int query(int x)
{
    int ret = 0;
    while (x>0)
    {
       ret += bit[x];
       x -= lowbit(x); 
    }
    return ret;
}

struct num
{
    int _v,_pos;
    num(int va=0,int pos=-1):_v(va),_pos(pos){}
};
struct qry
{
    int _l,_r,_k,_i;
    qry(int l,int r,int k,int i):_l(l),_r(r),_k(k),_i(i)
    {}
};

v<num> a;
vi c;
int n,m;
vi ans;
v<qry> q;

void split(v<qry> &arr,v<qry> &left,v<qry> &right)
{
    for (auto i:arr)
    {
        int sum = query(i._r)-query(i._l);
        if (sum >= i._k)
            left.pb(i);
        else
            right.pb(i);
    }
    v<qry>().swap(arr);
}

void do_something(int k)
{
    for (auto i:a)
    {
        if (i._v<k)
            add(i._pos,1);
    }
}

void undo_something(int k)
{
    for (auto i:a)
    {
        if (i._v<k)
            add(i._pos,-1);
    }
}

void total_bs(v<qry> &arr,int l,int r)
{
    if (r == l+1)
    {
        for (auto i:arr)
            ans[i._i] = l;
    }
    int m = l + (r-l)/2;
    v<qry> lt,rt;
    do_something(m);
    split(arr,lt,rt);
    total_bs(rt,m,r);
    undo_something(m);
    total_bs(lt,l,m);
}

signed main()
{
	settings();
    cin >> n >> m;
    a.eb();
    c.assign(n+1,0);
    ans.assign(m,0);
    for (int i=1;i<=n;++i)
    {
        int x;
        cin >> x;
        a.eb(x,i);
    }
    sort(all(a),[](num x,num y){return x._v<y._v;});
    for (int i=1;i<=n;++i)
    {
        c[i]=a[i]._v;
        a[i]._v = i;
    }
    sort(all(a),[](num x,num y){return x._pos<y._pos;});
    for (int i=0;i<m;++i)
    {
        int l,r,k;
        cin >> l >> r >> k;
        q.eb(l,r+1,k,i);
    }
    total_bs(q,1,a.size()+1);
    for (auto i:ans)
        cout << i << '\n';
	return 0;
}