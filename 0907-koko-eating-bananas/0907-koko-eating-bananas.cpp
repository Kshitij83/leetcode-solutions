class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpile = 0;
        for(int i : piles) maxpile = max(i,maxpile);
        int left = 1;
        int right = maxpile;
        while(left<=right) {
            int mid = (left+right)/2;
            long long hr = 0;
            for(int i : piles) {
                if(i%mid != 0) hr += 1;
                hr += i/mid;
            }
            if(hr>h) left = mid + 1;
            else right = mid - 1; 
        }
        return left;
    }
};