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

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

int main() {

    int N;
    cin >> N;
    for (int k = 1; k <= N; ++k){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vvii AdjList(n);
        for (int i = 0; i < m; ++i) {
            int from , to , w;
            cin >>from >> to >>  w;
            AdjList[from].push_back(ii(to , w));
            AdjList[to].push_back(ii(from , w));
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
        if (dist[t] != inf)
            cout << "Case #" << k << ": " << dist[t] << endl;
        else
            cout << "Case #" << k << ": " << "unreachable" << endl;

    }
}
