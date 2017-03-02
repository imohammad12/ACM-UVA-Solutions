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

//ios::sync_with_stdio(0);



int main(){
    int k ;
    cin >> k;
    while ( k){
        vi numbers(k);
        for (int i = 0; i < k; ++i) {
            int num ;
            cin >> num;
            numbers[i] =  num;
        }
        for (int j = 0; j <= k-6 ; ++j) {
            for (int i = j+1; i <= k - 5; ++i) {
                for (int l = i+1; l <= k - 4; ++l) {
                    for (int m = l+1; m <= k - 3; ++m) {
                        for (int n = m+1; n <= k - 2; ++n) {
                            for (int i1 = n+1; i1 <= k-1; ++i1) {
                                cout << numbers[j]<<" "<<numbers[i]<<" "<<numbers[l]<<" "<<numbers[m]<<" "<<numbers[n]<<" "<<numbers[i1]<<endl;
                            }
                        }
                    }
                }
            }
        }
        cin >> k;
        if(k)
            cout << endl;
    }

}
