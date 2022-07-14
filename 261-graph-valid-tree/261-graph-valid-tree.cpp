class Solution {
public:
    
    int find_par(int x, vector<int> &par)
    {
        if(x== par[x]) return x;
        
        return par[x]=find_par(par[x],par);
            
    }
    
    void makeUnion(int node1, int node2, vector<int> &par)
    {
        int par1=find_par(node1,par);
        int par2=find_par(node2,par);
        
        // we already know both have diff parent
        par[par1]=par2;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        
        //by union and find no need of rank
        vector<int> par(n);
        
        for(int i=0;i<n;i++)
            par[i]=i;
        
        
// adding a new edge => both the node should not be present in same union
// at the end all the vertex should be present in same union aka same parent
        int flag=0;
        
        for(int i=0;i<edges.size();i++)
        {
           int u=edges[i][0];
            int v=edges[i][1];
            
           int par1= find_par(u,par);
           int par2= find_par(v,par);
            
            if(par1==par2)
            {
                flag=1;
                break;
                //cout<<"djvn";
            }
            
            makeUnion(u,v,par);
        }
        
        int temp=find_par(0,par);
        for(int it:par)
        {
            //cout<<it<<endl;
            if(temp!=find_par(it,par))
            {
                flag=1;
                break;
            }
        }
        
        if(flag) return false;
        
        return true;
        
    }
};