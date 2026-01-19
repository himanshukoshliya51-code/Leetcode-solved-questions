class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> st;
        vector<int> ans;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && a < 0) {
                if (st.back() < -a) {
                    st.pop_back();
                    continue;
                } 
                else if (st.back() == -a) {
                    st.pop_back();
                }
                destroyed = true;
                break;
            }

            if (!destroyed) {
                st.push_back(a);
            }
        }

        for (int x : st) {
            ans.push_back(x);
        }

        return ans;
    }
};
