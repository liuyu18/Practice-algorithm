#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//构建一个同义词基础类:one: single unique
class CWord {
public:
	CWord(string strLine) {
		istringstream in(strLine);
		in >> m_mainword;//假定第一个单词是关键词
		string mid = "";
		//剩下的其余单词，都认为是同义词
		while (!in.eof()) {
			in >> mid;
			m_vecword.push_back(mid);
		}
	}
	string GetMainWord() {
		return m_mainword;
	}

	void Show() {
		cout << "单词是：" << m_mainword << endl;
		cout << "同义词是：" << "\t";
		for (int i = 0;i < m_vecword.size();i++) {
			cout << m_vecword[i] << "\t";
		}
		cout << endl;
	}
private:
	string m_mainword;//一个单词
	vector<string> m_vecword;//多个同义词
};

class CWordMgr {
public:
	bool Add(string strLine) {
		CWord word(strLine);
		pair<string, CWord> p(word.GetMainWord(), word);
		m_myMap.insert(p);
		return true;
	}

	void Show(string strFind) {//显示待查的同意词
		multimap<string, CWord>::iterator itFind = m_myMap.find(strFind);
		if (itFind != m_myMap.end()) {
			CWord& obj = (*itFind).second;
			obj.Show();
		}
		else {
			cout << strFind << "不在字典中" << endl;
		}
	}

	void Show() {//显示字典中所有同义词的信息
		multimap<string, CWord>::iterator te = m_myMap.begin();
		while (te != m_myMap.end()) {
			CWord& obj = (*te).second;
			obj.Show();
			te++;
		}
	}
private:
	multimap<string, CWord> m_myMap;
};

int main(void) {

	string s[] = {
		string("one single unique"),string("correct true right"),
		string("near close"),string("happy pleased"),string("strong pwoerful")
	};
	CWordMgr mgr;
	for (int i = 0;i < 5;i++) {
		mgr.Add(s[i]);
	}

	mgr.Show();
	cout << "************" << endl;
	mgr.Show("happy");
	cout << "************" << endl;
	mgr.Show("China");
	cin.get();
	return 0;
}
