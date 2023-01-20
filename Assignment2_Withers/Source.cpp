#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//Trevor Withers
//This program keeps track of home addresses and their prices.
const int SIZE = 20;

int loadArrays(string[], double[]);
int removeHome(string[], double[], int);
int findHighest(const double[], int);
int addHome(string[], double[], int);

double validatePrice(double);

void printHomes(const string[], const double[], int);

int main()
{
	string address[SIZE];
	double price[SIZE];
	int noRecords = 0;

	cout << "\nDelete an empty list:\n\n" << endl;
	printHomes(address, price, noRecords);
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nInitial array load:\n\n" << endl;
	noRecords = loadArrays(address, price);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a new home:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd the same home:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a home to the beginning of the array:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a home to the end of the array:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nAdd a home to middle of array:\n\n" << endl;
	noRecords = addHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete a home from start of array:\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete the same home\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete a home from middle of array:\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nDelete a home from the end of the array:\n\n" << endl;
	noRecords = removeHome(address, price, noRecords);
	printHomes(address, price, noRecords);
	cout << "# homes = " << noRecords << endl;
	cout << "\nProgram ended successfully" << endl;
	system("type homes.txt");
	system("pause");
}

/// <summary>
/// Loads the values from the file into the arrays
/// </summary>
/// <param name="passedAddress"></param>
/// <param name="passedPrice"></param>
/// <returns>index</returns>
int loadArrays(string address[], double price[])
{
	int index;
	ifstream fin("homes.txt");

	if (!fin.is_open())
	{
		cout << "File will not open. Program will now close..." << endl;
		system("pause");
		exit(-1);
	}

	for (index = 0; index < SIZE; index++)
	{
		getline(fin, address[index]);
		if (fin.eof())
		{
			break;
		}
		fin >> price[index];
		fin.ignore(80, '\n');
	}

	return index;
}


/// <summary>
/// Finds the highest price home and returns as a index number
/// </summary>
/// <param name="price"></param>
/// <param name="noHomes"></param>
/// <returns>highestPrice</returns>
int findHighest(const double price[], int noRecords)
{
	int highestPrice = 0;

	for (int index = 0; index < noRecords; index++)
	{
		if (price[index] > price[highestPrice])
		{
			highestPrice = index;
		}
	}

	return highestPrice;
}

/// <summary>
/// Prints the list of homes to the screen in an organized fashion
/// </summary>
/// <param name="address"></param>
/// <param name="price"></param>
/// <param name="noRecords"></param>
void printHomes(const string address[], const double price[], int noRecords)
{
	double highest = findHighest(price, noRecords);

	cout << left << setw(20) << "Address" << right << setw(20) << "Price" << endl << endl;

	for (int ctr = 0; ctr < noRecords; ctr++)
	{
		cout << fixed << setprecision(2) << left << setw(20) << address[ctr] << right << setw(20) << price[ctr];

		if (ctr == highest)
		{
			cout << " ***Highest Price*** ";
		}
		cout << endl;
	}

	cout << endl << "Number of homes = " << noRecords << endl;
}

/// <summary>
/// Validates price between two values
/// </summary>
/// <param name="passedPrice"></param>
/// <returns>passedPrice</returns>
double validatePrice(double passedPrice)
{
	while (passedPrice < 50000 || passedPrice > 10000000 || cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Invalid entry. The price must be between 50000 and 10000000." << endl;

		cout << "Enter house price: ";
		cin >> passedPrice;
	}

	return passedPrice;
}

/// <summary>
/// Add a home to the list
/// </summary>
/// <param name="address"></param>
/// <param name="price"></param>
/// <param name="noRecords"></param>
/// <returns>noRecords</returns>
int addHome(string address[], double price[], int noRecords)
{
	if (noRecords < SIZE)
	{
		int pos;
		string newHouse;
		double newPrice = 0.0;

		cout << "Please enter a home: ";
		getline(cin, newHouse);

		while (newHouse == "")
		{
			cout << "Invalid entry. Please Enter a home: ";
			getline(cin, newHouse);
		}

		for (pos = 0; pos < noRecords; pos++)
		{
			if (address[pos] >= newHouse)
			{
				break;
			}
		}

		if (pos < noRecords&& address[pos] == newHouse)
		{
			cout << "Can't add element, item already exists" << endl;
		}
		else
		{
			for (int index = noRecords; index > pos; index--)
			{
				address[index] = address[index - 1];
				price[index] = price[index - 1];
			}
			address[pos] = newHouse;

			cout << "Please enter the price: ";
			cin >> price[pos];
			price[pos] = validatePrice(newPrice);
			//price[pos] = newPrice;

			noRecords++;
			cin.ignore(80, '\n');
		}
	}
	else
	{
		cout << "Available space reached. Cannot enter any more homes." << endl;
	}

	return noRecords;
}

/// <summary>
/// Remove a home from the list
/// </summary>
/// <param name="address"></param>
/// <param name="price"></param>
/// <param name="noRecords"></param>
/// <returns>noRecords</returns>
int removeHome(string address[], double price[], int noRecords)
{
	if (noRecords > 0)
	{
		int pos;

		string homeToRemove;

		cout << "Enter home to remove: ";
		getline(cin, homeToRemove);

		for (pos = 0; pos < noRecords; pos++)
		{
			if (address[pos] == homeToRemove)
			{
				break;
			}
		}

		if (pos == noRecords)
		{
			cout << "Home not found" << endl;
		}
		else
		{
			noRecords--;
			for (; pos < noRecords; pos++)
			{
				address[pos] = address[pos + 1];
				price[pos] = price[pos + 1];
			}
		}
	}
	else
	{
		cout << "There are no homes in the list." << endl;
	}

	return noRecords;
}

/*

	Delete an empty list:


	Address                            Price


	Number of homes = 0
	There are no homes in the list.
	Address                            Price


	Number of homes = 0
	# homes = 0

	Initial array load:


	Address                            Price

	100 Main Street                100000.00
	1 Princess Street             1000000.00 ***Highest Price***
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00

	Number of homes = 8
	# homes = 8

	Add a new home:


	Please enter a home: 11 Mill Street
	Please enter the price: 450000
	Address                            Price

	100 Main Street                100000.00
	1 Princess Street             1000000.00 ***Highest Price***
	11 Mill Street                 450000.00
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00

	Number of homes = 9
	# homes = 9

	Add the same home:


	Please enter a home: 11 Mill Street
	Can't add element, item already exists
	Address                            Price

	100 Main Street                100000.00
	1 Princess Street             1000000.00 ***Highest Price***
	11 Mill Street                 450000.00
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00

	Number of homes = 9
	# homes = 9

	Add a home to the beginning of the array:


	Please enter a home: 0 Main Street
	Please enter the price: 10000000
	Address                            Price

	0 Main Street                10000000.00 ***Highest Price***
	100 Main Street                100000.00
	1 Princess Street             1000000.00
	11 Mill Street                 450000.00
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00

	Number of homes = 10
	# homes = 10

	Add a home to the end of the array:


	Please enter a home: 8 Pine Street
	Please enter the price: 51000
	Address                            Price

	0 Main Street                10000000.00 ***Highest Price***
	100 Main Street                100000.00
	1 Princess Street             1000000.00
	11 Mill Street                 450000.00
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00
	8 Pine Street                   51000.00

	Number of homes = 11
	# homes = 11

	Add a home to middle of array:


	Please enter a home: 44 Pine Street
	Please enter the price: 565600
	Address                            Price

	0 Main Street                10000000.00 ***Highest Price***
	100 Main Street                100000.00
	1 Princess Street             1000000.00
	11 Mill Street                 450000.00
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	44 Pine Street                 565600.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00
	8 Pine Street                   51000.00

	Number of homes = 12
	# homes = 12

	Delete a home from start of array:


	Enter home to remove: 0 Main Street
	Address                            Price

	100 Main Street                100000.00
	1 Princess Street             1000000.00 ***Highest Price***
	11 Mill Street                 450000.00
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	44 Pine Street                 565600.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00
	8 Pine Street                   51000.00

	Number of homes = 11
	# homes = 11

	Delete the same home


	Enter home to remove: 0 Main Street
	Home not found
	Address                            Price

	100 Main Street                100000.00
	1 Princess Street             1000000.00 ***Highest Price***
	11 Mill Street                 450000.00
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	44 Pine Street                 565600.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00
	8 Pine Street                   51000.00

	Number of homes = 11
	# homes = 11

	Delete a home from middle of array:


	Enter home to remove: 44 Pine Street
	Address                            Price

	100 Main Street                100000.00
	1 Princess Street             1000000.00 ***Highest Price***
	11 Mill Street                 450000.00
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00
	8 Pine Street                   51000.00

	Number of homes = 10
	# homes = 10

	Delete a home from the end of the array:


	Enter home to remove: 8 Pine Street
	Address                            Price

	100 Main Street                100000.00
	1 Princess Street             1000000.00 ***Highest Price***
	11 Mill Street                 450000.00
	2 Pine Street                   89888.00
	3 Pine Street                   89889.00
	4 Pine Street                   89890.00
	5 Pine Street                   89891.00
	6 Pine Street                   89892.00
	7 Pine Street                   89893.00

	Number of homes = 9
	# homes = 9

	Program ended successfully
	100 Main Street
	100000.00
	1 Princess Street
	1000000.00
	2 Pine Street
	89888.00
	3 Pine Street
	89889.00
	4 Pine Street
	89890.00
	5 Pine Street
	89891.00
	6 Pine Street
	89892.00
	7 Pine Street
	89893.00
	Press any key to continue . . .
*/