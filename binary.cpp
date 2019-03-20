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
			if(current->left == NULL ){
				return current;	
			}
			else return find_min1(current->left);
		}
		int count(int value){
			Node *current = search1(root,value);
			int total = count1(current,0,0);
			return total;
		}
		int count1(Node *current,int numl,int numr){
			if (current == NULL) {	
			return numl+numr;
			}
			//Display left
			if(current->left!=NULL){
				count1(current->left,numl,numr);
				numl++;
			}
			else{
				count1(current->right,numl,numr);
				numr++;
			}
		
		}
};
int main(){
	BiST t1;
	t1.insert(5);	
	t1.insert(6);
	t1.insert(4);
	t1.insert(3);
	t1.insert(7);
	t1.insert(2);
	t1.insert(1);
	t1.insert(9);
	t1.insert(10);
	t1.insert(8);
	t1.display();
	cout<<t1.find_min(5)<<endl;
	cout<<t1.count(5)<<endl;
}
