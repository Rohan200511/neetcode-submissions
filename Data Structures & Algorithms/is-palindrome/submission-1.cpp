class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for(char c : s){
            if(isalnum(c)) temp += c;
        }

        cout << temp;
        int i = 0;
        int j = temp.length() - 1;

        while(i <= j){
            if(tolower(temp[i++]) != tolower(temp[j--])) return false;
        }
        return true;
    }
};
