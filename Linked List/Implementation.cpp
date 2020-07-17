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

//delete by key
void del_key(node **head_ref, int k){
	node *temp = *head_ref;
	node *prev;
	//If key found at first node
	if (temp->value==k){
		*head_ref=(*head_ref)->next;
		free(temp);
		return;
	}
	//search for key 
	while(temp!=NULL && temp->value!=k){
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL){cout<<"Key not found"<<endl; return;}
	prev->next = temp->next;
	free(temp);
}

// delete first element
void del_first(node **head_ref){
	if(*head_ref==NULL){cout<<"Can't delete List is empty"<<endl; return;}
	node *temp = *head_ref;
	*head_ref = (*head_ref)->next;
	free(temp); 
}

//delete last element
void del_end(node **head_ref){
	if(*head_ref==NULL){cout<<"Can't delete List is empty"<<endl; return;}
	node *temp = *head_ref;
	if(temp->next==NULL){
		*head_ref = NULL;
		free(temp);
		return;
	}
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	free(temp->next);
	temp->next=NULL;
}

//Print Linked List
void print(node *ptr){
	if(ptr==NULL){cout<<"List is empty"<<endl; return;}
	while (ptr!=NULL){
		cout<<ptr->value<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
} 

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	node *head =NULL;
	push_start(&head, 8); print(head);
	push_start(&head, 10); print(head);
	push_end(&head, 15); print(head);
	push_between(head->next, 20); print(head);
	del_first(&head); print(head);
	del_first(&head); print(head);
	del_end(&head); print(head);
	push_end(&head,50); print(head);
	push_end(&head, 40);print(head);
	del_key(&head,50); print(head);
	return 0;

}
