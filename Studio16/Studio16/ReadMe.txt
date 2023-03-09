1. Name: Ermu Lu

2. The process of declaring an "interface": Make a class with 
   pure virtual methods. Use the interface by creating another class 
   that overrides those virtual methods.A pure virtual method is 
   a class method that is defined as virtual and assigned to 0.

3. a. Interface inheritance.
   b. They should be private.

4. I write to the file and test "getSize" and "getName".
   The class behaved as expected.

5. int main()
{
	/*AbstractFile* t = new TextFile("t.txt");
	vector<char> x = { 'h', 'o' };
	t->write(x);
	cout << t->getSize();
	cout << t->getName();*/
	std::ifstream myfile("aaa.txt");
	return 0;
}
