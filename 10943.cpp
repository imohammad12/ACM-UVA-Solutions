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


vvll memo;
ll k , n;

ll dp( ll k_remian , ll sum_remain  ){
    if( k_remian == k && sum_remain == 0)
        return 1;
    if(k_remian > k || sum_remain < 0 )
        return 0;
    ll &nec = memo[k_remian][sum_remain];
    if(nec != -1)
        return nec;
    nec  = 0;
    for (ll i = 0; i <= n; ++i) {
        nec += dp(k_remian +1 , sum_remain - i) % 1000000;
    }
    return nec;
}

int main(){
    while (cin >> n >> k && n){
        memo.assign(k+3 , vll(n+3 , -1 ));
        cout << dp(0 , n) % 1000000 << endl;
    }
}
