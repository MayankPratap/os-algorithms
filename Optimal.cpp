// Optimal Page Replacement Algorithm , It can only be implemented in real systems when we are able to see the future :P 

/* A sample test case :- 

       Number of frames :- 3
       
       Number of pages in reference string :- 20
       
       Reference string :- 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1                            

*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

set<int>::iterator sit;
map<int,int>::iterator mit;


int main(){

   map<int,int>memory;        // Map which acts as main memory
   map<int,int>nextPos;       // nextPos will save what is the next occurence of a value 
   map<int,int>pos;           // pos will save for each index what is the next occcurence of value at that index
   map<int,int>visited;       // visited will keep track of pages which are currently in the main memory

   int nframes,npages;       
   vector<int>pages;              

   int x;

   cout<<"Enter number of frames\n";
   cin>>nframes;

   cout<<"Enter number of pages\n";
   cin>>npages;

   cout<<"Enter reference pages\n";

   for(int i=0;i<npages;++i){

      cin>>x;
      pages.pb(x);

   }

   for(int i=npages-1;i>=0;--i){

      if(nextPos.find(pages[i])==nextPos.end()){

         nextPos[pages[i]]=npages;
         pos[i]=nextPos[pages[i]];
         nextPos[pages[i]]=i;

      }

      else{

         pos[i]=nextPos[pages[i]];
         nextPos[pages[i]]=i;


      } 
       
   }
   for(int i=0;i<npages;++i){

       if(visited[pages[i]]==0){

           cout<<"Page fault at : "<<pages[i]<<"\n";

           if(memory.size()<nframes){           

               memory[pos[i]]=pages[i];    /*  You may be wondering why memory[pos[i]] ? Because in this algorithm we want to swap out
                                               that page whose next occurence is far away, so we needed the element in our map with largest 
                                               pos[i] , so we keep pos[i] as key of the map to get an O(log(n)) time complexity in accessing 
                                               the maximum element */
               visited[pages[i]]=1;

           }

           else{

              mit=memory.end();
              mit--;                 
              
              memory.erase(mit);
              //cout<<"Raula machegea\n";
              visited[mit->ss]=0;
              memory[pos[i]]=pages[i];
              visited[pages[i]]=1;

           }


       }
   }
}
