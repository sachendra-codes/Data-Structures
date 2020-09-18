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
	node():data(false), left(NULL),right(NULL){}
	node(int k):data(k), left(NULL), right(NULL){}
};
int height(node *t){
	if(t==NULL) return 0;
	return max(1+height(t->left), 1+height(t->right));
}

int height_iterative(node *t){
	list<node *> q;
	if(t==NULL) return 0;
	int h=0;
	q.push_back(t);
	while(!q.empty()){
		int size= q.size();
		while(size--){
			node *cur=q.front();
			q.pop_front();
			if(cur->left) q.push_back(cur->left);
			if(cur->right) q.push_back(cur->right);
		}
		h++;
	}
	return h;

}
int main()
{
	cpSetup();
	node *t1 = new node(25);
	t1->left = new node (15);
	t1->right = new node (36);
	t1->left->right = new node(20);
	t1->right->left = new node(30);
	t1->right->left->left = new node(70);

	cout<<height_iterative(t1);
}
