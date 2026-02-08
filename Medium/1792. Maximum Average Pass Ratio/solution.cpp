class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> PQ;

        for (int i = 0; i < classes.size(); i++){
            PQ.push(
                {getPossibleImprovement({classes[i][0], classes[i][1]}), 
                {classes[i][0], classes[i][1]}}
            );
        }


        while (extraStudents--){
                        pair<int, int> curClass = PQ.top().second;
            PQ.pop();   

            curClass.first++;
            curClass.second++;

            PQ.push({getPossibleImprovement(curClass), curClass});
        }

        double ans = 0.0;
        while (!PQ.empty()){
            pair<int, int> curClass = PQ.top().second;

            ans += (curClass.first * 1.0) / curClass.second;
            PQ.pop();
        }

        return ans / classes.size();
    }

    double getPossibleImprovement(pair<int, int> cls){
        double curImp = (cls.first * 1.0) / cls.second;
        double possibleImp = ((cls.first + 1) * 1.0) / (cls.second + 1);

        return possibleImp - curImp;
    }
};