class Solution {
public:
    int maxDistance(string s, int k) {
        int N, S, E, W;
        N = S = E = W = 0;

        int ans = 0;
        for (char ch : s){
            if (ch == 'N')  N++;
            else if (ch == 'S') S++;
            else if (ch == 'E') E++;
            else if (ch == 'W') W++;

            ans = max(ans, getCurrentMaxDistance(N, S, E, W, k));
        }

        return ans;
    }


    int getCurrentMaxDistance(int N, int S, int E, int W, int k){
         int ans = 0;
        if (N > S){
            if (S > k){
                S -= k;
                N += k;
                k = 0;
            }
            else{
                k -= S;
                N += S;
                S = 0;
            }

            ans += N - S;
        }
        else{
            if (N > k){
                N -= k;
                S += k;
                k = 0;
            }
            else{
                k -= N;
                S += N;
                N = 0;
            }

            ans += S - N;
        }

        if (E > W){
            if (W > k){
                W -= k;
                E += k;
            }
            else{
                E += W;
                W = 0;
            }

            ans += E - W;
        }
        else{
            if (E > k){
                E -= k;
                W += k;
            }
            else{
                W += E;
                E = 0;
            }

            ans += W - E;
        }

        return ans;
    }
};