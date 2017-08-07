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
vvll memo;
ll compilerkhar[5] = { 1, 5, 10, 25, 50 };
vll coins (&compilerkhar[0], &compilerkhar[0]+5);

ll DP(int m , int id){
    if(m < 0 || id == 5)
        return 0;
    if(m == 0)
        return 1;
    ll &ne = memo[m][id];
    if( ne!= -1)
        return ne;
    ne = DP(m - coins[id] ,id) + DP(m , id +1);
    return ne;
}

int main() {
    memo.assign(30001 ,vll(5 , -1));
    while (cin >> n) {
        ll temp = DP(n , 0);
        if (temp != 1)
            cout << "There are " << temp << " ways to produce " << n << " cents change." << endl;
        else
            cout << "There is only " << temp << " way to produce " << n << " cents change." << endl;
    }
}
