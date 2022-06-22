class Solution {
public:
    int calculate(string s) {
        
      stack<int> st;
      int n=s.length();
        
        int operand=0,sign=1,res=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]-'0'>=0 && s[i]-'0'<=9) //is a digit
            {
                operand= 10* operand + (s[i]-'0');
            }
            else if(s[i]=='+')
            {
                res=res+ (sign*operand);
                sign=1;
                operand=0;
            }
            else if(s[i]=='-')
            {
                res=res+ (sign*operand);
                sign=-1;
                operand=0;
            }
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                res=res+(sign*operand);
                res*= st.top();
                st.pop();
                res+= st.top();
                st.pop();
                operand=0;
            }
            
            
        }
        
        //manipulate the stack expression
        return res+(sign*operand);
    }
};