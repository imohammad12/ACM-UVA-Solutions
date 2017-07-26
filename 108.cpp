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





int main(){
    int n;
    while (cin >> n) {
        vvi grade(n, vi(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grade[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0)
                    grade[i][j] += grade[i - 1][j];
            }
        }
        int maxx = -100000000;
        for (int i1 = 0; i1 < n; ++i1) {
            for (int k = i1; k < n; ++k) {
                int sub, sum_until_now = 0;
                for (int l = 0; l < n; ++l) {
                    if (i1)
                        sub = grade[k][l] - grade[i1 - 1][l];
                    else
                        sub = grade[k][l];
                    sum_until_now += sub;
                    if (sum_until_now > maxx)
                        maxx = sum_until_now;
                    if (sum_until_now < 0)
                        sum_until_now = 0;
                }
            }
        }
        cout << maxx << endl;
    }
}

