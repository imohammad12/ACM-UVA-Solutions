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


class UnionFind { // OOP style
 private: vi p, rank; // remember: vi is vector<int>
 public:
    UnionFind(int N) { rank.assign(N+1, 0);
        p.assign(N+1, 0); for (int i = 1; i <=N; i++) p[i] = i; }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { // if from different set
             int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
             else { p[x] = y;
            if (rank[x] == rank[y]) rank[y]++; }
    } } };


int main () {
    int computers, tc;
    cin >> tc;
    cin >> computers;
    while (tc--) {
        int corrects = 0, incorrects = 0;
        UnionFind Union(computers);
        string c;
        while ( cin >> c && (c == "c" || c == "q")) {
            int comp1, comp2;
            cin >> comp1 >> comp2;
            if (c == "c")
                Union.unionSet(comp1, comp2);
            else {
                if (Union.isSameSet(comp1, comp2))
                    corrects++;
                else
                    incorrects++;
            }
        }
        if(tc)
         computers = stoi(c);
        if (tc)
            cout << corrects << "," << incorrects << endl << endl;
        else
            cout << corrects << "," << incorrects << endl;
    }
}


