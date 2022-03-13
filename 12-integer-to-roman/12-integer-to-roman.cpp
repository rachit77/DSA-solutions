class Solution {
public:
    

    string intToRoman(int num) {
        string s;
        
        int m=num/1000;
        int remM=num%1000;
         while(m)
        {
            s=s+'M';
            m--;
        }
        if(remM>=900)
        {
            s=s+'C'+'M';
                remM-=900;
        }
        
        int d=remM/500;
        int remD=remM%500;
        while(d)
        {
            s=s+'D';
                d--;
        }
        if(remD>=400)
        {
            s=s+'C'+'D';
                remD-=400;
        }
        
        
        int c=remD/100;
        int remC=remD%100;
        while(c)
        {
            s=s+'C';
            c--;
        }
        if(remC>=90)
        {
            s=s+'X'+'C';
                remC-=90;
        }
        
        int l=remC/50;
        int remL=remC%50;
         while(l) {
            s=s+'L';
            l--;
        }
        if(remL>=40)
        {
            s=s+'X'+'L';
                remL-=40;
        }
        
        int x=remL/10;
        int remX=remL%10;
         while(x)
        {
            s=s+'X';
            x--;
        }
        if(remX>=9)
        {
            s=s+'I'+'X';
                remX-=9;
        }
        
        int v=remX/5;
        int remV=remX%5;
        while(v) {
            s=s+'V';
            v--;
            
        }
        if(remV>=4)
        {
            s=s+'I'+'V';
                remV-=4;
        }
        
        int i=remV/1;
         while(i) {
            s=s+'I';
            i--;
        }
        return s;
        
    }
};