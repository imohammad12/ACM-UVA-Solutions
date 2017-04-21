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

vi numbers;
vi check;
int n;

long power(int a, int n, int mod)
{
    long power=a,result=1;

    while(n)
    {
        if(n&1)
            result=(result*power)%mod;
        power=(power*power)%mod;
        n>>=1;
    }
    return result;
}

bool witness(int a, int n)
{
    int t,u,i;
    long prev,curr;

    u=n/2;
    t=1;
    while(!(u&1))
    {
        u/=2;
        ++t;
    }

    prev=power(a,u,n);
    for(i=1;i<=t;++i)
    {
        curr=(prev*prev)%n;
        if((curr==1)&&(prev!=1)&&(prev!=n-1))
            return true;
        prev=curr;
    }
    if(curr!=1)
        return true;
    return false;
}

inline bool IsPrime( int number )
{
    if ( ( (!(number & 1)) && number != 2 ) || (number < 2) || (number % 3 == 0 && number != 3) )
        return (false);

    if(number<1373653)
    {
        for( int k = 1; 36*k*k-12*k < number;++k)
            if ( (number % (6*k+1) == 0) || (number % (6*k-1) == 0) )
                return (false);

        return true;
    }

    if(number < 9080191)
    {
        if(witness(31,number)) return false;
        if(witness(73,number)) return false;
        return true;
    }


    if(witness(2,number)) return false;
    if(witness(7,number)) return false;
    if(witness(61,number)) return false;
    return true;

}

 void print(){
     for (int i = 0; i < n; ++i) {
         cout<<numbers[i];
         if(i <n-1)
             cout<<" ";
     }
     cout << endl;
 }

void backtrack(int index){
    if(index == n){
        print();
    }

    for (int i = 1; i <=n; ++i) {
        if(!check[i] && (IsPrime(numbers[index-1] + i))){
            if(index == n-1){
                if(!IsPrime(1+i))
                    continue;
            }
            numbers[index] = i;
            check[i] = 1;
            backtrack(index +1);
            check[i] = 0;
        }
    }
}

int main() {
    int tc = 0;
    while (cin >> n) {
        if (tc)
            cout << endl;
        tc++;
        numbers.clear();
        numbers.resize(n);
        check.clear();
        check.resize(n, 0);
        cout << "Case " << tc << ":" << endl;
        check[1] = 1;
        numbers[0] = 1;
        backtrack(1);

    }
}
