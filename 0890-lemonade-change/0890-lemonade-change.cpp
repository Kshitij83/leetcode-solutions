class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> moneyinhand;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                moneyinhand[5]++;
            }
            else if(bills[i]==10){
                if(moneyinhand[5]>=1){
                    moneyinhand[5]--;
                    moneyinhand[10]++;
                }
                else{
                    cout<<"a";
                    return false;
                }
            }
            else if(bills[i]==20){
                if(moneyinhand[5]>=1 && moneyinhand[10]>=1){
                    moneyinhand[5]--;
                    moneyinhand[10]--;
                    moneyinhand[20]++;
                }
                else if(moneyinhand[5]>=3){
                    moneyinhand[5]-=3;
                    moneyinhand[20]++;
                }
                else{
                    cout<<"b"<<moneyinhand[5]<<" "<<moneyinhand[10]<<" "<<moneyinhand[20];
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