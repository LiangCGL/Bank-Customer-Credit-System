#include<iostream>
#include<string>
#include"view.h"
using namespace std;


typedef void(*Fun)();


class node1
{
public:
	node1()
	{
		_next = NULL;
	}
	~node1()
	{

	}

private:

	char _key;
	Fun  _fun_val;
	node1 * _next;

	friend class Model;

};
class Model
{

public:

	Fun search(char key)
	{
		node1 * s = _head._next;
		
		while (s != NULL)
		{
			if (s->_key == key)
			{
				break;
			}
			s = s->_next;
		}
		
		return s->_fun_val;
	}

	

	node1 * BuyNode(char key, Fun fun_val, node1 * next)
	{
		node1 * s = new node1;

		s->_key = key;
		s->_fun_val = fun_val;
		s->_next = next;

		return s;
	}

	void Insert(char key, Fun fun_val)
	{
		node1 *s = Model::BuyNode(key, fun_val, _head._next);
		s->_next = _head._next;
		_head._next = s;
		_count++;
	}



	void Delete(Fun fun_val)
	{
		node1 *s = _head._next;
		node1 *p = &_head;;
		while (p->_next != NULL)
		{
			if (s->_fun_val == fun_val)
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

	void show()
	{
		node1 * p = _head._next;
		while (p != NULL)
		{
			cout << p->_key;
			cout << p->_fun_val;
		
			p = p->_next;
		}
	}
private:
	node1 _head;
	int _count;

};
