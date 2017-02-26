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

//ios::sync_with_stdio(0);



int main() {
    double k;
    while (cin >> k) {
        int sum = 0;
        vector<pair<long double,long double> > numbers;
        long double x, y = inf, last_y = inf;
        bool con = true;
        for (x = k + 1; y > x; ++x) {
            y = (x*k)/(x-k);
            int a = (int) y;
            if( (double) a - y == 0) {
                numbers.push_back(make_pair(x, y));
                sum++;
            }
        }
        cout << sum << endl;
        for (int i = 0; i < numbers.size(); ++i) {
            std::cout << std::fixed;
            std::cout << std::setprecision(0);
            cout << "1/" << k << " = " << "1/" << numbers[i].second << " + " << "1/" << numbers[i].first << endl;
        }
    }
}
