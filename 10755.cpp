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
typedef vector<long long> vi;
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
    for(int kk = 0 ; kk < tc ; kk++) {
        int A, B, C;
        long long maxx = -1000000000000 , final_max = -10000000000000 ;
        cin >> A >> B >> C;
        vvvi grade(A , vvi(B , vi(C , 0)));
        for (int o = 0; o < A ; o++){
            for (int oo = 0; oo < B; ++oo) {
                for (int ooo = 0; ooo < C; ++ooo) {
                    cin >> grade[o][oo][ooo];
                }
            }
        }
        for (int i = 0; i < A; ++i) {
            for (int j = i; j < A; ++j) {
                vvi sum_rectangle(B , vi(C , 0));
                for (int k = 0; k < B; ++k) {
                    for (int l = 0; l < C; ++l) {
                        for (int m = i; m < j + 1; ++m) {
                            sum_rectangle[k][l] += grade[m][k][l];
                        }
                    }
                }
                for (int n = 0; n < B; ++n) {
                    for (int k = 0; k < C; ++k) {
                        if(n > 0)
                            sum_rectangle[n][k] += sum_rectangle[n-1][k];
                    }
                }
                for (int i1 = 0; i1 < B; ++i1) {
                    for (int k = i1; k < B; ++k) {
                        long long sub , sum_until_now = 0;
                        for (int l = 0; l < C; ++l) {
                            if(i1)
                                sub = sum_rectangle[k][l] - sum_rectangle[i1 -1][l];
                            else
                                sub = sum_rectangle[k][l];
                            sum_until_now += sub;
                            if(sum_until_now > maxx)
                                maxx = sum_until_now;
                            if (sum_until_now < 0)
                                sum_until_now = 0;
                        }
                    }
                }
                final_max = max(final_max , maxx);
            }
        }
        cout << final_max << endl;
        if(kk != tc-1)
            cout << endl;
    }
}
