#include <afx.h>
#include <iostream>

using namespace std;
void Find(CString path) {
	CString strPath = path;
	strPath += "/*.*";
	CFileFind find;//文件搜索类对象
	BOOL goFind = find.FindFile(strPath); //开启查找
	while (goFind) {
		goFind = find.FindNextFile();//找到当前文件，将文件信息保存find对象的成员变量中
		CString filename = find.GetFileName();
		CString filepath = find.GetFilePath();
		if (find.IsDirectory() && !find.IsDots()) {
			cout << "[" << filename << "]" << endl;
			Find(filepath);
		}
		else {
			cout << filename << endl;
		}
	}
	find.Close();
}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	Find(".");
	return 0;
}