#include "Spisok.h"

Elements* Elements::p_begin = nullptr;
Elements* Elements::p_back = nullptr;
size_t Elements::count = 0;

Elements::Elements()//����������� �� ��������� ����� ��� Spisok �� ������
{
}

Elements::Elements(int32_t a)//������������ � push_back ��� �������� ������ ��������
{
	if(count == 0)
		p_begin = this;
	++count;
	one_element_of_list = a;
}

void Elements::add_link(Elements* previous, Elements* next)// ��������� ��� ��������, ������ �������� ����� ���� �������(nullptr)
{
	if (next != nullptr)
		next->p_previous = previous;
	if (previous != nullptr)
		previous->p_next = next;
}
void Elements::push_back(int32_t elem)//���������� ����� ������� � �����
{
	Elements *pointer = new Elements(elem);
	add_link(p_back, pointer);
	p_back = pointer;
}
void Elements::delete_element(int16_t index)//������� �������
{
	--index;//���������� ������ � 1
	if (index < count && index >= 0)//�������� ���������
	{

		Elements *Current = find_element(index);
		add_link(Current->p_previous, Current->p_next);//��������� ��� �������� �������� ��� � ������ ������ ����� ������� ���� Elements � nullptr

		if (p_begin == Current)//���������� p_begin � p_back, ���� ������� ������� � ������/�����
			p_begin = Current->p_next;
		if (p_back == Current)
			p_back = Current->p_previous;

		Current->p_next = nullptr;
		Current->p_previous = nullptr; //����� ���������� �� ������ ������

		delete Current;//�������� ��������, ������� �������� � push_back
		--count;
	}
	else
		throw static_cast<std::string>("index out of range");
}
Elements* Elements::find_element(int16_t index)//���������� ������ ������ delete �������� �� �����.
{
	Elements *local = p_begin;
	for (int i = 0; i < index; ++i)
	{
		local = local->p_next;
	}
	return local;
}
int32_t Elements::findMax()
{
	int32_t Max=p_begin->one_element_of_list;
	Elements *local = p_begin;
	while (local != p_back)
	{
		local = local->p_next;
		if (local->one_element_of_list > Max)
		{
			Max = local->one_element_of_list;
		}
	}
	return Max;
}
void Elements::show()
{
	if (count != 0)
	{
		Elements *local = p_begin;
		while (local != p_back)
		{
			std::cout << local->one_element_of_list << "\t";
			local = local->p_next;
		}
		std::cout << local->one_element_of_list << "\t";
		std::cout << std::endl << "---------------" << std::endl;
	}
}
Elements::~Elements()
{
	if (p_next != nullptr)
		delete p_next;
	std::cout << this->one_element_of_list << " Was removed from the list" << std::endl;
	std::cout << "---------------" << std::endl;
}
void Elements::delete_all()
{
	delete p_begin;
}
Spisok::Spisok()
{
}
Spisok::~Spisok()
{
	delete_all();
}