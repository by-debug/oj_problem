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

struct edge
{
    int _i,_j,_value;
    edge(int i=0,int j=0,int val=0):_i(i),_j(j),_value(val){}
    bool  operator<( const edge b) const
    {
        return this->_value > b._value;
    }
};

const double eps = 1e-9;
int n,m,ans,root;

priority_queue<edge> pq;

vi disjoint_set;

int find_root(int pos)
{
    if (disjoint_set[pos] == pos)
        return pos;
    return find_root(disjoint_set[pos]);
}

signed main()
{
	settings();
    while(cin >> n >> m, m != 0 && n!= 0)
    {
        ans = 0;
        disjoint_set.resize(n);
        for (int i = 0; i < n; ++i)
            disjoint_set[i] = i;
        for (int i = 0; i < m; ++i)
        {
            int a,b,c;
            cin >> a >> b >> c;
            pq.push(edge(a-1,b-1,c));
        }
        while (!pq.empty())
        {
            edge now = pq.top();
            if (find_root(now._i) != find_root(now._j))
            {
                disjoint_set[find_root(now._i)] = find_root(now._j);
                ans += now._value;
            }
            pq.pop();
        }
        root = find_root(disjoint_set[0]);
        bool connected = true;
        for (auto i:disjoint_set)
        {
            if (find_root(i) != root)
                connected = false;
        }
        if (connected)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }
	return 0;
}
/*
4 5
1 2 4
1 3 2
1 4 7
2 3 5
2 4 9
*/
