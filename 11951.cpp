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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back





int main() {
    int tc;
    cin >> tc;
    for (int i = 1; i <=tc; ++i) {
        int n , m , k;
        cin >> n >> m >> k;
        vvi grade(n , vi(m ,0));
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < m; ++l) {
                cin >> grade[j][l];
            }
        }
        for (int i1 = 0; i1 < n; ++i1) {
            for (int j = 0; j < m; ++j) {
                if(i1)
                    grade[i1][j] += grade[i1-1][j];
                if(j)
                    grade[i1][j] += grade[i1][j-1];
                if(i1 && j)
                    grade[i1][j] -= grade[i1-1][j-1];
            }
        }
        int p , s , smax = 0, pmin = k+1;
        for (int t = 0; t < n; ++t) {
            for (int j = t; j < n ; ++j) {
                for (int l = 0; l < m; ++l) {
                    for (int u = l; u < m; ++u) {
                        p = grade[j][u];
                        if(t)
                            p -= grade[t-1][u];
                        if(l)
                            p -= grade[j][l-1];
                        if(t && l)
                            p += grade[t-1][l-1];
                        s = (j - t + 1) * (u - l +1);
                        if( p <= k){
                            if( s > smax) {
                                smax = s;
                                pmin = p;
                            } else if( s == smax && p < pmin)
                                pmin = p;
                        }
                    }
                }
            }
        }
        if( pmin == k+1)
            pmin = 0;
        cout <<"Case #"<<i<<": "<< smax << " " << pmin << endl;
    }
}
