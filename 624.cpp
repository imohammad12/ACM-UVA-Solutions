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

int sum = 0 , all_long , numbers , minutes[21] , max1 = -1 , time1 = 0;
vi finals , last;
bool accoured[21] = {} , check = true;

void backtrack(int P){
//    cout << minutes[P] << " ";
    time1++;
    sum+=minutes[P];
    accoured[P] = 1;
    finals.push_back(P);
    if(P == 20)
        P = -1;
    for (int i = P+1; i < numbers && check ; ++i) {
        if(sum+minutes[i]> all_long || i== P || accoured[i] == 1)
            continue;
        backtrack(i);
        if(sum > max1) {
            last.clear();
            last = finals;
            max1 = sum;
        }
        if(sum == all_long)
            check = false;
        sum -=minutes[i];
        finals.pop_back();
        accoured[i] = 0;
//        cout << endl;
    }
}



int main() {
    clock_t tStart = clock();
    minutes[20]=0;
    while (cin>> all_long && all_long){

        cin >> numbers;
        for (int i = 0; i < numbers; ++i) {
            cin >> minutes[i] ;
        }
        backtrack(20);
        last.erase(last.begin());
        for (int j = 0; j < last.size(); ++j) {
            cout<< minutes[last[j]] << " " ;
        }
        cout <<"sum:"<< max1<<endl ;
        sum = 0;
        max1 = -1;
        finals.clear();
        last.resize(0);
        check = true;
        //cout << endl << time1 << endl;
    }
  //  printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}


