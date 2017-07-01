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
    int tc;
    cin >> tc;
    while(tc--){
        int coin;
        cin >> coin;
        vi coins(coin);
        for (int i = 0; i < coin; ++i) {
            cin >> coins[i];
        }
        int answer = 0 , sum = 0;
        bool chechk = false;
        for (int j = 0; j <coin; ++j) {
            if(sum  >= coins[j]) {
                sum -= coins[j-1];
            }
            sum += coins[j];
        }
        int X = sum;
        for (int k = coin -1; k >= 0; --k) {
            while (X >= coins[k]){
                X -= coins[k];
                chechk = true;
            }
            if(chechk)
                answer++;
            chechk = false;
        }
        cout << answer<<endl;
    }
}

