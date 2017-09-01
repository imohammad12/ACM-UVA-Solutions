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

//vi visit , graph;
//
//int dfs(int i){
//    if(!visit[i] && graph[i]){
//        visit[i] = 1;
//
//    }
//}

int main() {
    int tc;
    cin >> tc;
    for (int kk = 0; kk < tc; kk++) {
        int n, max = 0, ind;
        cin >> n;
        vi graph(n + 1, -1);
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            cin >> graph[v];
        }
        vi ansrs(n + 1, -1), flag(n + 1, 0), seenyet(n + 1, -1);
        for (int j = 1; j <= n; ++j) {
            if (flag[j] == 1)
                continue;
            int k = j, num = 0, nodes_befor_loop;
            vi seq(0);
            while (true) {
                if (flag[k] == 1 && seenyet[k] == -1) {
                    nodes_befor_loop = seq.size() - num - ansrs[k] + 1;
                    for (int i = 0; i < seq.size(); ++i) {
                        ansrs[seq[i]] = num;
                        if (i < nodes_befor_loop)
                            num--;
                        seenyet[seq[i]] = 1;
                    }
                    break;
                }
                if (flag[k] == 1 && seenyet[k] == 1) {
                    nodes_befor_loop = num;
                    for (int i = 0; i < seq.size(); ++i) {
                        ansrs[seq[i]] = ansrs[k] + nodes_befor_loop;
                        nodes_befor_loop--;
                        seenyet[seq[i]] = 1;
                    }
                    break;
                }
                num++;
                flag[k] = 1;
                seq.push_back(k);
                ansrs[k] = num;
                k = graph[k];
            }
        }
//        for (int l = 1; l <= ansrs.size() -1; ++l) {
//            cout << l<< " " << ansrs[l] <<endl;
//        }

        for (int l = 1; l <= n; ++l) {
            if (ansrs[l] > max) {
                max = ansrs[l];
                ind = l;
            } else if (ansrs[l] == max && l < ind)
                ind = l;
        }
        cout << "Case "<<kk +1<<": "<< ind<<endl;
    }
}

