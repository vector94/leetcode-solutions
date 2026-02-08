class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> movieShop;
    unordered_map<string, int> moviePrice;
    set<pair<pair<int, int>, int>> rentedMovies;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (int i = 0; i < entries.size(); i++){
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];

            movieShop[movie].insert({price, shop});
            moviePrice[getShopMovieKey(shop, movie)] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ret;

        int i = 0;
        for (auto itr = movieShop[movie].begin(); i < 5 && itr != movieShop[movie].end(); i++, itr++){
            ret.push_back((*itr).second);
        }

        return ret;
    }
    
    void rent(int shop, int movie) {
        int curMoviePrice = moviePrice[getShopMovieKey(shop, movie)];
        auto it = movieShop[movie].find({curMoviePrice, shop});
        movieShop[movie].erase(it);
        rentedMovies.insert({{curMoviePrice, shop}, movie});
    }
    
    void drop(int shop, int movie) {
        int curMoviePrice = moviePrice[getShopMovieKey(shop, movie)];
        auto it = rentedMovies.find({{curMoviePrice, shop}, movie});
        rentedMovies.erase(it);
        movieShop[movie].insert({curMoviePrice, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ret;

        int i = 0;
        for (auto itr = rentedMovies.begin(); i < 5 && itr != rentedMovies.end(); i++, itr++){
            ret.push_back({itr -> first.second, itr -> second}); 
        }

        return ret;
    }

    string getShopMovieKey(int shop, int movie){
        return to_string(shop) + "+" + to_string(movie);
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */