
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	//ofstream outfile;
	//outfile.open("test.txt");

	//ofstream outfile("test.txt"); // << ofstream outfile("test.txt",ios::out | ios::trunc); // << 
	ofstream outfile("test.txt", ios::out | ios::app); // << 
	outfile << "This is a test file." << endl;
	int n = 100;
	outfile << n << endl;
	outfile.close();


	ifstream infile("test.txt");
	if(!infile) //if (!infile.is_open())
	{
		cout << "File Open error" << endl;
		return 0;
	}
	//한 글자씩
	char ch=' ';
	while ((ch = infile.get()) != EOF)
		cout << ch << endl;
	cout << "--------------" << endl;

	//word단위로 
	infile.clear();//eof상태 clear
	infile.seekg(ios::beg);// get pointer
	char word[100];
	while ( !infile.eof() )
	{
		infile >> word; // >> 공백으로 구분
		cout << word << endl;
	}
	cout << "-----------" << endl;

	// 한줄씩
	infile.clear();//eof상태 clear
	infile.seekg(ios::beg);// get pointer
	char line[256];
	int count = 0;
	while (!infile.eof())
	{
		infile.getline(line,256); // >> 공백을 포함
		cout << setiosflags(ios::left) <<  setw(3) << ++count << line << endl;
	}


	infile.close();



	

}
