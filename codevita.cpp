#include<bits/stdc++.h> 
using namespace std; 

const int mod = 1e9+7;

vector<int> r_l(vector<int>&v){
 
   stack<pair<int,int>>s;
   vector<int>temp;
   for(int i=(int)v.size()-1;i>=0;i--){
 
	  if(s.size()==0) temp.push_back(v.size());
 
	  if(s.size()>0 and s.top().first < v[i]) temp.push_back(s.top().second);
 
	  else if(s.size()>0 and s.top().first >= v[i]){
		  while(s.size()>0 and s.top().first >= v[i]){
			  s.pop();
		  }
		  if(s.size()==0) temp.push_back(v.size());
		  else
		     temp.push_back(s.top().second);
	  }
    s.push({v[i],i});    
 
   }
   reverse(temp.begin(),temp.end());
  return temp;
 
}
 
vector<int> l_r(vector<int>&v){
 
   stack<pair<int,int>>s;
   vector<int>temp;
   for(int i=0;i<(int)v.size();i++){
 
	  if(s.size()==0) temp.push_back(-1);
 
	  if(s.size()>0 and s.top().first < v[i]) temp.push_back(s.top().second);
 
	  else if(s.size()>0 and s.top().first >= v[i]){
		  while(s.size()>0 and s.top().first >= v[i]){
			  s.pop();
		  }
		  if(s.size()==0) temp.push_back(-1);
		  else
		     temp.push_back(s.top().second);
	  }
    s.push({v[i],i});    
 
   }
  return temp;	
}
 
 
int main() {
 
	int L;
	cin>>L;
	int h,b;
	cin>>h>>b;
	vector<int>v(L);
	for(int i=0;i<L;i++){
		cin>>v[i];
	}
 
   int sum = accumulate(v.begin(),v.end(),0);
   int volume = sum*h*b;
   vector<int>l = l_r(v);
   vector<int>r = r_l(v);
 
   int maxi=INT_MIN;
   for(int i=0;i<L;i++){
    maxi = max(maxi,(r[i]-l[i]-1)*v[i]);
   } 
   cout<<maxi<<endl;
   cout<<(volume-maxi)%mod;
}
