using namespace std;

 int lis(int arr[], int n) {
		
				
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/
     if(n ==0)
     {
         return 0;
     }
     int *output = new int[n];
     
     output[0] = 1;
     
     for(int i = 1; i<n; i++)
     {
         output[i] = 1;
         for(int j = i-1; j>=0; j--)
         {
             
             if(arr[j]>=arr[i])
             {
                 continue;
             }
             int ans = output[j]+1;
             if(ans > output[i])
             {
                 output[i] = ans;
             }
         }
         
     }
     
     
     int best = 0; 
     for(int i = 0; i<n; i++)
     {
         if(output[i]>best)
         {
             best = output[i];
         }
     }
     delete []output;
     return best;

 }
