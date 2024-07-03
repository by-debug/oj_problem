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

int n,s,t,c,m;
const int maxn = 101;

struct Edge
{
    int _from, _to, _cap, _flow;
    Edge(int i,int j, int c, int f):_from(i), _to(j), _cap(c), _flow(f){}
};

struct EdmondsKarp 
{
    int n,m;
    v<Edge> edges;
    vi G[maxn];
    int a[maxn];
    int p[maxn];
    
    void init(int);
    void AddEdge(int, int, int);
    int MaxFlow(int, int);
};

void EdmondsKarp::init(int n)
{
    for (int i = 0; i < n; ++i)
        G[i].clear();
    edges.clear();
}

void EdmondsKarp::AddEdge(int from, int to, int cap)
{
    edges.eb(from,to,cap,0);
    edges.eb(to,from,0,0);
    m = edges.size();
    G[from].pb(m-2);
    G[to].pb(m-1);
}
 
int EdmondsKarp::MaxFlow(int s, int t)
{
    int flow = 0;
    while(1)
    {
        memset(a, 0 ,sizeof(a) );
        queue<int> Q;
        Q.push(s);
        a[s] = INF;
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); ++i)
            {
                Edge &e = edges[G[x][i]];
                if (!a[e._to] && e._cap > e._flow)
                {
                    p[e._to] = G[x][i];
                    a[e._to] = min(a[x], e._cap - e._flow);
                    Q.push(e._to);
                }
            }
            if (a[t])
                break;
        }
        if (!a[t])
            break;
        for (int u = t; u != s; u = edges[p[u]]._from)
        {
            edges[p[u]]._flow += a[t];
            edges[p[u]^1]._flow -= a[t];
        }
        flow += a[t];
    }
    return flow;
}

signed main()
{
	settings();
    m = 0;
    while(cin >> n, n)
    {
        cin >> s >> t >> c;
        EdmondsKarp graph;
        graph.init(n);
        for (int i = 0; i < c; ++i)
        {
            int from, to, cap;
            cin >> from >> to >> cap;
            graph.AddEdge(from, to, cap);
            graph.AddEdge(to, from, cap);
        }
        int ans = graph.MaxFlow(s,t);
        cout << "Network " << ++m << "\nThe bandwidth is " << ans << ".\n";
    }
	return 0;
}
