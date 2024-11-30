#define _CRT_SECURE_NO_WARNINGS

#include "libs.h"

struct Car
{
public:
	int type;
	string model, color;
	union
	{
		char s_number[8];
		int i_number;
	};
	Car()
	{
		type = 0;
		model = "Unknown";
		color = "Unknown";
		i_number = 0;
	}
	void setValues(string m, string c, const string& n)
	{
		type = 1;
		model = m;
		color = c;
		strncpy(s_number, n.c_str(), sizeof(s_number) - 1);
		s_number[sizeof(s_number) - 1] = '\0';
	}
	void setValues(string m, string c, int n)
	{
		type = 2;
		model = m;
		color = c;
		i_number = n;
	}
	void printFunc() const
	{
		cout << "Model: " << model << endl;
		if (type == 1)
			cout << "Number: " << s_number << endl;
		else if (type == 2)
			cout << "Number: " << i_number << endl;
		else
			cout << "Error occurred..." << endl;
		cout << "Color: " << color << endl;
	}
	static void editFunc(Car& car)
	{
		cout << "Enter model: " << endl;
		cin >> car.model;
		cout << "Enter color: " << endl;
		cin >> car.color;
		if (car.type == 1)
		{
			cout << "Enter text car number: " << endl;
			string number_1; cin >> number_1;
			strncpy(car.s_number, number_1.c_str(), sizeof(car.s_number) - 1);
			car.s_number[sizeof(car.s_number) - 1] = '\0';
		}
		else if (car.type == 2)
		{
			cout << "Enter int car number: " << endl;
			cin >> car.i_number;
		}
	}
	static void printCars(const Car array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Car " << i + 1 << ": ";
			array[i].printFunc();
			cout << endl;
 		}
	}
	static void searchFunc(const Car array[], int size, const string& u_number)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i].type == 1 && u_number == array[i].s_number)
			{
				cout << "Car is found: " << endl;
				array[i].printFunc();
			}
		}
		cout << "Car with number " << u_number << " wasn't found." << endl;
	}
	static void searchFunc(const Car array[], int size, int u_number)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i].type == 2 && u_number == array[i].i_number)
			{
				cout << "Car is found: " << endl;
				array[i].printFunc();
			}
		}
		cout << "Car with number " << u_number << " wasn't found." << endl;
	}
};