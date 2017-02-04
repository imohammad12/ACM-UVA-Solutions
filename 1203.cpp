

//This code was wrongly written & because of a mistake is too long but it works





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
#include <functional>

//ios::sync_with_stdio(0);
using namespace std;

typedef vector<int > vi;
typedef vector<string > vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<string> > vvs;
typedef pair<int , int> pi;

struct Queries {
    int name;
    int period;
    int number;
    int coeficeint = 1;
};

typedef struct Queries Queries;

class compare {
    bool reverse;
public:
    compare(bool Reverse = false) {
        reverse = Reverse;
    }

    bool operator()(const Queries &left,const Queries &right) const {
        if (left.coeficeint * left.period > right.coeficeint * right.period)
            return true;
        else if (left.coeficeint * left.period == right.coeficeint * right.period) {
            return left.name > right.name;
        }
        else
            return false;
    }

};


void print(priority_queue<struct Queries , vector<Queries> , compare> Q){
    while (!Q.empty()) {
        cout << Q.top().name << " " << Q.top().period * Q.top().coeficeint << " " << Q.top().coeficeint <<endl;
        Q.pop();
    }
}


int main (){
    string s;
    int i =1;
    priority_queue<struct Queries , vector<Queries> , compare> queries;
    while(cin >> s && s!= "#"){
        int time , Name;
        cin >> Name >> time;
        Queries temp;
        temp.period = time;
        temp.name = Name;
        temp.number = i;
        queries.emplace(temp);
        i++;

    }
   // print(queries);
    int N;
    cin >> N;
    while (N--){
        Queries temp;
        temp.period = queries.top().period;
        temp.coeficeint = queries.top().coeficeint;
        temp.name = queries.top().name;
        temp.number = queries.top().number;
        cout<<queries.top().name<<endl;
        temp.coeficeint++;
//        temp.period += temp.period;
        queries.pop();
        queries.emplace(temp);
    }
}
