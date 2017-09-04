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
vvi checkbfs;
vii xes;
int h , m;
vii moves = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
vvi visit;

void holedfs(int x , int y){
    visit[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        if(grid[x+moves[i].first][y+moves[i].second] == '0' && visit[x+moves[i].first][y+moves[i].second] == 0){
            holedfs(x+moves[i].first ,y+moves[i].second );
        }
    }
}

void zdfs(int x , int y){
    for (int i = 0; i < 4; ++i) {
        int nf = x + moves[i].first , ns = y + moves[i].second;
        if(nf <0 || nf >h-1 || ns < 0 || ns > m-1 || checkbfs[nf][ns] == 1 || grid[nf][ns] == '1')
            continue;
        checkbfs[nf][ns] = 1;
        grid[nf][ns] = 'X';
        zdfs(nf , ns);
    }
}


int main() {
    map<int , char> hieroglyphs;
    hieroglyphs[1] = 'A';
    hieroglyphs[0] = 'W';
    hieroglyphs[2] = 'K';
    hieroglyphs[3] = 'J';
    hieroglyphs[5] = 'D';
    hieroglyphs[4] = 'S';
    int tc = 0;
    while ((cin >> h >> m) && h && m) {
        tc++;
        grid.assign(h, "");
        for (int i = 0; i < h; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); ++j) {
                stringstream ss;
                ss << hex << s[j];
                int n;
                ss >> n;
                bitset<4> b(n);
                grid[i].append(b.to_string());
            }
        }                               // until here we decoded the grid
        m *= 4;
        visit.assign(h, vi(m, 0));
        int k = 0 ,l;
        checkbfs.assign(h , vi(m  , 0));
        for ( l = 0; l < m; ++l) {
            if(grid[k][l] == '0' && checkbfs[k][l] == 0){
                checkbfs[k][l] = 1;
                grid[k][l] = 'X';
                zdfs(k , l);
            }
        }
        k = h-1;
        for ( l = 0; l < m; ++l) {
            if(grid[k][l] == '0' && checkbfs[k][l] == 0){
                checkbfs[k][l] = 1;
                grid[k][l] = 'X';
                zdfs(k , l);
            }
        }
        l = 0;
        for ( k = 0; k < h; ++k) {
            if(grid[k][l] == '0' && checkbfs[k][l] == 0){
                checkbfs[k][l] = 1;
                grid[k][l] = 'X';
                zdfs(k , l);
            }
        }
        l = m-1;
        for ( k = 0; k < h; ++k) {
            if(grid[k][l] == '0' && checkbfs[k][l] == 0){
                checkbfs[k][l] = 1;
                grid[k][l] = 'X';
                zdfs(k , l);
            }
        }
                                        // until here we converted the out zeros to X
        vector<char> ans;
        for (int k = 0; k < h; ++k) {
            for (int i = 0; i < m; ++i) {
                int holes = 0;
                if (grid[k][i] != '1' || visit[k][i] != 0)
                    continue;
                queue<ii> bfs;
                bfs.push(ii(k, i));
                visit[k][i] = 1;
                while (!bfs.empty()) {
                    ii now;
                    now = bfs.front();
                    int nf = now.first, ns = now.second;
                    bfs.pop();
                    if (grid[nf][ns] == '0' && visit[nf][ns] == 0) {
                        visit[nf][ns] = 1;
                        holes++;
                        holedfs(nf, ns);
                        continue;
                    }

                    for (int j = 0; j < 4 && grid[nf][ns] == '1'; ++j) {
                        int x = nf + moves[j].first, y = ns + moves[j].second;
                        if ((x >= 0) && (x < h) && (y >= 0) && (y < m) && (grid[x][y] != 'X') && (visit[x][y] == 0)) {
                            if(grid[x][y] == '1')
                                visit[x][y] = 1;
                            bfs.push(ii(x, y));

                        }
                    }
                }
                ans.push_back(hieroglyphs[holes]);
            }
        }
        sort(ans.begin() , ans.end());
        cout << "Case " << tc <<": ";
        for (int k1 = 0; k1 <ans.size() ; ++k1) {

            cout << ans[k1];
        }
        cout << endl;
    }
}
