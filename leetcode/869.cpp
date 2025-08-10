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

struct num
{
    int _n, _digits;
    vi _num_count;
    num(int n):_n(n){
        _num_count.assign(10, 0);
        _digits = 0;
        do
        {
            int x = n%10;
            if (x)
                ++_num_count[x];
            ++_digits;
        }while(n /= 10);
        /*
        debug(_n);
        debug_all(_num_count);
        debug(_digits);
        debug_enter();
        */
    }
    bool operator<(const num& rhs) const
    {
        if (_digits < rhs._digits)
            return true;
        else if (_n < rhs._n)
            return true;
        return false;
    }
    bool equal(num& rhs)
    {
        bool eq = true;
        if (_digits != rhs._digits)
            eq = false;
        for (int i = 0; eq && i < 10; ++i)
        {
            if (_num_count[i] != rhs._num_count[i])
                eq = false;
        }
        return eq;
    }
};

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        num inputs(n);
        num small((int)pow(10,inputs._digits-1)), big((int)pow(10,inputs._digits));
        v<num> twos;
        int x = 1;
        do
        {
            twos.eb(x);
        }while ((x *= 2) <= (int)1e9);
        auto begin = lower_bound(all(twos), small), end = upper_bound(all(twos), big);
        bool ans = false;
        for (auto it = begin; it != end; ++it)
        {
            if (inputs.equal(*it))
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
} S1;


signed main()
{
	settings();
    int n;
    cin >> n;
    cout << S1.reorderedPowerOf2(n) << '\n';
	return 0;
}
