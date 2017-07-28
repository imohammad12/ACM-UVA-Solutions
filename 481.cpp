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





int main() {
    vi seq;
    int a , lis = 1;
    while (cin >> a)
        seq.push_back(a);
    vi l(seq.size() , 0) , sec(seq.size() , -1) , l_index(seq.size() , 0);
    l[0] = seq[0];
    for (int i = 1; i < seq.size(); ++i) {
        int pow = lower_bound(l.begin() , l.begin() + lis , seq[i]) - l.begin();
        l[pow] = seq[i];
        l_index[pow] = i;
        sec[i] = pow ? l_index[pow-1] : -1;
        if(lis == pow ){
            lis = pow +1;
        }
    }
    cout << lis <<endl <<"-"<<endl;
    vi final;
    for (int kk = l_index[lis-1]; kk > -1 ; ) {
        final.push_back(seq[kk]);
        kk = sec[kk];
    }
    for (int m = final.size() - 1; m >= 0; --m) {
        cout << final[m]<<endl;
    }

}
