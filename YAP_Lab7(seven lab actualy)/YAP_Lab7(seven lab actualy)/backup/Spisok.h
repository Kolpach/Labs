#pragma once
#include <iostream>
//� ��������� ���������� ����� Elements, ������� ������ �������� ������ ��������, � ��� �� ��������� �� ������
//����� Spisok ������������ ����� ���������� ������ Elements, ������� �� ������ ��������, � ������ ����������� �������� � ����������� ������ ��� ������
//������ ���: �� ������ ����� ������� ����� �������, � ���� ������� ���, �� ���������� ����� ������ ����������(������ ������� Spisok)
//� ��������� ������ �� �������� ������ ����� ��������� p_begin � p_back, ��� �� �������� ���������� count
 class Elements
{
private:
	 int32_t one_element_of_list;
	 Elements *p_next = nullptr, *p_previous = nullptr;
	 static Elements *p_begin, *p_back;
	 static size_t count;
	 
	 Elements(int32_t);

	 void add_link(Elements* next, Elements* previous);
	 Elements* find_element(int16_t index);
public:
	Elements();//�� ���� �� �����, �� ��� ������� Spisok
	void push_back(int32_t elem);
	void delete_element(int16_t index);
	int32_t findMax();
	void show();
	~Elements();
protected:
	void delete_all();
};
class Spisok : public Elements
{
public:
	Spisok();//�� ���� ������ �� ������ ���������, �� ���������� ������������ �� ��������, �� ������ Element, ������� ������ �� ������
	~Spisok();
};