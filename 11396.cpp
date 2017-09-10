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

int main(){
    int n;
    while(cin >> n && n){
        vvi graph;
        vii edg;
        graph.assign(n , vi( 0 , 0));
        int x , y ;
        while (cin >> x >> y && x){
            x-- , y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
            edg.push_back(ii(x , y));
            edg.push_back(ii(y , x));
        }
        map<ii , int> visitedg;
        for (int i = 0; i < edg.size(); ++i) {
            visitedg[edg[i]] = 0;
        }
        bool ans = true;
        for (int j = 0; j < edg.size(); ++j) {
            if(visitedg[edg[j]])
                continue;
            if(visitedg[ii(edg[j].first , graph[edg[j].first][0])] == 0 && visitedg[ii(edg[j].first , graph[edg[j].first][1])] == 0 && visitedg[ii(edg[j].first , graph[edg[j].first][2])] == 0){
                visitedg[ii(edg[j].first , graph[edg[j].first][2])] = 1;
                visitedg[ii( graph[edg[j].first][2] ,edg[j].first )] = 1;
                visitedg[ii(edg[j].first , graph[edg[j].first][1])] = 1;
                visitedg[ii( graph[edg[j].first][1] ,edg[j].first )] = 1;
                visitedg[ii(edg[j].first , graph[edg[j].first][0])] = 1;
                visitedg[ii( graph[edg[j].first][0] ,edg[j].first )] = 1;
            }
            else if(visitedg[ii(edg[j].second , graph[edg[j].second][0])] == 0 && visitedg[ii(edg[j].second , graph[edg[j].second][1])] == 0 && visitedg[ii(edg[j].second , graph[edg[j].second][2])] == 0) {
                visitedg[ii(edg[j].second, graph[edg[j].second][2])] = 1;
                visitedg[ii( graph[edg[j].second][2] ,edg[j].second )] = 1;
                visitedg[ii(edg[j].second, graph[edg[j].second][1])] = 1;
                visitedg[ii( graph[edg[j].second][1] ,edg[j].second )] = 1;
                visitedg[ii(edg[j].second, graph[edg[j].second][0])] = 1;
                visitedg[ii( graph[edg[j].second][0] ,edg[j].second )] = 1;
            }
            else{
                ans = false;
                break;
            }
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}
