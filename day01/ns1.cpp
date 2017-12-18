#include <iostream>
namespace icbc {
	int balance = 0;
	void save (int money) {
		balance += money;
	}
	void draw (int money) {
		if (balance >= money)
			balance -= money;
	}
	void query (void) {
		std::cout << "工行账户余额：" << balance
			<< std::endl;
	}
}
namespace abc {
	int balance = 0;
	void save (int money) {
		balance += money;
	}
	void draw (int money) {
		if (balance >= money)
			balance -= money;
	}
	void query (void) {
		std::cout << "农行账户余额：" << balance
			<< std::endl;
	}
}
int main (void) {
	using namespace icbc; // 名字空间指令
	query ();
	save (10000);
	query ();
	draw (2000);
	query ();
	using abc::query; // 名字空间声明
//	using icbc::query;
	query ();
	abc::save (100000);
	abc::query ();
	abc::draw (20000);
	abc::query ();
	return 0;
}
