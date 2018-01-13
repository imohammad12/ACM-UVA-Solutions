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

int r , c;
vvi graph;
vii moves;
ii endd;

int bfs(ii start , int orien) {
    queue<iiii> qq;
    vvvi flag(r, vvi(c, vi(4, 1)));
    if (graph[start.first][start.second] && graph[start.first + 1][start.second] &&
        graph[start.first][start.second + 1] &&
        graph[start.first + 1][start.second + 1]) {
        qq.push(iiii(start, ii(orien, 0)));
        flag[start.first][start.second][orien] = 0;
    }
    while (!qq.empty()) {
        ii top = {qq.front().first.first, qq.front().first.second};
        int dist = qq.front().second.second, topo = qq.front().second.first; //
        if (top == endd)
            return dist;
        qq.pop();
        for (int i = topo, j = 0; j < 4; ++j, i++, i %= 4) {
            ii next = {top.first + moves[i].first, top.second + moves[i].second};
            if (j == 0) {
                for (int k = 0; k < 3; ++k) {
                    if (next.first < r - 1 && next.first >= 0 && next.second >= 0 && next.second < c - 1 &&
                        graph[next.first][next.second] &&
                        graph[next.first + 1][next.second] &&
                        graph[next.first][next.second + 1] && graph[next.first + 1][next.second + 1]) {
                        if(flag[next.first][next.second][i]) {
                            qq.push(iiii(next, ii(i, dist + 1)));
                            flag[next.first][next.second][i] = 0;
                        }

                        next.first += moves[i].first;
                        next.second += moves[i].second;
                    }

                }
            }

            if (j == 1 && flag[top.first][top.second][i]) {
                qq.push(iiii(top,ii(i, dist + 1)));
                flag[top.first][top.second][i] = 0;
            }
            if (j == 2)
                continue;
            if (j == 3 && flag[top.first][top.second][i]) {
                qq.push(iiii(top, ii(i, dist + 1)));
                flag[top.first][top.second][i] = 0;
            }
        }

    }
    return -1;
}



int main() {
    moves = {{-1, 0},
             {0,  1},
             {1,  0},
             {0,  -1}};
    while (cin >> r >> c && r) {
        graph.assign(r, vi(c, 1));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int temp;
                cin >> temp;
                if (temp)
                    graph[i][j] = 0;
            }
        }
        ii start;
        string ori;
        int orientation;
        cin >> start.first >> start.second >> endd.first >> endd.second >> ori;
        start.first -= 1;
        start.second -= 1;
        endd.first -= 1 , endd.second -= 1;
        if (ori == "north")
            orientation = 0;
        else if (ori == "east")
            orientation = 1;
        else if (ori == "south")
            orientation = 2;
        else if (ori == "west")
            orientation = 3;
        cout << bfs(start, orientation) << endl;

    }

    return 0;
}
