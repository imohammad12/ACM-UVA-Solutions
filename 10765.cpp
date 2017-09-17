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

int m , n , num = 0;
vvi graph;
vi dfs_num , dfs_low , artiP, visit , parent;

void finde_articulation(int v){
    for (int i = 0; i < graph[v].size(); ++i) {
        if(!visit[graph[v][i]] ){
            visit[graph[v][i]] = 1;
            parent[graph[v][i]] = v;
            dfs_num[graph[v][i]] = dfs_low[graph[v][i]] = ++num;
            finde_articulation(graph[v][i]);
            dfs_low[v] = min(dfs_low[v] , dfs_low[graph[v][i]]);
            if(dfs_low[graph[v][i]] >= dfs_num[v] )
                artiP[v]++;
        }
        else if(parent[v] != graph[v][i] && graph[v][i] != v){
            dfs_low[v] = min(dfs_low[v] , dfs_num[graph[v][i]]);
        }
    }
}

void dfs(int x){
    for (int i = 0; i < graph[x].size(); ++i) {
        if(visit[graph[x][i]])
            continue;
        visit[graph[x][i]] = 1;
        dfs(graph[x][i]);
    }
}

int main(){
    while (cin >> n >> m && m){
        int x , y;
        graph.assign(n , vi(0 ,0));
        while (cin >> x >> y && x != -1){
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        visit.assign(n , 0) ;
        vi roots;
        int ConComp = 0; // number of connected components
        for (int k = 0; k < n; ++k) {
            if(!visit[k]) {
                dfs(k);
                ConComp++;
                roots.push_back(k);
            }
        }
        dfs_low.assign(n , 0) , dfs_num.assign(n , 0) , artiP.assign(n , ConComp - 1) , visit.assign(n, 0) , parent.assign(n , -1);
        visit[0] = 1;
        for (int l = 0; l < roots.size(); ++l) {
            finde_articulation(roots[l]);
            artiP[roots[l]]--;
        }
        vii ans;
        for (int i = 0; i < artiP.size(); ++i) {
            artiP[i]++;
            ans.push_back(ii(i , artiP[i]));
        }
        std::sort(ans.begin(), ans.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
            if(left.second > right.second){
                return true;
            }
            else if(left.second == right.second){
                return left.first < right.first;
            }
            else
                return false;
        });
        for (int j = 0; j < m; ++j) {
            cout << ans[j].first << " " << ans[j].second << endl;
        }
        cout << endl;
    }
}
