#include<iostream>
#include"list.h"

using namespace std;


class Datebase
{
public:
	static Datebase* getbase()
	{
		if (_base == NULL)
		{
			_base = new Datebase();
		}
		return _base;
	}
	Datebase()
	{

	}

	 void Intset_datebase(string name,string id,string date,string strings,string limit)
	{
			
		_list.Insert( name, id, date, strings, limit);
	}

	 void Update_datebase(string id, string name, string date, string strings, string limit)
	{
	
		_list.Update(id, name, date, strings, limit);
	}

	 void Select_datebase(string id)
	{
		
		_list.Select(id);

	}

	 void Delete_datebase(string id)
	{
		
		_list.Delete(id);
	}

    void Show_datebase()
    {
        _list.show();
    }
private:

	static Datebase* _base;
	List _list;

	
};

Datebase*  Datebase::_base = NULL;
