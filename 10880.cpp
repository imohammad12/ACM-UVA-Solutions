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

    long long C, R;
    for (int k = 0; k < tc; ++k) {
        vector<long long> numbers;
        cin >> C >> R;
        if (C == R) {
            cout <<"Case #"<< k+1 <<": "<<0<<endl;
            continue;
        }
        C -= R;
        long double sq = sqrt((double) C);
        for (long long i = 1; i <= sq; ++i) {
            if (!(C % i)) {
                if (i > R)
                    numbers.push_back(i);
                if ((C / i) > R && ((C/i)!= i))
                    numbers.push_back(C / i);
            }
        }
        sort(numbers.begin(), numbers.end());
        cout <<"Case #"<< k+1 <<":";
        for (int j = 0; j < numbers.size(); ++j) {
            cout<<" "<<numbers[j];
        }
        cout << endl;
    }
}
