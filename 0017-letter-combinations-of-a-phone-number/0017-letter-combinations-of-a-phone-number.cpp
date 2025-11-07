class Solution {
public:
void backtrack(int index,vector<string>& result,string& current,const string& digits,const vector<string>& mapping){
    if(index == digits.size()){
        result.push_back(current);
        return;
    }

     int digit = digits[index] - '0'; // Convert char to int
        const string& letters = mapping[digit];

        for (char c : letters) {
            current.push_back(c);
            backtrack(index+1,result,current,digits,mapping);
            current.pop_back();
        }

}


    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return{};
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string> result;
        string current;

        backtrack(0,result,current,digits,mapping);
        return result;  
    }
};

