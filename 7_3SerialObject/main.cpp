#include <afxwin.h>
#include <iostream>
using namespace std;

class CMyDoc : public CDocument {
	//	DECLARE_SERIAL( CMyDoc )
	_DECLARE_DYNCREATE(CMyDoc) //��̬�������Ƶ�������
		AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, CMyDoc*& pOb);//���������غ���
public:
	CMyDoc(int age = 0, float score = 0.0, CString name = "") :m_age(age), m_score(score), m_name(name) {}
	int m_age;
	float m_score;
	CString m_name;
	virtual void Serialize(CArchive& ar);
};
IMPLEMENT_SERIAL(CMyDoc, CDocument, 1)
/*
��̬��������ʵ�ֺ�վ�����Ķ���
CArchive& AFXAPI operator>>(CArchive& ar, CMyDoc* &pOb)
{
	pOb = (class_name*) ar.ReadObject(RUNTIME_CLASS(CMyDoc));
			return ar;
}
*/
void CMyDoc::Serialize(CArchive& ar) {
	if (ar.IsStoring()) {
		ar << this->m_age << this->m_score << this->m_name; //���л��������ͱ���  
	}
	else {
		ar >> m_age >> m_score >> m_name;//�����л��������ͱ���
	}
}
void Store() {//���л����洢��д������
	CFile file;
	file.Open("serial.txt", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store, 4096);//�鵵�����,ά����������
	CMyDoc data(18, 88.5, "zhangsan");
	ar << &data; //���л����󣬾��ǽ�����ĸ�����Ա�������л���
	ar.Close();
	file.Close();
}
void Load() {//�����л�������/����
	CFile file;
	file.Open("serial.txt", CFile::modeRead);
	CArchive ar(&file, CArchive::load, 4096);//ά��һ��buff����С4096�ֽ�
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