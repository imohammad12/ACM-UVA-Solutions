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

vi number;

int check(int x){
    for (int i = 1; i < number.size(); ++i) {
        if(number[i]- number[i-1] == x)
            x--;
        else if(number[i]- number[i-1] > x)
            return -1;
    }
    return x;
}

int main () {
    int tc;
    cin >> tc;
    for (int j = 1; j <=tc ; ++j) {
        int numbers , bigestdif = 0;
        cin >> numbers;
        number.clear();
        number.resize(numbers+1);
        number[0] = 0;
        for (int i = 1; i < numbers+1; ++i) {
            cin >> number[i];
            if(i){
                if(number[i]-number[i-1]> bigestdif)
                    bigestdif = number[i]-number[i-1];
            }
        }
        int F = bigestdif , S = bigestdif*10, mid  = (F+S)/2;
        while (F != S){
            if(S-F == 1 && check(S) && check(F) == -1 )
                break;
            if(check(mid) == -1) {
                F = mid;
                double temp = F + S;
                mid = ceil(temp/2);
            }
            else {
                S = mid;
                mid = (F+S)/2;
            }
        }

        cout <<"Case "<<j<<": "<< S << endl;

    }
}

