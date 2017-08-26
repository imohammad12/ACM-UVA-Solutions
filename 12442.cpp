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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back


vector<string> grid;
vii directions = { {-1 , 0}, {0 , 1}  , {1 , 0} ,{0 , -1} };



int main() {
    int n, m , s;
    while (cin >> n >> m >> s && s) {
        int orientation , finalstars = 0;
        grid.assign(n , "");
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        ii start;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (grid[j][i] == 'N') {
                    orientation = 0;
                    start = make_pair(j, i);
                }
                if (grid[j][i] == 'S') {
                    orientation = 2;
                    start = make_pair(j, i);
                }
                if (grid[j][i] == 'O') {
                    orientation = 3;
                    start = make_pair(j, i);
                }
                if (grid[j][i] == 'L') {
                    orientation = 1;
                    start = make_pair(j, i);
                }
            }
        }
        string instruction;
        cin >> instruction;
        ii now = start;
        for (int k = 0; k < s; ++k) {

            if(instruction[k] == 'D'){
                orientation = (orientation+1) %4;
            }
            if(instruction[k] == 'E'){
                if(orientation -1 <0)
                    orientation += 4;
                orientation = (orientation-1) % 4;
            }
            if(instruction[k] == 'F') {
                if (now.first + directions[orientation].first < n && now.second + directions[orientation].second < m && now.second + directions[orientation].second >= 0 && now.first + directions[orientation].first >= 0) {
                    char c = grid[now.first + directions[orientation].first][now.second +
                                                                             directions[orientation].second];
                    if (c != '#'){
                        now.first += directions[orientation].first;
                        now.second += directions[orientation].second;
                    }
                }
            }
            if(grid[now.first][now.second] == '*'){
                finalstars++;
                grid[now.first][now.second] = '.';
            }
        }
        cout << finalstars<< endl;
    }
}
