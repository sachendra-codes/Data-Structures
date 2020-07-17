#include<bits/stdc++.h>
using namespace std;

struct node{
	int value;
	node *next;
	
	node(int x) : value(x), next(NULL){}
};

//Push element in front of the linked list
void push_start(node **head_ref, int k){
	node *new_node = new node(k);
	new_node->next = *head_ref;
	*head_ref = new_node;
}

//Insert element after a given location
void push_between(node *loc, int k){
	if(loc==NULL) {return;}
	node *new_node = new node(k);
	new_node->next = loc->next;
	loc->next = new_node;
}

//Insert element at the end of the list
void push_end(node **head_ref, int k){
	node *new_node = new node(k);
	//If linked list is empty
	if(*head_ref==NULL) {*head_ref=new_node; return;}

	//Traverse the list and reach to the end
	node *temp = *head_ref;
	while(temp->next!=NULL){temp=temp->next;}
	temp->next = new_node;

}


//Recursive traversal of linked list
void print_recur(node *ptr){
	if(ptr==NULL){
		cout<<endl;
		return;
	}
	cout<<ptr->value<<" ";
	print_recur(ptr->next);
} 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	node *head =NULL;
	push_start(&head, 8); print_recur(head);
	push_start(&head, 10); print_recur(head);
	push_end(&head, 15); print_recur(head);
	push_between(head->next, 20); print_recur(head);
	push_end(&head,50); print_recur(head);
	push_end(&head, 40);print_recur(head);
	
	return 0;

}
