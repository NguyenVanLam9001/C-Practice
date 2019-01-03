#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include<fstream>
using namespace std;
using std::setw;
const string file = "Student.txt";
struct student
{   
	int ID;
	string name;
	float score;
};
vector<student> list;
int checkid(int id, vector<student>&list);
void display(vector<student>list);
bool savefile(vector<student>list);
int loadfile(vector<student>*list);


void addstudent(vector<student> &list)
{
	student st;
	do {
		cin.get(); cout << " Id: ";
		cin >> st.ID;
		if (checkid(st.ID, list) == -1)
		{
			break;
		}
	} while (checkid(st.ID, list) == 1);
	
	cout << "\nName: ";
	cin.get();
	getline(cin, st.name);
	cout << "\nscore: ";
	cin >> st.score;

	list.push_back(st);	
}
int checkid(int id, vector<student>&list)
{
	for (auto i : list)
	{
		if (id == i.ID)
		{
			return 1;
			break;
		}

	}
	return  -1;
}
void display(vector<student>list)
{
	system("CLS");
	if (list.empty())
	{
		cout << "List Empty ! " << endl;
		
		
			
	}
	else
	{
		cout.clear();
		cout << setw(70) << left << "============================== CONTACT LIST ============================" << endl;
		cout << setw(25) << "|| Id " << setw(17) << "|| Name " << setw(28) << "|| Score " << "||" << endl;
		cout << setw(70) << left << "||--------------------------------------------------------------------||" << endl;
		for (auto st : list)
		{
			cout << setw(25) << "||"<< st.ID ;
			cout << setw(17) << "||"<< st.name;
			cout << setw(28) << "||"<< st.score<<"||"<<endl;
			cout << setw(70) << left << "\n========================================================================" << endl;
		}		
	}
	cout << "\n exit";
	system("pause");
	
}
bool savefile(vector<student>list)
{
	
	ofstream savefile(file, std::ios::out);
	for (int i=0;i<list.size();i++)
	{
		savefile << list.at(i).ID << endl;
		savefile << list.at(i).name << endl;
		savefile << list.at(i).score << endl;
		if (savefile.fail())
		{
			return false;
		}
		savefile.close();
		return true;
	}
	

	
}

int loadfile(vector<student>*list)
{
	student student;
	int id;
	string name;
	float score;
	int size = list->size();
	ifstream File(file);
	if (File.fail()) return 2;
	int line = 0;
	while (getline(File, name))
	{
		line++;
		switch (line)
		{
		case 1:
		      id=stoi(name);
		      student.ID = id;
		break;
		case 2:
			student.name = name;
			break;
		case 3:
			score = stof(name);
			student.score = score;
			line = 0;
			list->push_back(student);

		default:
			break;
		}
	}
	File.close();
	if (size < list->size()) return 3;
	else
		return 4;
}
int main()
 {
	bool exit = false;
	while (!exit)
	{
		int n;
		cout << "---------------------------MENU--------------------------" << endl;
		cout << "1 . Input" << endl;
		cout << "2 . Display" << endl;
		cout << "3 . Save to file" << endl;
		cout << "4 . Load from file" << endl;
		cout << "0 . Exit" << endl;
		cout << "----------------------------------------------------------" << endl;
		cin >> n;

		switch (n)
		{
		case 1: addstudent(list);
			break;
		case 2: display(list);
			break;
		case 3: if (savefile(list))
			      cout << "save file success" << endl;
				else
				{
					cout << "fail ! " << endl;
				}
				system("pause");
			break;
		case 4: 
			switch (loadfile(&list))
		       {
			    case 5: 
					cout<<"Load file Failed!\n";
					break;
				case 6:
					cout << "Load file success!\n";
					break;
				case 7:
					cout << "File empty!\n";
					break;

		           default:
			       break;
		         }
			//system("pause");
			break;
		default:
			break;
		    }
	}
	system("pause");
	return 0;
 }