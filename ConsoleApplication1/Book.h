#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
	Book();
	Book(string bi, string bn, string au, string pu, double pr); // 构造函数
	void display(); // 显示函数
private:
	string _bookID; // 编号 
	string _bookName; // 书名 
	string _author; // 作者
	string _publish; // 出版社 
	double _price;  // 价格
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
	cout << "书号： " << _bookID << "\t";
	cout << "书名： " << _bookName << "\t";
	cout << "作者： " << _author << "\t";
	cout << "出版社： " << _publish << "\t";
	cout << "价格： " << _price << "\t";
}