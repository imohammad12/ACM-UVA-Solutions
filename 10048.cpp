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
#include <bitset>

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

vector<int> ufds;
vector<pair<int, ii>> graph;
vvii graph2;

void buildUfds(int n) {
    ufds.clear(); ufds.resize(n+1);
    for(int i = 1; i <= n; i++) ufds[i] = i;
}

int findSet(int i) {
    return (ufds[i] == i) ? i : (ufds[i] = findSet(ufds[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void joinSets(int i, int j) {
    int a = findSet(i), b = findSet(j);
    if (a < b) ufds[a] = b;
    else ufds[b] = a;
}

int kruskal() {
    int cost = 0;
    for (int i = 0; i < graph.size(); i++) {
        pair<int, ii> fr = graph[i];
        if (!isSameSet(fr.second.first, fr.second.second)) {
            graph2[graph[i].second.first].push_back(ii(graph[i].second.second , graph[i].first));
            graph2[graph[i].second.second].push_back(ii(graph[i].second.first , graph[i].first));
            cost++;
            joinSets(fr.second.second, fr.second.first);
        }
    }
    return ++cost;
}

int c1 , c2 , finalmax;
vi visited;

void dfs(int x , int maxx){
    for (int i = 0; i < graph2[x].size(); ++i) {
        if(!visited[graph2[x][i].first])
        {
            maxx = max( maxx , graph2[x][i].second);
            visited[graph2[x][i].first] = 1;
            if(graph2[x][i].first == c2) {
                finalmax = maxx;
                return;
            }
            dfs(graph2[x][i].first , maxx);
        }
    }
}

int main() {

    int c, s, q, tc = 0;
    while (cin >> c >> s >> q && c) {
        if (tc)
            cout << endl;
        tc++;
        buildUfds(c);
        graph.clear();
        graph2.assign(c, vii(0, ii(0, 0)));
        for (int j = 0; j < s; ++j) {
            int x, y, w;
            cin >> x >> y >> w;
            graph.push_back(make_pair(w, ii(x - 1, y - 1)));
        }
        std::sort(graph.begin(), graph.end(), [](const std::pair<int, ii> &left, const std::pair<int, ii> &right) {
            return left.first < right.first;
        });
        kruskal();
        cout << "Case #" << tc << endl;
        for (int i = 0; i < q; ++i) {
            visited.assign(c, 0);
            finalmax = 0;
            cin >> c1 >> c2;
            c2--;
            dfs(c1 - 1, 0);
            if (finalmax)
                cout << finalmax << endl;
            else
                cout << "no path" << endl;
        }

    }
}



