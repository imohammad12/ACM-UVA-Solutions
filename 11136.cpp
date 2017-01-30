#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <fstream>
#include <set>
#include <vector>
#include <utility>
#include <map>
#include <math.h>
#include <iostream>
#include <string>
#include <cstddef>
#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <forward_list>
#include <math.h>
#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <string>

//ios::sync_with_stdio(0);
using namespace std;

typedef vector<int > vi;
typedef vector<string > vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<string> > vvs;
typedef pair<int , int> pi;



int main() {
    int tc ;
    while (cin >> tc && tc){
        multiset<int> urn;
        int long long sum = 0;
        for (int i = 0; i < tc; ++i) {
            int Bills_Nom;
            cin >> Bills_Nom;
            for (int j = 0; j < Bills_Nom; ++j) {
                int bills;
                cin >> bills;
                urn.insert(bills);
            }
            multiset<int>::iterator it1 = urn.begin() , it3;
            multiset<int>::reverse_iterator it2 = urn.rbegin();
            sum += (*it2) - (*it1);
            urn.erase(it1);
            it3 = urn.find(*it2);
            urn.erase(it3);
        }
        cout << sum <<endl;
    }

}
