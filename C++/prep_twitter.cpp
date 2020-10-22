/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int numMethod(int m, int n){
    if (m==0 || n==0) return 0;
    vector<vector<int>> num(m, vector<int>(n, 0));
    for (int i=0; i<n; i++){
        num[0][i] = 1;
    }
    for (int i=0; i<m; i++){
        num[i][0] = 1;
    }
    for (int i=1; i<m; i++){
        for (int j=1; j<n; j++){
            num[i][j] = num[i-1][j-1] + num[i][j-1] + num[i-1][j];
        }
    }
    return num[m-1][n-1];
}

template <typename T, int count>
void foo(T x){
    T val[count];
    for (int i=0; i<count; i++){
        val[i] = x++;
        cout << val[i] << ' ';
    }
};

int main()
{
    float y = 2.1;
    foo<float,3>(y);
    return 0;
}
