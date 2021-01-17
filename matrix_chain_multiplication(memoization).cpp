#include<bits/stdc++.h>
using namespace std;
int matrixMultiply(int *a,int s,int e,int **output)
{
    if(s == e || s == (e-1))
    {
        return 0; // as either no matrix is present or one matrix is present only
    }
    
    if(output[s][e]!=-1)
    {
        return output[s][e];
    }
    int best = INT_MAX;  
    for(int k = s+1; k<e; k++)
    {
        int smallout1 = matrixMultiply(a,s,k,output);
        int smallout2 = matrixMultiply(a,k,e,output);
        int ans1 = a[s]*a[k]*a[e];
        
        int smallout = smallout1 + smallout2 + ans1;
        
        if(smallout < best)
        {
            best = smallout;
        }
        else
        {
            continue;
        }
    }
    output[s][e] = best;
    return best;
}

int mcm(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    int s = 0;
    int e = n-1;
    int **output = new int *[n+1];
    for(int i = 0; i<=n; i++)
    {
        output[i] = new int [n+1];
    }
    
    for(int i =0; i<=n; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            output[i][j] = -1;
        }
    }
    
    int ans =  matrixMultiply(p,s,n,output);
    for(int i = 0; i<=n; i++)
    {
        delete []output[i];
    }
    delete []output;
    return ans;

}

