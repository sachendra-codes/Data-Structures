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

//Add element in front
void push(node **head_ref,int k){
	node *new_node=new node(k);
	new_node->next = *head_ref;
	*head_ref = new_node; 
}

//print List
void print(node* ptr){
	if(ptr==NULL) return;
	cout<<ptr->data<<" ";
	print(ptr->next);
}

//Print list in reverse order
void print_rev(node* ptr){
	if(ptr==NULL) return;
	print_rev(ptr->next);
	cout<<ptr->data<<" ";
}

//Reverse list p1=head p2=head->next
void rev(node **head_ref, node* p1, node* p2){
	if( p2==NULL){
		(*head_ref)->next=NULL;
		*head_ref = p1;
		return;
	}
	rev(head_ref, p1->next, p2->next);
	p2->next=p1;
}

//Check Palindrome 
//if flag becomes 1 than it is not palindrome else palindrome
int flag=0 ; //globally declared
void palindrome(node *ptr_e){
	static node *ptr_s=ptr_e;
	if(ptr_e==NULL) return ;
	palindrome(ptr_e->next);
	if(ptr_s->data !=ptr_e->data) flag=1;
	ptr_s=ptr_s->next;
}

int main() {
	cpSetup();
 	node *head=NULL;
 	push(&head,5);
 	push(&head,5);
 	push(&head,0);
 	push(&head,5);
 	push(&head,5);

 	//print_rev(head);
 	//cout<<endl;
	//rev(&head,head,head->next);
	palindrome(head);
	if (flag==0) cout<<"yes"<<endl;
	else cout<<"NO"<<endl;
	/*print_rev(head);*/
	return 0;
}
