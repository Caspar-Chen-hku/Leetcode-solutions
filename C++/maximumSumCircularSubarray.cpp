class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSum = INT_MIN, curSum = 0, l = A.size();
        for (int a:A){
            curSum = max(0, curSum) + a;
            maxSum = max(maxSum, curSum);
        }
        vector<int> rightSum(l, 0);
        vector<int> leftSum(l-2, 0);
        vector<int> rightMax(l, 0);
        rightSum[l-1] = rightMax[l-1] = A[l-1];
        for (int i=l-2; i>=0; i--){
            rightSum[i] = rightSum[i+1] + A[i];
            rightMax[i] = max(rightMax[i+1], rightSum[i]);
        }
        leftSum[0] = A[0];
        maxSum = max(maxSum, A[0]+rightMax[2]);
        for (int i=1; i<l-2; i++){
            leftSum[i] = leftSum[i-1] + A[i];
            maxSum = max(maxSum, leftSum[i]+rightMax[i+2]);
        }
        return maxSum;
    }
};