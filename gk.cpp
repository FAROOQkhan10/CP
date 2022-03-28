#include<bits/stdc++.h>
using namespace std;


void solve(){  

       string s1,s2;
       cin>>s1>>s2;
       
       unordered_map<char,int> m;
       
       unordered_set<char> s;
       
       int flag=0;
       
       for(auto t:s1) s.insert(t);
       

       	for(auto t:s2){
       	if(s.find(t)==s.end()) {flag=1; break;}
       }
       
       if(flag==1) cout<<"IMPOSSIBLE\n";
      	    
       else{
       for(auto t:s2) m[t]++;
       
       for(auto t:s1) m[t]--;
       
       int count=0;
       
       for(auto t:m){
       	if(t.second>0) count +=1; 
       }
       
       cout<<count<<"\n";
       }
       
}


int main(){
	
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int t;
   cin>>t;
   for(int i=1;i<=t;i++){          
      cout<<"Case #"<<i<<": ";
      solve();
   }        
   
}