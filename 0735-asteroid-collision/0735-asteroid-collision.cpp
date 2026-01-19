class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        int n = asteroids.size();

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && a < 0) {
                if (st.top() < -a) {
                    st.pop();          // top explodes
                    continue;
                } 
                else if (st.top() == -a) {
                    st.pop();          // both explode
                }
                destroyed = true;
                break;
            }

            if (!destroyed) {
                st.push(a);
            }
        }
        while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
}

reverse(ans.begin(), ans.end());

return ans;
        
    }
};