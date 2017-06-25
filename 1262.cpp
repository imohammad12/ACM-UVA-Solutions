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

std::vector<std::vector<char>> first_grade(5) , second_grade(5);
string final="00000";
set<string> finalset;

bool promising(int i , int j){
    char c = first_grade[i][j];
    for (int k = 0; k < 6; ++k) {
        if(second_grade[i][k] == c)
            return true;
    }
    return false;

}

void backtracking(int i , int j){
    for(;j<6;j++) {
        if (promising(i, j)) {
            final[i] = first_grade[i][j];
            if (i < 4) {
                backtracking(i + 1, 0);
            }
            else if(i == 4){
                //cout << final << endl;
                finalset.insert(final);
            }
        }
    }
}

int main() {
    int tc, findingnom;
    cin >> tc;
    while(tc--) {
        cin>>findingnom;
        getchar();
        for (size_t i = 0; i < 6; i++) {
            for (size_t j = 0; j < 5; j++) {
                char num;
                num = getchar();
                first_grade[j].push_back(num);
            }
            getchar();
        }
        for (size_t i = 0; i < 6; i++) {
            for (size_t j = 0; j < 5; j++) {
                char num;
                num = getchar();
                second_grade[j].push_back(num);
            }
            getchar();
        }
        backtracking(0, 0);
        int ii = 1;
        if(findingnom > finalset.size())
            cout<< "NO"<<endl;
        else {
            for (auto it = finalset.begin(); it != finalset.end(); it++, ii++) {
                if (ii == findingnom)
                    cout << (*it) << endl;
            }
        }
        first_grade.clear();
        first_grade.resize(5);
        second_grade.clear();
        second_grade.resize(5);
        finalset.clear();
    }

}
