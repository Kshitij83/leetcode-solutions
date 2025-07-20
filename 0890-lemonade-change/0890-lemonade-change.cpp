class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twenties = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fives++;
            }
            else if(bills[i]==10){
                if(fives>=1){
                    fives--;
                    tens++;
                }
                else{
                    return false;
                }
            }
            else if(bills[i]==20){
                if(fives>=1 && tens>=1){
                    fives--;
                    tens--;
                    twenties++;
                }
                else if(fives>=3){
                    fives-=3;
                    twenties++;
                }
                else{
                    return false;
                }
            }
            else{
                cout<<"c";
                return false;
            }
        }
        return true;
    }
};