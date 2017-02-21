//                                                  In The Name Of God
//                                              programmer:Mohammad Dehghan
#include <iostream>
using namespace std;

#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <map>

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



class SegmentTree {
private:
    vi st, A;
    int n;

    int left(int p) { return p << 1; }

    int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if (L == R) {
            if(A[L] >0)
            st[p] = 1;
            else if( A[L] < 0)
                st[p]  = -1;
            else
                st[p] =0;
//            if(L == 12)
//                cout << p<<endl;
        }
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            if ((p1 * p2) > 0)
                st[p] = 1;
            else if ((p1 * p2) < 0)
                st[p] = -1;
            else
                st[p] = 0;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -2;
        if (L >= i && R <= j) return st[p];


        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

        if (p1 == -2) return p2;
        if (p2 == -2) return p1;
        if ((p1 * p2) > 0)
            return 1;
        else if ((p1 * p2) < 0)
            return -1;
        else return 0;
    }

public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int) A.size();
        st.assign(4 * n, 1);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

    void replace (int p , int value) {
        int left = 0, right = n - 1, i;
        for (i = 1; ;) {
            int middle = (left + right) / 2;
            if (p <= middle && left != right) {
                right = middle;
                i *= 2;
            }
            else if (p > middle) {
                left = middle + 1;
                i = i * 2 + 1;
            }
            else if(left == right){
               // i *= 2;
                break;
            }

        }
        if (value > 0)
            st[i] = 1;
        else if (value < 0)
            st[i] = -1;
        else
            st[i] = 0;
        for (; i > 1; i /= 2) {
            if (i % 2 == 1)
                st[(i / 2)] = st[i] * st[i - 1];
            else
                st[(i / 2)] = st[i] * st[i + 1];
        }

    }

};

int main(){
   int numbers , Queries;
    while( cin >> numbers >> Queries){
        vi A(numbers );
        for (int i = 0; i < numbers; ++i) {
            cin >> A[i];
        }
        SegmentTree st(A);
        for (int j = 0; j < Queries; ++j) {
            char c;
            int p , value ;
            cin >> c >> p >> value;
            p--;
            if(c == 'C'){
                st.replace(p , value);
            }
            else {
                value--;
                if (st.rmq(p, value) > 0) // p == i , value == j
                    cout << '+';
                else if (st.rmq(p, value) < 0)
                    cout << '-';
                else
                    cout << 0;
            }
        }
        cout << endl;
    }

}
