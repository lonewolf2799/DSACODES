
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    
    // Creating the output table
    int **output = new int *[numDenominations+1];
    
    for(int i = 0 ; i<=numDenominations; i++)
    {
        output[i] = new int[value+1];
        
        
    }

    
    // filling the default values for amount 0 and including 0 coints (first row and column)
    
    for(int i = 0; i<numDenominations+1; i++)
    {
        output[i][0] = 1; // for 0 amount there is only 1 possible way of doing it
        
        
    }
    
    for(int i = 1; i<=value; i++)
    {
        output[0][i] = 0; 
    }
    
    
    // Doing the DP solution
    
    for(int i = 1; i<=numDenominations; i++)
    {
        for(int j = 1; j<=value; j++)
        {
            
            if(j >= denominations[i-1])
            {
                output[i][j] = output[i-1][j]+output[i][j-denominations[i-1]];
            }
            else
            {
                output[i][j] = output[i-1][j];
            }
        }
    }
    
   int ans = output[numDenominations][value];
    
    for(int i = 0; i<=numDenominations; i++)
    {
        delete []output[i];
    }
    
    delete []output;
    
   return ans;

}

