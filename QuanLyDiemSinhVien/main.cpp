#include "MonHoc.h"
#include "Xuly.h"
#include "LopTinChi.h"
#include "SinhVien.h"
#include<iostream>
#include <typeinfo>
#include "DiemMonHocCuaLop.h"
#include <Windows.h>


using namespace std;
int main()
{

	COORD coord;
	coord.X = 1500;
	coord.Y = 400;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//fullscreen();
	system("color 5A");
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SetConsoleScreenBufferSize(handle, coord);
	PTR_LISTCREDITCLASS listCC = new LIST_CREDITCLASS;
	TREE_SUBJECT t;
	LIST_STUDENT l;

	InitTreeSubject(t);
	InitListStudent(l);

	LoadCreditClassFromFile(listCC);
	LoadSubjectFormFile(t);
	LoadStudentFromFile(l);

	MergeAll(listCC, t, l);

	SaveCreditClassToFile(listCC);
	SaveStudentToFile(l);
	SaveSubjectToFile(t);
	//	string a = "          ";
	//	trim(a);
	//	StandarString(a);
	//	cout << "1"+a+"1";
	return 0;
}


