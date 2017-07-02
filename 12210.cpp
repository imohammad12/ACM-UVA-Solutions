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
   int B , s , cases = 0;
    while (cin >> B >> s && B){
        cases++;
        vi bachelors(B) , spinster(s);
        for (int i = 0; i < B; ++i) {
            cin >> bachelors[i];
        }
        for (int j = 0; j < s; ++j) {
            cin >> spinster[j];
        }
        if(B > s){
            std::sort(bachelors.begin(), bachelors.end());
            cout <<"Case "<< cases<<": "<<B - s<<" "<<bachelors[0]<<endl;
        }
        else{
            cout << "Case "<< cases<<": 0"<<endl;
        }
    }
}

