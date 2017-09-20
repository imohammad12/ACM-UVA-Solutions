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
#include <bitset>

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


class UnionFind {
private:
    vi p, rank; // vi is vector<int>
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

double distance(pair<double , double> x , pair<double , double> y){
    return (sqrt(pow(x.first-y.first , 2) + pow(x.second - y.second , 2)));
}

int main(){
    ios::sync_with_stdio(0);
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        double n , r , rail = 0 , road = 0 , nStates = 0; // nStates is the number of states
        cin >> n >> r;
        vii positons(n);
        for (int j = 0; j < n; ++j) {
            cin >> positons[j].first >> positons[j].second;
        }
        vector<pair<double , ii>> weights;
        for (int k = 0; k < n; ++k) {
            for (int j = k +1 ; j <n ; ++j) {
                weights.push_back(pair<double ,ii>(distance(positons[k] , positons[j]), ii(k , j) ));
            }
        }
        std::sort(weights.begin(), weights.end(), [](const std::pair<double , ii> &left, const std::pair<double , ii> &right) {
            return left.first < right.first;
        });
        UnionFind uni(n);
        UnionFind states(n+1);
        for (int l = 0; l < weights.size(); ++l) {
            if(!uni.isSameSet(weights[l].second.first , weights[l].second.second)){
                uni.unionSet(weights[l].second.first , weights[l].second.second);
                if(weights[l].first <= r){
                    states.unionSet(weights[l].second.first , weights[l].second.second);
                    road += weights[l].first;
                } else
                    rail += weights[l].first;
            }
        }
        for (int m = 0; m < n; ++m) {
            if(!states.isSameSet(n , m)){
                states.unionSet(n, m);
                nStates++;
            }
        }
        cout << "Case #"<<i+1<<": " << nStates << " "<<round(road) <<" "<<round(rail)<<endl;
    }

}
