#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
int main(){
  
    int nframes,npages;   // Number of frames in Main Memory  and Number Of Pages
    vector<int>pages;     // Reference vector of pages
    int x;

    cout<<"Enter number of frames\n";
    cin>>nframes;

    cout<<"Enter number of pages\n";
    cin>>npages;

     queue<int>q;          // A queue whose maximum size will be number of frames in main memory
     map<int,int>visited;    // A map to keep track of which pages are currenly in our FIFO queue

    for(int i=0;i<npages;++i){

       cin>>x;
       if(visited[x]==0){     // If page is not in main memory : so page fault
           
          cout<<"Page fault at "<<x<<"\n";
          visited[x]=1;           // Now page has been brought into main memory therefore mark as visited
          if(q.size()<nframes){     // If queue is not full to its maximum size , simply push the page 
            
             q.push(x);

          }

          else{
             x=q.front();          // If queue is full , we need to replace some page , what page should we choose ??
                                   // The page that is first in our current queue
             visited[x]=0;          // Mark it as unvisited
             q.pop();               // Remove it from queue

          }

       }

       
    }
	return 0;
}
