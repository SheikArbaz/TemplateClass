#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <locale>
using namespace std;
#define sf scanf
#define pf printf
struct node{
	bool is_end;//Is end point of word
	int prefix_count;//no. of words with the given prefix....from head to that node
	struct node* child[26]; 
	node() {
    for(int i=0;i<26;i++) 
        child[i]= NULL;
	}
};
struct node *head=NULL;
void init(){
	head=new node();
	head->is_end=false;
	head->prefix_count=0;
}
void insert(string word){
	struct node *current=head;
	current->prefix_count++;
	for (int i = 0; i < word.size(); ++i){
		int letter=(int)word[i]-(int)'A';
		if(current->child[letter]==NULL)
			current->child[letter]=new node();
		current->child[letter]->prefix_count++;
		current=current->child[letter];
	}
	current->is_end=true;
}
bool search(string word){
	struct node *current=head;
	for (int i = 0; i < word.size(); ++i){
		struct node *next=current->child[((int)word[i]-(int)'A')];
		if(next==NULL)
			return false;
		current=next;

	}
	return current->is_end;
}
//count words with given prefix
int words_with_prefix(string prefix){
	struct node *current=head;
	for (int i = 0; i < prefix.size(); ++i){
		struct node *next=current->child[((int)prefix[i]-(int)'A')];
		if(next==NULL)
			return 0;
		current=next;

	}
	return current->prefix_count;
}
int main(int argc, char const *argv[])
{
	int n;
	string s;
	std::vector<string> elems;
	cin>>n;
	char delim=' ',x[10000];
	init();
	while(n--){
		sf(" %[^\n]",x);
		s=(string)x;
		for(auto& pq: s)
        	pq = toupper(pq);
		elems.clear();
	    stringstream ss(s);
    	string item;
    	while (getline(ss, item, delim))
        	elems.push_back(item);
       if(elems[0].compare("ADD")==0)
        	insert(elems[1]);
        else
        	cout<<words_with_prefix(elems[1])<<endl;
	}
	return 0;
}