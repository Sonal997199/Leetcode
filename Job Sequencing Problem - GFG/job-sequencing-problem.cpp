//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool comp(const struct Job &job1,const struct Job &job2)
{
    return job1.profit>job2.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int jobs=0;
        int profit=0;
        int maxTime=0;
        
        for(int i=0;i<n;i++)maxTime=max(maxTime,arr[i].dead);
        
        vector<int> timeslots(maxTime+1,false);
        
        for(int i=0;i<n;i++)
        {
            Job curr=arr[i];
            for(int j=curr.dead;j>0;j--)
            {
                if(timeslots[j]==false)
                {
                    timeslots[j]=true;
                    profit+=curr.profit;
                    jobs++;
                    break;
                }
            }
        }
        return {jobs,profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends