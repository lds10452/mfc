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
	static CObject* PASCAL CreateObject();//动态创建机制与动态运行机制差别一，声明
};

//IMPLEMENT_DYNCREATE( CDog, CAnimal )
CObject* PASCAL CDog::CreateObject()//动态创建机制与动态运行机制差别二，实现
{
	return new CDog;
}
AFX_COMDAT const CRuntimeClass CDog::classCDog = {
		"CDog",
		sizeof(class CDog),
		0xFFFF,
		CDog::CreateObject,//动态创建机制与动态运行机制差别三，动态运行为null
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
	//动态运行机制测试,判断是否属于某个类
	CDog yellowdog;
	if (yellowdog.IsKindOf(RUNTIME_CLASS(CAnimal))) {
		cout << "yellowdog is CAnimal" << endl;
	}
	else {
		cout << "yellowdog isnot CAnimal" << endl;
	}

	//动态创建机制测试，不直接创建对象，内部间接new对象
	CObject* pob = RUNTIME_CLASS(CDog)->CreateObject();//对象加工厂
	if (pob) {
		cout << pob << endl;
	}
	else {
		cout << "对象创建失败" << endl;
	}
	return 0;
}