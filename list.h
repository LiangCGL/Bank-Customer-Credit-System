#include<iostream>

#include<string>
using namespace std;

class node
{
public:
	node()
	{
		_next = NULL;
	}
	~node()
	{

	}

private:
	string _name;
	string _id;
	string _date;
	string _strings;
	string _limit;

	node * _next;

	friend class List;
	friend class Datebasd;

};


class List
{
public:
	List()
		:_top()
	{
		_count = 0;
	}

	static node * BuyNode(string name, string id, string date, string strings, string limit, node *next)
	{
		node *s = new node;

		s->_name = name;
		s->_id = id;
		s->_date = date;
		s->_strings = strings;
		s->_limit = limit;
		s->_next = next;

		return s;
	}

	 void Insert(string name, string id, string date, string strings, string limit)
	{
		node *p = List::BuyNode(name, id, date, strings, limit, _top._next);
		p->_next = _top._next;
		_top._next = p;
		_count++;
	}

	void Select(string id)
	{
		node *p = _top._next;

		while (p != NULL)
		{
			if (p->_id == id)
			{
				break;
			}
			p = p->_next;
		}
		cout << p->_name<<" ";
		cout << p->_id<<" "; 
		cout << p->_date << " ";
		cout << p->_strings << " ";
		cout << p->_limit << " " << endl;

	}

	void Update(string id, string name, string date, string strings, string limit)
	{
		node *s = _top._next;

		while (s != NULL)
		{
			if (s->_id == id)
			{
				break;
			}
			s = s->_next;
		}
		s->_id = id;
		s->_name = name;
		s->_limit = limit;
		s->_date = date;
		s->_strings = strings;

	}

	void Delete(string id)
	{
		node *s = _top._next;
		node *p = &_top;
		while (p->_next != NULL)
		{
			if (s->_id == id)
			{
				break;
			}
			s = s->_next;
			p = p->_next;
		}

		p->_next = s->_next;

		delete s;

		_count--;
	}



	List(const List & src)
	{
		_top._next = src._top._next;
		for (int i = 0; i < _count; i++)
		{
			Insert(src._top._name, src._top._id, src._top._date, src._top._limit, src._top._strings);
		}
	}

	List operator = (const List & src)
	{
		if (this == &src)
		{
			return *this;
		}

		if (NULL != _top._next)
		{
			delete _top._next;
		}
		_top._next = src._top._next;
		for (int i = 0; i < _count; i++)
		{
			Insert(src._top._name, src._top._id, src._top._date, src._top._limit, src._top._strings);
		}

		return *this;
	}
	void show()
	{
		node * p = _top._next;
		while (p != NULL)
		{
			cout << p->_name;
			cout << p->_id;
			cout << p->_date;
			cout << p->_strings;
			cout << p->_limit << endl;
			p = p->_next;
		}
	}

	~List()
	{

	}

private:
	node _top;

	int _count;

};
