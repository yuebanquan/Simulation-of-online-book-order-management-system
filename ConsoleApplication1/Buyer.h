#pragma once
#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <string>
using namespace std;

// 购书者类
class Buyer {
public:
	Buyer();
	Buyer(string id, string na, string ad); // 构造函数
	virtual void display(); // 显示函数（虚函数）
protected:
	string _buyerID; // 买家ID 
	string _name; // 姓名
	string _address; // 地址
};

// 普通人类
class People : public Buyer {
public:
	People(string id, string na, string ad) :Buyer(id, na, ad) { }
	void display();
};

// 会员类
class Member : public Buyer {
public:
	Member(string id, string na, string ad, double dc) :Buyer(id, na, ad) {
		_discountMember = dc;
	}
	void display();
private:
	double _discountMember; // 折扣率
};

// 贵宾类
class Vip : public Buyer {
public:
	Vip(string id, string na, string ad, double dc) :Buyer(id, na, ad) {
		_discountVip = dc;
	}
	void display();
private:
	double _discountVip; // 折扣率
};

Buyer::Buyer() {
	_buyerID = "";
	_name = "";
	_address = "";
}

Buyer::Buyer(string id, string na, string ad) {
	_name = na;
	_buyerID = id;
	_address = ad;
}


//获取Buyer.txt中的行数
int getLine() {
	ifstream in("Buyer.txt");
	string line;
	int n = 0;
	while (getline(in, line)) {
		n++;
	}
	in.close();
	return n;
}

void Buyer::display() {
	cout << "买家信息： "; cout << "ID ：" << _buyerID << "\t";
	cout << "姓名： " << _name << "\t"; cout << "地址： " << _address << "\n";
}

void People::display() {
	Buyer::display();
	cout << "该买家是普通人，无折扣率。 " << "\n";
}

void Member::display() {
	Buyer::display(); cout << "该买家是会员，折扣率为  " << _discountMember * 10 << " 折！ \n";
}

void Vip::display() {
	Buyer::display();
	cout << "该买家是贵宾，折扣率为  " << _discountVip * 10 << "折！ \n";
}