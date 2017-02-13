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
        if (L == R)
            st[p] = L;
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if (i > R || j < L) return -1;
        if (L >= i && R <= j) return st[p];


        int p1 = rmq(left(p), L, (L + R) / 2, i, j);
        int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (A[p1] >= A[p2]) ? p1 : p2;
    }
public:
    SegmentTree(const vi &_A) {
        A = _A;
        n = (int) A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};

int main(){
    int Numbers;
    while (cin >>Numbers && Numbers ){
        vi A(Numbers , inf);
        int Queries , lastseen = (int) eps;
        cin >> Queries;
        for (int i = 0; i < Numbers; ++i) {
            int num;
            cin >> num;
            if(i && lastseen ==num  && A[i-1]!= inf) {
                A[i] = A[i - 1] +1;
            }
            else
                A[i] = 1;
            lastseen = num;
        }
        SegmentTree sgtr(A);
        for (int k = 0; k < Queries; ++k) {
            int i , j;
            cin >> i >> j;
            i -=1;
            j -= 1;
            int Left_Remain , Right_remain;
            if( A[i] != 1 )
                for (Left_Remain = 0; A[i] != 1 && i<=j; ++Left_Remain , ++i);

            if(j+1 < A.size() && A[j+1] != 1 && A[j] !=1) {
                for (Right_remain = 1; A[j] != 1 && i<=j; --j, ++Right_remain);
                j--;
            }
            int Final_index = sgtr.rmq(i , j);
            if(Final_index == -1){
                if(Right_remain > Left_Remain)
                    cout<< Right_remain<<endl;
                else
                    cout << Left_Remain<<endl;
            }
            else if(Right_remain >= A[Final_index] && Right_remain >= Left_Remain)
                cout<< Right_remain << endl;
            else if(Left_Remain >= A[Final_index] && Left_Remain >= Right_remain)
                cout<< Left_Remain << endl;
            else
                cout<< A[Final_index] << endl;
            Left_Remain = 0;
            Right_remain = 0;
        }
    }

}
