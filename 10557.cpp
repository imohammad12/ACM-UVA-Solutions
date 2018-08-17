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

int t , s;
bool win;
vvii AdjList;
vi visited;


bool dfs (int node){
    if(node == t)
        return true;
    for (int i = 0; i < AdjList[node].size(); ++i) {
        if(!(visited[AdjList[node][i].first])) {
            visited[AdjList[node][i].first] = 1;
            if (dfs(AdjList[node][i].first))
                return true;
        }
    }
    return false;
}

int main() {
    int n;
    while (cin >> n && n != -1) {
        AdjList.assign(n, vii(0, ii(0, 0)));
        vi node_energies(n , 0);
        for (int k = 0; k < n; ++k) {
            int energy, nn;
            cin >> energy >> nn;
            energy = -1 * energy;
            for (int i = 0; i < nn; ++i) {
                int des;
                cin >> des;
                AdjList[k].push_back(ii(des - 1, 0));
            }
            node_energies[k] = energy;
        }
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i < AdjList[l].size(); ++i) {
                AdjList[l][i].second = node_energies[AdjList[l][i].first];
            }
        }
        s = 0;
        vi dist(n, inf);
        dist[s] = 0; // holds the distance
        for (int i = 0; i < n - 1; i++) {
            bool up = false; // used to prune before finishing when no update is neccessary.
            for (int j = 0; j < n; j++)
                for (auto &e : AdjList[j])
                    if (dist[e.first] > e.second + dist[j] && e.second + dist[j] < 100) {
                        up = true;
                        dist[e.first] = e.second + dist[j];
                    }
            if (!up) break;
        }

        int CircleNode = -1;
        bool hasNegCircle = false;
        for (int j = 0; j < n && !hasNegCircle; j++)
            for (auto &e : AdjList[j])
                if (dist[e.first] > e.second + dist[j] && e.second + dist[j] < 100) {
                    hasNegCircle = true;
                    CircleNode = e.first;
                    break;
                }


        if (dist[n - 1] != inf)
            cout << "winnable" << endl;
        else if (!hasNegCircle)
            cout << "hopeless" << endl;
        else {
            visited.assign(n, 0);
            t = n - 1, s = 0;
            if (dfs(CircleNode))
                cout << "winnable" << endl;
            else
                cout << "hopeless" << endl;
        }

    }
}
