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




int main () {
    int rows , columns;
    while (cin >> rows >> columns  && rows){
        vvi grade1(rows , vi(columns));
        vvi grade2(columns , vi(rows));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int temp;
                cin >> temp;
                grade1[i][j] = temp;
                grade2[j][i] = temp;
            }
        }
        int Queries;
        cin >> Queries;
        for (int k = 0; k < Queries; ++k) {
            int least , most , index , answer, lastmax = 0 , lastmin = 1000000;
            cin >> least >> most;
            vii leastnumbers , mostnumbers;
            vi flagR(500 , 0) , flagC(500 , 0);
            for (int i = 0; i < rows; ++i) {
                auto it = lower_bound(grade1[i].begin() , grade1[i].end() , least);
                //&& lastmin >= abs ((rows-i) - (grade1[i].end() - it))
                if(it != grade1[i].end() && !flagR[it - grade1[i].begin()]){
                    flagR[it - grade1[i].begin()] = 1;
                    //lastmin = abs((rows-i) - (grade1[i].end() - it));
                    leastnumbers.push_back(ii(i,it - grade1[i].begin()));
                }
            }
            for (int j = columns-1; j >= 0; j--) {
                auto it = lower_bound(grade2[j].begin() , grade2[j].end() , most);
                if((it != grade2[j].begin() && *it > most) || (*it == most && it == grade2[j].end()) || it == grade2[j].end())
                    it--;
//                int temp = j + (it - grade2[j].begin());
//                lastmax <= j + (it - grade2[j].begin()) &&
                if( !(it == grade2[j].begin() && *grade2[j].begin() > most)  && (*it >= least && *it <= most)){
                    //&& !flagC[it - grade2[j].begin()]
                    bool chech = false;
                    for(;*it ==  most;it++)
                        chech = true;
                    if(chech)
                        it--;
                    //flagC[it - grade2[j].begin()] = 1;
                    lastmax = j + (it - grade2[j].begin());
                    //else if(*it == most )
                    mostnumbers.push_back(ii(j,it - grade2[j].begin()));
                }
            }
            int max = 0;
            for (int l = leastnumbers.size()-1; l >= 0 ; l--) {
                int least1 , least2 , most1 , most2;
                least1 = leastnumbers[l].first;
                least2 = leastnumbers[l].second;
                if(max >(rows-least1+1) || max > (columns-least2+1) )
                    continue;
                for (int i = mostnumbers.size()-1; i >= 0 ; i--) {
                    most1 = mostnumbers[i].second;
                    most2 = mostnumbers[i].first;
                    answer = min(most2 - least2 +1 , most1 - least1 +1);
                    if (answer > max)
                        max = answer;
//                    if(most1 + most2 < lastmax)
//                        break;
                }

//                if(abs((rows-least1) - (columns-least2)) >= lastmin)
//                    break;
            }


            cout << max<<endl;
        }
        cout << "-"<<endl;
    }
}

