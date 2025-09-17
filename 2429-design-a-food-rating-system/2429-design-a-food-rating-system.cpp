class FoodRatings {

    unordered_map<string, int> rating; // food,rating

    unordered_map<string, set<pair<int,string>>> highestRatedFood; // cuisine,highestRatedFood

    unordered_map<string, string> cuisine; // food,cuisine

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        for (int i = 0; i < foods.size(); i++) {

            if(rating.count(foods[i])) {

                pair<int,string>old={-ratings[i],foods[i]};

                if( highestRatedFood[cuisines[i]].count(old) ) highestRatedFood[cuisines[i]].erase(old);
                
            }

            rating[foods[i]] = ratings[i];
            cuisine[foods[i]] = cuisines[i];
           
            highestRatedFood[cuisines[i]].insert({-ratings[i],foods[i]});


        }
    }

    void changeRating(string food, int newRating) {


        if(rating.count(food)) {

            pair<int,string>old={-rating[food],food};

            if( highestRatedFood[cuisine[food]].count(old) ) highestRatedFood[cuisine[food]].erase(old);
                
        }

        rating[food] =newRating;
        
        highestRatedFood[cuisine[food]].insert({-newRating,food});

        
    }

    string highestRated(string cuisine) { return highestRatedFood[cuisine].begin()->second; }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */