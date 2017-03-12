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
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9





int main() {

    // std::ios::sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc--) {
        bool check = false;
        int A, B, C;
        cin >> A >> B >> C;
        for (int i = -22; i < 22 && !check; ++i) {
            for (int j = -100; j < 100 && !check; ++j) {
                for (int k = -100; k < 100; ++k) {
                    if ((i + j + k == A) && (i * j * k == B) && (j * j + i * i + k * k) == C && i != j && i != k &&
                        j != k) {
                        cout << i << " " << j << " " << k  << endl;
                        check = true;
                        break;
                    }
                }
            }
        }
        if (!check)
            cout << "No solution." << endl;
    }

}
