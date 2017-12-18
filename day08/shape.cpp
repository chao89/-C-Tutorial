#include <iostream>
using namespace std;
// 形状
class Shape {
public:
	Shape (int x, int y) : m_x (x), m_y (y) {}
	/*
	virtual void draw (void) const {
		cout << "形状(" << m_x << ',' << m_y << ')'
			<< endl;
	}
	*/
	virtual void draw (void) const = 0; // 纯虚函数
//	virtual void foo (void) = 0;
protected:
	int m_x;
	int m_y;
};
// 矩形
class Rect : public Shape {
public:
	Rect (int x, int y, int w, int h) :
		Shape (x, y), m_w (w), m_h (h) {}
	void draw (void) const {
		cout << "矩形(" << m_x << ',' << m_y << ','
			<< m_w << ',' << m_h << ')' << endl;
	}
private:
	int m_w;
	int m_h;
};
// 圆形
class Circle : public Shape {
public:
	Circle (int x, int y, int r) : Shape (x, y),
		m_r (r) {}
	void draw (void) const {
		cout << "圆形(" << m_x << ',' << m_y << ','
			<< m_r << ')' << endl;
	}
private:
	int m_r;
};
void render (Shape* shapes[]) {
	for (size_t i = 0; shapes[i]; ++i)
		shapes[i]->draw (); // 多态调用
}
int main (void) {
	Shape* shapes[] = {
		new Rect (1, 2, 3, 4),
		new Rect (5, 6, 7, 8),
		new Circle (9, 10, 11),
		new Circle (12, 13, 14),
		new Rect (15, 16, 17, 18),
		NULL};
	render (shapes);
//	Shape shape (10, 20);
//	Shape* shape = new Shape (10, 200);
	return 0;
}
