# Simulation-of-online-book-order-management-system
模拟网上购书订单管理系统（大一小学期C++大作业）

## 一、任务

### 1. 基础任务

1. 建立继承了Buyer类的三个子类作为顾客的三种类型，用于管理顾客对象；
2. 建立Book类，管理书本对象；
3. 根据不同类型的顾客，计算出顾客需要支付的费用；



### 2. 拓展任务

1. 使用Git**管理**；
2. 推到GitHub上**开源**：https://github.com/yuebanquan/Simulation-of-online-book-order-management-system
3. **绘制**Shell界面
4. 可**选择**系统功能
5. 将不同功能的代码**分开**存放
6. 有一定的**异常处理**机制
7. 统一**命名规则**
8. 从TXT文件中**读取**顾客信息和书本信息
9. **添加**订单信息**写入**TXT文件中
10. 从TXT文件中**删除**订单信息
11. 根据订单编号顾客编号或从TXT文件中**查询**订单信息



## 二、系统环境

### 1. 软件环境

操作系统：Windows 10

IDE：Visual Studio 2019

编程语言：C++



## 2. 硬件环境

处理器：AMD Ryzen 5 2600X

显卡：RTX 2070

内存：DDR4 16GB

硬盘：1T



### 三、设计内容

### 1. 系统管理模块

![系统管理模块](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E7%B3%BB%E7%BB%9F%E7%AE%A1%E7%90%86%E6%A8%A1%E5%9D%97.jpg)



### 2. 数据存储模块

![数据存储模块](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E6%95%B0%E6%8D%AE%E5%AD%98%E5%82%A8%E6%A8%A1%E5%9D%97.jpg)



### 3. 程序模块流程图

![程序模块流程图](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E7%A8%8B%E5%BA%8F%E6%A8%A1%E5%9D%97%E6%B5%81%E7%A8%8B%E5%9B%BE.jpg)

 

## 四、代码

### App.cpp

### Book.h

### Buyer.h

### Order.h

### Receipt.h


## 五、运行截图

### 主菜单

![主菜单](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E4%B8%BB%E8%8F%9C%E5%8D%95.jpg)



### 订单信息录入

1. 菜单截图

![订单信息录入1](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E8%AE%A2%E5%8D%95%E4%BF%A1%E6%81%AF%E5%BD%95%E5%85%A51.jpg)

2. 文件变化

![订单信息录入2](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E8%AE%A2%E5%8D%95%E4%BF%A1%E6%81%AF%E5%BD%95%E5%85%A52.jpg)

![订单信息录入3](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E8%AE%A2%E5%8D%95%E4%BF%A1%E6%81%AF%E5%BD%95%E5%85%A53.jpg)



### 订单信息删除

1. 菜单截图

![订单信息删除1](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E8%AE%A2%E5%8D%95%E4%BF%A1%E6%81%AF%E5%88%A0%E9%99%A41.jpg)

2. 文件变化

![订单信息删除2](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E8%AE%A2%E5%8D%95%E4%BF%A1%E6%81%AF%E5%88%A0%E9%99%A42.jpg)

![订单信息删除3](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E8%AE%A2%E5%8D%95%E4%BF%A1%E6%81%AF%E5%88%A0%E9%99%A43.jpg)



### 根据订单编号查询订单信息

![根据订单编号查询订单信息](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E6%A0%B9%E6%8D%AE%E8%AE%A2%E5%8D%95%E7%BC%96%E5%8F%B7%E6%9F%A5%E8%AF%A2%E8%AE%A2%E5%8D%95%E4%BF%A1%E6%81%AF.jpg)



### 根据买家编号查询订单信息

![根据买家编号查询订单信息](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E6%A0%B9%E6%8D%AE%E4%B9%B0%E5%AE%B6%E7%BC%96%E5%8F%B7%E6%9F%A5%E8%AF%A2%E8%AE%A2%E5%8D%95%E4%BF%A1%E6%81%AF.jpg)



### 打印所有信息

![打印所有信息](https://yuebanquan.github.io/2019/07/09/%E5%A4%A7%E4%B8%80%E5%B0%8F%E5%AD%A6%E6%9C%9F%E2%80%94%E2%80%94%E6%A8%A1%E6%8B%9F%E7%BD%91%E4%B8%8A%E8%B4%AD%E4%B9%A6%E8%AE%A2%E5%8D%95%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F/%E6%89%93%E5%8D%B0%E6%89%80%E6%9C%89%E4%BF%A1%E6%81%AF.jpg)



## 六、心得体会

1. 独立开发了一个C++的小程序；
2. 掌握标识符命名规范；
3. 掌握C++面向对象的思想；
4. 掌握C++文件的读取与写入；
5. 使用Git工具
