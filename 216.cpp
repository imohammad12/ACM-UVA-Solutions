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

int n;
vvd memo , dis;
vvi nex;

double TSP(int now , int bitmastk){
    if(bitmastk == (1 << n) - 1)
        return 0;
    double &nec = memo[now][bitmastk];
    if(nec != -1)
        return nec;
    nec = inf;
    int minn = 0;
    for (int nxt = 0; nxt < n; ++nxt) {
        if(nxt != now && !(bitmastk & (1 << nxt)))
            if(nec > dis[now][nxt] + TSP(nxt , (bitmastk | (1 << nxt)))){
                minn = nxt;
                nec = dis[now][nxt] + TSP(nxt , (bitmastk | (1 << nxt)));
            }
    }
    nex[now][bitmastk] = minn;
    return nec;
}

int main() {
    int tc = 0;
    while (cin >> n && n){
        tc++;
        vii loc(n);
        for (int i = 0; i < n; ++i) {
            cin >> loc[i].first >> loc[i].second;
        }
        dis.assign(n , vd(n , 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                dis[j][i] = sqrt(pow(loc[i].first - loc[j].first , 2) + pow(loc[i].second - loc[j].second , 2));
            }
        }
        int start ;
        double ans;
        ans = inf;
        nex.assign(n , vi((unsigned long) pow(2 , n), -1 ));
        for (int k = 0; k < n; ++k) {
            memo.assign(n , vd((unsigned long) (1 << n), -1));
            if(ans > TSP(k , 1 << k)){
                start = k ;
                ans = TSP(k , 1 << k);
            }
        }
        nex.assign(n , vi((unsigned long) pow(2 , n), -1 ));
        memo.assign(n , vd((unsigned long) (1 << n), -1));
        TSP(start , 1 << start);
        cout <<"**********************************************************"<<endl;
        cout <<"Network #" << tc<<endl;
        for (int l = start , mask = 1 << start , j = 0; j<n-1 ; j++) {
            int kk = nex[l][mask];
            mask = mask | (1 << kk);
            cout <<"Cable requirement to connect ("<< loc[l].first << "," << loc[l].second <<")" <<" to ("<< loc[kk].first << "," << loc[kk].second <<") is "<<fixed<< setprecision(2) <<dis[l][kk] +16<<" feet." << endl;
            l = kk;
        }
        cout<<fixed<<setprecision(2)<<"Number of feet of cable required is " <<ans + (n-1)*16 <<"."<<endl;
    }
}
