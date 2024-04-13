//명품 C++ 프로그램 12장 13번 실습문제
//단어가 들어있는 words.txt 파일을 읽어 단어별로 vector<string>에 저장하고
//사용자가 입력한 문자열로 시작되는 모든 단어를 출력하는 프로그램
//"exit"을 입력하면 프로그램을 종료한다.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Words 
{
	ifstream fin;
	vector<string> wordVector;
public:
	Words();
	~Words();
	void Search(string word);

};

Words::Words()
{
	fin.open("words.txt");
	if (!fin)
	{
		cerr << "words.txt" << " 열기 실패" << endl;
		exit(0); // 프로그램 종료
	}

	// words.txt 파일을 읽어 wordVector에 저장
	string word;
	while (!fin.eof())
	{
		fin >> word;
		wordVector.push_back(word);
	}
	cout << "... 파일 읽기 완료" << endl;
}

Words::~Words()
{
	fin.close();
}
void Words::Search(string word) 
{
	int count = 0;
	int length = word.length();
	for (int i = 0; i < wordVector.size(); i++) 
	{
		string tmp = wordVector[i];
		if (tmp.length() >= length) 
		{  			
			int index = tmp.find(word);
			if (index == 0) { // 첫 글자부터 같음. 찾았음. 
				cout << tmp << endl;
				count++;
			}
		}
	}
	if (count == 0)
		cout << "해당 단어가 없습니다." << endl;
}


int main() 
{
	Words w;

	cout << "검색을 시작합니다. 단어를 입력해 주세요." << endl;
	while (true) {
		cout << "단어>> ";
		string word;
		cin >> word;
		if (word == "exit")
			return 0; // 게임 종료
		w.Search(word);
	}
	return 0;
}