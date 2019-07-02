#pragma once
#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <string>
using namespace std;

// ��������
class Buyer {
public:
	Buyer();
	Buyer(string id, string na, string ad); // ���캯��
	virtual void display(); // ��ʾ�������麯����
protected:
	string _buyerID; // ���ID 
	string _name; // ����
	string _address; // ��ַ
};

// ��ͨ����
class People : public Buyer {
public:
	People(string id, string na, string ad) :Buyer(id, na, ad) { }
	void display();
};

// ��Ա��
class Member : public Buyer {
public:
	Member(string id, string na, string ad, double dc) :Buyer(id, na, ad) {
		_discountMember = dc;
	}
	void display();
private:
	double _discountMember; // �ۿ���
};

// �����
class Vip : public Buyer {
public:
	Vip(string id, string na, string ad, double dc) :Buyer(id, na, ad) {
		_discountVip = dc;
	}
	void display();
private:
	double _discountVip; // �ۿ���
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


//��ȡBuyer.txt�е�����
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
	cout << "�����Ϣ�� "; cout << "ID ��" << _buyerID << "\t";
	cout << "������ " << _name << "\t"; cout << "��ַ�� " << _address << "\n";
}

void People::display() {
	Buyer::display();
	cout << "���������ͨ�ˣ����ۿ��ʡ� " << "\n";
}

void Member::display() {
	Buyer::display(); cout << "������ǻ�Ա���ۿ���Ϊ  " << _discountMember * 10 << " �ۣ� \n";
}

void Vip::display() {
	Buyer::display();
	cout << "������ǹ�����ۿ���Ϊ  " << _discountVip * 10 << "�ۣ� \n";
}