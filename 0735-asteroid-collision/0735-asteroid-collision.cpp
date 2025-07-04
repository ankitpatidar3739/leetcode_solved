class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::list<int> st;

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                st.push_back(asteroid);
            } else {
                bool destroyed = false;
                while (!st.empty() && st.back() > 0) {
                    if (st.back() < std::abs(asteroid)) {
                        st.pop_back();
                    } else if (st.back() == std::abs(asteroid)) {
                        st.pop_back();
                        destroyed = true;
                        break;
                    } else {
                        destroyed = true;
                        break;
                    }
                }
                if (!destroyed && (st.empty() || st.back() < 0)) {
                    st.push_back(asteroid);
                }
            }
        }
        std::vector<int> result(st.begin(), st.end());
        return result;
    }
};