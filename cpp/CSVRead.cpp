
#include <iostream>
#include <fstream>
#include<vector> 
#include<string>
using namespace std;

/* ReadCsv�Լ��� csv(Comma Separated Values)������ ������ �о�ͼ� 2���� ���Ϳ� �����ϴ� �Լ��̴�.*/
/*�Ķ��Ÿ�� string���� FileName�� �ް� string Ÿ���� ��ҷ� �����ϴ� ���͸� �����ϴ� ������ ���͸� ���۷����� �޴´�.*/
void ReadCsv(std::string FileName, std::vector<std::vector<std::string>>& Data)
{
	std::ifstream ifs;

	ifs.open(FileName);
	if (!ifs.is_open()) 
		return; /*is_open�Լ��� ����� ������ ����� ���ȴ��� Ȯ���Ѵ�. ������ �ʾ��� ��� �׳� ��ȯ�Ѵ�..*/

	std::string LineString = "";  
	std::string Delimeter = ","; 
	while (getline(ifs, LineString)) /*getline���� ������ �ٹٲ޹���('\n')�� ������ ���پ� �о LineString�� �����Ѵ�. ������ �� ������ ios_base::eofbit��  �µǸ鼭 while���� �����Ѵ�.*/
	{
		/*LineString�� ����Ǿ� �ִ� �� ���� ���ڿ����� ','�� ���е� ���ڿ�(�ܾ�)�� ������ vector RowData�� �����Ѵ�*/
		std::vector<std::string> RowData; 
		unsigned int nPos = 0, nFindPos;

		do 
		{
			nFindPos = LineString.find(Delimeter, nPos);
			/*find�Լ��� ���ڿ����� ","�� ��ġ�� ���Ѵ�.find �Լ��� Delimeter�� nPos�� �Ķ��Ÿ�� �����Ѵ�. 
			//ù��° �Ķ��Ÿ Delimeter(,)�� �ε����� ��ȯ �ϴ� ���̰�  �ι�° �Ķ��Ÿ nPos�� �˻��� ������ ��ġ�� �������ش�.
			//find�Լ��� ã�� ���� ������ �� std::string::npos(-1)�� ��ȯ�Ѵ�.*/

			if (nFindPos == std::string::npos) nFindPos = LineString.length();
			/*nFindPos�� stringŬ������ npos�� ���� ���, �� find �Լ��� Delimeter�� ã�� ������ ��� nFindPos�� LineString�� ���̸� �����Ѵ�.*/

			RowData.push_back(LineString.substr(nPos, nFindPos - nPos));
			/*substr�� �̿��ؼ� LineString�� �κ� ���ڿ��� �����Ѵ�.
			ù��° �Ķ��Ÿ�� ���� ��ġ�� �ι�° �Ķ��Ÿ�� ������ ���� ������ �����Ѵ�
			nPos���� ���� nFindPos�� nPos�� �� ���� ������ŭ �����Ͽ� RowData�� �߰��Ѵ�.
				�� nPos���� ','���� �������� ���ڿ��� RowData�� �߰��Ѵ�.*/
			nPos = nFindPos + 1; /*���� ���ڿ��� ã�� ���Ͽ� nPos�� ���� nFindPos�� 1�� ���� ���� �����Ѵ�.*/
		} while (nFindPos < LineString.length());

		Data.push_back(RowData);/*�Ķ��Ÿ�� ���� ������ ���Ϳ� RowData�� �ϳ��� �߰� ���ش�.*/
	/*Data ������ ���ͷ� �࿡�� ������ �� �ٿ� �ش��ϴ� �ܾ���� ���ͷ� ������ �ȴ�*/
	}

	ifs.close(); /*close�Լ��� ������ ������ �ݾ��ش�. */
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
	/*string�� ��ҷ� ������ 1���� ���͸� ��ҷ� ������ 2���� ���� v1�� �����Ѵ�.*/
	ReadCsv(file, v1); /*ReadCsv�Լ��� file�� v1�� �Ѱ��ش�.*/
	print(v1);
}
