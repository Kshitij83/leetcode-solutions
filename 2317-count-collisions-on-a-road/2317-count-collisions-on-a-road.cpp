class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        stack<int> st;
        int count1 = 1;
        int count2 = 2;
        int n = directions.length();
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
            {
                st.push(directions[i]);
            }
            else
            {
                if(!st.empty() && st.top() == 'R' && directions[i] == 'L')
                {
                    res+=count2;
                    st.pop();
                    st.push('S');
                    st.push('S');
                }
                else if(!st.empty() && st.top() == 'R' && directions[i] == 'S' || !st.empty() && st.top() == 'S' && directions[i] == 'L')
                {
                    res += count1;
                    st.pop();
                    st.push('S');
                    st.push('S');
                }
                else
                {
                    st.push(directions[i]);
                }

                // not handeling the cases when top and directions are same letters
            }
        }
        int foundS = 0;
        while(!st.empty()) {
            if(st.top()=='S') foundS = 1;
            if(st.top()=='R' && foundS) res++;
            st.pop();
        }
        return res;
    }
};
