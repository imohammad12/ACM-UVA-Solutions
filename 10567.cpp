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




int main () {
    string s, ss;
    cin >> s;
    vvi Character_Indexs(128);
    for (int i = 0; i < s.size(); ++i) {
        Character_Indexs[s[i]].push_back(i);
    }
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> ss;
        int Last_index = -3;
        bool checker = true;
        int first;
        for (int j = 0; j < ss.size(); ++j) {
            auto it = upper_bound(Character_Indexs[ss[j]].begin(), Character_Indexs[ss[j]].end(), Last_index);
            if (it == Character_Indexs[ss[j]].end()) {
                checker = false;
                break;
            }
            Last_index = (*it);
            if (j == 0)
                first = Last_index;
        }
        if (!checker)
            cout << "Not matched" << endl;
        else {
            cout << "Matched " << first << " " << Last_index << endl;
        }
    }
}
