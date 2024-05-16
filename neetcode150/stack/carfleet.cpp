class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int i, n = position.size();
        float time;
        vector<pair<int, float>> carStatus(n);
        stack<float> st;

        for (i=0; i<n; i++){
            time = static_cast<float>(target - position[i]) / speed[i];
            carStatus[i] = make_pair(position[i], time);
        }

        auto compare = [](const auto& a, const auto& b) {
            return a.first < b.first;
        };

        sort(carStatus.begin(), carStatus.end(), compare);

        for (const auto& t: carStatus){
            while(!st.empty() && t.second >= st.top()){ //t.second => time of the car to reach the target
                st.pop();
            }
            st.push(t.second);
        }

        return st.size();       
    }
};

// if a car at lower position takes lesser time to reach the target than the one in higher position, then that means the lower car has to overtake. 
// thus the stmt (t.second >= st.top())
//at such situation, when the lower car reaches the higher car position, both the cars would move with the speed that of the higher car and becomes the fleet
//-> thus we add the higher position car time to the stack so that we can compare that time with other cars time.
