#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

template<class H> class List
{
	public:
		virtual List<H>* ins(H *x)=0;
		virtual	List<H>* del(H *x)=0;
		virtual	int search(H *x)=0;
		virtual void print()=0;

};


template<class P> class Node
{
	private: 
		P key;
		Node<P> *prev,*next;
	public:
		Node(P x) 
			{
				key=x;
				prev=next=NULL;
			}
		Node<P>* getPrev(){return prev;}
		Node<P>* getNext(){return next;}
		void setPrev(Node<P> *prev){this->prev=prev;}
		void setNext(Node<P> *next){this->next=next;}
		P getKey(){return key;}
	
};

template<class H> class MyList:public List<H>
{
	private:
		Node<H> *head,*tail;
		int size;
		
	
	public:
		
		MyList()
			{
				size=0;
				head=tail=NULL;
			}
		
		List<H>* ins(H *x)
			{
				Node<H> *node= new Node<H>(*x);
				
				if(!tail){tail=head=node; size++; return this;}
				else	
					{
						head->setPrev(node);
						node->setNext(head);
						head=node;
						size++;
						return this;
					}	
			}
		List<H>* del(H *x)
			{
				int trov=0;
				Node<H>* current=head;
				Node<H> *p=current->getPrev();
				Node<H> *s=current->getNext();
				if(search(x)==1)
				{
					while(trov==0)
					{
						if(current->getKey()==*x)
							{ 
								p->setNext(s);
								s->setPrev(p);
								size--;
								return this;
								trov=1;
							}
						else {
								current=current->getNext(); 
							 	p=current->getPrev();
								s=current->getNext();
							 }
					}	
				}
				else cout << "L'elemento non e' presente nella lista " << endl;
				
			
			
			};
		
		int search(H *x)
			{
				Node<H> *current=head;
				while(current!=NULL)
				{
					if(current->getKey()==*x){return 1;}
					else current=current->getNext();
				}			
				
				return 0;
			
			};
		
		void print()
			{
				Node<H> *current=tail;
				cout << "{ ";
				while(current!=NULL)
				{
					cout << current->getKey() <<" " ;
					current=current->getPrev();
				}	
				cout << " }" << endl;
			};

};







int main(int argc, char** argv) {
	
	MyList<int> *porcaccio=new MyList<int>();
	int a[13]={23,4,6,8,12,21,5,9,7,3,16,2,24};
	for(int i=0;i<13;i++) {
	porcaccio->ins(&(a[i]));
	}
	porcaccio->del(&a[1]);
	porcaccio->del(&a[6]);
	porcaccio->del(&a[10]);
	porcaccio->del(&a[11]);
	porcaccio->print();
	
	
	return 0;
}
