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
#include <bitset>

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



vvi memo , graph;
int cities , start , endss , interc;
set<int> endc;

int dp(int m , int id) {
    if (m == interc && endc.count(id)) {
        return 0;
    }
    if(m >= interc )
        return -9999999;
    int &nec = memo[m][id];
    if( nec != -1)
        return nec;
    nec = 0;
    for (int i = 0; i < cities; ++i) {
        if (i != id)
            nec = max(nec, graph[id][i] + dp(m+1 , i));
    }
    return nec;
}

int main(){
    while(cin >> cities >> start >> endss >> interc && cities){
        graph.assign(cities , vi ( cities , 0));
        for (int i = 0; i < cities; ++i) {
            for (int j = 0; j < cities; ++j) {
                cin >> graph[i][j];
            }
        }
        endc.clear();
        for (int k = 0; k < endss; ++k) {
            int temp;
            cin >> temp;
            endc.insert(temp - 1);
        }
        memo.assign(interc+1 , vi(cities+1 , -1));
        cout << dp(0 , start - 1)<<endl;
    }
}
