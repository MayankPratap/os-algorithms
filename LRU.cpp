#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

set<int>::iterator sit;
map<int,int>::iterator mit;

int main(){

    int nframes,npages,x,y;  
    map<int,int>mapa;          // map with time as key and page value as value
    map<int,int>mapa2;         // map with page value as key and time as value
    map<int,int>visited;       // To keep track of whether a page has been visited or not.
 
    cin>>nframes>>npages;       // Enter number of frames and number of pages

    for(int i=0;i<npages;++i){    // Now enter pages one by one, Here iterator i acts as time at which page arrives.

       cin>>x;                       

       if(visited[x]==0){           // If page is not in main memory then page fault

       	  cout<<"Page fault at "<<x<<"\n";   
       	  visited[x]=1;              // Page has been brought into main memory
          
          if(mapa.size()<nframes){    // If number of pages in main memory is less than maximum size then put this page into main
                                      // memory

              mapa[i]=x;            // Here we keep track of which page arrived at ith time
              mapa2[x]=i;           // Here we keep track of latest time at which page x arrived

          }

          else{
            
             mit=mapa.begin();     // If main memory is full then we have to remove some of the pages from main memory
                                   // We are using LRU therefore we will choose , page in main memory with most earlier access time.             mapa.erase(mit);       
             visited[mit->ss]=0;     // We mark that page as unvisited.
             
            // cout<<mit->ff<<" "<<mit->ss<<"\n";

             mapa[i]=x;           // Mark the page which arrived at ith time
             mapa2[x]=i;          // Update the latest time of arrival of page x

          }

       }

       else{                       // If page is already in main memory  , page hit 
                                   // In this case we have to remove the already existing entry for page x and update new
          mit=mapa2.find(x);       // First we find the time at which page x had arrived 
          mit=mapa.find(mit->ss);  // Then we delete that entry from map , and update the current time
          mapa.erase(mit);
          mapa2[x]=i;
          mapa[i]=x;


       }
      


    }     
      
	return 0;
}
