// LRU cache design problem. 
/*
	// possible operation
	1. Put a key-value pair .
	2. Fixed capacity.
	3. eviction if the size is full.
	4. All the insertion and deletion operation O(1) time.
*/


#include <bits/stdc++.h>
using namespace std;

class LRU_cache{
	private:
		int capacity;
		list <pair <int,int> > l; // double linked list used for storing the information.
		unordered_map <int ,list <pair <int,int> > ::iterator> m;// map to store the information 
	public :
		LRU_cache(int capacity)
			{
				this->capacity = capacity;
				m.clear();
				l.clear();
			}
		int find(int key)
			{	// thinking of try and catch situation
			  try{
			  	if(m.find(key)==m.end())
			  		{
			  			throw -1;
			  		}
				if(m.find(key)!=m.end())
					{	cout<<11<<" ";
						auto it = m[key];
						pair <int,int> kv = *it;
						l.erase(it);
						l.push_front(kv);
						m[key]  = l.begin();
						return kv.second;
					}
				}
			  catch(int e)
				{
					cout<<"INVAlID";
				}
				return -1;
			}
		void insert(int key,int val)
			{
				if(m.find(key)!=m.end())
					{
						auto it = m[key];
						l.push_front({key,val});
						l.erase(it);
						m[key] = l.begin();
					}
				else
					{
						pair <int,int> kv;
						kv.first = key;
						kv.second = val;
						l.push_front(kv);
						m[key] = l.begin();
					}
				if(l.size()>capacity)
					{
						pair <int,int> kv = l.back();
						l.pop_back();
						m.erase(kv.first);
					}
				return ;
			}
};



int main() {
	LRU_cache* lr = new LRU_cache(10);
	int t;
	cin>>t;// for number of operations to activate.
	while(t--)
		{	int c;
			cin>>c;
			if(c==1)
				{	int x,y;
					cin>>x>>y;
					lr->insert(x,y);
				}
			else
				{	int x;
					cin>>x;
					cout<<lr->find(x)<<" ";
				}
		}
	// your code goes here
	return 0;
}