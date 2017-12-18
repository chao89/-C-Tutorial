#include <iostream>
using namespace std;
// 电话
class Phone {
public:
	Phone (string const& no) : m_no (no) {}
	void call (string const& target) const {
		cout << m_no << "致电" << target << "。"
			<< endl;
	}
private:
	string m_no;
};
// 播放器
class Player {
public:
	Player (string const& media) : m_media (media){}
	void play (string const& clip) const {
		cout << m_media << "播放器播放" << clip
			<< "。" << endl;
	}
private:
	string m_media;
};
// 计算机
class Computer {
public:
	Computer (string const& os) : m_os (os) {}
	void run (string const& app) const {
		cout << "在" << m_os << "上运行" << app
			<< "。" << endl;
	}
private:
	string m_os;
};
// 智能手机
class SmartPhone : public Phone, public Player,
	public Computer {
public:
	SmartPhone (string const& no,
		string const& media, string const& os) :
		Phone (no), Player (media), Computer (os) {}
};
int main (void) {
	SmartPhone sp ("13910110072", "MP4", "Android");
	sp.call ("01062332018");
	sp.play ("小苹果");
	sp.run ("淘宝");
	return 0;
}
