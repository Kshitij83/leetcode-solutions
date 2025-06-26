class Solution {
public:
    // int max(int a,int b){
    //     return (a>b)?a:b;
    // }
    int largestRectangleArea(vector<int>& heights) {
        //optimal approach - do onfly computation of pse and nse
        //TC - O() , SC - O()
        int max_area = INT_MIN;
        stack<int> st;
        int nse, pse;
        int h = heights.size();
        for(int i=0;i<h;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                nse = i;
                int id = st.top();
                st.pop();
                pse = (st.empty())?-1:st.top();
                max_area = max(heights[id]*(nse-pse-1),max_area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int id = st.top();
            st.pop();
            if(!st.empty() && heights[st.top()]==heights[id]){
                while(!st.empty() && heights[st.top()]==heights[id]){
                    st.pop();
                }
            }
            nse = h;
            pse = (st.empty())?-1:st.top();
            max_area = max(heights[id]*(nse-pse-1),max_area);
        }
        return max_area;


        //brute force method using nse and pse
        //TC - O(5N) , SC - O(4N)
        //loop from 0 to n-1 
        //area=arr[i]*(nse[i]-pse[i]-1);
        //get the max area
    }
};