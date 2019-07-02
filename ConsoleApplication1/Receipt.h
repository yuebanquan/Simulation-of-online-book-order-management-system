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

// 行号类，存放一个 int 数组
class returnLs {
public:
	int l[50];
	//returnLs() {
	//
	//	}
};


// 订单类
class Receipt {
public:
	Receipt();
	Receipt(int re, string bo, int nu); // 构造函数
	int getBookLine(); // 获取 Book.txt 中的行数
	void readBook(string bookID[], string bookName[], string author[],
		string publish[], string price[]); // 从Book.txt 中读取数据放入数组中
	int getBuyerLine(); // 获取 Buyer.txt 的行数
	void readBuyer(string buyerID[], string name[], string address[], string type[]);
	// 从Buyer.txt 中读取数据放入数组中
	void readOrder(string receiptID[], string buyerIDs[]); // 从Order.txt 中，读取数据，放入数组中
	int getReceiptLine(); // 获取Receipt.txt 的行数
	void readReceipt(Receipt receipt[]); // 从Receipt.txt 中读取数据放入 Receipt 对象数组中
	returnLs Judge(int receiptID); // 判断 Receipt.txt 中是否存在用户要求的订单编号，如果存在， 返回行号数组类
	void addReceipt(); // 添加订单
	void deleteReceipt(); // 删除订单
	void selectReceiptByRI(); // 根据订单号查找订单
	void selectReceiptByBI(); // 更具买家 ID查找订单
	void print(); // 打印订单

private:
	int receiptID; // 订单编号
	string bookID; // 图书编号
	int num; // 购书数量
	double pay; // 支付总金额
};


Receipt::Receipt() {
	receiptID = 0;
	pay = 0; // 支付总金额
}

// 构造函数
Receipt::Receipt(int re, string bo, int nu) {
	receiptID = re;
	bookID = bo;
	num = nu;
}


// 获取 Book.txt 的行数
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

// 从Book.txt 中读取数据放入数组中
void Receipt::readBook(string bookID[], string bookName[], string author[], string publish[],
	string price[]) {
	ifstream infile("Book.txt", ios::in);
	if (!infile) {
		cerr << " open error" << endl;
		exit(1);
	}
	for (int i = 0; i < 5; i++) {
		infile >> bookID[i] >> bookName[i] >> author[i] >> publish[i] >> price[i]; // 只读取存放在数组中 但不对其进行相关操作
	}
	infile.close();
}

// 获取 Buyer.txt 的行数
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

// 从Buyer.txt 中读取数据放入数组中
void Receipt::readBuyer(string buyerID[], string name[], string address[], string type[]) {
	ifstream infile("Buyer.txt", ios::in | ios::binary);
	if (!infile) {
		cerr << " open error" << endl;
		exit(1);
	}
	for (int i = 0; i < 5; i++) {
		infile >> buyerID[i] >> name[i] >> address[i] >> type[i]; // 只读取存放在数组中 但不对其进行相关操作
	}
	infile.close();
}

// 从Order.txt 中，读取数据，放入数组中
void Receipt::readOrder(string receiptId[], string buyerIDs[]) {
	ifstream infile("Order.txt", ios::in | ios::binary);
	if (!infile) {
		cerr << " open error" << endl;
		exit(1);
	}
	Order o;
	int n = o.getLine();
	for (int i = 0; i < n; i++) { // 只读取存放在数组中 但不对其进行相关操作
		infile >> receiptId[i] >> buyerIDs[i];
	}
	infile.close();
}

// 获取 Receipt.txt 的行数
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

// 从Receipt.txt 中读取数据放入 Receipt 对象数组中
void Receipt::readReceipt(Receipt receipt[]) {
	ifstream infile("Receipt.txt", ios::in | ios::binary);
	if (!infile) {
		cerr << " open error" << endl;
		exit(1);
	}
	int n = getReceiptLine();
	for (int i = 0; i < n; i++) { // 只读取存放在数组中 但不对其进行相关操作
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

// 判断 Receipt 中是否存在用户要求的订单编号，如果存在，返回行号数组类
returnLs Receipt::Judge(int receiptid) {
	Receipt receipt[G_MAX];
	returnLs ls;
	readReceipt(receipt); // 调用 Read() 函数，获取数据，以便等下进行相关数据的判断
	int j = 0;
	for (int i = 0; i < 10; i++) {
		int ri = receipt[i].receiptID;
		if (receiptid == ri) {
			ls.l[j] = i;
			j++;
		}
		//else {
		//cout << "没有此订单号，请输入正确订单号";
		//break;
		//}
	}
	return ls; // 如果存在，返回其下标数组的类
}


/********************************************************
添加订单

1.判断行数，新增的订单号为 行数+1
2.判断能否打开
3.获取买家ID，并将订单号和买家ID写入到Order.txt中
4.将订单编号和书籍编号及数量存入Receipt.txt中(0退出)
******************************************************/
void Receipt::addReceipt() {
	string buyerID;
	string bookID;
	int num = 0;
	// 从Receipt.txt 中读取数据放入 Receipt 对象数组中
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	int l = getReceiptLine(); // 获取行数
	receiptID = receipt[l - 1].receiptID; // 将订单号的初值赋为 Receipt.txt 中最后一行的 receiptID 的值
	receiptID++;
	ofstream outfile("Receipt.txt", ios::app);
	if (!outfile) {
		cerr << " open error" << endl;
		exit(1);
	}
	// 获取买家 ID
	cout << "请输入买家 ID：";
	cin >> buyerID;
	// 将买家 ID和订单编号写入 Order.txt 中
	Order order;
	order.addOrder(receiptID, buyerID);
	// 将订单编号和书籍编号及数量存入 Receipt.txt 中
	cout << "请输入购买书籍编号及数量，当书籍编号为 0时，停止录入 " << endl;
	while (bookID != "0") {
		int i = 0;
		cin >> bookID;
		// 当用户输入 0时跳出循环，停止录入
		if (bookID == "0")
			break;
		cin >> num;
		outfile << receiptID << "\t";
		outfile << bookID << "\t";
		outfile << num << endl;
	} // 关闭文件
	outfile.close();
	cout << "添加订单成功！ " << endl;
}

// 删除订单
void Receipt::deleteReceipt() {
	// 从Receipt.txt 中读取数据放入 Receipt 对象数组中
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	cout << "请输入你要删除的订单的订单编号 :";
	cin >> receiptID;
	// 删除 Order.txt 中用户输入订单号的那行数据
	Order o;
	o.deleteOrder(receiptID);
	// 获取用户所需订单号在 Receipt.txt 所在的行
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
			// 把下标不等于 ls[] 中的订单信息（即除了要删的订单信息外）其余的数据重新写入磁盘保存
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
		cout << "删除成功 !" << endl;
	}
	else
		cout << "该数据库没有此订单 !" << endl;
}

// 根据订单号查找订单
void Receipt::selectReceiptByRI() {
	// 读取 Receipt.txt 中的内容
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	// 读取 Book.txt 中的内容
	string bookID[G_MAX], bookName[G_MAX], author[G_MAX], publish[G_MAX], price[G_MAX];
	readBook(bookID, bookName, author, publish, price);
	// 读取 Buyer.txt 中的内容
	string buyerID[G_MAX], name[G_MAX], address[G_MAX], type[G_MAX];
	readBuyer(buyerID, name, address, type);
	// 读取 Order.txt 中的内容
	string receiptId[G_MAX], buyerIDs[G_MAX];
	readOrder(receiptId, buyerIDs);
	cout << "请输入所需查找订单的编号： ";
	int ri = 0;
	cin >> ri;
	double discount = 1;
	int x = 0;
	Order o;
	int n = o.getLine(); // 循环 Order.txt 中的内容，匹配查找订单号与循环内容中的订单号相同，从而获得对应订单的买家ID
	for (int i = 0; i < n; i++) {
		int rei = atoi(receiptId[i].c_str());
		if (ri == rei) {
			x++;
			cout << endl << " 订单编号： " << ri << endl;
			// 循环 Buyer.txt 中的内容， 匹配查找订单号的买家 ID与循环体中的买家 ID相同，输出买家信息
			int n1 = getBuyerLine();
			for (int k = 0; k < n1; k++) {
				if (buyerIDs[i] == buyerID[k]) {
					// 判断买家身份，获取折扣
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
		int n = getReceiptLine(); // 循环 Receipt.txt 中的内容，判断查找的订单号与循环的订单号是否相同，循环结束后输出该 订单的总金额
		for (int j = 0; j < n; j++) {
			// 相同时，获取它的书籍编号
			if (ri == receipt[j].receiptID) {
				int n2 = getBookLine(); // 循环书籍的内容，判断上面获取的书籍编号与循环的书籍编号是否相同
				for (int m = 0; m < n2; m++) {
					// 相同，输出书籍信息，计算总金额
					if (receipt[j].bookID == bookID[m]) {
						double pri = atof(price[m].c_str());
						Book b(bookID[m], bookName[m], author[m], publish[m], pri);
						b.display();
						cout << " 数量： " << receipt[j].num << endl << endl;
						pay = pay + pri * receipt[j].num;
					}
				}
			}
		}
		cout << "总金额： " << pay * discount << endl;
		cout << "***********************************************************" << endl;
	}
	if (x == 0) {
		cout << endl << "不存在该订单！ " << endl;
		cout << "***********************************************************" << endl;
	}
}

// 根据买家 ID查找订单
void Receipt::selectReceiptByBI() {
	// 读取 Receipt.txt 中的内容
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	// 读取 Book.txt 中的内容
	string bookID[G_MAX], bookName[G_MAX], author[G_MAX], publish[G_MAX], price[G_MAX];
	readBook(bookID, bookName, author, publish, price);
	// 读取 Buyer.txt 中的内容
	string buyerID[G_MAX], name[G_MAX], address[G_MAX], type[G_MAX];
	readBuyer(buyerID, name, address, type);
	// 读取 Order.txt 中的内容
	string receiptId[G_MAX], buyerIDs[G_MAX];
	readOrder(receiptId, buyerIDs);
	cout << "请输入所需查找订单的卖家 ID：";
	string bi = "";
	cin >> bi;
	double discount = 1;
	int x = 0;
	Order o;
	int n2 = o.getLine();
	int n = atoi(receiptId[n2 - 1].c_str());
	// 循环 Order 中的内容，判断用户输入的买家 ID是否与循环体中的内容是否相同
	for (int i = 0; i < n; i++) {
		// 相同时，输出订单号，卖家信息，书籍信息，总价
		if (bi == buyerIDs[i]) {
			x++; //1. 输出订单号
			cout << endl << " 订单号为： " << receiptId[i] << endl; //2. 输出买家信息

			// 循环 Buyer.txt ，判断在 Order.txt 中的买家 ID是否与用户输入的买家 ID相同
			int n2 = getBuyerLine();
			for (int k = 0; k < n2; k++) {
				// 如果相同输出买家信息
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
			//3. 输出书籍信息
			int n = getReceiptLine();
			// 循环 Receipt.txt, 判断循环体中的订单号与上述循环是否相同
			for (int j = 0; j < n; j++) {
				int reci = atoi(receiptId[i].c_str());
				if (receipt[j].receiptID == reci) {
					int n3 = getBookLine(); // 循环 Book.txt, 判断Receipt.txt 中的书籍编号与循环体中书籍编号是否相同
					for (int m = 0; m < n3; m++) {
						// 相同则输出书籍信息
						if (receipt[j].bookID == bookID[m]) {
							double pri = atof(price[m].c_str());
							Book b(bookID[m], bookName[m], author[m], publish[m], pri);
							b.display();
							cout << " 数量： " << receipt[j].num << endl << endl;
							pay = pay + pri * receipt[j].num;
						}
					}
				}
			}
			cout << " 总金额： " << pay * discount << endl;
			cout << "***********************************************************" << endl;
		}
	}
	if (x == 0) {
		cout << endl << "该买家没有订单！ " << endl;
		cout << "***********************************************************" << endl;
	}
}

// 显示所有订单
void Receipt::print() {
	// 读取 Receipt.txt 中的内容
	Receipt receipt[G_MAX];
	readReceipt(receipt);
	// 读取 Book.txt 中的内容
	string bookID[G_MAX], bookName[G_MAX], author[G_MAX], publish[G_MAX], price[G_MAX];
	readBook(bookID, bookName, author, publish, price);
	// 读取 Buyer.txt 中的内容
	string buyerID[G_MAX], name[G_MAX], address[G_MAX], type[G_MAX];
	readBuyer(buyerID, name, address, type);
	// 读取 Order.txt 中的内容
	string receiptId[G_MAX], buyerIDs[G_MAX];
	readOrder(receiptId, buyerIDs);
	double discount = 1;
	Order o;
	int n2 = o.getLine();
	int n = atoi(receiptId[n2 - 1].c_str());
	for (int z = 0; z < n; z++) {
		// 判断 Order.txt 中是否存在内容
		if (n2 <= 0) {
			cout << " 不存在任何订单！ " << endl;
			break;
		}
		else {
			// 循环 Order 中的内容，判断订单号是否存在
			for (int i = 0; i < n2; i++) {
				int rei = atoi(receiptId[i].c_str());
				// 如果存在，输出订单号，输出买家信息，输出书本，输出订单总价
				if (rei == z) {
					//1. 输出订单号 cout<<endl<< "订单号为： " <<rei<<endl;
					//2. 输出买家信息 // 循环 Buyer.txt ，判断在 Order.txt 中的买家 ID是否与循环体中的买家 ID相同
					int n2 = getBuyerLine();
					for (int k = 0; k < n2; k++) {
						// 如果相同输出买家信息
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
					//3. 输出书籍信息
					int n = getReceiptLine(); // 循环 Receipt.txt, 判断循环体中的订单号与上述是否相同
					for (int j = 0; j < n; j++) {
						if (receipt[j].receiptID == z) {
							int n3 = getBookLine();
							// 循环 Book.txt, 判断Receipt.txt 中的书籍编号与循环体中书籍编号是否相同
							for (int m = 0; m < n3; m++) {
								// 相同则输出书籍信息
								if (receipt[j].bookID == bookID[m]) {
									double pri = atof(price[m].c_str());
									Book b(bookID[m], bookName[m], author[m], publish[m],
										pri);
									b.display();
									cout << "数量： " << receipt[j].num << endl << endl;
									pay = pay + pri * receipt[j].num;
								}
							}
						}
					}
					cout << "总金额： " << pay * discount << endl;
					cout << "***********************************************************" << endl;
				}
			}
		}
	}
}