#include"todoList.h"
int main(){
	cout<<"0: exit\n1: add\n2: del\n3: print\n\naction: ";
	int act;
	todoList todo;
	while(cin>>act){
		switch(act){
			case 0:
				return 0;
			case 1:
				todo.add();
				break;
			case 2:
				cout<<"delete id(-1 to cancel): ";
				int del;
				cin>>del;
				if(del==-1){
					cout<<"delete canceled"<<endl;
					break;
				}
				todo.del(del);
				break;
			case 3:
				todo.print();
				break;
			default:
				cout<<"unknown action"<<endl;
		}
		cout<<"\naction: ";
	}
	return 0;
}
