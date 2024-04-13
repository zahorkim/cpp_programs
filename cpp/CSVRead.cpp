
#include <iostream>
#include <fstream>
#include<vector> 
#include<string>
using namespace std;

/* ReadCsv함수는 csv(Comma Separated Values)파일의 내용을 읽어와서 2차원 벡터에 저장하는 함수이다.*/
/*파라메타를 string으로 FileName을 받고 string 타입을 요소로 저장하는 벡터를 저장하는 이차원 벡터를 레퍼런스로 받는다.*/
void ReadCsv(std::string FileName, std::vector<std::vector<std::string>>& Data)
{
	std::ifstream ifs;

	ifs.open(FileName);
	if (!ifs.is_open()) 
		return; /*is_open함수를 사용해 파일이 제대로 열렸는지 확인한다. 열리지 않았을 경우 그냥 반환한다..*/

	std::string LineString = "";  
	std::string Delimeter = ","; 
	while (getline(ifs, LineString)) /*getline으로 파일을 줄바꿈문자('\n')로 구분해 한줄씩 읽어서 LineString에 저장한다. 파일을 다 읽으면 ios_base::eofbit가  셋되면서 while문을 종료한다.*/
	{
		/*LineString에 저장되어 있는 한 줄의 문자열에서 ','로 구분된 문자열(단어)를 복사해 vector RowData에 저장한다*/
		std::vector<std::string> RowData; 
		unsigned int nPos = 0, nFindPos;

		do 
		{
			nFindPos = LineString.find(Delimeter, nPos);
			/*find함수로 문자열에서 ","의 위치를 구한다.find 함수에 Delimeter와 nPos를 파라메타로 전달한다. 
			//첫번째 파라메타 Delimeter(,)의 인덱스를 반환 하는 것이고  두번째 파라메타 nPos는 검색을 시작할 위치를 전달해준다.
			//find함수는 찾는 것을 실패할 시 std::string::npos(-1)를 반환한다.*/

			if (nFindPos == std::string::npos) nFindPos = LineString.length();
			/*nFindPos와 string클래스의 npos가 같을 경우, 즉 find 함수로 Delimeter을 찾지 못했을 경우 nFindPos에 LineString의 길이를 저장한다.*/

			RowData.push_back(LineString.substr(nPos, nFindPos - nPos));
			/*substr을 이용해서 LineString의 부분 문자열을 복사한다.
			첫번째 파라메타는 시작 위치고 두번째 파라메타는 복사할 문자 개수를 전달한다
			nPos에서 부터 nFindPos에 nPos를 뺀 값의 개수만큼 복사하여 RowData에 추가한다.
				즉 nPos에서 ','문자 전까지의 문자열을 RowData에 추가한다.*/
			nPos = nFindPos + 1; /*다음 문자열을 찾기 위하여 nPos의 값을 nFindPos에 1을 더한 값을 저장한다.*/
		} while (nFindPos < LineString.length());

		Data.push_back(RowData);/*파라메타로 받은 이차원 벡터에 RowData를 하나씩 추가 해준다.*/
	/*Data 이차원 벡터로 행에는 파일의 각 줄에 해당하는 단어들을 벡터로 가지게 된다*/
	}

	ifs.close(); /*close함수로 열었던 파일을 닫아준다. */
}
void print(vector<vector<string>>& v) 
{ 
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++) 
		{
			cout << v[i][j] << ",";
		}
		cout << endl;
	}
}

int main() \{
	string file = "D:\\Downloads\\cpp\\cpp\\IO\\diabetes.csv";  

	vector<vector<string>>v1;
	/*string을 요소로 가지는 1차원 벡터를 요소로 가지는 2차원 벡터 v1을 선언한다.*/
	ReadCsv(file, v1); /*ReadCsv함수에 file과 v1을 넘겨준다.*/
	print(v1);
}
