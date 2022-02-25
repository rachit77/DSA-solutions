class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int s1,s2;
        s1= version1.length();
        s2= version2.length();
        
        int num1=0,num2=0;
        
        for(int i=0,j=0;i<s1 || j<s2;)
        {
            while(i<s1 && version1[i]!='.')
            {
                //make it num for comaparison
                num1=num1*10+  version1[i]-'0';
                i++;
            }
            
            while(j<s2 && version2[j]!='.')
            {
                num2=10*num2 + version2[j]-'0';
                j++;
            }
            
            if(num1<num2)
            {
                return -1;
                break;
            }
            
            if(num2<num1)
            {
                return 1;
                break;
            }
            
            num1=0;
            num2=0;
            i++;
            j++;
            
        }
        
        return 0;
        
        
    }
};