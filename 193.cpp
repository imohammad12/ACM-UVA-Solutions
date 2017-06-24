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
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9


int nodes , edges;
vvi graph;
vector<string> colors;
set<int> finallist;
int black = 0 , maxblack = 0;
bool promising(int i){
    if ( i == 0)
        return true;
    for (int j = 0; j <graph[i].size() ; ++j) {
        if (colors[graph[i][j]] == "black")
            return false;
    }
    return true;
}

void backtracking(int i){
    if (promising(i) || colors[i] == "white") {
        if(i == nodes && maxblack < black){
            maxblack = black;
            finallist.clear();
            for (int j = 1; j <= nodes; ++j) {
                if(colors[j] == "black")
                    finallist.insert(j);
            }
        }
        else if(i!= nodes) {
            black++;
            colors[i + 1] = "black";
            backtracking(i + 1);
            colors[i + 1] = "white";
            black--;
            backtracking(i + 1);
        }
    }
}


int main(){
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> nodes >> edges;
        graph.resize(nodes + 1);
        colors.resize(nodes + 1, "white");
        for (int i = 0; i < edges; ++i) {
            int first, second;
            cin >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }

        backtracking(0);
        cout << maxblack << endl;
        auto it = finallist.begin();
        cout << (*it);
        it++;
        for (; it != finallist.end(); it++) {
            cout << " " << (*it);
        }
        cout<< endl;
        black = maxblack = 0;
        graph.clear();
        graph.resize(0);
        colors.clear();
    }

}
