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

vvi graph;
vi printlist , visit;

void dfs(int v) {
    for (int i = 0; i < graph[v].size(); ++i) {
        if (visit[graph[v][i]] == 0) {
            visit[graph[v][i]] = 1;
            dfs(graph[v][i]);
        }
    }
    printlist.push_back(v);
}

int main(){
    int n ,m ;
    while (cin >> n >> m && n){
        graph.assign(n , vi(0 , 0));
        printlist.assign(0 , 0);
        visit.assign(n , 0);
        for (int i = 0; i < m; ++i) {
            int v , v2;
            cin >> v >> v2;
            v--;
            graph[v].push_back(v2 - 1);
        }
        for (int j = 0; j < n; ++j) {
            if(visit[j] == 0) {
                visit[j] = 1;
                dfs(j);
            }
        }
        for (int k = n-1; k >=0; --k) {
            if(k)
                cout << printlist[k] +1 << " ";
            else
                cout << printlist[k] +1<<endl;
        }
    }
}
