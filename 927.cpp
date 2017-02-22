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
    int tc;
    cin >> tc;
    while (tc--){
        int power , d , k ;
        long long int  result = 0;
        cin >> power;
        vi coefs(power+1);
        for (int i = 0; i < power + 1; ++i) {
            int num;
            cin >> num;
            coefs[i] = num;
        }
        cin >> d >> k;
        int sum = d , j =1;
        for ( j = 2; ; ++j) {
            if(sum >= k)
                break;
            sum += d*j;
        }
        j--;
       // cout<< pow(6 , 20);
        for (int l = 0; l < power + 1; ++l) {
            result += coefs[l] * (long long int) pow((double)j , (double)l);
        }
        cout << result<<endl;

    }

}
