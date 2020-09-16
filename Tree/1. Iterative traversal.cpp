#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void cpSetup(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
struct node{
	int data;
	node *left, *right;
	node():data(0), left(NULL),right(NULL){}
	node(int k):data(k), left(NULL), right(NULL){}
};

void inorder(node *root){
	unordered_map<node*, int> cnt;
	stack<node *> s;
	s.push(root);
	while(!s.empty()){
		node *cur = s.top();
		if(cur==NULL){s.pop(); continue;}
		
		if(cnt[cur]==0){s.push(cur->left);}
		else if(cnt[cur]==1) {cout<<cur->data<<" ";}
		else if(cnt[cur]==2){s.push(cur->right);}
		
		else (s.pop());
		cnt[cur]++;
	}
}

void preorder(node *root){
	unordered_map<node*, int> cnt;
	stack<node *> s;
	s.push(root);
	while(!s.empty()){
		node *cur = s.top();
		if(cur==NULL){s.pop(); continue;}
		
		if(cnt[cur]==0) {cout<<cur->data<<" ";}
		else if(cnt[cur]==1) {s.push(cur->left);}
		else if(cnt[cur]==2){s.push(cur->right);}
		
		else (s.pop());
		cnt[cur]++;
	}
}

void postorder(node *root){
	unordered_map<node*, int> cnt;
	stack<node *> s;
	s.push(root);
	while(!s.empty()){
		node *cur = s.top();
		if(cur==NULL){s.pop(); continue;}
		
		if(cnt[cur]==0)  {s.push(cur->left);}
		else if(cnt[cur]==1) {s.push(cur->right);} 
		else if(cnt[cur]==2) {cout<<cur->data<<" ";}
		
		else (s.pop());
		cnt[cur]++;
	}
}


int main()
{
	cpSetup();
	node *root = new node(25);
	root->left = new node (15);
	root->right = new node (36);
	root->left->right = new node(20);
	root->right->left = new node(30);
	postorder(root);
	return 0;
}
