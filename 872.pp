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

map<char , int> varmap;
string variables , constraints;
vector<char> var;
vvi graph;
vi isolates;
vi printlist , visit;
int n;

bool dfs(int v1 , int v2){
    if(v2 == v1)
        return false;
    bool check = true;
    for (int i = 0; i < graph[v2].size(); ++i) {
       check = (check && dfs(v1 , graph[v2][i]));
    }
    return check;
}

bool topology(int v1 , int v2 , int i){
    if(isolates[v2] == 0)
        return true;
    bool check = true;
    for (int j = 0; j<= i; ++j) {
        check = (check && dfs(printlist[j] , v2));
    }
    return check;
}

void backtracking(int i , int now){
    if(i == n-1){
        printlist[i] = now;
        for (int j = 0; j < n; ++j) {
            if(j!=n-1)
            cout <<var[printlist[j]]<<" ";
            else
                cout << var[printlist[j]];
        }
        cout << endl;
        return;
    }
    //cout << i<<" : "<<var[now]<<" " <<endl;
    for (int j = 0; j < n; ++j) {
        if(visit[j] != 1 && topology(now , j , i)){
            visit[j] = 1;
            printlist[i+1] = j;
            backtracking(i+1,j);
            visit[j] = 0;
        }
    }
}

bool is_ok(int v , int start){
    bool check = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        if(graph[v][i] == start)
            return false;
        check = check && is_ok(graph[v][i] , start);
    }
    return check;
}

int main() {
    int tc;
    cin >> tc;
    getchar();
    while (tc--) {

        getchar();
        getline(cin, variables);
        getline(cin, constraints);
        var.clear();
        var.resize(0);
        for (int i = 0; i < variables.size(); i += 2) {
            var.push_back(variables[i]);
        }
        n = var.size();
        sort(var.begin(), var.end());
        for (int k = 0; k < n; ++k) {
            varmap[var[k]] = k;
        }
        graph.clear();
        graph.resize(n);
        isolates.assign(n, 0);
        for (int j = 0; j < constraints.size(); j += 4) {
            graph[varmap[constraints[j]]].push_back(varmap[constraints[j + 2]]);
            isolates[varmap[constraints[j]]] = 1;
            isolates[varmap[constraints[j + 2]]] = 1;
        }
        bool possible = true;
        for (int m = 0; m < n; ++m) {
            possible = possible && is_ok(m, m);
        }
        if (!possible) {
            if (tc)
                cout << "NO" << endl << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        printlist.assign(n, -1);
        visit.assign(n + 1, 0);
        for (int l = 0; l < n; ++l) {
            printlist[0] = l;
            visit[l] = 1;
            backtracking(0, l);
            visit[l] = 0;
        }
        cout << endl;
    }
}
