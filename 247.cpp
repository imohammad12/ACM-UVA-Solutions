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

int m , n , num , nSCC; // nSCC is the number of SCCs;
map <string , int > mapname;
vector<string> vecname;
vvi graph , ans;
vi visit , dfs_num , dfs_low , stck;

void SCC(int x){
    visit[x] = 1;
    dfs_low[x] = dfs_num[x] = ++num;
    stck.push_back(x);
    for (int i = 0; i < graph[x].size(); ++i) {
        if(!dfs_num[graph[x][i]])
            SCC(graph[x][i]);
        if(visit[graph[x][i]])
            dfs_low[x] = min(dfs_low[x]  , dfs_low[graph[x][i]]);
    }
    if(dfs_low[x] == dfs_num[x]){
        vi temp;
        while (true) {
            int v = stck.back();
            stck.pop_back();
            temp.push_back(v);
            visit[v] = 0;
            if(v == x)
                break;
        }
        ans.push_back(temp);
    }

}

int main(){
    int tc = 0;
    while (cin >> n >>m && n){
        if(tc)
            cout << endl;
        tc++;
        num = 0;
        set<string> setname;
        graph.assign(n , vi(0 , 0));
        mapname.clear();
        vecname.clear();
        for (int i = 0; i < m; ++i) {
            string name1 , name2;
            cin >> name1 >> name2;
            if(!setname.count(name1)) {
                mapname[name1] = (int) vecname.size();
                vecname.push_back(name1);
                setname.insert(name1);
            }
            if(!setname.count(name2)) {
                mapname[name2] = (int) vecname.size();
                vecname.push_back(name2);
                setname.insert(name2);
            }
            graph[mapname[name1]].push_back(mapname[name2]);
        }
        visit.assign(n, 0) , dfs_low.assign(n , 0) , dfs_num.assign(n , 0) , ans.assign(0 , vi(0 , 0)) , stck.assign(0 , 0) , stck.assign(0 , 0);
        for (int j = 0; j < vecname.size(); ++j) {
            if(!dfs_num[j])
                SCC(j);
        }
        cout << "Calling circles for data set " << tc <<":"<<endl;
        for (int k = 0; k < ans.size(); ++k) {
            for (int i = 0; i < ans[k].size(); ++i) {
                if(i != ans[k].size() -1 )
                    cout << vecname[ans[k][i]] <<", ";
                else
                    cout << vecname[ans[k][i]] << endl;
            }
        }

    }
}
