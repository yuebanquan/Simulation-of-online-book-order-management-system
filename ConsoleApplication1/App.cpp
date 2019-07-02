// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#include <iostream>
#include "Receipt.h"
using namespace std;

// 函数原型
void mainMenu();	// 主菜单
void addMenu();		// 添加订单操作完成后显示的菜单
void deleteMenu();	// 删除订单操作完成后显示的菜单
void selectMenu();	// 查找订单操作完成后显示的菜单
void printMenu();	// 显示所有订单信息操作完成后显示的菜单

int main() {
	mainMenu();
	return 0;
}

// 主菜单
void mainMenu() {
	Receipt re;
	cout << "****************网 上 购 书 的 结 账 系 统****************" << endl;
	cout << "*********************1. 订单信息录入**********************" << endl;
	cout << "*********************2. 订单信息删除**********************" << endl;
	cout << "*********************3. 根据订单编号查询订单信息************" << endl;
	cout << "*********************4. 根据买家编号查询订单信息***********" << endl;
	cout << "*********************5. 打印所有订单信息******************" << endl;
	cout << "*********************0. 退出******************************" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;
	cout << "请输入0-5中的任意数字选择功能：";
	int index = -1;
	cin >> index;
	
	switch (index) {
	case 0:
		break;
	case 1: {
		re.addReceipt();
		addMenu();
		//break;
	}
	case 2: {
		re.deleteReceipt();
		deleteMenu();
		//break;
	}
	case 3: {
		re.selectReceiptByRI();
		selectMenu();
		//break;
	}
	case 4: {
		re.selectReceiptByBI();
		selectMenu();
		//break;
	}
	case 5: {
		re.print();
		printMenu();
		//break;
	}
	}
}

// 添加订单操作完成后显示的菜单
void addMenu() {
	Receipt re;
	cout << "****************网 上 购 书 的 结 账 系 统****************" << endl;
	cout << "********************1. 订单信息再录入*********************" << endl;
	cout << "********************2. 返回上级目录***********************" << endl;
	cout << "********************0. 退出*******************************" << endl;
	cout << "**********************************************************" << endl;
	cout << "请输入 1-2中的任意数字 (0 退出 ):";
	
	int index = -1;
	cin >> index;
	cout << endl;
	cout << endl;

	switch (index) {
	case 0:
		break;
	case 1: {
		re.addReceipt();
		addMenu();
		//break;
	}
	case 2:
		mainMenu();
		//break;
	}
}

// 删除订单操作完成后显示的菜单
void deleteMenu() {
	Receipt re;
	cout << "****************网 上 购 书 的 结 账 系 统****************" << endl;
	cout << "********************1. 订单信息再删除*********************" << endl;
	cout << "********************2. 返回上级目录***********************" << endl;
	cout << "********************0. 退出*******************************" << endl;
	cout << "**********************************************************" << endl;
	cout << "请输入 0-2中的任意数字 (0 退出 ):";
	int index = -1;
	cin >> index;
	switch (index) {
	case 0:
		break;
	case 1: {
		re.deleteReceipt();
		deleteMenu();
		//break;
	}
	case 2:
		mainMenu();
		//break;
	}
}

// 根据订单号查找订单操作完成后显示的菜单
void selectMenu() {
	Receipt re;
	cout << "****************网 上 购 书 的 结 账 系 统****************" << endl;
	cout << "********************1. 根据订单号查询订单信息*************" << endl;
	cout << "********************2. 根据买家 ID查询订单信息************" << endl;
	cout << "********************3. 返回上级目录***********************" << endl;
	cout << "********************0. 退出*******************************" << endl;
	cout << "**********************************************************" << endl;
	cout << "请输入0-2中的任意数字 (0 退出 ):";
	
	int index = -1;
	cin >> index;
	cout << endl;
	cout << endl;
	
	switch (index) {
	case 0:
		break;
	case 1: {
		re.selectReceiptByRI();
		selectMenu();
		//break;
	}
	case 2: {
		re.selectReceiptByBI();
		selectMenu();
		//break;
	}
	case 3:
		mainMenu();
		//break;
	}
}

// 显示所有订单信息操作完成后显示的菜单
void printMenu() {
	Receipt re;
	cout << "****************网 上 购 书 的 结 账 系 统****************" << endl;
	cout << "********************1. 返回上级目录***********************" << endl;
	cout << "********************0. 退出*******************************" << endl;
	cout << "**********************************************************" << endl;
	cout << "请输入0-2中的任意数字 (0 退出 ):";
	
	int index = -1;
	cin >> index;
	
	switch (index) {
	case 0:
		break;
	case 1:
		mainMenu();
		//break;
	}
}