#include <cstdio>
#include <cstring>

using namespace std;

class CMyString{
	public:
		CMyString(char* pData = NULL);
		CMyString(const CMyString& str);
		~CMyString(void);
		CMyString& operator=(const CMyString& str);
		void print(void);
	private:
		char* m_pData;
}; 

// 普通构造函数
CMyString::CMyString(char* pData){
	if(pData == NULL){
		m_pData = new char[1];
		*m_pData = '\0';
	}else{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

// 拷贝构造函数
CMyString::CMyString(const CMyString& str){
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

// 析构函数
CMyString::~CMyString(){
	delete [] m_pData;
}

// 赋值操作符
CMyString& CMyString::operator=(const CMyString& str){
	if(this == &str){
		return *this;
	}
	delete [] m_pData;
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

//// 高级程序员做法：考虑异常安全（以上做法中如果new异常，则当前对象的m_pData已释放内存）
//CMyString& CMyString::operator=(const CMyString& str){
//	if(this != &str){
//		CMyString strTemp(str);
//		char* tmp = strTemp.m_pData;
//		strTemp.m_pData = str.m_pData;
//		m_pData = tmp;
//	}
//	return *this;
//}

void CMyString::print(void){
	printf("%s\n", m_pData);
}

int main(){
	char a[] = "Hello,World";
	char b[] = "Hello,China";
	CMyString cStrA(a);
	cStrA.print();
	CMyString cStrB(cStrA);
	cStrB.print();
	CMyString cStrC(b);
	CMyString cStrD;
	cStrD = cStrC;
	cStrC.print();
	cStrD.print();
	
}


