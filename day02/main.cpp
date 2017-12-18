int main (void) {
	char fun (short, int);
	void fun (float, double);
	fun (100, 200); // _Z3funsi (100, 200);
	fun (1.0, 2.0); // _Z3funfd (1.0, 2.0);
	return 0;
}
