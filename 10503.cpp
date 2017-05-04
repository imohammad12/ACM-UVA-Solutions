
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



int n , m;
viii domines;
vii finallist;
ii first , last;
bool finished = false;

void backtrack (int index) {
    if (index == n + 1) {
        finished = true;
        return;
    }
    for (int i = 0; i < 2*m && !finished; ++i) {
        if (!domines[i].first && (domines[i].second.first == finallist[index - 1].second)) {
            if (index == n && (domines[i].second.second != last.first))
                continue;
            finallist[index] = domines[i].second;
            domines[i].first = 1;
            if (!(i % 2))
                domines[i + 1].first = 1;
            else
                domines[i - 1].first = 1;
            backtrack(index + 1);
            domines[i].first = 0;
 //           domines[i].second = make_pair(inf , inf);
            if (!(i % 2)) {
                domines[i + 1].first = 0;
 //               domines[i + 1].second = make_pair(inf, inf);
            }
            else {
                domines[i - 1].first = 0;
  //              domines[i - 1].second = make_pair(inf, inf);
            }
        }
    }

}

int main(){

    while (cin >> n >> m && n){
        domines.clear();
        domines.resize(2*m,make_pair(0 , make_pair(0,0)));
        finallist.clear();
        finallist.resize(n+1);
//        finallist[n-1].first = last.first;
//        finallist[n-1].second = last.second;
        cin>>first.first>>first.second>>last.first>>last.second;
        finallist[0].first = first.first;
        finallist[0].second = first.second;
        for (int i = 0; i < 2*m; ++i) {
            cin>>domines[i].second.first>>domines[i].second.second;
            domines[i+1].second.first = domines[i].second.second;
            domines[i+1].second.second = domines[i].second.first;
            ++i;
        }
        backtrack(1);
        if(finished)
            cout <<"YES"<<endl;
        else
            cout << "NO"<<endl;
        finished = false;
    }
}
