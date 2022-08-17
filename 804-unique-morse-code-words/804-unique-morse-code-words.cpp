class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        //string of set
        set<string> s;
        vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
       
        for(auto word:words)
        {
            string temp="";
            
            for(int i=0;i<word.length();i++)
            {
                temp+=v[word[i]-'a'];
            }
            
            s.insert(temp);
        }
        
        return s.size();
    }
};