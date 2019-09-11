class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()!= speed.size())
            return -1;
        
        vector<pair<int, int>> car;
        for(int i=0; i< position.size(); i++){
            car.push_back(make_pair(position[i],speed[i])); // hard part
        }
        sort(car.begin(), car.end());
        
        int res=0;    
        double max_time=0;
        
        for(int j=car.size()-1; j>=0; j--){
            double temp = (double)(target - car[j].first) / car[j].second;
            if(temp>max_time){
                max_time = temp;
                res++;
            }
        }
        
        return res;
    }
};
