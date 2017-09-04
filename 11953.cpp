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

vector<string> grid;
vvi visit;
int n;
vii moves = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};

void dfs(int x , int y){
    for (int i = 0; i < 4; ++i) {
        int nowfirst = x + moves[i].first , nowsecond = y + moves[i].second;
        if(nowfirst < 0 || nowfirst > n-1 || nowsecond < 0 || nowsecond > n-1 || visit[nowfirst][nowsecond] == 1 || grid[nowfirst][nowsecond] == '.')
            continue;
        visit[nowfirst][nowsecond] = 1;
        dfs(nowfirst , nowsecond);
    }
}

int main(){
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        cin >>n;
        grid.assign(n  , "");
        for (int j = 0; j < n; ++j) {
            cin >> grid[j];
        }
        visit.assign(n , vi(n , 0));
        int ans = 0;
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                if(grid[k][j] != 'x' || visit[k][j] == 1)
                    continue;
                visit[k][j] = 1;
                ans++;
                dfs(k , j);
            }
        }
        cout <<"Case "<<i+1<<": " <<ans<<endl;
    }
}
