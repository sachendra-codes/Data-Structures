#include <bits/stdc++.h>
using namespace std;
 
struct node
{
	int data;
	node *next;
	node(int k):data(k),next(NULL){}
};
 
void cpSetup() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

//iterativly print ptr=last
void print(node *ptr){
	if(ptr==NULL){cout<<"List is empty"<<endl;return;}
	node *end=ptr;
	cout<<ptr->next->data<<" ";
	ptr=ptr->next->next;
	while(ptr!=end->next) {
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

//Recursive print ptr=last
void rec_print(node *ptr,int flag=0){
	if(ptr==NULL){cout<<"List is empty"<<endl; return;}
	static node *end=ptr;
	if (ptr==end && flag==1) {cout<<endl; return;}
	cout<<ptr->next->data<<" ";
	rec_print(ptr->next,1);
}

//printing list in reverse order ptr=last
void rev_print(node *ptr, int flag=0){
	if(ptr==NULL){cout<<"List is empty"<<endl; return;}
	static node *end=ptr;
	if (ptr==end && flag==1) return;
	rev_print(ptr->next,1);
	cout<<ptr->next->data<<" ";
}

//Reverse the linked list ptr1=head ptr2=head->next
void reverse(node **last_ref, node *ptr1, node *ptr2 ,int flag=0){
	static node *start=ptr1;
	if (ptr1==start && flag==1) {(*last_ref)=ptr1; return;}
	reverse(last_ref,ptr1->next,ptr2->next,1);
	ptr2->next=ptr1;
}

//Add element at start
void add_front(node **last_ref, int k){
	node *new_node=new node(k);
	if (*last_ref==NULL){
		*last_ref=new_node;
		(*last_ref)->next=new_node;
	}
	else{
		new_node->next=(*last_ref)->next;
		(*last_ref)->next=new_node;
	}
}

//Add element to the end
void add_end(node **last_ref, int k){
	node *new_node=new node(k);
	if (*last_ref==NULL){
		*last_ref=new_node;
		(*last_ref)->next=new_node;
	}
	else{
		new_node->next=(*last_ref)->next;
		(*last_ref)->next=new_node;
		*last_ref=new_node;
	}
}
//Delete first node of linked list
void del_front(node **last_ref){
	if (*last_ref==NULL){cout<<"List is empty"<<endl; return;}
	node *del =(*last_ref)->next;
	if((*last_ref)->next == *last_ref){
		*last_ref=NULL;
		free(del);
		return;
	}
	(*last_ref)->next=(*last_ref)->next->next;
	free(del);
}

//delete last node of list
void del_end(node **last_ref){
	if (*last_ref==NULL){cout<<"List is empty"<<endl; return;}
	node *del =*last_ref;
	if((*last_ref)->next == *last_ref){
		*last_ref=NULL;
		free(del);
		return;
	}
	node *ptr=(*last_ref)->next;
	while(ptr->next!=*last_ref) ptr=ptr->next;
	ptr->next=(*last_ref)->next;
	*last_ref=ptr;
	free(del);
}

//del kth node of list
void del_k(node **last_ref, int k){
	if (*last_ref==NULL){cout<<"List is empty"<<endl; return;};
	if((*last_ref)->next==*last_ref){
		if(k==1) {*last_ref=NULL; return;}
		else{cout<<"Node not exist"<<endl;return;}
	}
	//k is pointing to first node
	if(k==1){
		(*last_ref)->next=(*last_ref)->next->next;
		return;
	}
	//reaching to kth node
	node *ptr = *last_ref;
	while(k>1 && ptr->next!=*last_ref){
		ptr=ptr->next;
		k--;
	}
	//k>length of list
	if(k!=1){cout<<"Node not exist"<<endl;return;}
	//k is pointing to last node
	if(ptr->next==*last_ref){
		ptr->next=(*last_ref)->next;
		*last_ref=ptr;
		return;
	}
	//k is between first and last node
	ptr->next=ptr->next->next;
}


int main() {
	cpSetup();
	cout<<"sac";
 	node *last = NULL;
 	add_front(&last,5);
 	add_front(&last,12);
 	add_end(&last,13);
 	add_end(&last,6);
 	add_end(&last,7);
 	print(last);
 	del_front(&last);
 	del_end(&last);
 	
 	del_k(&last,1);
 	rec_print(last);
 	rev_print(last);
 	del_k(&last,1);
 	//print(last);
 	del_k(&last,1);
 	//print(last);
 	del_front(&last);
 	del_front(&last);
 	//reverse(&last, last->next,last->next->next);
 	print(last);
 	rec_print(last);

 	
 	return 0;
}