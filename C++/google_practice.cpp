/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

string maxTime(string origin){
    if (origin[0]=='?'){
        origin[0] = origin[1]=='?' || origin[1]<='3' ? '2' : '1';
    }
    if (origin[1]=='?'){
        origin[1] = origin[0]=='2' ? '3' : '9';
    }
    if (origin[3]=='?'){
        origin[3] = '5';
    }
    if (origin[4]=='?'){
        origin[4] = '9';
    }
    return origin;
}

vector<int> maxSub(vector<int> arr, int k){
    int start = 0;
    for (int i=0; i<=arr.size()-k; i++){
        for (int j=0; j<k; j++){
            if (arr[i+j] > arr[start+j]){
                start = i; break;
            }
        }
    }
    vector<int> res = vector<int>(arr.begin()+start, arr.begin()+start+k);
    return res;
}

void printVec(vector<int> arr){
    for (int a:arr){
        cout << a << '\t';
    }
    cout << endl;
}
int gcd (int a, int b) {
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int maxDiff(){
    int n, temp1, temp2, cur, maxc = INT_MIN, minc = INT_MAX;
    cin >> n >> temp1;
    for (int i=1; i<=n; i++){
        for (int j=0; j<pow(2, i); j+=2){
            cin >> temp1 >> temp2;
            if (temp1==-1 || temp2==-1){
                continue;
            }
            cur = gcd(temp1, temp2);
            maxc = max(maxc, cur);
            minc = min(minc, cur);
        }
    }
    if (maxc == INT_MIN){
        return 0;
    }
    cout << maxc << '\t' << minc << endl;
    return maxc-minc;
}

vector<int> nearestShops(vector<int> shops, vector<int> homes){
    sort(shops.begin(), shops.end());
    sort(homes.begin(), homes.end());
    vector<int> res;
    int j=0, temp;
    for (int i=0; i<shops.size()&&j<homes.size(); i++){
        if (shops[i]>=homes[j]){
           temp = (i>0 ? homes[j]-shops[i-1] : INT_MAX);
           res.push_back(temp<shops[i]-homes[j]?i-1:i);
           j++; i--;
        }
    }
    for (int i=j; i<homes.size(); i++){
        if (i==homes.size()){
            break;
        }else{
            res.push_back(shops.size()-1);
        }
    }
    return res;
}

int find(vector<int> tall, int a){
    int i=0, j=tall.size()-1, mid;
    while (i<=j){
        mid = (i+j)/2;
        if (tall[mid]>a && (mid==0 || tall[mid]<=a)) return mid;
        else if (tall[mid]<=a) i = mid+1;
        else j = mid-1;
    }
    return -1;
}

int solution(vector<int> A)
{
  int sum = 0;
  for (int a:A){
      sum += a;
  }
  int target = sum/2+1, maximum = 0;
  vector<vector<bool>> dp(A.size()+1, vector<int>(target, true));
  for (int i=0; i<=A.size(); i++){
      dp[i][0] = true;
  }
  for (int j=1; j<target; j++){
      dp[0][j] = false;
  }
  for (int i=1; i<=A.size(); i++){
      for (int j=1; j<target; j++){
          dp[i][j] = dp[i-1][j];
          if (!dp[i][j] && A[i-1]<=j){
              dp[i][j] = dp[i-1][j-A[i-1]];
          }
          if (dp[i][j]) maximum = j;
      }
  }
  return sum-2*maximum; 
}

int main()
{
    vector<int> shops = {3,5,7,10};
    vector<int> homes = {11,13,17,119,123,126};
    printVec(nearestShops(shops, homes));
    return 0;
}
