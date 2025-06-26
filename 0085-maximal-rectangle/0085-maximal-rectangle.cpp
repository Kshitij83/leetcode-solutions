class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //optimal approach - do onfly computation of pse and nse
        //TC - O(2N) {n for traversal and n for all stack traversals which include first loop as well as separately} , SC - O(N)
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
            nse = h;
            pse = (st.empty())?-1:st.top();
            max_area = max(heights[id]*(nse-pse-1),max_area);
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        //TC - O(N*M) + O(N*2M) , SC - O(N*M) + O(N) {N - ROWS, M - COLUMNS}
        //MAKE A PREFIX SUM MATRIX AND PASS EACH ROWS OF THAT MATRIX TO THE HISTOGRAM PROBLEM

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        for(int j=0;j<m;j++){
            int sum = 0;
            for(int i=0;i<n;i++){
                sum += (matrix[i][j]=='0')?0:1;
                if(matrix[i][j]=='0') sum = 0;
                prefixSum[i][j] = sum;
            }
        }
        int max_area = INT_MIN;
        for(int i=0;i<n;i++){
            max_area = max(max_area,largestRectangleArea(prefixSum[i]));
        }
        return max_area;
    }
};