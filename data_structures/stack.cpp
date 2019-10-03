#include<iostream>
using namespace std;
template <class T> 
class stack{
	int capacity;
	T *sarr;
	int size;
	int top;
	public:
		//constructor
		stack(){
			sarr = new T[10];
			capacity=10;
			size=0;
			top=-1;
		}
		
		void push(T x){
			if(capacity<=size+1){
				extend();
				sarr[top+1]=x;
				top++;
				size++;
			}
			else{
				sarr[top+1]=x;
				top++;
				size++;
			}
		}
		T peek(){
			if(top==-1){
				throw "Empty Stack";
			}
			else{
				return sarr[top];
			}
		}
		int length(){
			return size;
		}
		void pop(){
			if(top==-1)
				throw "Empty Stack";
			else{
				top--;
				size--;
				if(size<=(capacity+1)/2&&capacity>10){
					reduce();
				}
			}
		
		}
		bool empty(){
			if(top==-1)
				return true;
			else
				return false;	
		}
	private:
		void extend(){
			T *temp = new T[2*capacity];
			capacity = capacity*2;
			for(int i=0;i<size;i++){
				temp[i] = sarr[i];
			}
			sarr=temp;
		}
		void reduce(){
			T *temp = new T[(capacity+1)/2];
			capacity = (capacity+1)/2;
			for(int i=0;i<size;i++){
				temp[i] = sarr[i];
			}
			sarr = temp;
		}			

};
int main(){
	stack<int> s;
	//you can use stack class here
	return 0;	
}
