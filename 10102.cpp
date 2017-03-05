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
    int m;
    while (cin >> m) {
        int table[m][m] , Max_distance = 0;
        for (int i = 0; i < m; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < m; ++j)
                table[i][j] = line[j] - 48;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if(table[i][j] == 1){
                    int distance = inf;
                    for (int k = 0; k <m; ++k) {
                        for (int l = 0; l < m; ++l) {
                            if(table[k][l] == 3 && (abs(i-k) + abs(j-l)) < distance)
                                distance = (abs(i-k) + abs(j-l));
                        }
                    }
                    if(distance > Max_distance)
                        Max_distance = distance;
                }
            }
        }
        cout << Max_distance << endl;
    }


}
