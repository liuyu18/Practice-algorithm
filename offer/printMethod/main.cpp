#include <iostream>
// #include "printMatrix.h"
#include "Permutation.h"

using namespace std;

int main(){
// vector<vector<int> > datas(0, vector<int> (4));
// datas.resize(4);
//  datas[0].push_back(1);
//  datas[0].push_back(2);
//  datas[0].push_back(3);
//  datas[0].push_back(4);
//  datas[1].push_back(5);
//  datas[1].push_back(6);
//  datas[1].push_back(7);
//  datas[1].push_back(8);
//  datas[2].push_back(9);
//  datas[2].push_back(10);
//  datas[2].push_back(11);
//  datas[2].push_back(12);
//  datas[3].push_back(13);
//  datas[3].push_back(14);
//  datas[3].push_back(15);
//  datas[3].push_back(16);

// vector<vector<int> >::iterator IE;
// vector<int>::iterator it;
// for(IE=datas.begin();IE<datas.end();IE++){
// 	for (it=(*IE).begin();it<(*IE).end();it++){
// 			cout<<*it<<" ";
// 		}
// 		cout<<endl;
// 	}

//     printMatrix *obj = new printMatrix();
//     vector<int> result = obj->printMethod(datas);
// 	// vector<int>::iterator it;
// 	for (std::vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
// 	{
// 		/* code */
// 		cout<<"result :"<<*iter<<endl;
// 	}


	Permutation *obj = new Permutation();
	string stringData("ab");
	vector<string> result = obj->PermutationString(stringData);
	for (std::vector<string>::iterator iter = result.begin(); iter != result.end(); iter++){
		cout<<"result :"<<*iter<<endl;
	}
}