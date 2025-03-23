#include <afx.h>
#include <iostream>

using namespace std;
void Find(CString path) {
	CString strPath = path;
	strPath += "/*.*";
	CFileFind find;//�ļ����������
	BOOL goFind = find.FindFile(strPath); //��������
	while (goFind) {
		goFind = find.FindNextFile();//�ҵ���ǰ�ļ������ļ���Ϣ����find����ĳ�Ա������
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