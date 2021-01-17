string solve(int n, int x, int y)
{
	// Write your code here .
    int *dp = new int [n+1];
    
    for(int i = 0; i<n+1; i++)
        dp[i] = 0;
    //  the player would win if there are 1,x or y coins present there. 
    dp[1] = 1;
    dp[x] = 1;
    dp[y] = 1;
    
    for(int i = 2; i<=n; i++)
    {
        if(!dp[i]) // Here we don't know for sure the player 1 would win or not 
        {
            dp[i] = dp[i-1]^1; // player can remove 1 coins and see at i-1, if he loses at i-1, he will win at i
            
            if(i-x>=1) // after removing x coins the player comes at atleast 1 coin
            {// we haven't used i-x = 0  as there the case is already defined to be true. so player will outomatically win if he has x coins left.
                dp[i] = max(dp[i],dp[i-x]^1); // if player is not winning at i coins he can see where  he is losing at i-1 or i-x coins . In any of those conditions the player will win at i coins
                
            }
            
            if(i-y>=1)
            {
              dp[i] = max(dp[i],dp[i-y]^1);   
            }
        }
    }
    
    if(dp[n])
    {
    	delete []dp;
        return "Beerus"; // player 1
    }
    else
    {	delete []dp;
        return "Whis"; // player 2
    }
    
        
        

    
}
