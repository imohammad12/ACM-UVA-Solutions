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
int n;
vvi memo;
vvi memo2;
vi bills;

int DP(int id , int v) {
    if (v <= 0)
        return v;
    if (id >= n)
        return -1000000;

    int &ne = memo[id][v];
    if(ne != -1)
        return ne;
    return ne = max( DP(id+1 , v - bills[id]) , DP(id+1 , v));
}

int DP2(int id , int v){
    if(v == 0)
        return 0;
    if(id >= n)
        return inf;
    if(v < 0)
        return inf;

    int &ne = memo2[id][v];
    if(ne != -1)
        return ne;
    return ne = min(DP2(id+1 , v - bills[id]) +1 , DP2(id+1 , v));
}

int main() {
    int tc;
    cin >> tc;
    while (tc--){
        int total;
        cin >> total >> n;
        bills.assign(n , 0);
        memo.assign(n , vi(10001 , -1));
        for (int i = 0; i < n; ++i) {
            cin >> bills[i];
        }
        memo2.assign(n , vi(20001 , -1));
        cout << total + abs(DP(0 , total)) << " "<<DP2(0 , total + abs(DP(0 , total))) << endl;

    }
}
