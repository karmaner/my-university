///*
//	��ϵ�У�
//		����ʱ��
//		2022/4/12
//		Mic_d;
//*/
//
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Clock {
//public :
//	void setHour(int h) { hour = h; }
//	void setMinute(int m) { minute = m; }
//	void setSecond(int s) { second = s; }
//	void dispTime() { cout << "NOW is :" << hour << ":" << minute << ":" << "seconed" << endl; }
//
//private:
//	int hour, minute, second;
//};
//
//int main() {
//
//	Clock* pa, * pb, aClock, bClock;
//	aClock.setMinute(2);
//	aClock.setHour(16);
//	aClock.setSecond(27);
//	bClock = aClock;
//	pa = new Clock;
//	pa->setHour(10);
//	pa->setMinute(23);
//	pa->setSecond(34);
//	pb = pa;
//	pa->dispTime();
//	pb->dispTime();
//	aClock.dispTime();
//	bClock.dispTime();
//
//}

///*
//	���У���Ա���������ݳ���ĳ�ʼ��
//	���ֳ�ʼ����ʽ
//*/
//
//#include <iostream>
//using namespace std;
//class Tdate {
//protected:
//	int month, day = 30, year;//1
//public :
//	Tdate(int m, int d, int y);
//};
//Tdate::Tdate(int m, int d, int y) : month(m) {		//2
//	year = y;	//3
//	cout << month << "/" << day << "/" << year << endl;
//}
//int main() {
//	Tdate bday2(10, 1, 2003);
//	return 0;
//}

///*
// *	���ں�����
// *	����������
//*/
////�����6��con~~123321  ������������˳��	����ȳ�
//#include <iostream>
//using namespace std;
//
//class A{
//private :
//	int i;
//public :
//	A(int x) {
//		i = x;
//		cout << "constructor: " << i << endl;
//	}
//	~A() {	cout << "constructor: " << i << endl; }
//};
//int main() {
//	
//	A a1(1);
//	A a2(2);
//	A a3(3);
//	return 0;
//}

///*
//	���ԣ�
//		ָ���������⣺ָ�뻥�ำֵʱ ����ֵָ��͸�ֵָ��ָ��ͬһ�ڴ�����ԭ���򱻷����޷����ʡ�
//		�ඨ������������ã�ָ�룬String���͵���ͬ��������������⡣
//		Ҫ������⣬��������������ء�
//
//		operatorXX   XX�����+ =��
//*/
//#include<iostream>
//#include<string>
//using namespace std;
//
//class String {
//private:
//	char* ptr;
//	int n;
//public:
//	String(char* s, int a) {
//		ptr = new char[strlen(s) + 1];
//		strcpy(ptr, s);
//		n = a;
//	}
//	~String() {
//		delete ptr;
//	}
//	String& operator=(const String& s);
//
//	void print() { cout << ptr << endl; }
//};
//
//String& String::operator=(const String& s) {
//	if (this == &s)
//		return *this;
//	delete ptr;
//	ptr = new char[strlen(s.ptr) + 1];
//	strcpy(ptr, s.ptr);
//	return *this;
//}
//
//int main() {
//	string const a = "hello";
//	String p1(a , 8);
//	{
//		String p2("chong qing", 10);
//		p2 = p1;
//		cout << "p2:";
//		p2.print();
//	}
//	cout << "p1:";
//	p1.print();
//}

#include <iostream>
#include <string>
using namespace std;

//����
class Book {
public:
	Book(char* name = "", double x = 0) :price(x) {
		newbkName(name);
		cout << "constructor..." << endl;
	}

	Book(const Book& bk) :price(bk.price) {
		newbkName(bk.bookName);
		cout << "constructoe..." << endl;
	}

	~Book() {
		delete bookName;
	}

	Book(Book&& bk) :bookName(bk.bookName) {
		price = bk.price;
		bk.bookName = nullptr;
		cout << "copy constructor..." << endl;
	}

	Book& setData(char* name, double p) {
		newbkName(name);
		price = p;
		return *this;
	}
	Book& operator=(Book& bk) {
		if (this == &bk)
			return *this;
		delete bookName;
		newbkName(bk.bookName);
		cout << "operator=" << endl;
		return *this;
	}

	Book& operator=(Book&& bk) {
		if (this == &bk)
			return *this;
		delete bookName;
		bookName = bk.bookName;
		bk.bookName = nullptr;
		cout << "move operator=(&&)" << endl;
		return *this;
	}
	char* getName() { return bookName; }
	double getPrice() { return price; }

private:
	void newbkName(char* name) {
		bookName = new char[strlen(name) + 1];
		strcpy(bookName, name);
	}
	char* bookName;
	double price;
};

Book getBook(Book a) {
	Book b = a;
	return a;
}
int main() {
	Book b, book;
	book.setData("���ݿ�ԭ��", 32.4);
	Book a = getBook(book);
	cout << a.getName() << "\t" << a.getPrice() << endl;
	Book c = std::move(c);
	b = std::move(c);
	a = b;
	return 0;
}