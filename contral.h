#include<iostream>
#include"model.h"
using namespace std;

class Contral
{
public:
	void contral()
	{
		Fun a1= View::Insert_view;
		Fun a2= View::Delete_view;
		Fun a3= View::Select_view;
		Fun a4= View::Update_view;
		Fun a5= View::Show_view;

		_model.Insert('1', a1);
		_model.Insert('2', a2);
		_model.Insert('3', a3);
		_model.Insert('4', a4);
		_model.Insert('5', a5);
		

	}
	void process()
	{
		cout << "1.insert" << endl;
		cout << "2.delete" << endl;
		cout << "3.update" << endl;
		cout << "4.select" << endl;
		cout << "5.show" << endl;
		cout << "6.exit" << endl;
		cout << "请选择您要使用的功能：" << endl;
		while (1)
		{
			char a;
			a=getchar();

			if (a == '1')
			{
				
				_model.search('1')();
				cout << "插入数据完成" << endl;
			}

			if (a == '2')
			{
				_model.search('2')();
				cout << "删除数据完成" << endl;
			}

			if (a == '3')
			{
				_model.search('3')();
				cout << "修改数据完成" << endl;
			}

			if (a == '4')
			{
				_model.search('4')();
				cout << "寻找数据完成" << endl;
			}
    
            if (a == '5')
            {
                _model.search('5')();
            }
			if (a == '6')
			{
				break;
			}
		}

	}
	
private:
	Model _model;

};
