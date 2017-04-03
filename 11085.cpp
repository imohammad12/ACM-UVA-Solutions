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

vi Queens(8) ;
vector<bool> row(8 , 0) , column(8 , 0) , right_diagonal(15 , 0) , left_diagonal(15 , 0);
int distance1 = 0 , min_distance = inf;

void backtrack(int P){
    if(P == 8){
        //cout << distance1 << endl;
        if(min_distance > distance1)
            min_distance = distance1;
        return;
    }
    for (int i = 0; i < 8; ++i) {
        if(!right_diagonal[(i-P) + 7] && !left_diagonal[i+P] && !row[i] && !column[i]){
            right_diagonal[(i-P) + 7] = left_diagonal[i+P] = row[i] = column[i] = 1;
            if(abs(Queens[P]-1 - i))
                distance1++;
            //cout << "(" << i << " , "<<P << ") " ;
            backtrack(P+1);
            right_diagonal[(i-P) + 7] = left_diagonal[i+P] = row[i] = column[i] = 0;
            //cout << endl;
            if(abs(Queens[P]-1 - i))
                distance1--;
        }
    }
}



int main() {
    int tc = 0;
    while (cin >> Queens[0]){
        tc++;
        for (int i = 1; i <=7; ++i) {
            cin >> Queens[i];
        }
        backtrack(0);
        cout <<"Case "<< tc <<": "<< min_distance << endl;
        row.resize(8 , 0) , column.resize(8 , 0) ;
        right_diagonal.resize(15 , 0) , left_diagonal.resize(15 , 0);
        distance1 = 0;
        min_distance = inf ;
    }
}


