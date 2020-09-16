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

bool isidentical(node *t1, node *t2){
	if(t1==NULL && t2==NULL) return true;

	return ((t1 && t2) && (t1->data==t2->data) && isidentical(t1->left,t2->left)
		&& isidentical(t1->right,t2->right));
}

bool isidentical_iterative(node *t1, node *t2){
	stack<pair<node*,node*>> s;
	if(t1==NULL && t2==NULL) return true;
	else if(t1 && t2) s.push({t1,t2});
	else return false;
	while(!s.empty()){
		pair<node*, node*> temp = s.top();
		s.pop();
		if(temp.first->data==temp.second->data){
			if(temp.first->right && temp.second->right){
				s.push({temp.first->right,temp.second->right});
			}
			else if(temp.first->right || temp.second->right){
				return false;
			}

			if(temp.first->left && temp.second->left){
				s.push({temp.first->left,temp.second->left});
			}
			else if(temp.first->left || temp.second->left){
				return false;
			}
		}
		else{
			return false;
		}
	}
	return true;
}


int main()
{
	cpSetup();
	node *t1 = new node(25);
	t1->left = new node (15);
	t1->right = new node (36);
	t1->left->right = new node(20);
	t1->right->left = new node(30);

	node *t2 = new node(25);
	t2->left = new node (15);
	t2->right = new node (36);
	t2->left->right = new node(20);
	t2->right->left = new node(30);
	if(isidentical_iterative(t1,t2)) cout<<"Trees are identical";
	else cout<<"Tree are not identical";
	return false;
}
