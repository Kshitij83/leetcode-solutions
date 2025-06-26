class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // long long int number = 0;
        // float multiplier = 1;
        // for(int i=digits.size()-1;i>=0;i--){
        //     number+=digits[i]*multiplier;
        //     cout<<digits[i]*multiplier<<" number is "<<number<<endl;
        //     multiplier*=10;
        // }
        // cout<<number<<endl;
        // number++;
        // cout<<number;
        // digits.clear();
        // while(number>0){
        //     int digit = number%10;
        //     digits.insert(digits.begin(),digit);
        //     number/=10;
        // }
        // return digits;
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]+=carry;
            if(digits[i]==10){
                digits[i]=0;
                carry=1;
            }
            else{
                carry=0;
                break;
            }
        }
        if(carry){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};