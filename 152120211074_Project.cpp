#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include<sstream> 
#include<ctime>
struct person
{
	char ID[5];
	char name[30];
	char surname[30];
	int age;
	char city[30];
	string last_vaccine_date = "01.06.2020";
	int last_vaccination_year;
	int last_vaccination_month;
	int last_vaccination_day;
	int doseNo = 0;
	char vaccineType[10] = "NULL";

};

void StringBirlestir(char* str)
{
	string ret = string(str);
	size_t offset = 0;

	while ((offset = ret.find(' ', offset)) != string::npos)
	{
		ret[offset] = '_';
	}
	strcpy(str, ret.c_str());
}

void StringAyir(char* str)
{
	string ret = string(str);
	size_t offset = 0;

	while ((offset = ret.find('_', offset)) != string::npos)
	{
		ret[offset] = ' ';
	}
	strcpy(str, ret.c_str());
}

void takeInformation(person* you)
{
	cout << "----------Hasta Kayit-----------" << endl << endl;
	cout << "Isim: ";
	cin.ignore();
	cin.getline(you->name, 30);
	StringBirlestir(you->name);
	cout << "Soyisim: ";
	cin.getline(you->surname, 30);
	cout << "Yas: ";
	cin >> you->age;
	cout << "Sehir: ";
	cin.ignore();
	cin.getline(you->city, 30);

	cout << "ID'niz: " << you->ID << endl;




}
void IDgenerator(person* you)
{
	srand(time(NULL));
	char ID[5] = {};
	int Len = 'Z' - 'A';
	ID[0] = (char)(65 + rand() % Len);
	ID[1] = (char)(65 + rand() % Len);
	ID[2] = (char)(48 + rand() % 9);
	ID[3] = (char)(48 + rand() % 9);
	strcpy(you->ID, ID);
}


void testInformation(person* you)
{


	cout << you->ID << "_" << you->name << "_" << you->surname << "_" << you->age << "_" << you->city << "_" << you->last_vaccine_date << "_" << you->doseNo << "_" << you->vaccineType << endl;


}
void write_to_file(person* you)
{

	ofstream  dataFile;

	dataFile.open("database.txt", std::ios_base::app);

	dataFile << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;
	dataFile.close();
	cout << endl << "Bilgileriniz kaydedildi." << endl;
}

void split(const string& str, const string& delim, vector<string>& parts) {
	size_t start, end = 0;
	while (end < str.size()) {
		start = end;
		while (start < str.size() && (delim.find(str[start]) != string::npos)) {
			start++;
		}
		end = start;
		while (end < str.size() && (delim.find(str[end]) == string::npos)) {
			end++;
		}
		if (end - start != 0) {
			parts.push_back(string(str, start, end - start));
		}
	}
}

void read_from_file(person* you)
{
	ifstream dataFile;
	dataFile.open("database.txt", ios::in);
	string Line;
	vector<string> Field;

	while (getline(dataFile, Line))
	{
		cout << Line << endl;
		/*getline(dataFile, Line);
		split(Line, " ", Field);
		strcpy(you->ID, Field[0].c_str());
		strcpy(you->name, Field[1].c_str());
		strcpy(you->surname, Field[2].c_str());
		you->age = stoi(Field[3])  ;
		strcpy(you->city, Field[4].c_str());
		strcpy(you-> last_vaccine_date, Field[5].c_str());
		you->doseNo = stoi(Field[6]);
		strcpy(you->vaccineType, Field[7].c_str());*/

	}
	//testInformation(you);
	dataFile.close();

}
void view_registiration(person* you)
{
	cout << "---------------KAYIT SORGULAMA--------------------" << endl << endl;

	ifstream dataFile("database.txt");
	char ID_input[5];

	cout << "Kayit goruntulemek icin ID'nizi giriniz: ";
	cin.ignore();
	cin >> ID_input;

	cout << endl;



	while (!dataFile.eof())

	{

		dataFile >> you->ID >> you->name >> you->surname >> you->age >> you->city >> you->last_vaccine_date >> you->doseNo >> you->vaccineType;


		if (strcmp(ID_input, you->ID) == 0)

			cout << you->ID << "_" << you->name << "_" << you->surname << "_" << you->age << "_" << you->city << "_" << you->last_vaccine_date << "_" << you->doseNo << "_" << you->vaccineType << endl;

	}


	dataFile.close();


}
void updateInformation(person* you)
{
	cout << "-------------------------------Kayit Guncelleme-------------------------------" << endl;

	ifstream dataFile("database.txt");
	ofstream dataTemp;
	dataTemp.open("temp.tmp", std::ios_base::app);
	char ID_input[5];

	cout << "ID'nizi giriniz: ";
	cin.ignore();
	cin >> ID_input;
	int ID_test = 0;




	while (dataFile >> you->ID >> you->name >> you->surname >> you->age >> you->city >> you->last_vaccine_date >> you->doseNo >> you->vaccineType)

	{
		//dataFile >> you->ID >> you->name >> you->surname >> you->age >> you->city >> you->last_vaccine_date >> you->doseNo >> you->vaccineType;



		if (strcmp(ID_input, you->ID) == 0) {

			cout << you->ID << "_" << you->name << "_" << you->surname << "_" << you->age << "_" << you->city << "_" << you->last_vaccine_date << "_" << you->doseNo << "_" << you->vaccineType << endl;

			cout << "Guncel bilgilerinizi giriniz" << endl;
			cout << "Isim: ";
			cin.ignore();
			cin.getline(you->name, 30);
			StringBirlestir(you->name);
			cout << "Soyisim: ";
			cin.getline(you->surname, 30);
			cout << "Yas: ";
			cin >> you->age;
			cout << "Sehir: ";
			cin.ignore();
			cin.getline(you->city, 30);

			dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;
			ID_test = 1;
			cout << endl << "Guncel bilgileriniz kaydedildi." << endl;
		}
		else
			dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;

	}
	if (ID_test == 0)
		cout << "Hatali ID girisi" << endl;

	dataTemp.close();
	dataFile.close();

	remove("database.txt");
	rename("temp.tmp", "database.txt");


}
void vaccineRequest(person* you)
{
	cout << "-----------------------------Asi Talebi Olusturma-------------------------" << endl;
	time_t current_time;
	struct tm  local_time;

	time(&current_time);
	localtime_s(&local_time, &current_time);

	int Year = local_time.tm_year + 1900;
	int Month = local_time.tm_mon + 1;
	int Day = local_time.tm_mday;
	int yil = Year;
	int month = Month;

	stringstream ss;
	ss << Day;
	string s;
	ss >> s;
	stringstream aa;
	aa << Month;
	string a;
	aa >> a;
	stringstream bb;
	bb << Year;
	string b;
	bb >> b;
	ifstream dataFile("database.txt");
	ofstream dataTemp;
	dataTemp.open("temp.tmp", std::ios_base::app);
	char ID_input[5];
	char vaccine_type_request[10];

	cout << "ID'nizi giriniz: ";
	cin.ignore();
	cin >> ID_input;
	while (dataFile >> you->ID >> you->name >> you->surname >> you->age >> you->city >> you->last_vaccine_date >> you->doseNo >> you->vaccineType)
	{

		if (strcmp(ID_input, you->ID) == 0) {

			cout << you->ID << "_" << you->name << "_" << you->surname << "_" << you->age << "_" << you->city << "_" << you->last_vaccine_date << "_" << you->doseNo << "_" << you->vaccineType << endl << endl;
			vector<string> Field;
			split(you->last_vaccine_date, ".", Field);
			you->last_vaccination_day = stoi(Field[0]);
			you->last_vaccination_month = stoi(Field[1]);
			you->last_vaccination_year = stoi(Field[2]);



			if (you->age < 18)
			{
				cout << "18 yasini doldurmayanlar asi kaydi yaptiramazlar.";
				dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;


			}
			else
			{

				if (you->doseNo >= 2)
				{
					cout << "En fazla 2 adet asi olabilirsiniz.";
					dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;


				}
				else
				{

					if (strcmp(you->vaccineType, "NULL") == 0)
					{


						you->last_vaccine_date = s + "." + a + "." + b;

						cout << "Olmak istediginiz asi turunu seciniz." << endl;
						cout << "   X/Y" << endl;
						cin.ignore();
						cin.getline(vaccine_type_request, 10);
						if (strcmp(vaccine_type_request, "X") == 0 || strcmp(vaccine_type_request, "Y") == 0)
						{
							strcpy(you->vaccineType, vaccine_type_request);
							you->doseNo = you->doseNo + 1;

							dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;
							cout << endl << "Gecmis olsun." << endl;
						}
						else
						{
							cout << "Gecersiz bir asi turu girdiniz.";
							dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;


						}


					}
					else
					{

						if (yil > you->last_vaccination_year) {
							you->last_vaccine_date = s + "." + a + "." + b;
							cout << "2. doz asi turu 1. doz asi turuyle ayni olmak zorundadir." << "Randevunuz otomatik olarak " << you->vaccineType << " asisindan olusturulmustur.";
							you->doseNo = you->doseNo + 1;
							dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;

						}
						else if (yil == you->last_vaccination_year) {

							if (month > you->last_vaccination_month) {

								you->last_vaccine_date = s + "." + a + "." + b;
								cout << "2. doz asi turu 1. doz asi turuyle ayni olmak zorundadir." << "Randevunuz otomatik olarak " << you->vaccineType << " asisindan olusturulmustur.";
								you->doseNo = you->doseNo + 1;
								dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;

							}
							else {

								cout << "Son asinizin uzerinden en az 1 ay gecmelidir.";
								dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;


							}
						}
						else {
							cout << "Son asinizin uzerinden en az 1 ay gecmelidir.";
							dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;



						}



					}





				}




			}
		}
		else
			dataTemp << "\n" << you->ID << " " << you->name << " " << you->surname << " " << you->age << " " << you->city << " " << you->last_vaccine_date << " " << you->doseNo << " " << you->vaccineType << endl;










	}

	dataTemp.close();
	dataFile.close();

	remove("database.txt");
	rename("temp.tmp", "database.txt");


}
void menuStyle(person* you)
{
	int tus_ana_menu = 0;
	int tus_islem1 = 0;
	int tus_islem2 = 0;
	int tus_islem3 = 0;
	int tus_islem4 = 0;
	cout << "-------------------------------------------------HOSGELDINIZ------------------------------------------------------------" << endl << endl;
	while (tus_ana_menu != 5) {
		cout << "Yapacaginiz islemi seciniz:" << endl << endl;
		cout << "Yeni hasta kaydi icin 1'i tuslayin." << endl << "Kayit sorgulatmak icin 2'yi tuslayin." << endl << "Asi randevusu icin 3'u tuslayin." << endl << "Bilgilerinizi guncellemek icin 4'u tuslayin." << endl << "Cikis yapmak icin 5'i tuslayin." << endl << endl;

		cout << "Islem numaranizi giriniz: ";
		cin >> tus_ana_menu;
		system("cls");


		if (tus_ana_menu == 1) {
			IDgenerator(you);
			//StringBirlestir(&you);
			takeInformation(you);
			write_to_file(you);
			//read_from_file(&you);
			cout << "\n\n" << "Ana menuye donmek icin 1'i, cikis yapmak icin 2'yi tuslayin: ";
			cin >> tus_islem1;
			if (tus_islem1 == 2)
				break;
			system("cls");
		}
		else if (tus_ana_menu == 2) {
			view_registiration(you);
			cout << "\n\n" << "Ana menuye donmek icin 1'i, cikis yapmak icin 2'yi tuslayin: ";
			cin >> tus_islem2;
			if (tus_islem2 == 2)
				break;
			system("cls");
		}
		else if (tus_ana_menu == 3) {
			vaccineRequest(you);
			cout << "\n\n" << "Ana menuye donmek icin 1'i, cikis yapmak icin 2'yi tuslayin: ";
			cin >> tus_islem3;
			if (tus_islem3 == 2)
				break;
			system("cls");
		}
		else if (tus_ana_menu == 4) {
			updateInformation(you);
			cout << "\n\n" << "Ana menuye donmek icin 1'i, cikis yapmak icin 2'yi tuslayin: ";
			cin >> tus_islem4;
			if (tus_islem4 == 2)
				break;
			system("cls");
		}
		else if (tus_ana_menu == 5)
		{

		}
		else {
			cout << "Tanimli bir operasyon seciniz..." << endl;

		}
	}
}
int main()
{
	person you{};

	menuStyle(&you);
}