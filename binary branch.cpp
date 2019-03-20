#include<iostream>
using namespace std;
class Node{
	public:
		//store data
		int data;
		//children
		Node *parent;
		Node *left;
		Node *right;
		Node(int value){
			data = value;
			parent = NULL;
			left = NULL;
			right = NULL;	
	}
};
class BiST{
	public:
		Node *root;
		BiST(){
			root = NULL;
		}
		void insert(int value){
			insertHelper(root,value);
		}
		void insertHelper(Node * current, int value){
			//Base case if current is NULL, insert there.
			if(current == NULL){
				current = new Node(value); 
				if (root == NULL) root = current;	
				return;
			}
			 
			/*if (root == NULL){
				root = new Node(value);
			}*/ 
			//Else compare the current data with value
			else if(value <  current->data){
				//If value <current data  ->move left and call insert
				//if left is NULL,insert it.
				if(current->left == NULL)	{
					current->left = new Node(value);
					current->left->parent = current;
				}
				//else move left and call insert
				else insertHelper(current->left , value);
			}
			else{
				//else move right and call insert
				if (current->right == NULL) {
					current->right = new Node(value);
					current->right->parent = current;
				}
				else insertHelper(current->right,value);
			}			
		}
			
		void display(){
			display2(root);
			cout<<endl;
		}
		
		void display2(Node *current){
			//Base condition
			if (current == NULL) return;
			//Display left
			display2(current->left);
			//display current
			cout<<current->data<<" , ";
			//display right
			display2(current->right);
		}
		Node * search1(Node * current,int value){
			if (current == NULL || current->data == value) return current;
			else if(value<current->data){
				return search1(current->left,value);
			}
			else return search1(current->right,value);
		}
		bool search(int value){
			if(search1(root,value)!=NULL) {
				cout<<"found"<<endl;
				return 1;
			}
			else {
				cout<<"Not found"<<endl;return 0;	
			}
		}
		int find_min(int value){
			Node *current = search1(root,value);
			Node *min = find_min1(current);
			cout<<endl;
			return min->data;
		}
		Node *find_min1(Node *current){
			if(current->left != NULL ){
				current = current->left;
			}
			else return current;
		}
		int count(int value){
			Node *current = search1(root,value);
			int total = count1(current,0);
			return total;
		}
		int count1(Node *current,int num){
			
			if (current == NULL) {	
			return num;
			}
			//Display left
			count1(current->left,num);
			count1(current->right,num);
		}
		
		/*void displayFancy(int spaces){
			//increase number of spaces
			//display right
			//print reqiured spaces
			//display current
			//display left
		/*
				16
			14	
				12
		10
				8
			6		
				4
		/*
			
		}*/
		//NExt class - Friday
		int height();
		void deleteNode();
		void replace_with_parent(Node *current,Node rep);
		void Range_search(k,l);
		
};
int main(){
	BiST t1;
	int k,n,x,min,num;
	cout<<"No of elements do you want?"; cin>>n; cout<<endl;
	cout<<"Insert the elements"<<endl;
	for(int i = 0; i < n ; i++){
		cin>>k;	
		t1.insert(k);	
	}
	t1.display();
	cout<<"Do you want to search whether any elements exist ?: Type the element ";
	cin>>x;cout<<endl;
	t1.search(x);
	cout<<"find the min of :";
	cin>>min;cout<<endl;
	cout<<t1.find_min(min);
	cout<<"find the pos:";
	cin>>min;cout<<endl;
	cout<<t1.count(num);
}
