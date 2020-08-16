#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
class Todo{
public:
	void add();
	void del(int);
	void print();
private:
	typedef struct{
		string name;
		int year;
		int month;
		int day;
	}Event;
	vector<Event> list;
	bool check(int, int, int);
	bool leap(int);
};
void Todo::add(){
	Event event;
	cout<<"name: ";
	cin>>event.name;
	cout<<"year: ";
	cin>>event.year;
	cout<<"month: ";
	cin>>event.month;
	while(event.month>12 || event.month<1){
		cout<<"retry month: ";
		cin>>event.month;
	}
	cout<<"day: ";
	cin>>event.day;
	while(!check(event.year, event.month, event.day)){
		cout<<"retry day: ";
		cin>>event.day;
	}
	int size=list.size();
	for(int i=0;i<list.size();i++){
		if(event.year>list[i].year) continue;
		if(event.year<list[i].year){
			list.insert(list.begin()+i, event);
			break;
		}
		if(event.month>list[i].month) continue;
		if(event.month<list[i].month){
			list.insert(list.begin()+i, event);
			break;
		}
		if(event.day>list[i].day) continue;
		list.insert(list.begin()+i, event);
		break;
	}
	if(size==list.size()) list.push_back(event);
}
void Todo::del(const int id){
	if(id>=list.size() || id<0){
		cout<<"failed to delete event"<<endl;
		return;
	}
	list.erase(list.begin()+id);
}
void Todo::print(){
	int name=4;
	for(int i=0;i<list.size();i++){
		if(list[i].name.length()>name){
			name=list[i].name.length();
		}
	}
	cout<<"id "<<setw(name)<<"name"<<" year month day"<<endl;
	for(int i=0;i<18+name;i++){
		cout<<"-";
	}
	cout<<endl;
	for(int i=0;i<list.size();i++){
		cout<<setw(2)<<i<<setw(name+1)<<list[i].name<<setw(5)<<list[i].year<<setw(6)<<list[i].month<<setw(4)<<list[i].day<<endl;
	}
}
bool Todo::check(const int year, const int month, const int day){
	switch(month){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(day>=1 && day<=31) return true;
			else return false;
		case 4: case 6: case 9: case 11:
			if(day>=1 && day<=30) return true;
			else return false;
		case 2:
			if(leap(year)){
				if(day>=1 && day<=29) return true;
				else return false;
			}else{
				if(day>=1 && day<=28) return true;
				else return false;
			}
		default:
			return true;
	}
}
bool Todo::leap(const int year){
	if(year%400==0) return true;
	else if(year%100==0) return false;
	else if(year%4==0) return true;
	else return false;
}
int main(){
	cout<<"0: exit\n1: add\n2: del\n3: print\n\naction: ";
	int act;
	Todo todo;
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