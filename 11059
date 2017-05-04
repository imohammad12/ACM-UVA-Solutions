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
typedef vector<vector<viii>> vvviii;
typedef vector<vector<iii>> vviii;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<double, double> dd;
typedef vector<dd> vdd;

#define inf 1000000000
#define eps 1e-9

int main(){
    int num , tc = 0;
    while (cin>> num){
        tc++;
        long long max = 0;
        vector<long long> numbers(num);
        for (int i = 0; i < num; ++i) {
            cin>> numbers[i];
        }
        long long sum = 0;
        for (int j = 0; j < num; ++j) {
            sum = numbers[j];
            if(max < sum)
                max = sum;
            for (int i = j+1; i <num ; ++i) {
                sum = sum * numbers[i];
                if(max < sum)
                    max = sum;
            }
            sum = 0;
        }
        cout <<"Case #"<<tc<<": The maximum product is "<< max <<"."<<endl<<endl;
    }
}
