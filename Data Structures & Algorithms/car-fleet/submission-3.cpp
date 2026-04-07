class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int,int>> car;
    stack<double> fleet ;

    for(int i=0;i<position.size();i++){
        car.push_back({position[i],speed[i]});
    }
    sort(car.begin(), car.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.first > b.first; // Descending by pos
    });

    for(int i=0;i<car.size();i++){
        // int time = (target-car[i].first)/car[i].second;
        // if(fleet.empty()) fleet.push(time);
        double time = (double)(target - car[i].first) / car[i].second;

         if(fleet.empty() || time>fleet.top()) fleet.push(time);
    }

    return fleet.size();
    }
};
