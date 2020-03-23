#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	string filepath;

	string choice;

	srand(time(NULL));

	int filesize;
	string suffix;
	int coefficient;

	bool areyousure = 0;
	string sure;

	while (!areyousure)
	{
		fflush(stdin);
		cout << "Choose type of file (bin/text): ";
		getline(cin, choice);
		fflush(stdin);
		cout << "Choose file destination and name: ";
		fflush(stdin);
		getline(cin, filepath);
		fflush(stdin);
		cout << "Select the file size (use a space after the number): ";
		cin >> filesize;
		cin >> suffix;

		fflush(stdin);
		cout << "\n\n Are you sure? [Y/n]\n";
		cin >> sure;
		if (sure != "n" or sure != "N")
			areyousure = 1;

		system("cls");
	}



	if (suffix == "KB" || suffix == "kb" || suffix == "Kb" || suffix == "kB")
		coefficient = 1000;
	else if (suffix == "MB" || suffix == "mb" || suffix == "Mb" || suffix == "mB")
		coefficient = 1000000;
	else if (suffix == "GB" || suffix == "gb" || suffix == "Gb" || suffix == "gB")
		coefficient = 1000000000;
	else if (suffix == "TB" || suffix == "tb" || suffix == "Tb" || suffix == "tB")
		coefficient = pow(10, 12);
	else if (suffix == "PB" || suffix == "pb" || suffix == "Pb" || suffix == "pB")
		coefficient = pow(10, 15);

	else if (suffix == "KBi" || suffix == "kbi" || suffix == "Kbi" || suffix == "kBi")
		coefficient = 1024;
	else if (suffix == "MBi" || suffix == "mbi" || suffix == "Mbi" || suffix == "mBi")
		coefficient = 1024 * 1024;
	else if (suffix == "GBi" || suffix == "gbi" || suffix == "Gbi" || suffix == "gBi")
		coefficient = pow(1024, 3);
	else if (suffix == "TBi" || suffix == "tbi" || suffix == "Tbi" || suffix == "tBi")
		coefficient = pow(1024, 4);
	else if (suffix == "PBi" || suffix == "pbi" || suffix == "Pbi" || suffix == "pBi")
		coefficient = pow(1024, 5);
	else
		coefficient = 1;

	if (choice == "bin")
	{
		char temp;
		ofstream file(filepath, ios::app | ios::binary);
		for (int i = 0; i < filesize * coefficient; i++)
		{
			temp = (char)(rand() % (126 - 32) + 32);
			file.write((char*)&temp, sizeof(temp));
		}
		file.close();
		cout << "\nsuccssess\n";
	}

	else if (choice == "text")
	{
		ofstream file(filepath, ios::app);
		for (int i = 0; i < filesize * coefficient; i++)
		{
			file << (char)(rand() % (126 - 32) + 32);
		}
		file.close();
		cout << "\nsuccssess\n";
	}
	system("pause");
	return 0;
}