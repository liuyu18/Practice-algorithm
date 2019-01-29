#include "aglo.h"




template<class T,class _outPara>
class PrintInfo:public unary_function<T,_outPara>{
    public:
    PrintInfo():m_count(0),m_nSum(0){}
    T __get_sp_mut(){
        return m_nSum;
    }
    T GetMax(){
        return m_nMax;
    }
    T GetMin(){
        return m_nMin;
    }
    _outPara operator()(T x){
        if ( (m_count == 0)) {
            m_nMax = x;
            m_nMin = x;
        }else{
   			if (m_nMax < x)
				m_nMax = x;
			if (m_nMin > x)
				m_nMin = x;
        }
        m_nSum += x;
        m_count++;

    }
    private:
	T m_nSum;
	T m_nMax;
	T m_nMin;
	int m_count;
}

int main()
{

    float A[] = {1.0,2.1,3.2,4.3,5.4};
    const int N = sizeof(A)/sizeof(int);
    

    // aglo *test = new aglo();
    // test->showUseSTL();
    //system("pause");
    return 0;
}