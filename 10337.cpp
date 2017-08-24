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

vvi wind , memo;
int n;

int dp(int altitude , int road){
    if(road == n && altitude == 0)
        return 0;
    if(altitude < 0 || (road == n && altitude != 0) || altitude > 9)
        return inf;
    int &nec = memo[altitude][road];
    if( nec != -1 )
        return nec;
    if(altitude > 0) {
        nec = min(dp(altitude - 1, road + 1) + 20, dp(altitude, road + 1) + 30);
        nec = min(nec, dp(altitude + 1, road + 1) + 60);
    }
    if(altitude == 0)
        nec = min(dp(altitude , road+1) + 30 , dp(altitude +1 , road+1) +60);
    nec = nec - wind[altitude][road];

    return nec;
}

int main(){
    int tc;
    cin >> tc;
    while (tc--){
        int x;
        cin >> x;
        n = x/100;
        wind.assign(10 , vi(n , 0));
        for (int i = 9; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                cin >> wind[i][j];
            }
        }
        memo.assign(10 , vi(n , -1));
        cout << dp(0 , 0)<<endl<<endl;
    }
}
