class Solution {
public:
    bool find(int i,int &s1,int &s2,int &s3,int &s4,vector<int>& m, map<string,bool> &dp, int &side)
    {
        if(s1>side || s2> side || s3 > side || s4>side) return false;
        
        if(i==m.size())
        {
            if(s1==s2 && s2==s3 && s3==s4) return true;
            else
                return false;
        }
        
        vector<int> temp(4);
        temp[0]=s1;
        temp[1]=s2;
        temp[2]=s3;
        temp[3]=s4;
        sort(temp.begin(), temp.end());
        
        string key=to_string(i)+"*"+ to_string(temp[0])+"*"+ to_string(temp[1])+"*"+ to_string(temp[2])+"*"+ to_string(temp[3]);
        
        if(dp.find(key)!= dp.end()) //already present
            return dp[key];
            
        
        bool ans=false;
        
        s1+=m[i];
        ans |= find(i+1,s1,s2,s3,s4,m,dp,side);
        s1-=m[i];
        
        s2+=m[i];
        ans |= find(i+1,s1,s2,s3,s4,m,dp,side);
        s2-=m[i];
        
        s3+=m[i];
        ans |= find(i+1,s1,s2,s3,s4,m,dp,side);
        s3-=m[i];
        
        s4+=m[i];
        ans |= find(i+1,s1,s2,s3,s4,m,dp,side);
        s4-=m[i];
        
        return dp[key]=ans;
    }
    
    bool makesquare(vector<int>& m) {
        
        map<string,bool> dp;
        
        int sum=0;
        for(auto it:m) sum+=it;
        
        if(sum%4!=0 || m.size()<=3) return false;
        
        sum/=4;
        
        sort(m.begin(), m.end(), greater<int>());
        int s1=0,s2=0,s3=0,s4=0,i=0;
        return find(i,s1,s2,s3,s4,m,dp,sum);
    }
};