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

const int MaxN = 1000000+5;
const int MaxQ = 100000+5;
int A[MaxN];
bool C[MaxQ];
int X[MaxQ] , Y[MaxQ];
int k,m,N,Q;
void gen_dat()
{
   int i,j;
   for( i=k+1; i<=max(Q,N); ++i )
        A[i] = ( A[i-2]*97 + A[i-1]*3 )%m+1;
   for(i=1,j=max(Q,N); i<=Q; ++i,--j)
  {
       C[i] = A[i]&1;
       X[i] = (A[i]+A[j])%N+1;
       if(C[i]) Y[i] = X[i]+ ( (A[i]<<3)+(A[j]<<5)+m )%( N-X[i]+1 );
       else Y[i] = ((A[i]<<3)+(A[j]<<5))%m+1;
   }
}

vi bit;

int sum(int x)
{
    int ret = 0;
    do
    {
        ret += bit[x];
        x -= lowbit(x);
    }while(x > 0);
    return ret;
}

int query(int x)
{
    if (x > 1)
        return sum(x)-sum(x-1);
    else
        return sum(x);
}

void update(int x, int val)
{
    int diff = val - query(x);
    for (;x <= N; x += lowbit(x))
        bit[x] += diff;
}

void init()
{
    bit.resize(N+1);
    for (int i = 1; i <= N; ++i)
        update(i,A[i]);
}

signed main()
{
	settings();
    cin >> k >> m;
    for (int i = 1; i <= k; ++i)
        cin >> A[i];
    cin >> N >> Q;
    gen_dat();
    init();
    for (int i = 1; i <= Q; ++i)
    {
        if (C[i])
            cout << (sum(Y[i]) - sum(X[i]-1))%m << '\n';
        else
            update(X[i],Y[i]);
    }
	return 0;
}
