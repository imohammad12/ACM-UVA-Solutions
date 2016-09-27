#include <iostream>
#include <iomanip>

#include <algorithm>
#include <fstream>
#include <set>
#include <vector>
#include <utility>
#include <map>
#include <math.h>

#include <iostream>
#include <sstream>
#include <string>

#include <math.h>
#include <iostream>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    int N, n;
    cin >> N >> n;
    while (N) {
        vector<vector<char>> vectorN, vectorn;
        vectorN.resize(N);
        vectorn.resize(n);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char ch;
                cin >> ch;
                vectorN[i].push_back(ch);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char ch;
                cin >> ch;
                vectorn[i].push_back(ch);
            }
        }
        int row = 0;
        int sum = 0;
        for (int l = 0; l < 4; ++l) {

            if(l>0)
                cout<<" ";
            while (row <= (N - n)) {
                for (int i = 0; i <= N - n; i++) {
                    bool tt = true;
                    if (vectorN[row][i] == vectorn[0][0]) {
                        for (int j = i + 1, k = 1; j < n + i; j++, k++) {
                            if (vectorN[row][j] != vectorn[0][k]) {
                                tt = false;
                                break;
                            }

                        }
                        if (tt) {
                            bool ttt = true;
                            for (int Trow = row + 1, krow = 1; Trow < row + n && krow < n; ++Trow, krow++) {
                                for (int col = i, kcol = 0; col < n + i && kcol < n; col++, kcol++) {
                                    if (vectorN[Trow][col] != vectorn[krow][kcol]) {
                                        ttt = false;
                                        break;
                                    }
                                }
                            }
                            if (ttt)
                                sum++;
                        }
                    }
                }
                row++;
            }
            cout << sum;
            vector<vector<char>> vectorn2;
            vectorn2.resize(n);
            for (int j = 0; j < n; ++j) {
                for (int i = n - 1; i >= 0; --i) {
                    vectorn2[j].push_back(vectorn[i][j]);

                }

            }
            vectorn = vectorn2;
            row=0;
            sum=0;


        }
        cout<<endl;
        cin >> N >> n;
    }
}

