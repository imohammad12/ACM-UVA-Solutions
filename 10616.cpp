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



vvvll memo;
int D , nums;
vi numbers;
long long DP( int id , int M , int rem){
    if(M == 0 && rem == 19)
        return 1;
    if(M == 0)
        return 0;
    if(id == nums)
        return 0;
    long long &mem = memo[id][M][rem];
    if(mem != -1)
        return mem;
    return mem = DP(id+1 , M-1 , ((rem -19 +(numbers[id] % D)) % D) + 19) + DP(id+1 , M , rem);
}


int main() {
    int  queries , sets = 0;
    while (cin >> nums >> queries && nums){
        sets++;
        numbers.clear();
        numbers.resize(nums , 0);
        for (int i = 0; i < nums; ++i) {
            cin >> numbers[i];
        }
        cout <<"SET "<<sets<<":"<<endl;
        for (int j = 1; j <= queries; ++j) {
            memo.clear();
            memo.resize(nums + 2 , vvll(12 , vll( 39 , -1)));
            int M;
            cin >> D >> M;
            cout<<"QUERY "<<j<<": "<< DP(0 , M , 19) << endl;
        }
    }
}
