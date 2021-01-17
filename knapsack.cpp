#include<iostream>
using namespace std;


int knapsack(int* weights, int* values, int n, int maxWeight){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    
    //Let's have dp array which stores max profit at i for capacity i
    
    int dp[maxWeight+1]={0};
    
    for(int i=0;i<n;i++){
        
        for(int j=maxWeight;j>=weights[i];j--){
            
            dp[j]=max(dp[j],values[i]+dp[j-weights[i]]);
        }
    }
    return dp[maxWeight];
    
    /* ******Recursive Solution for basic understanding************
    if(n==0 || maxWeights==0)
        return 0;
    
    if(weights[n-1]>maxWeights)
        return knapsack(weights,values, n-1,maxWeight);
    
    else
        return max(val[n-1]+knapsack(weights,values,n-1,maxWeight-weights[n-1]),knapsack(weights,values,n-1,maxWeight));
    */

}
