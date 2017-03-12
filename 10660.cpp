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

//ios::sync_with_stdio(0);
map < ii ,int> Numbers_Map;
vii Numbers_Vec;

vvi table(5 , vi(5,0));
int distance(int i , int j){
    return (abs(Numbers_Vec[i].first - Numbers_Vec[j].first) + abs(Numbers_Vec[i].second - Numbers_Vec[j].second))*table[Numbers_Vec[j].first][Numbers_Vec[j].second];
}

struct houses{
    int house_number , i , j , k ,l , m  ;
    bool operator<(const houses& rhs) const
    {
        if(house_number > rhs.house_number)
            return true;
        else if(house_number == rhs.house_number){
            if(i > rhs.i)
                return true;
            else if(i == rhs.i){
                if(j > rhs.j)
                    return true;
                else if(j == rhs.j){
                    if(k > rhs.k)
                        return true;
                    else if(k == rhs.k){
                        if(l > rhs.l)
                            return true;
                        else if(l == rhs.l){
                            if(m > rhs.m)
                                return true;
                            else if(m == rhs.m){
                                return true;
                            }
                            else return false;
                        }
                        else return false;
                    }
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
};



int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int Non_Null;
        cin >> Non_Null;
        priority_queue<houses> minhouses;
        for (int k = 0; k < Non_Null; ++k) {
            int i, j, value;
            cin >> i >> j >> value;
            table[i][j] = value;
        }

        int House_Number = 0;
        for (int n = 0; n < 5; ++n) {
            for (int i = 0; i < 5; ++i, House_Number++) {
                Numbers_Map[ii(n, i)] = House_Number;
                Numbers_Vec.push_back(ii(n, i));
            }
        }
        House_Number = 0;
        int minimum = inf;

        for (int i = 0; i < 21; ++i) {
            for (int j = i+1; j < 22; ++j) {
                for (int k = j+1; k < 23; ++k) {
                    for (int l = k+1; l < 24; ++l) {
                        for (int m = l+1; m < 25; ++m) {
                            int sum = 0;
                            for (int n = 0; n < 25; ++n) {
                               // int in = distance(i ,n) , jn = distance(j , n);
                                int b = min(distance(i ,n), distance(j , n) );
                                int minn = min( distance(k, n) , b);
                                int minnn = min(minn , distance(l , n));
                                sum += min(minnn, distance(m, n));
                            }
                            priority_queue<int, vector<int>, greater<int> > temp;
                            houses temp1;
                            temp.push(i), temp.push(j), temp.push(k), temp.push(l), temp.push(m);
                            temp1.i = temp.top(), temp.pop();
                            temp1.j = temp.top(), temp.pop();
                            temp1.k = temp.top(), temp.pop();
                            temp1.l = temp.top(), temp.pop();
                            temp1.m = temp.top(), temp.pop();
                            temp1.house_number = sum;
                            minhouses.push(temp1);

                        }
                    }
                }
            }
        }
        cout << minhouses.top().i << " " << minhouses.top().j << " "<< minhouses.top().k << " "<< minhouses.top().l << " "<< minhouses.top().m << endl;
        Numbers_Map.clear();
        Numbers_Vec.clear();
        table.clear();
        table.resize( 5 , vi(5 , 0));
    }

}

