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
    int Front_Numbers , Rear_Numbers;
    while (cin >> Front_Numbers && Front_Numbers && cin >> Rear_Numbers){
        vi Front(Front_Numbers) , Rear(Rear_Numbers) ;
        vector<double> drives;
        vii adjacent;
        for (int i = 0; i < Front_Numbers; ++i) {
            int a;
            cin >> a;
            Front[i] = a;
        }
        for (int i = 0; i < Rear_Numbers; ++i) {
            int a;
            cin >> a;
            Rear[i] = a;
        }
        for (int j = 0; j < Front_Numbers; ++j) {
            for (int i = 0; i < Rear_Numbers; ++i) {
                drives.push_back((double)Rear[i]/(double)Front[j]);
            }
        }
        bool Not_Adjacent =false;
        double max = 0;
        for (int k = 0; k < drives.size(); ++k) {
            for (int i = 0; i < drives.size(); ++i) {
                Not_Adjacent = false;
                for (int j = 0; j < drives.size() && i != k; ++j) {
                    if(j != i && j != k && ((drives[i] > drives[j] && drives[j] > drives[k]) ||(drives[k] > drives[j] && drives[j] > drives[i])))
                        Not_Adjacent = true;
                }
                if(!Not_Adjacent && i!= k){
                    if(drives[i]>drives[k]) {
                        if ((drives[i] / drives[k]) > max)
                            max = (drives[i] / drives[k]);

                    }
                    else {
                        if ((drives[k] / drives[i]) > max)
                            max = (drives[k] / drives[i]);
                    }

                }
            }
        }
        cout<< setprecision(2)<< fixed  << max  << endl;
    }
}
