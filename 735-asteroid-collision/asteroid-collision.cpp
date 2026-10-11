class Solution {
public:
    bool collide(int top,int ast){
        if(top>0 && ast<0) return true;
        return false;
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int si = asteroids.size();
        for(int i=0;i<si;i++){
            int cond =1;
            while(!st.empty() && collide(st.top(),asteroids[i])){
                if(st.top() == abs(asteroids[i])){
                    cond =0;
                    st.pop();
                    break;
                }
                else if(st.top()>abs(asteroids[i])){
                    cond =0;
                    break;
                }
                else{
                    st.pop();
                }
            }
            
            if(cond) st.push(asteroids[i]);
        }

        vector<int> final;

        while(!st.empty()){
            final.push_back(st.top());
            st.pop();
        }
        reverse(final.begin(), final.end());
        return final;
    }
};