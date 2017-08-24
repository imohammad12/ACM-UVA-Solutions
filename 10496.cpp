//                                                  In The Name Of God
//                                              programmer:Mohammad Dehghan
#include <iostream>
using namespace std;

#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <sstream>

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back

int n , start;
vvi dist , memo;

int tsp(int pos, int bitmask) { // bitmask stores the visited coordinates
    if (bitmask == (1 << (n + 1)) - 1)
        return dist[pos][start]; // return trip to close the loop
    if (memo[pos][bitmask] != -1)
        return memo[pos][bitmask];

    int ans = inf;
    for (int nxt = 0; nxt <= n; nxt++) // O(n) here
        if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
            ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
    return memo[pos][bitmask] = ans;
}

int main(){
    int tc;
    cin >> tc;
    while (tc--){
        int width , length , temp1 , temp2;
        cin >> width >> length >> temp1 >> temp2 >> n;
        vii loc(n+1);
        loc[0].first = temp1 ; loc[0].second = temp2;
        for (int i = 1; i <= n; ++i) {
            cin >> loc[i].first >> loc[i].second;
        }
        dist.assign(n+1, vi( n+1 , 0));
        for (int j = 0; j <= n; ++j) {
            for (int i = 0; i <= n; ++i) {
                dist[j][i] = abs(loc[i].first - loc[j].first) + abs(loc[i].second - loc[j].second);
            }
        }
        start = 0;
        memo.assign(n+2 , vi((unsigned long) pow(2 , n+2), -1));
        cout <<"The shortest path has length " <<tsp(0 , 1<< 0) << endl;

    }
}
