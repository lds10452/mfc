#include <afxwin.h>
#include <iostream>
using namespace std;

void File() {
	CFile file;
	file.Open("file.txt", CFile::modeCreate | CFile::modeReadWrite);
	char str[] = "hello file";
	file.Write(str, strlen(str));
	file.SeekToBegin();//读之前先将指针移动到首部，不然读不出数据
	char buf[256] = { 0 };
	long nLen = file.Read(buf, 255);
	cout << buf << ' ' << nLen << endl;
	file.Close();
}

int main() {
	File();
	return 0;
}