#include <iostream>
#include <string>
#include <set>
using namespace std;

class Student {
public:
	Student(string no, string name) :m_strNo(no), m_strName(name) {

	}
	bool operator<(const Student& s) const{
		int mark = m_strNo.compare(s.m_strNo);
		return mark < 0 ? true : false;
	}
	string GetNO()const {
		return m_strNo;
	}
	string GetName()const {
		return m_strName;
	}
private:
	string m_strNo;
	string m_strName;
};

ostream& operator << (ostream& os, const Student& s) {
	os << s.GetNO() << "\t" << s.GetName();
	return os;
}

template<class T,class Pred=less<T> ,class A=allocator <T> >
class MySet :public set<T, Pred, A> {
public:
	MySet(const T* first, const T* last) :set<T>(first, last) {

	}


	//并
	void add(MySet& second) {
		typename set<T>::iterator te;
		te = second.begin();
		while (te != second.end()) {
			set<T>::insert(*te);
			te++;
		}
	}

	void InterSect(MySet& second) {
		set<T> mid;
		typename set<T>::iterator te;
		te = set<T>::begin();
		while (te != set<T>::end()) {
			if (second.find(*te) != second.end()) {
				mid.insert(*te);
			}
			te++;
		}
		set<T>::swap(mid);

	}


	void Difference(MySet& second) {
		set<T> mid;
		typename set<T>::iterator te;
		te = set<T>::begin();
		while (te != set<T>::end()) {
			if (second.find(*te) == second.end()) {
				mid.insert(*te);
			}
			te++;
		}
		set<T>::swap(mid);
	}

	void Show() {
		typename set<T>::iterator te;
		te = set<T>::begin();
		while (te != set<T>::end()) {
			cout << *te << endl;
			te++;
		}
	}
};

int main() {
	Student s[2] = {
		{Student("1001","lilei")},
		{ Student("1002","HanMeiMei") }
	};
	Student t[3] = {
		{ Student("1001","lilei") },
		{ Student("1003","Lily") },
		{ Student("1004","Lucy")}
	};

	MySet<Student> m1(s, s + 2);
	MySet<Student> m2(t, t + 3);

	m1.Show();
	m2.Show();
	cout << "\n*********" << endl;
	//m1.add(m2);
	//m1.Difference(m2);
	m1.InterSect(m2);
	m1.Show();
	cin.get();
	return 0;
}