class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length()-1;
        string temp="";
        string ans="";
        while(left<=right){
            char ch = s[left];
            if(ch!=' '){
                temp+=ch;
            }
            else if(ch==' '){
                if(ans!="" && temp!=""){
                    temp=temp+" "+ans;
                    ans=temp;
                    temp="";
                }
                else{
                    if(temp!=""){
                        ans=temp;
                        temp="";
                    }
                }
            }
            left++;
        }
        if(temp!="" && ans!=""){
            temp=temp+" "+ans;
            ans=temp;
        }
        else if(temp!=""){
            ans=temp;
        }
        
        return ans;
    }
};