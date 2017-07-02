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

#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0) // alternative #define pi (2.0 * acos(0.0))
#define F first
#define S second
#define pb push_back



int main () {
    int numbers;
    while (cin >> numbers && numbers) {
        vii pieces;
        for (int i = 0; i < numbers; ++i) {
            int temp;
            cin >> temp;
            pieces.push_back(ii(temp, 0));
        }
        std::sort(pieces.begin(), pieces.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right) {
            return left.F < right.F;
        });

        int bags = 1, maxbag = 1;
        pieces[0].second = 1;
        for (int j = 1; j < pieces.size(); ++j) {
            if (pieces[j - 1].first == pieces[j].first) {
                pieces[j].second = ++bags;
                if (maxbag < bags)
                    maxbag = bags;
            } else {
                bags = 1;
                pieces[j].second = bags;
            }
        }
        cout << maxbag << endl;
        vvi finalbags(maxbag);
        int which = 0;
        for (int k = 0; k < pieces.size(); ++k, which++) {
            finalbags[which % maxbag].push_back(pieces[k].first);
        }
        for (int l = 0; l < maxbag; ++l) {
            for (int i = 0; i < finalbags[l].size(); ++i) {
                if (i != finalbags[l].size() - 1)
                    cout << finalbags[l][i] << " ";
                else
                    cout << finalbags[l][i];
            }
            cout << endl;
        }

        cout << endl;
    }
}

