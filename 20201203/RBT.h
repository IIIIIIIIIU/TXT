#include <cstdio>

namespace R_B_Tree{
	template <class T1,class T2>
	class RBTree {
		private:
			
			struct Node{
				T1 key;
				T2 value;
				
				bool color;
				
				Node *leftChild,*rightChild,*father;
				
				Node(T1 key_,T2 value_,bool color_=false,Node *leftChild_=NULL,Node *rightChild_=NULL,Node *father_=NULL){
					key=key_;
					value=value_;
					color=color_;
					leftChild=leftChild_;
					rightChild=rightChild_;
					father=father_;
				}
			};
			
			Node *Root;
			
			bool getColor(Node *x){
				if(x==NULL)
					return false;
				return x->color;
			}
			
			bool getLR(Node *x){
				return x->father->leftChild==x;
			}
			
			void rightRotate(Node *x){
				Node *fa=x->father;
				Node *ffa=fa->father;
				if(ffa!=NULL){
					if(getLR(x))
						ffa->rightChild=x;
					else
						ffa->leftChild=x;
				}
				x->father=ffa;
				fa->father=x;
				fa->leftChild=x->rightChild;
				x->rightChild=fa;
			}
			
			void leftRotate(Node *x){
				Node *fa=x->father;
				Node *ffa=fa->father;
				if(ffa!=NULL){
					if(getLR(x))
						ffa->rightChild=x;
					else
						ffa->leftChild=x;
				}
				x->father=ffa;
				fa->father=x;
				fa->rightChild=x->leftChild;
				x->leftChild=fa;
			}
			
			void Rotate(Node *x){
				if(x->father->leftChild==x)
					rightRotate(x);
				else
					leftRotate(x);
			}
			
			void reColor(Node *x){
				x->color^=true;
			}
			
			Node* find(T1 key){
				Node *now=Root;
				while(now!=NULL){
					if(key==now->key)
						return now;
					if(key<now->key)
						now=now->leftChild;
					else
						now=now->rightChild;
				}
				return NULL;
			}
			
			Node *getUncle(Node *x){
				if(x->father->leftChild==x)
					return x->father->rightChild;
				return x->father->leftChild;
			}
			
			void Update(Node *x){
				if(!getColor(x)||x==Root||!getColor(x->fa))
					return;
				Node *fa=x->father,*ffa=fa->father,un=getUncle(fa);
				if(getColor(un)){
					reColor(fa);
					reColor(un);
					if(ffa!=Root){
						reColor(ffa);
						Update(ffa);
					}
				}
				else if(getLR(x)==getLR(fa)){
					rotate(fa);
					reColor(fa);
					reColor(ffa);
				}
				else{
					rotate(x);
					rotate(x);
					reColor(x);
					reColor(ffa);
				}
			}
			
		public:
			RBTree(){
				Root=NULL;
			}
			
			bool Find(const T1 &key,T2 &value){
				Node result=find(key);
				if(result==NULL)
					return false;
				else{
					value=result->value;
					return true;
				}
			}
			
			bool Insert(const T1 &key,const T2 &value){
				if(Root==NULL){
					Root=new Node(key,value);
				}
				else{
					Node *now=Root,*last;
					while(now!=NULL){
						last=now;
						if(now->key==key){
							return false;
						}
						else if(key<now->key){
							now=now->leftChild;
						}
						else if(key>now->key){
							now=now->rightChild;
						}
					}
					Node temp=new Node(key,value,true);
					if(key<last->key){
						last->leftChild=temp;
						temp->father=last;
					}
					else{
						last->rightChild=temp;
						temp->father=last;
					}
					Update(temp);
					return true;
				}
			}
	};
}
