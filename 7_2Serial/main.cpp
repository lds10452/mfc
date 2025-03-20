#include <afxwin.h>
#include <iostream>
using namespace std;

void Store() {//���л����洢��д������
	CFile file;
	file.Open("serial.txt", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store, 4096);//�鵵�����,ά����������
	long age = 52;
	ar << age;//��18���浱ǰָ���λ�ã�������ƶ���ǰָ����Ӧ�ֽ�����
	float score = 88.5;
	ar << score;//��88.5���浱ǰָ���λ�ã�������ƶ���ǰָ����Ӧ�ֽ�����
	CString name = "zhangsan";
	ar << name;
	ar.Close();
	file.Close();
}

void Load() {//�����л�������/����
	CFile file;
	file.Open("serial.txt", CFile::modeRead);
	CArchive ar(&file, CArchive::load, 4096);//ά��һ��buff����С4096�ֽ�
	long age;
	ar >> age;//�������л���һ������ʱ���ڲ����ļ����������ݶ���arά����buff��
	float score;
	ar >> score;//�������л���������ʱ�򣬲���Ҫ��Ӳ���ļ��ж�ȡ��ֱ�ӵ�arά����buff�ж�ȡ
	CString name;
	ar >> name;//�������л���������ʱ�򣬲���Ҫ��Ӳ���ļ��ж�ȡ��ֱ�ӵ�arά����buff�ж�ȡ
	ar.Close();
	file.Close();
	cout << age << ' ' << score << ' ' << name << endl;
}

int main() {
	Store();
	Load();
	return 0;
}