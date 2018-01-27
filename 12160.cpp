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
#include <algorithm>
#include <iomanip>
#include <queue>
//#include<omp.h>

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii , ii> iiii;
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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;


#define inf 1000000000
#define eps 1e-9

string make4Digit(string s){
    while (s.size() < 4 ){
        s = '0' + s;
    }
    return s;
}


int main() {
    string l, u;
    int tc = 0, r;
    while (cin >> l >> u >> r && l != "0") {
        vs bottoms(r, "0");
        for (int i = 0; i < r; ++i) {
            cin >> bottoms[i];
        }
        tc++;
        queue<pair<string, int>> q;
        set<string> flag;
        q.push(make_pair(l, 0));
        flag.insert(l);
        string topp;
        while (!q.empty()) {
            topp = q.front().first;
            int dis = q.front().second;
            q.pop();
            if (topp == u) {
                cout << "Case " << tc << ": " << dis << endl;
                break;
            }
            for (int i = 0; i < r; ++i) {
                string temp = to_string(stoi(topp) + stoi(bottoms[i]));
                if (stoi(temp) > 9999)
                    temp = to_string(stoi(temp) - 10000);
                temp = make4Digit(temp);
                if (flag.count(temp))
                    continue;
                else {
                    flag.insert(temp);
                    q.push(make_pair(temp, dis + 1));
                }
            }
        }
        if (topp != u)
            cout << "Case " << tc << ": " << "Permanently Locked" << endl;
    }
}
