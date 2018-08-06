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

int n , m , s , tc , t , p;


int main() {

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> s >> t >> p;
        s--;
        t--;
        vvii AdjList(n);
        vvii AdjList2(n);
        for (int i = 0; i < m; ++i) {
            int node1, node2, price;
            cin >> node1 >> node2 >> price;
            node1--;
            node2--;
            AdjList[node1].push_back(ii(node2, price));
            AdjList2[node2].push_back(ii(node1, price));
        }
        vi dist(n, inf);
        dist[s] = 0;
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, s));
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
        vi dist2(n, inf);
        dist2[t] = 0;
        pq.push(ii(0, t));
        while (!pq.empty()) {
            ii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist2[u]) continue; // this is a very important check
            for (int j = 0; j < (int) AdjList2[u].size(); j++) {
                ii v = AdjList2[u][j];
                if (dist2[u] + v.second < dist2[v.first]) {
                    dist2[v.first] = dist2[u] + v.second;
                    pq.push(ii(dist2[v.first], v.first));
                }
            }
        }

        int maxim = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < AdjList[i].size(); ++j) {
                if (AdjList[i][j].second > maxim) {
                    if (dist[i] + dist2[AdjList[i][j].first] + AdjList[i][j].second <= p)
                        maxim = AdjList[i][j].second;
                }
            }
        }
        cout << maxim << endl;
    }
}
