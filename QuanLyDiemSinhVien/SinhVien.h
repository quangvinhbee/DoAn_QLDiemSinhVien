#define _STUDENT_H
#define MAXSINHVIEN 5000
//#define STUDENT_NULL null
#pragma warning(disable : 4996)
#include"LopTinChi.h"

struct student {
	char idStudent[13];
	char idClass[16];
	char fistName[21], lastName[11];

	int sex = 1; // 1 male, 2 female
	char phoneNUmber[13];
	int yearAdmission; // nam nhap hoc
	float mediumScore = 0;
};
typedef struct student STUDENT;

struct ListStudent {
	int n = 0;
	STUDENT ListST[MAXSINHVIEN];
};
typedef struct ListStudent LIST_STUDENT;



void InitListStudent(LIST_STUDENT& l)
{
}

void AddHeadListStudent(LIST_STUDENT& l, STUDENT data)
{
	if (l.n == MAXSINHVIEN) {
		return;
	}
	for (int i = l.n; i > 0; i--) {
		l.ListST[i] = l.ListST[i - 1];
	}
	l.ListST[0] = data;
}

bool ListStudentIsEmty(LIST_STUDENT l)
{
	return l.n = 0;
}

void AddTailListStudent(LIST_STUDENT& l, STUDENT data)
{
	l.ListST[l.n] = data;

	++l.n;
}

bool FindStudent(LIST_STUDENT l, char* id)
{
	for (int i = 0; i < l.n; i++) {
		if (strcmp(l.ListST[i].idStudent, id) == 0) {
			return true;
		}
	}
	return false;
}


STUDENT FindStudentByOrdinal(LIST_STUDENT l, int ordinal)
{
	return l.ListST[ordinal];
}


//void InsertAfter(STUDENT p, STUDENT& data)
//{
//	if (p == NULL) return;
//	STUDENT q = new STUDENT;
//
//	q->_student = data;
//	q->pNext = p->pNext;
//	p->pNext = q;
//}

void InsertOrderForListStudent(LIST_STUDENT& l, STUDENT data)
{
	l.ListST[l.n] = data;
	l.n++;
}

bool IsDeletedHead(LIST_STUDENT& l)
{
	/*if (ListStudentIsEmty(l)) return false;
	STUDENT p = l.pHead;

	l.pHead = p->pNext;
	delete p;
	--l.n;
	return true;*/
}

bool IsDeletedTail(LIST_STUDENT& l)
{
	/*if (ListStudentIsEmty(l)) return false;

	STUDENT beforeP = NULL;
	for (STUDENT p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p == l.pTail)
		{
			l.pTail = beforeP;
			beforeP->pNext = NULL;
			delete p;

			--l.n;
			return true;
		}
		beforeP = p;
	}*/
}

bool IsDeletedAfter(LIST_STUDENT& l, STUDENT p)
{
	/*if (p == NULL || p->pNext == NULL) return false;
	STUDENT nodeDeleted = p->pNext;
	p->pNext = nodeDeleted->pNext;
	delete nodeDeleted;
	--l.n;
	return true;*/
}

bool IsDeletedStudentWithId(LIST_STUDENT& l, STUDENT data)
{
	//STUDENT nodeDeleted = BinarySearchStudent(l, data.idStudent);   //FindStudent(l, data.idStudent);
	//if (nodeDeleted == NULL) return false;
	//if (nodeDeleted == l.pHead) return IsDeletedHead(l);
	//if (nodeDeleted == l.pTail) return IsDeletedTail(l);
	//else
	//{
	//	STUDENT temp = l.pHead;
	//	while (temp->pNext != nodeDeleted)
	//		temp = temp->pNext;
	//	return IsDeletedAfter(l, temp);
	//}
}

// xoa danh sach Sinh vien
bool ClearListStudent(LIST_STUDENT& l)
{
	l.n = 0;
	return true;
}

void OutputStudent(STUDENT st, int locate)
{
	DeleteOldData(sizeof(keyDisplayStudent) / sizeof(string), locate);
	Gotoxy(xKeyDisplay[0] + 1, Y_DISPLAY + 3 + locate); cout << st.idStudent;

	Gotoxy(xKeyDisplay[1] + 1, Y_DISPLAY + 3 + locate); cout << st.fistName;
	Gotoxy(xKeyDisplay[2] + 1, Y_DISPLAY + 3 + locate); cout << st.lastName;
	Gotoxy(xKeyDisplay[3] + 1, Y_DISPLAY + 3 + locate);
	if (st.sex == 1)cout << "Nam";
	else cout << "Nu";
	Gotoxy(xKeyDisplay[4] + 1, Y_DISPLAY + 3 + locate); cout << st.phoneNUmber;
	Gotoxy(xKeyDisplay[5] + 1, Y_DISPLAY + 3 + locate); cout << st.yearAdmission;
}

void OutputListStudentWithIdClassPerPage(LIST_STUDENT l, int indexBegin)
{
	/*if (l.pHead == NULL && l.pTail == NULL) return;
	int count = -1;
	for (STUDENT q = l.pHead; q != NULL; q = q->pNext)
	{
		count++;
		if (count == indexBegin)
		{
			int i = -1;
			while (q != NULL && i < QUANTITY_PER_PAGE - 1)
			{
				OutputStudent(q->_student, (++i) * 2);
				q = q->pNext;
			}
			break;
		}
	}*/

	for (int i = indexBegin; i < indexBegin + QUANTITY_PER_PAGE - 1; i++) {
		OutputStudent(l.ListST[i], i * 2);
	}

	Gotoxy(X_PAGE, Y_PAGE);
	cout << "Trang " << pageNowStudent << "/" << totalPageStudent;
}

bool DataStudentIsEmty(STUDENT st)
{
	if (strlen(st.idClass) == 0)return true;
	if (strlen(st.idStudent) == 0) return true;
	return false;
}

void InputStudent(LIST_STUDENT& l, STUDENT& st, bool isEdited = false)
{
	ShowCur(true);
	int ordinal = 0;
	bool isMoveUp = false;
	bool isSave = false;
	bool idIsExist = false;

	string idStudent, firstName, lastName, phoneNumber;
	int yearAdmission = 0, sex = 0;

	if (isEdited)
	{
		idStudent = st.idStudent;
		firstName = st.fistName;
		lastName = st.lastName;
		phoneNumber = st.phoneNUmber;
		yearAdmission = st.yearAdmission;
		sex = st.sex;


		Gotoxy(X_ADD + 20 + 7, 0 * 3 + Y_ADD);
		cout << idStudent;
		Gotoxy(X_ADD + 17 + 7, 1 * 3 + Y_ADD);
		cout << firstName;
		Gotoxy(X_ADD + 18 + 7, 2 * 3 + Y_ADD);
		cout << lastName;
		Gotoxy(X_ADD + 19 + 7, 3 * 3 + Y_ADD);
		cout << sex;
		Gotoxy(X_ADD + 20 + 7, 4 * 3 + Y_ADD);
		cout << phoneNumber;
		Gotoxy(X_ADD + 21 + 7, 5 * 3 + Y_ADD);
		cout << yearAdmission;
	}

	while (true)
	{
		switch (ordinal)
		{
		case 0:
			if (isEdited) break;
			CheckMoveAndValidateID(idStudent, isMoveUp, ordinal, isSave, 20 + 7, 12);
			if (FindStudent(l, (char*)idStudent.c_str()) == false)
			{
				idIsExist = false;
				break;
			}
			idIsExist = true;

			break;
		case 1:
			CheckMoveAndValidateNameSubject(firstName, isMoveUp, ordinal, isSave, 17 + 7, 20);
			break;
		case 2:
			CheckMoveAndValidateNameSubject(lastName, isMoveUp, ordinal, isSave, 18 + 7, 10);
			break;
		case 3:
			CheckMoveAndValidateNumber(sex, isMoveUp, ordinal, isSave, 19 + 7, 2);
			break;
		case 4:
			CheckMoveAndValidateID(phoneNumber, isMoveUp, ordinal, isSave, 20 + 7, 11);
			break;
		case 5:
			CheckMoveAndValidateNumber(yearAdmission, isMoveUp, ordinal, isSave, 21 + 7, 2019);
			break;
		}

		if (isMoveUp)
		{
			if (ordinal == 0)
				isMoveUp = false;
			ordinal--;
		}
		else
		{
			if (ordinal == 5)
				isMoveUp = true;
			ordinal++;
		}
		if (isSave)
		{
			Gotoxy(X_NOTIFY, Y_NOTIFY);
			cout << setw(50) << setfill(' ') << " ";
			trim(firstName);
			trim(lastName);
			StandarString(firstName);
			StandarString(lastName);

			if (sex == 0 || firstName.empty() || lastName.empty() || yearAdmission == 0 || phoneNumber.empty())
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY);
				cout << "Cac truong du lieu khong dc de trong";
			}
			else if (idIsExist)
			{
				Gotoxy(X_NOTIFY, Y_NOTIFY);
				cout << "Ma sinh vien khong duoc trung";
			}
			else
			{


				strcpy(st.idStudent, idStudent.c_str());
				strcpy(st.fistName, firstName.c_str());
				strcpy(st.lastName, lastName.c_str());
				strcpy(st.phoneNUmber, phoneNumber.c_str());
				st.sex = sex;

				st.yearAdmission = yearAdmission;
				StandardName(st.lastName);
				StandardName(st.fistName);

				if (isEdited)
				{
					STUDENT p;
					for (int k = 0; k < l.n; k++) {
						if (st.idStudent == l.ListST[k].idStudent) {
							p = st;
							break;
						}
					}
				}
				else
				{
					InsertOrderForListStudent(l, st);
				}
				totalPageStudent = ((l.n - 1) / QUANTITY_PER_PAGE) + 1;
				DeleteMenuAdd();
				return;
			}
			isSave = false;
		}
		else
		{
			isSave = false;
		}
	}
	ShowCur(false);
}

void SetDefaultChooseStudent(STUDENT st, int ordinal)
{
	SetBGColor(GREEN);
	OutputStudent(st, (ordinal % QUANTITY_PER_PAGE) * 2);
	SetBGColor(PURPLE);
}

void EffectiveMenuStudent(int ordinal, STUDENT stnew, STUDENT stold)
{
	int current = ordinal;
	SetDefaultChooseStudent(stnew, current);
	OutputStudent(stold, (currposPrecStudent % QUANTITY_PER_PAGE) * 2);
	currposPrecStudent = current;
}

void ChangePageChooseStudent(LIST_STUDENT l)
{
	clrscr();
	Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
	currposStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
	currposPrecStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
}

STUDENT ChooseStudent(LIST_STUDENT l)
{
	int keyboard_read = 0;
	ShowCur(false);
	pageNowStudent = 1;
	currposStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
	currposPrecStudent = (pageNowStudent - 1) * QUANTITY_PER_PAGE;
	totalPageStudent = ((l.n - 1) / QUANTITY_PER_PAGE) + 1;

	STUDENT newNodeStudent = l.ListST[currposStudent];
	STUDENT oldNodeStudent;

	OutputListStudentWithIdClassPerPage(l, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
	SetDefaultChooseStudent(newNodeStudent, currposStudent);

	while (true)
	{
		keyboard_read = _getch();
		if (keyboard_read == 0)
			keyboard_read = _getch();
		switch (keyboard_read)
		{
		case KEY_UP:
			if (currposStudent % QUANTITY_PER_PAGE > 0)
			{
				currposStudent = currposStudent - 1;
				oldNodeStudent = newNodeStudent;
				//for (newNodeStudent = l.pHead; newNodeStudent->pNext != oldNodeStudent; newNodeStudent = newNodeStudent->pNext);
				EffectiveMenuStudent(currposStudent, newNodeStudent, oldNodeStudent);
			}
			break;
		case KEY_DOWN:
			if (currposStudent % QUANTITY_PER_PAGE < QUANTITY_PER_PAGE - 1 && newNodeStudent.sex != NULL)
			{
				currposStudent = currposStudent + 1;
				oldNodeStudent = newNodeStudent;
				newNodeStudent = newNodeStudent;
				EffectiveMenuStudent(currposStudent, newNodeStudent, oldNodeStudent);
			}
			break;
		case PAGE_DOWN:
			if (pageNowStudent < totalPageStudent)
			{
				pageNowStudent++;
				ChangePageChooseStudent(l);
				OutputListStudentWithIdClassPerPage(l, (pageNowStudent - 1) * QUANTITY_PER_PAGE);

				newNodeStudent = FindStudentByOrdinal(l, currposStudent);
				SetDefaultChooseStudent(newNodeStudent, currposStudent);
			}
			break;
		case PAGE_UP:
			if (pageNowStudent > 1)
			{
				pageNowStudent--;
				ChangePageChooseStudent(l);
				OutputListStudentWithIdClassPerPage(l, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
				newNodeStudent = FindStudentByOrdinal(l, currposStudent);
				SetDefaultChooseStudent(newNodeStudent, currposStudent);
			}
			break;
		case ENTER:  //enter
			ShowCur(true);
			return newNodeStudent;
			break;
		case 27:
			return;
			break;
		}
	}
}

void ChangePageManageStudent(LIST_STUDENT l, string idClass)
{
	Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY SINH VIEN LOP: " + idClass;
	OutputListStudentWithIdClassPerPage(l, (pageNowStudent - 1) * QUANTITY_PER_PAGE);
	Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
}

void MenuManagerStudent(LIST_STUDENT& l)
{
backMenu:
	clrscr();
	int key;
	string idClass;
	Gotoxy(X_TITLE, Y_TITLE);
	cout << "NHAP VAO MA LOP CAN QUAN LY: ";

	DisplayEdit(keyDisplayEditClass, sizeof(keyDisplayEditClass) / sizeof(string), 35);
	CheckMoveAndValdateIdClass(idClass, 28);
	Gotoxy(X_NOTIFY - 10, Y_NOTIFY);
	cout << "BAN CO MUON SUA LAI MA LOP";
	Gotoxy(X_NOTIFY - 10, Y_NOTIFY + 1);
	cout << "ENTER: TIEO TUC - ESC: THOAT - AN PHIM BAT KI DE NHAP LAI";

	key = _getch();
	if (key == ESC)
		return;
	else if (key == ENTER)
	{
		clrscr();
		LIST_STUDENT temp;
		InitListStudent(temp);
		int n = 0;
		/*for (STUDENT p = l.pHead; p != NULL; p = p->pNext)
		{
			if (strcmp(p->_student.idClass, (char*)idClass.c_str()) == 0)
			{
				AddTailListStudent(temp, p->_student);
				n++;
			}
		}*/

		for (int i = 0; i < l.n; i++) {
			if (strcmp(l.ListST[i].idClass, (char*)idClass.c_str()) == 0)
			{
				AddTailListStudent(temp, l.ListST[i]);
				n++;
			}
		}
		pageNowStudent = 1;
		totalPageStudent = ((n - 1) / QUANTITY_PER_PAGE) + 1;
		OutputListStudentWithIdClassPerPage(temp, 0);

		Display(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string));
		Gotoxy(X_TITLE, Y_TITLE); cout << "QUAN LY SINH VIEN LOP: " + idClass;

		while (true)
		{
			while (_kbhit())
			{
				key = _getch();
				if (key == 0 || key == 224)
				{
					key = _getch();
					if (key == KEY_F2)
					{
						STUDENT st;
						strcpy(st.idClass, idClass.c_str());
						DisplayEdit(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string), 35);
						InputStudent(l, st, false);
						if (strlen(st.idStudent) == 0) return;

						//InsertOrderForListStudent(l, st);
						InsertOrderForListStudent(temp, st);

						n++;
						totalPageStudent = ((n - 1) / QUANTITY_PER_PAGE) + 1;
						clrscr();
						ChangePageManageStudent(temp, idClass);
						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << "Them thanh cong";
					}
					else if (key == KEY_F3)
					{
						STUDENT k = ChooseStudent(temp);
						if (k.sex == NULL) goto backMenu;

						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << "Ban co chac chan xoa? Enter dong y";
						key = _getch();
						if (key == ENTER)
						{
							string temps = k.idStudent;
							STUDENT p;
							for (int i = 0; i < l.n; i++) {
								if (l.ListST[i].idStudent == temps) {
									p = l.ListST[i];
								}
							}
							IsDeletedStudentWithId(l, p);
							if (IsDeletedStudentWithId(temp, k))
							{
								n--;
								totalPageStudent = ((n - 1) / QUANTITY_PER_PAGE) + 1;
								if (n % QUANTITY_PER_PAGE == 0) pageNowStudent--;
								clrscr();
								ChangePageManageStudent(temp, idClass);
								Gotoxy(X_NOTIFY, Y_NOTIFY);
								cout << "Xoa thanh cong";
							}
						}
						else goto backMenu;
					}
					else if (key == KEY_F4)
					{
						STUDENT k = ChooseStudent(temp);
						if (k.sex == NULL) goto backMenu;

						DisplayEdit(keyDisplayStudent, sizeof(keyDisplayStudent) / sizeof(string), 35);
						InputStudent(l, k, true);

						STUDENT p;
						//p = BinarySearchStudent(l, k.idStudent);
						p = k;

						clrscr();
						ChangePageManageStudent(temp, idClass);
						Gotoxy(X_NOTIFY, Y_NOTIFY);
						cout << "Sua thanh cong";
					}
					else if (key == PAGE_DOWN && pageNowStudent < totalPageStudent)
					{
						pageNowStudent++;
						clrscr();
						ChangePageManageStudent(temp, idClass);
					}
					else if (key == PAGE_UP && pageNowStudent > 1)
					{
						pageNowStudent--;
						clrscr();
						ChangePageManageStudent(temp, idClass);
					}
				}
				else if (key == ESC)
				{
					ClearListStudent(temp);
					return;
				}
			}
		}
	}
	else
		goto backMenu;
}
