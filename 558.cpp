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

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m , s;
        cin >> n >> m;
        vvii AdjList(n);
        for (int i = 0; i < m; ++i) {
            int x, y, t;
            cin >> x >> y >> t;
            AdjList[x].push_back(ii(y, t));
        }
        s = 0;
        vi dist(n, inf);
        dist[s] = 0; // holds the distance
        for (int i = 0; i < n - 1; i++) {
            bool up = false; // used to prune before finishing when no update is neccessary.
            for (int j = 0; j < n; j++)
                for (auto &e : AdjList[j])
                    if (dist[e.first] > e.second + dist[j]) {
                        up = true;
                        dist[e.first] = e.second + dist[j];
                    }
            if (!up) break;
        }

        bool hasNegCircle = false;
        for (int j = 0; j < n && !hasNegCircle; j++)
            for (auto &e : AdjList[j])
                if (dist[e.first] > e.second + dist[j]) {
                    hasNegCircle = true;
                    break;
                }
        if(hasNegCircle)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }
}
