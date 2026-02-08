class FoodRatings {
public:
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, set<pair<int, string>>> cuisineRatings;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int N = foods.size();
        for (int i = 0; i < N; i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodRating[food] = rating;
            foodCuisine[food] = cuisine;
            cuisineRatings[cuisine].insert({-rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        int oldRating = foodRating[food];

        cuisineRatings[cuisine].erase({-oldRating, food});
        cuisineRatings[cuisine].insert({-newRating, food});
        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return begin(cuisineRatings[cuisine]) -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */