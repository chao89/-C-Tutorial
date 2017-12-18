#include "student.h"
int main (void) {
	Student s1 ("张飞", 22), *s2 = new Student (
		"赵云", 20);
	s1.who ();
	s2->who ();
	delete s2;
	Student::where ();
	return 0;
}
