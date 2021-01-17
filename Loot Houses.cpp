using namespace std;
int getMaxMoney(int arr[], int n){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 

    if(n == 0)
    {
        return 0;
    }
    
    int *soln = new int[n];
    
soln[0] = arr[0];
    soln[1] = max(arr[0],arr[1]);
    
    for(int i = 2; i<n; i++)
    {
        soln[i] = max(soln[i-1],arr[i]+soln[i-2]);
        
        
    }
    
    int ans = soln[n-1];
    delete []soln;
    return ans;


}

