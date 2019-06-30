class Solution {
    
     vector<vector<double>> memo;
     vector<int> sum_array;
    
     public:
      double largestSumOfAverages(vector<int>& A, int K) {
        memo = vector<vector<double>> (K+1, vector<double>(A.size(), std::nan("1")));
        sum_array = vector<int>(A.size()+1);
        partial_sum(A.begin(), A.end(), sum_array.begin()+1);
        return dfs(A, K, 0);
      }

      double dfs(vector<int> & A, int K, int cur) {
        if(!isnan(memo[K][cur]))
          return memo[K][cur];
        if (K>=A.size()-cur)
          return memo[K][cur] = sum_array[A.size()] - sum_array[cur];
        if (K==1)
          return memo[K][cur] = (sum_array[A.size()] - sum_array[cur])/double(A.size()-cur);
        int cur_sum = 0;
        double max_sum = 0;

        for(int i=cur; i<A.size()-K+1; i++) {
          cur_sum += A[i];
          double cur_avg = cur_sum / double(i-cur+1);
          cur_avg += dfs(A, K-1, i+1);
          if(cur_avg>max_sum)
            max_sum = cur_avg;
        }
        return memo[K][cur] = max_sum;
      }
};
