class FoodRatings {
public:

unordered_map<string,pair<int,string>> foodratings;

map<string,set<pair<int,string>>> cuisinesmap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i =0 ; i<n;i++){
            string food=foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodratings[food]={rating,cuisine};
            cuisinesmap[cuisine].insert({(-1)*rating,food});

        }
    }
    
    void changeRating(string food, int newRating) {
        pair<int,string> p = foodratings[food];
        int oldrating = p.first;
        string cuisine = p.second;
        foodratings.erase(food);
        foodratings[food]={newRating,cuisine};

        cuisinesmap[cuisine].erase({-oldrating,food});
        cuisinesmap[cuisine].insert({(-1)*newRating,food});

    }
    
    string highestRated(string cuisine) {
     return cuisinesmap[cuisine].begin()->second;   
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */