#include <afxwin.h>
#include <iostream>
using namespace std;

class CMyDoc : public CDocument {
	//	DECLARE_SERIAL( CMyDoc )
	_DECLARE_DYNCREATE(CMyDoc) //动态创建机制的声明宏
		AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, CMyDoc*& pOb);//操作符重载函数
public:
	CMyDoc(int age = 0, float score = 0.0, CString name = "") :m_age(age), m_score(score), m_name(name) {}
	int m_age;
	float m_score;
	CString m_name;
	virtual void Serialize(CArchive& ar);
};
IMPLEMENT_SERIAL(CMyDoc, CDocument, 1)
/*
动态创建机制实现宏站出来的东西
CArchive& AFXAPI operator>>(CArchive& ar, CMyDoc* &pOb)
{
	pOb = (class_name*) ar.ReadObject(RUNTIME_CLASS(CMyDoc));
			return ar;
}
*/
void CMyDoc::Serialize(CArchive& ar) {
	if (ar.IsStoring()) {
		ar << this->m_age << this->m_score << this->m_name; //序列化基本类型变量  
	}
	else {
		ar >> m_age >> m_score >> m_name;//反序列化基本类型变量
	}
}
void Store() {//序列化（存储、写）数据
	CFile file;
	file.Open("serial.txt", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store, 4096);//归档类对象,维护缓冲区。
	CMyDoc data(18, 88.5, "zhangsan");
	ar << &data; //序列化对象，就是将对象的各个成员变量序列化。
	ar.Close();
	file.Close();
}
void Load() {//反序列化（加载/读）
	CFile file;
	file.Open("serial.txt", CFile::modeRead);
	CArchive ar(&file, CArchive::load, 4096);//维护一个buff，大小4096字节
	CMyDoc* pdata = NULL;
	ar >> pdata;
	ar.Close();
	file.Close();
	cout << pdata->m_age << ' ' << pdata->m_score << ' ' << pdata->m_name << endl;
}
int main() {
	Store();
	Load();
	return 0;
}