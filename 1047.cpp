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





int main() {

    int towers, built_nom, TC_nom = 0;
    while (cin >> towers >> built_nom && towers) {
        TC_nom++;
        vi tower_capacity((unsigned long) towers), answer;
        vvi common_table;
        for (int i = 0; i < towers; ++i) {
            int temp;
            cin >> temp;
            tower_capacity[i] = temp;
        }
        int commons;
        cin >> commons;
        common_table.resize(commons);
        for (int j = 0; j < commons; ++j) {
            int temp;
            cin >> temp;
            for (int i = 0; i < temp; ++i) {
                int temp1;
                cin >> temp1;
                common_table[j].push_back(temp1 - 1);
            }
            int last;
            cin >> last;
            common_table[j].push_back(last);
        }
        int sum = 0, built_same = 0, max = 0, savek = 0;
        for (int k = 0; k < (1 << towers); ++k) {
            set<int> answer_checking;
            for (int i = 0; i < towers; ++i) {
                if (k & (1 << i)) {
                    sum += tower_capacity[i];
                    built_same++;
                    answer_checking.insert(i);
                }

            }
            if (built_same == built_nom) {
                int check = 0;
                for (int j = 0; j < commons; ++j) {
                    for (int i = 0; i < common_table[j].size() - 1; ++i) {
                        if (answer_checking.count(common_table[j][i]) != 0)
                            check++;
                    }
                    if (check >= 2)
                        sum -= (check-1)*(common_table[j][common_table[j].size() - 1]);
                    check = 0;
                }
                int Xor = k ^savek;
                bool check1 = false;
                for (int l = 0; l < towers; ++l) {
                    if (Xor & (1 << l)) {
                        if (k & (1 << l)) {
                            check1 = true;

                        }
                        break;
                    }

                }
                if ((max < sum) ||(max == sum && check1) ) {
                    savek = k;
                    max = sum;
                    answer.clear();
                    for (auto &it :answer_checking)
                        answer.push_back(it);
                }

            }
            built_same = 0;
            sum = 0;
        }

        cout <<"Case Number  "<< TC_nom<<endl;
        cout<<"Number of Customers: "<<max<<endl;
        cout<<"Locations recommended:";
        for (auto &it :answer)
            cout << " "<< it + 1 ;
        cout <<endl<< endl;
    }
    

}
