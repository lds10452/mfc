#include <afxwin.h>
#include <iostream>
using namespace std;

void Store() {//序列化（存储、写）数据
	CFile file;
	file.Open("serial.txt", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store, 4096);//归档类对象,维护缓冲区。
	long age = 52;
	ar << age;//将18保存当前指向的位置，并向后移动当前指向，相应字节数。
	float score = 88.5;
	ar << score;//将88.5保存当前指向的位置，并向后移动当前指向，相应字节数。
	CString name = "zhangsan";
	ar << name;
	ar.Close();
	file.Close();
}

void Load() {//反序列化（加载/读）
	CFile file;
	file.Open("serial.txt", CFile::modeRead);
	CArchive ar(&file, CArchive::load, 4096);//维护一个buff，大小4096字节
	long age;
	ar >> age;//当反序列化第一个数据时候，内部将文件中所有数据读入ar维护的buff中
	float score;
	ar >> score;//当反序列化后续数据时候，不需要到硬盘文件中读取，直接到ar维护的buff中读取
	CString name;
	ar >> name;//当反序列化后续数据时候，不需要到硬盘文件中读取，直接到ar维护的buff中读取
	ar.Close();
	file.Close();
	cout << age << ' ' << score << ' ' << name << endl;
}

int main() {
	Store();
	Load();
	return 0;
}