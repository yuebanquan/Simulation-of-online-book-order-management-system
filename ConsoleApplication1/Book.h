#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
	Book();
	Book(string bi, string bn, string au, string pu, double pr); // ���캯��
	void display(); // ��ʾ����
private:
	string _bookID; // ��� 
	string _bookName; // ���� 
	string _author; // ����
	string _publish; // ������ 
	double _price;  // �۸�
};

Book::Book() {
	_bookID = "";
	_bookName = "";
	_author = "";
	_publish = "";
	_price = 0;
}

Book::Book(string bi, string bn, string au, string pu, double pr) {
	_bookID = bi;
	_bookName = bn;
	_author = au;
	_publish = pu;
	_price = pr;
}

void Book::display() {
	cout << "��ţ� " << _bookID << "\t";
	cout << "������ " << _bookName << "\t";
	cout << "���ߣ� " << _author << "\t";
	cout << "�����磺 " << _publish << "\t";
	cout << "�۸� " << _price << "\t";
}