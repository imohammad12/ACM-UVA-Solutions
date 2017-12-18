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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define inf 1000000000
#define eps 1e-9

vii moves;
vvi graph;
int destx , desty , r , c;

int bfs(int x , int y) {
    queue<iii> qq;
    vvi flag(r, vi(c, 1));
    int ans = 0, dist;
    qq.push(iii(0, ii(x, y)));
    flag[x][y] = 0;
    while (!qq.empty()) {
        x = qq.front().second.first, y = qq.front().second.second, dist = qq.front().first;
        if (x == destx && y == desty) {
            return dist;
        }
        qq.pop();
        for (auto e: moves) {
            if ((x + e.first) >= 0 && (x + e.first) < r && (y + e.second) >= 0 && (y + e.second) < c &&
                graph[x + e.first][y + e.second] && flag[x + e.first][y + e.second]) {
                qq.push(iii(dist + 1, ii(x + e.first, y + e.second)));
                flag[x + e.first][y + e.second] = 0;
            }
        }
    }
}

int main() {
    int Rbombs, x, nbombs, y;    //   Rbobms denotes the number of rows having bombs & nbombs denotes the number of bombs in each row
    moves = {{-1, 0},
             {0,  1},
             {1,  0},
             {0,  -1}};
    while (cin >> r >> c && r) {
        graph.assign(r, vi(c, 1));
        cin >> Rbombs;
        for (int i = 0; i < Rbombs; ++i) {
            cin >> x >> nbombs;
            for (int j = 0; j < nbombs; ++j) {
                cin >> y;
                graph[x][y] = 0;
            }
        }
        cin >> x >> y >> destx >> desty;
        cout << bfs(x, y) << endl;
    }
    return 0;
}
