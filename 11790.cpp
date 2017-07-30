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
    for (int i = 1; i <= tc; ++i) {
        int n;
        cin >> n;
        vi seq(n, 0);
        vi weght(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> seq[j];
        }
        for (int l = 0; l < n; ++l) {
            cin >> weght[l];
        }
        vi sum(n , 0);
        for (int k = 0; k < n; ++k) {
            int maxx = 0;
            for (int j = 0; j < k; ++j) {
                if(seq[j] < seq[k])
                    maxx = max(maxx , sum[j]);
            }
            sum[k] = maxx + weght[k];
        }
        int decreasing =0  , increasing = 0 ;

        for (int m = 0; m < n; ++m) {
            increasing = max(increasing , sum[m]);
        }
        sum.clear(); sum.resize(n , 0);
        for (int k = n-1; k >=0; --k) {
            int maxx = 0;
            for (int j = n-1; j > k; --j) {
                if(seq[j] < seq[k])
                    maxx = max(maxx , sum[j]);
            }
            sum[k] = maxx + weght[k];
        }
        for (int m = 0; m < n; ++m)
            decreasing = max(decreasing , sum[m]);
        cout << "Case " << i;
        if (increasing >= decreasing)
            cout << ". Increasing (" << increasing << "). Decreasing (" << decreasing << ").";
        else
            cout << ". Decreasing (" << decreasing << "). Increasing (" << increasing << ").";
        cout << endl;
    }

}
