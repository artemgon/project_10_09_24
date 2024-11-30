#include "structures.h"

int main()
{
    const int size = 10;
    int choice;
    Car car1;
    car1.setValues("Cullinan", "black", 34821);
    car1.printFunc();
    Car array[size];
    array[0].setValues("Tesla Model 3", "Red", "ABC123");
    array[1].setValues("Ford Mustang", "Blue", 456789);
    array[2].setValues("BMW X5", "Black", "XYZ987");
    array[3].setValues("Audi A4", "White", 123456);
    array[4].setValues("Toyota Corolla", "Grey", "LMN345");
    array[5].setValues("Honda Civic", "Green", 987654);
    array[6].setValues("Mercedes-Benz C", "Silver", "DEF456");
    array[7].setValues("Volkswagen Golf", "Blue", 654321);
    array[8].setValues("Chevrolet Camaro", "Yellow", "GHI789");
    array[9].setValues("Nissan Leaf", "White", 789123);
    do
    {
        cout << endl;
        cout << "Select your option: " << endl;
        cout << "1. Print cars" << endl;
        cout << "2. Edit a car" << endl;
        cout << "3. Search car by text number" << endl;
        cout << "4. Search car by int number" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Car::printCars(array, size);
            break;
        }
        case 2:
        {
            int index;
            cout << "Enter the index of car you want to edit: " << endl;
            cin >> index;
            if (index < 1 || index > size)
                cout << "Error occurred..." << endl;
            else
                Car::editFunc(array[index - 1]);
            break;
        }
        case 3:
        {
            string u_number;
            cout << "Enter text number to search: ";
            cin >> u_number;
            Car::searchFunc(array, size, u_number);
            break;
        }
        case 4:
        {
            int u_number;
            cout << "Enter integer number to search: ";
            cin >> u_number;
            Car::searchFunc(array, size, u_number);
            break;
        }
        case 5:
        {
            cout << "Exiting program..." << endl;
            exit(0);
            break;
        }
        default:
        {
        cout << "Error occurred..." << endl;
        break;
        }
        }
        } while (choice != 5);
        return 0;
}