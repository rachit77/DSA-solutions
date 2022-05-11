class Solution {
public:
    vector<string> ans;
    vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void makeCombination(int i, int n,string s, string digits)
    {
        if(s.length()==n)
        {
            ans.push_back(s);
            return;
        }
        
        //int z= std::stoi(digits[i]);
        
        for(int t=0;t<mappings[digits[i]-'2'].length();t++)
        {
            s.push_back(mappings[digits[i]-'2'][t]);
            makeCombination(i+1,n,s, digits);
            s.pop_back();
        }
        
        return;
            
    }
    
    
    vector<string> letterCombinations(string digits) {
        
      int n= digits.length();
        if(n==0) return ans;
        
        string s;
        makeCombination(0,n,s,digits);
        
        return ans;
        
    }
};