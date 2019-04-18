#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *left;
	Node *right;
	Node *parent;
	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};
class BiST{
	public:
	Node *root;
	BiST(){
		root = NULL;
	}
	//*********************************************************************
	void insert(int value){
		insertHelper(root,value);
	}
	void insertHelper(Node *current, int value){
		if(current == NULL){
			current = new Node(value);
			if(root == NULL){
				root = current;
			}
		}
		else{
			if(value<current->data){
				if(current->left == NULL){
					current->left = new Node(value);
					current->left->parent = current;
				}
				else insertHelper(current->left,value);
			}
			else{
				if(current->right == NULL){
					current->right = new Node(value);
					current->right->parent = current;
				}
				else insertHelper(current->right,value);
			}
		}
	}
	//*********************************************************************
	void display(){
		display(root);
		cout<<endl;
	}
	void display(Node *current){
		if(current == NULL){
			return;	
		}
		else{
			display(current->left);
			cout<<current->data<<",";
			display(current->right);
		}
	}
	
	//*********************************************************************
	int count(){
		return count(root);
	}
	int count(Node *current){
		if(current == NULL){
			return 0;
		}
		else return count(current->left)+1+count(current->right);
	}

	//*********************************************************************
	int height(Node *current){
		if(current == NULL){
			return 0;
		}
		else{
			int leftheight = height(current->left);
			int rightheight = height(current->right);
			if(leftheight>rightheight){
				return leftheight+1;
			}
			else return rightheight+1;
		}
	}
	int height(){
		return height(root);
	}
	//*********************************************************************
	Node *search(Node *current,int k){
		if(current == NULL || current->data == k){
			return current;
		}
		else if(k<current->data){
			search(current->left,k);
		}
		else search(current->right,k);
	}
	bool search(int k){
		if(search(root,k) == NULL){
			cout<<"Not found\n";return 0;
		}
		else cout<<"found\n";return 1;
	}
	//*********************************************************************
	int find_min(int value){
		Node *current = search(root,value);
		Node *min = find_min(current);
		return min->data;	
	}
	Node *find_min(Node *current){
		if(current == NULL){
			cout<<"NO minimum";
			return NULL;
		}
		else if(current->left == NULL){
			return current;
		}
		else{
			find_min(current->left);
		}
	}
	//*********************************************************************
	void print2Duntil(Node *current ,int space){
		if(current == NULL) return;
		space+=5;
		print2Duntil(current->right,space);
		cout<<endl;
		for(int i = 5; i < space; i++){
			cout<<" ";
		}
		cout<<current->data<<endl;
		print2Duntil(current->left,space);
	}
	void print2D(){
		cout<<"************************************************************\n";
		print2Duntil(root,0);
		cout<<"************************************************************\n";
	}
	//*********************************************************************
	int rangesearch(Node *current, int k1, int k2){
		if(current == NULL){
			return 0;
		}
		if(current->data == k2 && current->data == k1){
			return 1;
		}
		if(current->data<=k2 && current->data>= k1){
			cout<<current->data<<",";
			return rangesearch(current->left,k1,k2)+1+rangesearch(current->right,k1,k2);
		}
		else if(current->data<k2){
			rangesearch(current->right,k1,k2);
		}
		else rangesearch(current->left,k1,k2);
	}
	int rangesearch(int k1, int k2){
		return rangesearch(root,k1,k2);
	}
	//*********************************************************************
	void replace_at_parent(int i, int j){
		Node *current = search(root,i);
		Node *child = search(root,j);
		replace_at_parent(current,child);
		print2D();
	}
	void replace_at_parent(Node *current,Node *child){
		if(current == root){
			root = child;
		}
		if(child == root){
			cout<<"Not possible\n";
			return;
		}
		if(current == NULL){
			cout<<"Not possible\n";
			return;
		}
		else{	
		
			if(current == current->parent->left){
				if(child == NULL){
					child->parent->left = NULL;
				}
				else{
					current->parent->left = child;
					if(child == child->parent->left){
						child->parent->left = NULL;
					}
					else child->parent->right = NULL;
				}
			}
			else{
				if(child == NULL){
					child->parent->right = NULL;
				}
				else{
					current->parent->right = child;
					if(child == child->parent->left){
						child->parent->left = NULL;
					}
					else child->parent->right = NULL;
				}
			}
			child->parent = current->parent;
		}
	}
	//*********************************************************************
	void deleteVal(int value){
		Node *current = search(root,value);
		if(current == NULL){
			cout<<"cannot delete\n";
		}  
		else{
			if(current->left == NULL){
				replace_at_parent(current,current->right);
			}
			else if(current->right == NULL){
				replace_at_parent(current,current->left);
			}
			else{
				Node *temp = find_min(current->right);
				current->data = temp->data;
				replace_at_parent(temp,NULL);
				delete temp;
			}
		}
	}
	//*********************************************************************
};
int main(){
	BiST b1;
	b1.insert(5);
	b1.insert(4);
	b1.insert(7);
	b1.insert(6);
	b1.insert(2);
	b1.insert(3);
	b1.insert(8);
	b1.insert(1);
	b1.display();
	b1.print2D();
	cout<<"minimum :"<<b1.find_min(5)<<endl;
	cout<<"height :"<<b1.height()<<endl;
	cout<<"elements between 1 and 8 :"<<b1.rangesearch(1,8)<<endl;
	cout<<"No of elements :"<<b1.count()<<endl;
	b1.deleteVal(4);
	b1.print2D();
return 0;	
}
