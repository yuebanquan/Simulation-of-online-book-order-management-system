#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class Order
{
public:
	Order();					// 无参构造函数
	Order(int re, string bu);	// 构造函数
	int getLine();				// 获取 Order.txt 中的行数 
	void readOrder(Order o[]);	// 从Order.txt 中读取数据放入 Receipt 对象数组中 
	int Judge(int receiptID);	// 判断 Order.txt 中是否存在该订单号，若存在返回该订单的行号，不存在返回 - 1 
	void addOrder(int receiptID, string buyerID); // 添加订单信息 
	void deleteOrder(int receiptID); // 删除订单信息
private:
	int _receiptID; // 订单编号 
	string _buyerID; // 购书人编号
};

Order::Order()
{
	_receiptID = 0;
	_buyerID = "";
}
// 构造函数
Order::Order(int re, string bu)
{
	_receiptID = re;
	_buyerID = bu;
}
// 获取 Order.txt 中的行数
int Order::getLine()
{
	ifstream in("Order.txt");
	string line;
	int n = 0;		//行数
	while (getline(in, line))
	{
		n++;
	}
	in.close();
	return n;
}
// 从Order.txt中读取数据放入Receipt对象数组中
void Order::readOrder(Order o[]) {
	ifstream infile("Order.txt", ios::in | ios::binary);
	if (!infile) {		//如果不存在，提示错误
		cerr << " 读取Order.txt错误 " << endl;
		exit(1);
	}
	int n = getLine();
	for (int i = 0; i < n; i++) {
		// 只读取存放在数组中，但不对其进行相关操作
		string re, bu;
		infile >> re >> bu;
		int re2 = atoi(re.c_str());//把字符串re.c_str()转化为整数存入re2
		o[i]._receiptID = re2;
		o[i]._buyerID = bu;
	}
	infile.close();
}
// 判断 Order.txt 中是否存在该订单号，若存在返回该订单的行号，不存在返回 -1
int Order::Judge(int receiptID) {
	Order order[50];
	readOrder(order); // 读取Order.txt存入对象数组roder中
	int n = getLine();
	for (int i = 0; i < n; i++) {
		if (receiptID == order[i]._receiptID) {
			return i; // 如果存在，返回其下标
			break;
		}
	} return -1; // 否则，返回 -1
}
// 添加订单
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
// 删除订单
void Order::deleteOrder(int receiptID)
{
	Order order[50];
	readOrder(order);
	int l = Judge(receiptID);	// 定义一个l来接收Judge()的返回值，用来判断该num是否存在
	if (l != -1) {	// 如果l不等于-1,表示要删除的订单信息存在
		int n = getLine();
		ofstream outfile("Order.txt");
		if (!outfile) {
			cerr << "读取Order.txt错误" << endl;
			exit(1);
		}
		for (int i = 0; i < n; i++) {
			// 把下标不等于l （即除了要删的订单信息外）其余的数据重新写入磁盘保存
			if (i != l) {
				outfile << order[i]._receiptID << "\t";
				outfile << order[i]._buyerID << endl;
			}
		}
		outfile.close();
	}
}
