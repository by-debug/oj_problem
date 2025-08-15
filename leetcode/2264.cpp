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

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n=-1;
        for (int i = 0; i + 2 < num.size(); ++i)
        {
            if (num[i] == num[i+1] && num[i+1] == num[i+2])
            {
                if (((int)num[i]-(int)'0') > n)
                {
                    ans = num.substr(i, 3);
                    n = (int)num[i] - (int)'0';
                }
            }
        }
        return ans;
    }
};

signed main()
{
	settings();
    string s;
    cin >> s;
    cout << Solution().largestGoodInteger(s) << '\n';
	return 0;
}
