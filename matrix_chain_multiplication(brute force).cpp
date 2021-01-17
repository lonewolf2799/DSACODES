#include<bits/stdc++.h>
using namespace std;
int matrixMultiply(int *a,int s,int e)
{
    if(s == e || s == (e-1))
    {
        return 0; // as either no matrix is present or one matrix is present only
    }
    
    int best = INT_MAX;
    
    for(int k = s+1; k<e; k++)
    {
        int smallout1 = matrixMultiply(a,s,k);
        int smallout2 = matrixMultiply(a,k,e);
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
    
    return matrixMultiply(p,s,n);

}

