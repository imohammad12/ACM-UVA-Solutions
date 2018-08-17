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
#include <algorithm>
#include <iomanip>
#include <queue>
//#include<omp.h>
#include <sstream>

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii , ii> iiii;
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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

int main() {
    int n = 100, f, t , tc = 0;
    while (cin >> f >> t && f) {
        tc++;
        f-- , t--;
        vvi AdjMat(100, vi(100, inf));
        AdjMat[f][t] = 1;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i < n; ++i) {
                if (l == i)
                    AdjMat[l][i] = 0;
            }
        }
        while (cin >> f >> t && f) {
            f--, t--;
            AdjMat[f][t] = 1;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) // this time, we need to use if statement
                    if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) {
                        AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                    }
        int sum = 0, num_all_pairs = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (AdjMat[i][j] != inf && i != j) {
                    sum += AdjMat[i][j];
                    num_all_pairs++;
                }
        cout << fixed << setprecision(3) << "Case "<< tc <<": average length between pages = " <<float(sum) / float(num_all_pairs) << " clicks" << endl;
    }
}

