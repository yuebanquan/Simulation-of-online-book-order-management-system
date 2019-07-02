#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Buyer.h"
#include "Order.h"
using namespace std;

const int G_MAX = 50;

// �к��࣬���һ�� int ����
class returnLs {
public:
	int l[50];
	//returnLs() {
	//
	//	}
};


// ������
class Receipt {
public:
	Receipt();
	Receipt(int re, string bo, int nu); // ���캯��
	int getBookLine(); // ��ȡ Book.txt �е�����
	void readBook(string bookID[], string bookName[], string author[],
		string publish[], string price[]); // ��Book.txt �ж�ȡ���ݷ���������
	int getBuyerLine(); // ��ȡ Buyer.txt ������
	void readBuyer(string buyerID[], string name[], string address[], string type[]);
	// ��Buyer.txt �ж�ȡ���ݷ���������
	void readOrder(string receiptID[], string buyerIDs[]); // ��Order.txt �У���ȡ���ݣ�����������
	int getReceiptLine(); // ��ȡReceipt.txt ������
	void readReceipt(Receipt receipt[]); // ��Receipt.txt �ж�ȡ���ݷ��� Receipt ����������
	returnLs Judge(int receiptID); // �ж� Receipt.txt ���Ƿ�����û�Ҫ��Ķ�����ţ�������ڣ� �����к�������
	void addReceipt(); // ��Ӷ���
	void deleteReceipt(); // ɾ������
	void selectReceiptByRI(); // ���ݶ����Ų��Ҷ���
	void selectReceiptByBI(); // ������� ID���Ҷ���
	void print(); // ��ӡ����

private:
	int receiptID; // �������
	string bookID; // ͼ����
	int num; // ��������
	double pay; // ֧���ܽ��
};


Receipt::Receipt() {
	receiptID = 0;
	pay = 0; // ֧���ܽ��
}

// ���캯��
Receipt::Receipt(int re, string bo, int nu) {
	receiptID = re;
	bookID = bo;
	num = nu;
}


// ��ȡ Book.txt ������
int Receipt::getBookLine() {
	ifstream in("Book.txt");
	string line;
	int n = 0;
	while (getline(in, line)) {
		n++;
	}
	in.close();
	return n;
}

// ��Book.txt �ж�ȡ���ݷ���������
void Receipt::readBook(string bookID[], string bookName[], string author[], string publish[],
	string price[]) {
	ifstream infile("Book.txt", ios::in);
	if (!infile) {
		cerr << " open error" << endl;
		exit(1);
	}
	for (int i = 0; i < 5; i++) {
		infile >> bookID[i] >> bookName[i] >> author[i] >> publish[i] >> price[i]; // ֻ��ȡ����������� �������������ز���
	}
	infile.close();
}

// ��ȡ Buyer.txt ������
int Receipt::getBuyerLine() {
	ifstream in("Buyer.txt");
	string line;
	int n = 0;
	while (getline(in, line)) {
		n++;
	}
	in.close();
	return n;
}

// ��Buyer.txt �ж�ȡ���ݷ���������
void Receipt::readBuyer(string buyerID[], string name[], string address[], string type[]) {
	ifstream infile("Buyer.txt", ios::in | ios::binary);
	if (!infile) {
		cerr << " open error" << endl;
		exit(1);
	}
	for (int i = 0; i < 5; i++) {
		infile >> buyerID[i] >> name[i] >> address[i] >> type[i]; // ֻ��ȡ����������� �������������ز���
	}
	infile.close();
}

// ��Order.txt �У���ȡ���ݣ�����������
void Receipt::readOrder(string receiptId[], string buyerIDs[]) {
	ifstream infile("Order.txt", ios::in | ios::binary);
	if (!infile) {
		cerr << " open error" << endl;
		exit(1);
	}
	Order o;
	int n = o.getLine();
	for (int i = 0; i < n; i++) { // ֻ��ȡ����������� �������������ز���
		infile >> receiptId[i] >> buyerIDs[i];
	}
	infile.close();
}

// ��ȡ Receipt.txt ������
int Receipt::getReceiptLine() {
	ifstream in("Receipt.txt");
	string line;
	int n = 0;
	while (getline(in, line)) {
		n++;
	}
	in.close();
	return n;
}

// ��Receipt.txt �ж�ȡ���ݷ��� Receipt ����������
void Receipt::readReceipt(Receipt receipt[]) {
	ifstream infile("Receipt.txt", ios::in | ios::binary);
	if (!infile) {
		cerr << " open error" << endl;
		exit(1);
	}
	int n = getReceiptLine();
	for (int i = 0; i < n; i++) { // ֻ��ȡ����������� �������������ز���
		string re, bu, bo, nu;
		infile >> re >> bo >> nu;
		int re2 = atoi(re.c_str());
		receipt[i].receiptID = re2;
		receipt[i].bookID = bo;
		int nu2 = atoi(nu.c_str());
		receipt[i].num = nu2;
	}
	infile.close();
}

// �ж� Receipt ���Ƿ�����û�Ҫ��Ķ�����ţ�������ڣ������к�������
returnLs Receipt::Judge(int receiptid) {
	Receipt receipt[G_MAX];
	returnLs ls;
	readReceipt(receipt); // ���� Read() ��������ȡ���ݣ��Ա���½���������ݵ��ж�
	int j = 0;
	for (int i = 0; i < 10; i++) {
		int ri = receipt[i].receiptID;
		if (receiptid == ri) {
			ls.l[j] = i;
			j++;
		}
		//else {
		//cout << "û�д˶����ţ���������ȷ������";
		//break;
		//}
	}
	return ls; // ������ڣ��������±��������
}


/********************************************************
��Ӷ���

1.�ж������������Ķ�����Ϊ ����+1
2.�ж��ܷ��
3.��ȡ���ID�����������ź����IDд�뵽Order.txt��
4.��������ź��鼮��ż���������Receipt.txt��(0�˳�)
******************************************************/
void Receipt::addReceipt() {
	string buyerID;
	string bookID;
	int num = 0;
	// ��Receipt.txt �ж�ȡ���ݷ��� Receipt ����������
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	int l = getReceiptLine(); // ��ȡ����
	receiptID = receipt[l - 1].receiptID; // �������ŵĳ�ֵ��Ϊ Receipt.txt �����һ�е� receiptID ��ֵ
	receiptID++;
	ofstream outfile("Receipt.txt", ios::app);
	if (!outfile) {
		cerr << " open error" << endl;
		exit(1);
	}
	// ��ȡ��� ID
	cout << "��������� ID��";
	cin >> buyerID;
	// ����� ID�Ͷ������д�� Order.txt ��
	Order order;
	order.addOrder(receiptID, buyerID);
	// ��������ź��鼮��ż��������� Receipt.txt ��
	cout << "�����빺���鼮��ż����������鼮���Ϊ 0ʱ��ֹͣ¼�� " << endl;
	while (bookID != "0") {
		int i = 0;
		cin >> bookID;
		// ���û����� 0ʱ����ѭ����ֹͣ¼��
		if (bookID == "0")
			break;
		cin >> num;
		outfile << receiptID << "\t";
		outfile << bookID << "\t";
		outfile << num << endl;
	} // �ر��ļ�
	outfile.close();
	cout << "��Ӷ����ɹ��� " << endl;
}

// ɾ������
void Receipt::deleteReceipt() {
	// ��Receipt.txt �ж�ȡ���ݷ��� Receipt ����������
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	cout << "��������Ҫɾ���Ķ����Ķ������ :";
	cin >> receiptID;
	// ɾ�� Order.txt ���û����붩���ŵ���������
	Order o;
	o.deleteOrder(receiptID);
	// ��ȡ�û����趩������ Receipt.txt ���ڵ���
	returnLs ls = Judge(receiptID);
	if (ls.l[0] >= 0) {
		int n = getReceiptLine();
		ofstream outfile("Receipt.txt");
		if (!outfile) {
			cerr << " open error" << endl;
			exit(1);
		}
		int j = 0;
		for (int i = 0; i < n; i++) {
			// ���±겻���� ls[] �еĶ�����Ϣ��������Ҫɾ�Ķ�����Ϣ�⣩�������������д����̱���
			if (i != ls.l[j]) {
				outfile << receipt[i].receiptID << "\t";
				outfile << receipt[i].bookID << "\t";
				outfile << receipt[i].num << endl;
			}
			else {
				j++;
			}
		}
		outfile.close();
		cout << "ɾ���ɹ� !" << endl;
	}
	else
		cout << "�����ݿ�û�д˶��� !" << endl;
}

// ���ݶ����Ų��Ҷ���
void Receipt::selectReceiptByRI() {
	// ��ȡ Receipt.txt �е�����
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	// ��ȡ Book.txt �е�����
	string bookID[G_MAX], bookName[G_MAX], author[G_MAX], publish[G_MAX], price[G_MAX];
	readBook(bookID, bookName, author, publish, price);
	// ��ȡ Buyer.txt �е�����
	string buyerID[G_MAX], name[G_MAX], address[G_MAX], type[G_MAX];
	readBuyer(buyerID, name, address, type);
	// ��ȡ Order.txt �е�����
	string receiptId[G_MAX], buyerIDs[G_MAX];
	readOrder(receiptId, buyerIDs);
	cout << "������������Ҷ����ı�ţ� ";
	int ri = 0;
	cin >> ri;
	double discount = 1;
	int x = 0;
	Order o;
	int n = o.getLine(); // ѭ�� Order.txt �е����ݣ�ƥ����Ҷ�������ѭ�������еĶ�������ͬ���Ӷ���ö�Ӧ���������ID
	for (int i = 0; i < n; i++) {
		int rei = atoi(receiptId[i].c_str());
		if (ri == rei) {
			x++;
			cout << endl << " ������ţ� " << ri << endl;
			// ѭ�� Buyer.txt �е����ݣ� ƥ����Ҷ����ŵ���� ID��ѭ�����е���� ID��ͬ����������Ϣ
			int n1 = getBuyerLine();
			for (int k = 0; k < n1; k++) {
				if (buyerIDs[i] == buyerID[k]) {
					// �ж������ݣ���ȡ�ۿ�
					if (type[k] == "0") {
						People p(buyerID[k], name[k], address[k]);
						p.display();
					}
					else if (type[k] == "1") {
						Member m(buyerID[k], name[k], address[k], 0.9);
						m.display();
						discount = 0.9;
					}
					else if (type[k] == "2") {
						Vip v(buyerID[k], name[k], address[k], 0.8);
						v.display();
						discount = 0.8;
					}
				}
			}
		}
	}
	returnLs ls = Judge(ri);
	if (ls.l[0] >= 0) {
		int n = getReceiptLine(); // ѭ�� Receipt.txt �е����ݣ��жϲ��ҵĶ�������ѭ���Ķ������Ƿ���ͬ��ѭ������������� �������ܽ��
		for (int j = 0; j < n; j++) {
			// ��ͬʱ����ȡ�����鼮���
			if (ri == receipt[j].receiptID) {
				int n2 = getBookLine(); // ѭ���鼮�����ݣ��ж������ȡ���鼮�����ѭ�����鼮����Ƿ���ͬ
				for (int m = 0; m < n2; m++) {
					// ��ͬ������鼮��Ϣ�������ܽ��
					if (receipt[j].bookID == bookID[m]) {
						double pri = atof(price[m].c_str());
						Book b(bookID[m], bookName[m], author[m], publish[m], pri);
						b.display();
						cout << " ������ " << receipt[j].num << endl << endl;
						pay = pay + pri * receipt[j].num;
					}
				}
			}
		}
		cout << "�ܽ� " << pay * discount << endl;
		cout << "***********************************************************" << endl;
	}
	if (x == 0) {
		cout << endl << "�����ڸö����� " << endl;
		cout << "***********************************************************" << endl;
	}
}

// ������� ID���Ҷ���
void Receipt::selectReceiptByBI() {
	// ��ȡ Receipt.txt �е�����
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	// ��ȡ Book.txt �е�����
	string bookID[G_MAX], bookName[G_MAX], author[G_MAX], publish[G_MAX], price[G_MAX];
	readBook(bookID, bookName, author, publish, price);
	// ��ȡ Buyer.txt �е�����
	string buyerID[G_MAX], name[G_MAX], address[G_MAX], type[G_MAX];
	readBuyer(buyerID, name, address, type);
	// ��ȡ Order.txt �е�����
	string receiptId[G_MAX], buyerIDs[G_MAX];
	readOrder(receiptId, buyerIDs);
	cout << "������������Ҷ��������� ID��";
	string bi = "";
	cin >> bi;
	double discount = 1;
	int x = 0;
	Order o;
	int n2 = o.getLine();
	int n = atoi(receiptId[n2 - 1].c_str());
	// ѭ�� Order �е����ݣ��ж��û��������� ID�Ƿ���ѭ�����е������Ƿ���ͬ
	for (int i = 0; i < n; i++) {
		// ��ͬʱ����������ţ�������Ϣ���鼮��Ϣ���ܼ�
		if (bi == buyerIDs[i]) {
			x++; //1. ���������
			cout << endl << " ������Ϊ�� " << receiptId[i] << endl; //2. ��������Ϣ

			// ѭ�� Buyer.txt ���ж��� Order.txt �е���� ID�Ƿ����û��������� ID��ͬ
			int n2 = getBuyerLine();
			for (int k = 0; k < n2; k++) {
				// �����ͬ��������Ϣ
				if (buyerID[k] == bi) {
					if (type[k] == "0") {
						People p(buyerID[k], name[k], address[k]);
						p.display();
					}
					else if (type[k] == "1") {
						Member m(buyerID[k], name[k], address[k], 0.9);
						m.display();
						discount = 0.9;
					}
					else if (type[k] == "2") {
						Vip v(buyerID[k], name[k], address[k], 0.8);
						v.display();
						discount = 0.8;
					}
				}
			}
			//3. ����鼮��Ϣ
			int n = getReceiptLine();
			// ѭ�� Receipt.txt, �ж�ѭ�����еĶ�����������ѭ���Ƿ���ͬ
			for (int j = 0; j < n; j++) {
				int reci = atoi(receiptId[i].c_str());
				if (receipt[j].receiptID == reci) {
					int n3 = getBookLine(); // ѭ�� Book.txt, �ж�Receipt.txt �е��鼮�����ѭ�������鼮����Ƿ���ͬ
					for (int m = 0; m < n3; m++) {
						// ��ͬ������鼮��Ϣ
						if (receipt[j].bookID == bookID[m]) {
							double pri = atof(price[m].c_str());
							Book b(bookID[m], bookName[m], author[m], publish[m], pri);
							b.display();
							cout << " ������ " << receipt[j].num << endl << endl;
							pay = pay + pri * receipt[j].num;
						}
					}
				}
			}
			cout << " �ܽ� " << pay * discount << endl;
			cout << "***********************************************************" << endl;
		}
	}
	if (x == 0) {
		cout << endl << "�����û�ж����� " << endl;
		cout << "***********************************************************" << endl;
	}
}

// ��ʾ���ж���
void Receipt::print() {
	// ��ȡ Receipt.txt �е�����
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	// ��ȡ Book.txt �е�����
	string bookID[G_MAX], bookName[G_MAX], author[G_MAX], publish[G_MAX], price[G_MAX];
	readBook(bookID, bookName, author, publish, price);
	// ��ȡ Buyer.txt �е�����
	string buyerID[G_MAX], name[G_MAX], address[G_MAX], type[G_MAX];
	readBuyer(buyerID, name, address, type);
	// ��ȡ Order.txt �е�����
	string receiptId[G_MAX], buyerIDs[G_MAX];
	readOrder(receiptId, buyerIDs);
	double discount = 1;
	Order o;
	int n2 = o.getLine();
	int n = atoi(receiptId[n2 - 1].c_str());
	for (int z = 0; z < n; z++) {
		// �ж� Order.txt ���Ƿ��������
		if (n2 <= 0) {
			cout << " �������κζ����� " << endl;
			break;
		}
		else {
			// ѭ�� Order �е����ݣ��ж϶������Ƿ����
			for (int i = 0; i < n2; i++) {
				int rei = atoi(receiptId[i].c_str());
				// ������ڣ���������ţ���������Ϣ������鱾����������ܼ�
				if (rei == z) {
					//1. ��������� cout<<endl<< "������Ϊ�� " <<rei<<endl;
					//2. ��������Ϣ // ѭ�� Buyer.txt ���ж��� Order.txt �е���� ID�Ƿ���ѭ�����е���� ID��ͬ
					int n2 = getBuyerLine();
					for (int k = 0; k < n2; k++) {
						// �����ͬ��������Ϣ
						if (buyerIDs[i] == buyerID[k]) {
							if (type[k] == "0") {
								People p(buyerID[k], name[k], address[k]);
								p.display();
							}
							else if (type[k] == "1") {
								Member m(buyerID[k], name[k], address[k], 0.9);
								m.display();
								discount = 0.9;
							}
							else if (type[k] == "2") {
								Vip v(buyerID[k], name[k], address[k], 0.8);
								v.display();
								discount = 0.8;
							}
						}
					}
					//3. ����鼮��Ϣ
					int n = getReceiptLine(); // ѭ�� Receipt.txt, �ж�ѭ�����еĶ������������Ƿ���ͬ
					for (int j = 0; j < n; j++) {
						if (receipt[j].receiptID == z) {
							int n3 = getBookLine();
							// ѭ�� Book.txt, �ж�Receipt.txt �е��鼮�����ѭ�������鼮����Ƿ���ͬ
							for (int m = 0; m < n3; m++) {
								// ��ͬ������鼮��Ϣ
								if (receipt[j].bookID == bookID[m]) {
									double pri = atof(price[m].c_str());
									Book b(bookID[m], bookName[m], author[m], publish[m],
										pri);
									b.display();
									cout << "������ " << receipt[j].num << endl << endl;
									pay = pay + pri * receipt[j].num;
								}
							}
						}
					}
					cout << "�ܽ� " << pay * discount << endl;
					cout << "***********************************************************" << endl;
				}
			}
		}
	}
}