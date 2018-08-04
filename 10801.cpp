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
#include <algorithm>
#include <iomanip>
#include <queue>
//#include<omp.h>
#include <sstream>

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii , ii> iiii;
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
typedef pair<dd, double> ddd;
typedef vector<ddd> vddd;

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second
#define pb push_back

int main() {

    int n, k, ind;
    while (cin >> n >> k) {
        vi times(n);
        for (int i = 0; i < n; ++i) {
            cin >> times[i];
        }
        vvi elevator_floors(n);
        getchar();
        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);
            stringstream iss(line);
            int t;
            while (iss >> t)
                elevator_floors[i].push_back(t);
        }
        ind = 0;
        int indsize = 0;
        for (int i = 0; i < n; ++i) {
            indsize += elevator_floors[i].size();
        }
        map<int, int> indToflr;
        vi FinalFloors;
        vvi SameFloor(101);
        vvii AdjList(indsize);
        vi StartingFloors;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < elevator_floors[i].size(); ++j, ++ind) {
                indToflr[ind] = elevator_floors[i][j];
                if (elevator_floors[i][j] == k)
                    FinalFloors.push_back(ind);
                if(elevator_floors[i][j] == 0)
                    StartingFloors.push_back(ind);
                if (j != elevator_floors[i].size() - 1) {
                    AdjList[ind].push_back(ii(ind + 1, times[i] * (elevator_floors[i][j+1] - elevator_floors[i][j])));
                    AdjList[ind + 1].push_back(ii(ind, times[i] * (elevator_floors[i][j+1] - elevator_floors[i][j])));
                }
                SameFloor[elevator_floors[i][j]].push_back(ind);
            }
        }
        for (int i = 0; i < 101; ++i) {
            if (SameFloor[i].size() >= 2) {
                for (int j = 0; j < SameFloor[i].size(); ++j) {
                    for (int l = j + 1; l < SameFloor[i].size(); ++l) {
                        AdjList[SameFloor[i][j]].push_back(ii(SameFloor[i][l], 60));
                        AdjList[SameFloor[i][l]].push_back(ii(SameFloor[i][j], 60));
                    }
                }
            }
        }


        int s, mint = inf;
        for (int m = 0; m < StartingFloors.size(); ++m) {
            s = StartingFloors[m];
            vi dist(indsize, inf);
            dist[s] = 0;
            priority_queue<ii, vector<ii>, greater<ii> > pq;
            pq.push(ii(0, s));
            while (!pq.empty()) {
                ii front = pq.top();
                pq.pop();
                int d = front.first, u = front.second;
                if (d > dist[u]) continue; // this is a very important check
                for (int j = 0; j < (int) AdjList[u].size(); j++) {
                    ii v = AdjList[u][j];
                    if (dist[u] + v.second < dist[v.first]) {
                        dist[v.first] = dist[u] + v.second;
                        pq.push(ii(dist[v.first], v.first));
                    }
                }
            }
            for (int i = 0; i < FinalFloors.size(); ++i) {
                mint = min(mint, dist[FinalFloors[i]]);
            }
        }
        if(mint == inf)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << mint << endl;
    }
}
