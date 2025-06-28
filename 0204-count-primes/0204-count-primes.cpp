class Solution {
public:
    int countPrimes(int n) {
        //first brute force solution is of iterating and checking for prime
        //TC - O(NSQRTN) BAD FOR VERY LARGE NUMBERS
        //using seive of eratosthenes
        //TC - O(N) + O(NLOGLOGN) + O(N); NLOGLOGN IS DUE TO PRIME HARMONIC SERIES (mathematically derived)
        //CREATE A BLACKBOX WHERE EACH ELEMENT IS 1 AND ITERATE THROUGH THE MULTIPLES OF EACH NUMBER TO MARK IT ZERO
        //in the marking zero outer loop we run till sqrtn, take example of n=31 and its sqrt 5 will have marked everything thats non-prime
        if(n==0) return 0;
        int blackbox[n];
        for(int i=0;i<n;i++){
            blackbox[i] = 1;
        }
        for(int i=2;i*i<n;i++){
            if(blackbox[i]==1){
                for(int j=i*i;j<n;j+=i){//started from i*i because i*i-1, i*i-2 will be marked for previous values of j, eg: 3*2 marked already
                    blackbox[j]=0;
                }    
            }
        }
        int cnt = 0;
        for(int i=2;i<n;i++){
            if(blackbox[i]==1) cnt++;
        }
        return cnt;
    }
};