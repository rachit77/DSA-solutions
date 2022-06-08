class Solution {
public:
   
   static bool compare(string a,string b){
    return a+b > b+a;
}
    string largestNumber(vector<int>& nums) {
        
        vector<string> v;
        for(auto i:nums) v.push_back(to_string(i));
        string s="";
        
        //sort(v.begin() ,v.end(),compare);
        sort(v.begin(),v.end(),compare);
        
        for(int i=0;i<v.size();i++)
            s+=v[i];
                
        return s[0]=='0'? "0" : s;
    }
};