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
#include <cmath>

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
const int maxn = 1000;

struct Edge
{
    int _from, _to, _cap, _flow;
    Edge(int u, int v, int c, int f):_from(u), _to(v), _cap(c), _flow(f){}
};

struct Point
{
    double _x, _y;
    Point(double x=0, double y=0):_x(x),_y(y){};
    Point operator-(Point);
    double val();
};

Point Point::operator-(Point b)
{
    return Point(this->_x - b._x, this->_y - b._y);
}

double Point::val()
{
    return sqrt( this->_x * this->_x + this->_y * this->_y );
}

double distance(Point a, Point b)
{
    return (a-b).val();
}

struct EK_algorithm
{
    int _m;
    v<Edge> edges;
    vi G[maxn];
    int a[maxn], p[maxn];
    void Init(int);
    void AddEdge(int, int, int);
    int MaxFlow(int, int);
};

void EK_algorithm::Init(int n)
{
    edges.clear();
    for (int i = 0; i < n; ++i)
    {
        G[i].clear();
    }
}

void EK_algorithm::AddEdge(int from, int to, int cap)
{
    edges.eb(from, to, cap, 0);
    edges.eb(to, from, 0, 0);
    _m = edges.size();
    G[from].pb(_m-2);
    G[to].pb(_m-1);
}

int EK_algorithm::MaxFlow(int s, int t)
{
    int flow=0;
    while (1)
    {
        memset(a, 0, sizeof(a) );
        queue<int> Q;
        Q.push(s);
        a[s] = INF;
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < G[now].size(); ++i)
            {
                Edge &e = edges[G[now][i]];
                if (!a[e._to] && e._cap > e._flow)
                {
                    p[e._to] = G[now][i];
                    a[e._to] = min(a[now], e._cap-e._flow);
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
            edges[p[u]]._flow += a[u];
            edges[p[u]^1]._flow -= a[u];
        }
        flow += a[t];
    }
    return flow;
}

int n, m, s, vol;
v<Point> holes, gophers;

signed main()
{
	settings();
    while (cin >> n >> m >> s >> vol)
    {
        debug(n);
        debug(m);
        debug(s);
        debug(vol);
        gophers.assign(n, Point());
        holes.assign(m, Point());
        for (auto& gopher:gophers)
            cin >> gopher._x >> gopher._y;
        for (auto& hole:holes)
            cin >> hole._x >> hole._y;
        EK_algorithm graph;
        graph.Init( n+m+2 );
        for (int i = 1; i <= n; ++i)
            graph.AddEdge(0,i,1);
        for (int i = 1; i <= m; ++i)
            graph.AddEdge( n+i, n+m+1, 1);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (distance(gophers[i-1],holes[j-1]) <= vol*s)
                    graph.AddEdge(i, n+j, 1);
            }
        }
        for (int i = 0; i < n+m+2; ++i)
        {
            debug(i);
            debug_all(graph.G[i]);
        }
        int ans = graph.MaxFlow(0, n+m+1);
        cout << n - ans << '\n';
    }
	return 0;
}
