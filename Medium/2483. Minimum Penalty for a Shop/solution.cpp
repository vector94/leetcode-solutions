class Solution {
public:
    int bestClosingTime(string customers) {
        int shopsHour = customers.size();
        vector<int> Y_suffix_sum(shopsHour + 1, 0);
        vector<int> N_prefix_sum(shopsHour + 1, 0);

        for (int i = shopsHour - 1, j = 1; i >= 0; i--, j++){
            Y_suffix_sum[i] = Y_suffix_sum[i + 1] + (customers[i] == 'Y');
            N_prefix_sum[j] = N_prefix_sum[j - 1] + (customers[j - 1] == 'N');
        }

        int min_penalty = INT_MAX;
        int min_index;
        for (int i = 0; i <= shopsHour; i++){
            int cur_penalty = Y_suffix_sum[i] + N_prefix_sum[i];
            if (cur_penalty < min_penalty){
                min_penalty = cur_penalty;
                min_index = i;
            }
        }

        return min_index;
    }
};