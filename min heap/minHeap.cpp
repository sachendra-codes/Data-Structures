#include<bits/stdc++.h>
using namespace std;
void cpSetup(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
class minHeap
{
	int capacity,heap_size;
	int* harr;
public:
	minHeap(int cap);
	int getMin() {return harr[0];} 
	int parent(int i) {return (i-1)/2;}
	int left(int i) {return 2*i+1;}
	int right(int i) {return 2*i+2;}
	void minHeapify(int i);
	void insertKey(int k);
	int extractMin();
	void deleteKey(int i);
	void decreaseKey(int i, int keyValue);
};
void swap(int& a ,int& b){
	int temp =a;
	a = b;
	b = temp;
}

minHeap::minHeap(int cap){
	capacity=cap;
	heap_size=0;
	harr = new int[capacity];
}

void minHeap::minHeapify(int i){
	int smallest;
	if(left(i)<heap_size && harr[i]>harr[left(i)]) smallest=left(i);
	else smallest=i;
	if(right(i)<heap_size && harr[smallest]>harr[right(i)]) smallest=right(i);
	if(i!=smallest){
		swap(harr[i],harr[smallest]);
		minHeapify(smallest);
	}
}

void minHeap::insertKey(int k){
	if(heap_size==capacity) {cout<<"overflow"; return;}
	harr[heap_size] = k;
	int i= heap_size;
	heap_size++;
	while(i!=0 && harr[parent(i)]>harr[i]){
		swap(harr[parent(i)], harr[i]);
		i=parent(i);
	}
}

int minHeap::extractMin(){
	if(heap_size<=0) return -1;
	if(heap_size==1) {heap_size--; return harr[0];}
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	minHeapify(0);
	return root;
}

void minHeap:: decreaseKey(int i, int val){
	if(i<heap_size){
		harr[i]=val;
		while(i!=0 && harr[parent(i)]>harr[i]){
			swap(harr[parent(i)], harr[i]);
			i=parent(i);
		}
	}
}

void minHeap::deleteKey(int i){
	decreaseKey(i,INT_MIN);
	extractMin();
}


int main(){
	cpSetup();
	minHeap h(20);
	h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
}