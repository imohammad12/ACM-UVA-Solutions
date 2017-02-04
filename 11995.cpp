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



int main () {
    int lines;
    while (cin >> lines) {
        bool Queue = true, Stack = true, PQ = true;
        queue<int> queue1;
        priority_queue<int> priorityQueue;
        stack<int> stack1;
        for (int i = 0; i < lines; ++i) {
            int n, input;
            cin >> n >> input;
            switch (n) {
                case 1:
                    queue1.push(input);
                    priorityQueue.emplace(input);
                    stack1.push(input);
                    break;
                case 2:
                    if(!queue1.empty()) {
                        if (input != queue1.front())
                            Queue = false;
                        if (input != priorityQueue.top())
                            PQ = false;
                        if (input != stack1.top())
                            Stack = false;
                        queue1.pop();
                        priorityQueue.pop();
                        stack1.pop();
                        break;
                    }
                    else {
                        Queue = false;
                        Stack = false;
                        PQ = false;
                    }
            }
        }
        if ((Queue && PQ) || (Queue && Stack) || (Stack && PQ)) {
            cout << "not sure" << endl;
        }
        else if(Queue)
            cout << "queue" << endl;
        else if(Stack)
            cout << "stack" << endl;
        else if(PQ)
            cout << "priority queue" << endl;
        else
            cout << "impossible" << endl;

    }
}


