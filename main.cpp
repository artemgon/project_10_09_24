#include "structures.h"

int main()
{
    const int size = 10;
    Creature array[size];
	Creature creature1(0, "white", Creature::human);
	creature1.setInfo(24, "white", Creature::human, 140);
	creature1.printFunc();
    array[0].setInfo(20, "White", Creature::bird, static_cast<float>(35.5));
    array[1].setInfo(10, "Brown", Creature::cattle, static_cast<bool>(true));
    array[2].setInfo(15, "Black", Creature::human, static_cast<int>(120)); 
    array[3].setInfo(30, "Grey", Creature::bird, static_cast<float>(40.2));  
    array[4].setInfo(8, "White", Creature::cattle, static_cast<bool>(false));
    array[5].setInfo(12, "Blue", Creature::human, static_cast<int>(140));     
    array[6].setInfo(25, "Yellow", Creature::bird, static_cast<float>(50.0));
    array[7].setInfo(9, "Black", Creature::cattle, static_cast<bool>(true));
    array[8].setInfo(18, "Green", Creature::human, static_cast<int>(130));  
    array[9].setInfo(22, "Red", Creature::bird, static_cast<float>(45.5));
    int choice;
    do
    {
        cout << endl;
        cout << "Select your option: " << endl;
        cout << "1. Print creatures" << endl;
        cout << "2. Edit a creature" << endl;
        cout << "3. Search by velocity" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            array[0].printAll(array, size);
            break;
        case 2: {
            int index;
            cout << "Enter the index of the creature to edit (1-10): ";
            cin >> index;
            if (index >= 1 && index <= size)
                array[0].editFunc(array[index - 1]);
            else
                cout << "Invalid index!" << endl;
            break;
        }
        case 3: {
            float velocity;
            cout << "Enter velocity to search for: ";
            cin >> velocity;
            array[0].searchFunc(array, size, velocity);
            break;
        }
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
	return 0;
}