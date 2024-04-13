//p187
#include <iostream>
//#include <fstream>
#include "StudentList.h"  //<====
using namespace std;
int main()
{
	string filename = "data.txt";

	StudentList sl;//<======
	sl.ReadData(filename);//<=== 데이터 파일 읽어오기

	char select;
	do
	{
		cout << "----- 메 뉴 -----" << endl;
		cout << "1. 학생 성적 추가" << endl;
		cout << "2. 전체 성적 보기" << endl;
		cout << "3. 전체 성적 저장하기(텍스트)" << endl;
		cout << "4. 학생 성적 수정" << endl;
		cout << "5. 학생 성적 삭제" << endl;
		cout << "Q. 프로그램 종료" << endl;
		cout << "원하는 번호를 입력하세요:";
		cin >> select;
		switch (select)
		{
		case '1':
			//cout<<"학생 성적 추가" << endl;			
			if (!sl.AddStudent())//<========
			{
				cout << "학생 수를 초과하여 추가할 수 없습니다" << endl;
			}
			break;
		case '2':
			//cout<<"전체 성적 보기" << endl;
		//	sl.ShowAll(cout);
			sl.ShowAll(StudentList::CONSOLE); //<=====
			break;
		case '3': //파일로 저장
			//cout<<"전체 성적 보기" << endl;"
	/*		ofstream outfile("report.txt");
			sl.ShowAll(outfile );*/
			sl.ShowAll(StudentList::TEXTFILE); //<=====
			sl.ShowAll(StudentList::TEXTFILE, false); //<=====
			break;
		case '4':
			if (!sl.UpdateStudent())
				cout << "수정실패:해당 학생 성적이 없습니다" << endl;
			break;
		case '5':
			if (!sl.DeleteStudent())
				cout << "삭제실패:해당 학생 성적이 없습니다" << endl;
			break;
		case 'Q':
		case 'q':
			sl.SaveData(filename); //<====데이터 파일로 저장
			break;
		default:
			cout << "올바른 값을 선택하세요" << endl;
			break;

		}
	} while (select != 'q' && select != 'Q');
}