nclude <iostream>
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

int main() {

    int n;
    cin >> n;
    while(n--) {
        int row, col;
        cin >> row >> col;
        vvi matrix(row, vi(col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> matrix[i][j];
            }
        }

        vvii AdjList(row * col);



        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if(j != 0)
                    AdjList[i * col + j].push_back(ii(i * col + j - 1 ,matrix[i][j - 1] )) ;
                if(j != col - 1) {
                    AdjList[i * col + j].push_back(ii(i * col + j + 1 ,matrix[i][j + 1] )) ;
                }
                if(i != row - 1)
                    AdjList[i * col + j].push_back(ii((i + 1) * col + j , matrix[i + 1][j]));
                if(i != 0)
                    AdjList[i * col + j].push_back(ii((i - 1) * col + j , matrix[i - 1][j]));
            }
        }
        int s = 0;
        vi dist(row * col, 1000000);
        dist[s] = matrix[0][0];
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(matrix[0][0], s));
        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u]) continue; // this is a very important check
            for (int j = 0; j < (int) AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }
        cout << dist[row * col -1] << endl;

    }

}
