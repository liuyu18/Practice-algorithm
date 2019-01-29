#include <iostream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

template<size_t N>
class MyAttend {
public:
	MyAttend(int month, string strAttend) :m_month(month), b(strAttend) {

	}
	int GetMonth() {
		return m_month;
	}
	int GetAttendDays() {
		return b.count();
	}
private:
	int m_month;
	bitset<N> b; //出故障的位容器
};

class Device {
public:
	Device(string name) :m_name(name) {

	}
	void Add(MyAttend<31>& m) {
		v.push_back(m);
	}

	void Show() {
		cout << "设备名" << m_name << endl;
		cout << "月份\t故障上报天数" << endl;
		for (int i = 0;i < v.size();i++) {
			MyAttend<31>& m = v.at(i);
			int month = m.GetMonth();
			int days = m.GetAttendDays();
			cout << month << "\t" << days << endl;
		}
	}
private:
	string m_name;
	vector< MyAttend<31> > v;//故障记录集合
};

int main() {



    // printf("hello world\n");

	Device d1("加工中心");
	string s1 = "1111110001011101000101010101011";
	/*string s2 = "1000 1
		         11110 4
		         10100 2
		         01000 1
		         10101 3
		         0101"; 2*/

	MyAttend<31> m1(1, s1);
	//MyAttend<31> m2(2, s2);
	d1.Add(m1);
	// d1.Add(m2);
	d1.Show();
	cin.get();
	return 0;
}

