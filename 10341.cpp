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


double p , q , r , s , t , u;

double calcute( double x){
    return (p * exp((-1) * x) + t*(pow(x , 2)) + q * sin(x) + r * cos(x) + s * tan(x) +u);
}

int main () {
    double x;
    while (cin >> p >> q >> r >> s >> t>>u){
        x = 0 ;
        double high =calcute(x);
        x = 1 ;
        double low = calcute(x);
        if(low <= 0 && high >= 0){
            double F = 0 , S = 1 , mid = (F+S)/2;
            while (calcute(mid) > 0.0000001 || calcute(mid) < -0.0000001){
                mid = (F + S)/2;
                double temp = calcute(mid);
                if(calcute(mid) > 0)
                    F = mid;
                else
                    S = mid;
            }
            cout <<fixed<<setprecision(4) <<mid << endl;
        }
        else
            cout<<"No solution"<<endl;

    }
}

