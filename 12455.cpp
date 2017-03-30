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
    int tc;
    cin >> tc;
    while (tc--) {
        int length, bars;
        cin >> length >> bars;
        vi bar_lengths(bars);
        for (int i = 0; i < bars; ++i) {
            int temp;
            cin >> temp;
            bar_lengths[i] = temp;
        }
        int sum = 0 , j;
        for ( j = 0; j < (1 << bars); ++j) {
            for (int i = 0; i < bars; ++i) {
                if(j & (1<<i))
                   sum += bar_lengths[i];
            }
            if(sum == length) {
                cout << "YES" << endl;
                break;
            }
            sum = 0;
        }
        if(j == 1<<bars)
            cout << "NO"<<endl;
    }

}
