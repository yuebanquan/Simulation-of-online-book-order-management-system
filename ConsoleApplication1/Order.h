#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class Order
{
public:
	Order();					// �޲ι��캯��
	Order(int re, string bu);	// ���캯��
	int getLine();				// ��ȡ Order.txt �е����� 
	void readOrder(Order o[]);	// ��Order.txt �ж�ȡ���ݷ��� Receipt ���������� 
	int Judge(int receiptID);	// �ж� Order.txt ���Ƿ���ڸö����ţ������ڷ��ظö������кţ������ڷ��� - 1 
	void addOrder(int receiptID, string buyerID); // ��Ӷ�����Ϣ 
	void deleteOrder(int receiptID); // ɾ��������Ϣ
private:
	int _receiptID; // ������� 
	string _buyerID; // �����˱��
};

Order::Order()
{
	_receiptID = 0;
	_buyerID = "";
}
// ���캯��
Order::Order(int re, string bu)
{
	_receiptID = re;
	_buyerID = bu;
}
// ��ȡ Order.txt �е�����
int Order::getLine()
{
	ifstream in("Order.txt");
	string line;
	int n = 0;		//����
	while (getline(in, line))
	{
		n++;
	}
	in.close();
	return n;
}
// ��Order.txt�ж�ȡ���ݷ���Receipt����������
void Order::readOrder(Order o[]) {
	ifstream infile("Order.txt", ios::in | ios::binary);
	if (!infile) {		//��������ڣ���ʾ����
		cerr << " ��ȡOrder.txt���� " << endl;
		exit(1);
	}
	int n = getLine();
	for (int i = 0; i < n; i++) {
		// ֻ��ȡ����������У��������������ز���
		string re, bu;
		infile >> re >> bu;
		int re2 = atoi(re.c_str());//���ַ���re.c_str()ת��Ϊ��������re2
		o[i]._receiptID = re2;
		o[i]._buyerID = bu;
	}
	infile.close();
}
// �ж� Order.txt ���Ƿ���ڸö����ţ������ڷ��ظö������кţ������ڷ��� -1
int Order::Judge(int receiptID) {
	Order order[50];
	readOrder(order); // ��ȡOrder.txt�����������roder��
	int n = getLine();
	for (int i = 0; i < n; i++) {
		if (receiptID == order[i]._receiptID) {
			return i; // ������ڣ��������±�
			break;
		}
	} return -1; // ���򣬷��� -1
}
// ��Ӷ���
void Order::addOrder(int re, string bu)
{
	ofstream outfile("Order.txt", ios::app);
	if (!outfile)
	{
		cerr << " open error" << endl;
		exit(1);
	}
	outfile << re << "\t";
	outfile << bu << "\n";
	outfile.close();
}
// ɾ������
void Order::deleteOrder(int receiptID)
{
	Order order[50];
	readOrder(order);
	int l = Judge(receiptID);	// ����һ��l������Judge()�ķ���ֵ�������жϸ�num�Ƿ����
	if (l != -1) {	// ���l������-1,��ʾҪɾ���Ķ�����Ϣ����
		int n = getLine();
		ofstream outfile("Order.txt");
		if (!outfile) {
			cerr << "��ȡOrder.txt����" << endl;
			exit(1);
		}
		for (int i = 0; i < n; i++) {
			// ���±겻����l ��������Ҫɾ�Ķ�����Ϣ�⣩�������������д����̱���
			if (i != l) {
				outfile << order[i]._receiptID << "\t";
				outfile << order[i]._buyerID << endl;
			}
		}
		outfile.close();
	}
}
