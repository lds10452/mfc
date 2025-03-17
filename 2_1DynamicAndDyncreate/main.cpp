#include <afxwin.h>
#include <iostream>
using namespace std;

class CAnimal : public CObject {
	DECLARE_DYNAMIC(CAnimal)
};
IMPLEMENT_DYNAMIC(CAnimal, CObject)

class CDog : public CAnimal {
//	DECLARE_DYNCREATE( CDog )
public:
	static const CRuntimeClass classCDog;
	virtual CRuntimeClass* GetRuntimeClass() const;
	static CObject* PASCAL CreateObject();//��̬���������붯̬���л��Ʋ��һ������
};

//IMPLEMENT_DYNCREATE( CDog, CAnimal )
CObject* PASCAL CDog::CreateObject()//��̬���������붯̬���л��Ʋ�����ʵ��
{
	return new CDog;
}
AFX_COMDAT const CRuntimeClass CDog::classCDog = {
		"CDog",
		sizeof(class CDog),
		0xFFFF,
		CDog::CreateObject,//��̬���������붯̬���л��Ʋ��������̬����Ϊnull
		RUNTIME_CLASS(CAnimal),
		NULL,
		NULL
};
CRuntimeClass* CDog::GetRuntimeClass() const
{
//	return RUNTIME_CLASS(CDog);
	return ((CRuntimeClass*)(&CDog::classCDog));
}

int main() {
	//��̬���л��Ʋ���,�ж��Ƿ�����ĳ����
	CDog yellowdog;
	if (yellowdog.IsKindOf(RUNTIME_CLASS(CAnimal))) {
		cout << "yellowdog is CAnimal" << endl;
	}
	else {
		cout << "yellowdog isnot CAnimal" << endl;
	}

	//��̬�������Ʋ��ԣ���ֱ�Ӵ��������ڲ����new����
	CObject* pob = RUNTIME_CLASS(CDog)->CreateObject();//����ӹ���
	if (pob) {
		cout << pob << endl;
	}
	else {
		cout << "���󴴽�ʧ��" << endl;
	}
	return 0;
}