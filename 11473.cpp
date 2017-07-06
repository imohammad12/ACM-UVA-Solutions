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

double distance(pair<double , double> a , pair<double , double> b){
    return (sqrt(pow((a.first - b.first) , 2) + pow((b.second - a.second) ,2)));
}

int main() {
    int tc;
    cin >> tc;
    for (int kk = 1; kk <= tc; kk++) {
        int K, T;
        cin >> K >> T;
        double priemeter = 0, grap;
        vector<pair<double, double >> points, trees(T);
        for (int i = 0; i < K; ++i) {
            double temp1, temp2;
            cin >> temp1 >> temp2;
            points.push_back(make_pair(temp1, temp2));
        }
        for (int j = 1; j < K; ++j) {
            priemeter += distance(points[j - 1], points[j]);
        }
        grap = priemeter / (T - 1);
        trees[0] = points[0];
        trees[T - 1] = points[K - 1];
        double Distnow;
        pair<double, double> lastpoint = points[0];
        for (int t = 1, k = 0; t < T - 1; ++t) {
            Distnow = grap;
            while (Distnow > distance(lastpoint, points[k + 1])) {
                Distnow -= distance(lastpoint, points[k + 1]);
                k++;
                lastpoint = points[k];
            }
            double leftx = lastpoint.first, lefty = lastpoint.second, rightx = points[k + 1].first, righty = points[k +
                                                                                                                    1].second, x =
                    (leftx + rightx) / 2, y = (lefty + righty) / 2, tempdis = distance(lastpoint,
                                                                                       pair<double, double>(x, y));
            while (fabs(Distnow - tempdis) > 0.000000000001) {
                if (Distnow > tempdis)
                    leftx = x, lefty = y;
                else
                    rightx = x, righty = y;
                x = (leftx + rightx) / 2, y = (lefty + righty) / 2;
                tempdis = distance(lastpoint, pair<double, double>(x, y));
            }

            trees[t] = lastpoint = pair<double, double>(x, y);
        }
        cout << "Road #" << kk << ":" << endl;
        for (int l = 0; l < T; ++l) {
            cout << fixed << setprecision(2) << trees[l].first << " " << trees[l].second << endl;
        }
        cout << endl;
    }
}


