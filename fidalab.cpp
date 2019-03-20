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
		

		
		
		//NExt class - Friday
		//int height();
		void deleteNode(int value){
			Node *current = search1(root,value);
			if(current->left == NULL){ 
				replace_at_parent1(current,current->right);
			}
			else if(current->right == NULL){ 
				replace_at_parent1(current,current->left);
			}
			else{
				Node *temp = find_min1(current->right);
				replace_at_parent1(current,current->right);
				
			}
		}
		
		void replace_at_parent(int value1,int value2){
			Node *rep = search1(root,value2);
			Node *current = search1(root,value1);
			replace_at_parent1(current,rep);
		}
		void replace_at_parent1(Node *current,Node *rep){
			if(rep == root){
				root == current;	
			}
			else if(current == root){
				return;
			}
			else{
				if(rep->data > rep->parent->data){
					rep->parent->right = current;
					if(current->data > current->parent->data){
						rep->parent->right = NULL;
					}
					else rep->parent->left = NULL;
					current->parent = rep->parent;
				}
				else{
					rep->parent->left = current;
					if(current->data>current->parent->data){
						rep->parent->right = NULL;
					}
					else rep->parent->left = NULL;
					current->parent = rep->parent;
				}
			}
			print2DUtil(root,0);
		}     
		void print2DUtil(Node *root, int space){
			// Base case  
			if (root == NULL)  
			    return;  
			// Increase distance between levels  
			space += 5;  
			// Process right child first  
			print2DUtil(root->right, space);  

			// Print current node after space  
			// count  
			cout<<endl;  
			for (int i = 5; i < space; i++)  
			    	cout<<" ";  
				cout<<root->data<<"\n";  

			// Process left child  
			print2DUtil(root->left, space);  
			}  

			// Wrapper over print2DUtil()                                                           
		//void Range_search(k,l);
	
};
int main(){
	BiST t1;
	t1.insert(1);	
	t1.insert(6);
	t1.insert(4);
	t1.insert(0);
	t1.insert(7);
	t1.insert(2);
	t1.insert(5);
	t1.insert(9);
	t1.insert(10);
	t1.insert(8);
	t1.display();
	//cout<<t1.find_min(9)<<endl;
	//cout<<t1.count(5)<<endl;
	t1.replace_at_parent(7,1);
}
