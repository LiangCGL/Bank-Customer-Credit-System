#include<iostream>
#include"datebase.h"
using namespace std;

class View
{
public:
	static	void Insert_view()
	{
		string name;
		cin >> name;
		string id;
		cin >> id;
		string date;
		cin >> date;
		string strings;
		cin >> strings;
		string limit;
		cin >> limit;
		Datebase::getbase()->Intset_datebase(name, id, date, strings, limit);
	}
	static	void Delete_view()
	{
		string id;
		cin >> id;
		Datebase::getbase()->Delete_datebase(id);
	}
	static	void Update_view()
	{
		string id;
		cin >> id;
		string name;
		cin >> name;
		string date;
		cin >> date;
		string strings;
		cin >> strings;
		string limit;
		cin >> limit;
		Datebase::getbase()->Update_datebase(id, name, date, strings, limit);
	}
	static	void Select_view()
	{
		string id;
		cin >> id;
		Datebase::getbase()->Select_datebase(id);
	}

    static void Show_view()
    {
        Datebase::getbase()->Show_datebase();
    }
private:
	

};
