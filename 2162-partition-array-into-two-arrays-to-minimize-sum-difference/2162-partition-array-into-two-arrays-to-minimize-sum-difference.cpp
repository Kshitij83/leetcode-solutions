class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        //idea : use meet in the middle
        //use bit masking, binary search
        
        //step 1 : find total sum
        int N = nums.size();
        int n = N/2;
        int sum = accumulate(nums.begin(),nums.end(),0);

        //step 2 : create two vectors of size half of total size
        vector<vector<int>> left(n+1),right(n+1);

        //step 3 : store all possible sum in left & right part
        for(int mask=0;mask<(1<<n);mask++) {
            int sz = 0, l=0, r=0;
            for(int i=0;i<n;i++) {
                if(mask&(1<<i)) {
                    sz++;
                    l += nums[i];
                    r += nums[i+n];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        //step 4 : sort the right part and initialize res
        for(int sz=0;sz<=n;sz++) sort(right[sz].begin(),right[sz].end());
        int res = min(abs(sum-2*left[n][0]),abs(sum-2*right[n][0]));

        //step 5 : iterate over left to get a corresponding 'b' from each 'a' of left part
        for(int sz=1;sz<n;sz++) {
            int rsz = n-sz;
            for(auto a : left[sz]) {
                int b = (sum-2*a)/2;
                auto& v = right[rsz];
                auto itr = lower_bound(v.begin(),v.end(),b);
                if(itr!=v.end()) res = min(res,abs(sum-2*(a+(*itr))));
                if(itr!=v.begin()) {
                    itr--;
                    res = min(res,abs(sum-2*(a+(*itr))));
                }
            }
        }
        
        //step 6 : return res
        return res;
    }
};