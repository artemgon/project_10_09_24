#include "libs.h"

struct Creature
{
	float velocity;
	string color;
	union characteristic
	{
		float fly_vel;
		bool artiodactyl;
		int iq_level;
	} charac;
	enum type
	{
		bird,
		cattle,
		human
	};
	type c_type;
    Creature() : velocity(0), color("Unknown"), c_type(bird)
    {
        charac.fly_vel = 0.0;
    }
	Creature(float v, string c, type t) : velocity(v), color(c), c_type(t)
    {
        charac.iq_level = 0;
    }
    void setInfo(float v, string c, type t, float f)
    {
        velocity = v;
        color = c;
        c_type = t;
        if (t == bird)
            charac.fly_vel = f;
    }
    void setInfo(float v, string c, type t, bool a) 
    {
        velocity = v;
        color = c;
        c_type = t;
        if (t == cattle)
         charac.artiodactyl = a;
    }
    void setInfo(float v, string c, type t, int iq)
    {
        velocity = v;
        color = c;
        c_type = t;
        if (t == human)
            charac.iq_level = iq;
    }
    void printFunc() const
    {
        cout << "Velocity: " << velocity << ", Color: " << color << ", Type: ";
        switch (c_type)
        {
        case bird:
            cout << "Bird, Fly velocity: " << charac.fly_vel << endl;
            break;
        case cattle:
            cout << "Cattle, Artiodactyl: " << (charac.artiodactyl ? "Yes" : "No") << endl;
            break;
        case human:
            cout << "Human, IQ Level: " << charac.iq_level << endl;
            break;
        default:
            cout << "Unknown type!" << endl;
            break;
        }
    }
    void editFunc(Creature& creature)
    {
        int choice;
        cout << "Enter type (0 = Bird, 1 = Cattle, 2 = Human): ";
        cin >> choice;
        float velocity;
        string color;
        if (choice == 0)
        {
            float fly_velocity;
            cout << "Enter velocity, color, and fly velocity: ";
            cin >> velocity >> color >> fly_velocity;
            creature.setInfo(velocity, color, Creature::bird, fly_velocity);
        }
        else if (choice == 1)
        {
            bool artiodactyl;
            cout << "Enter velocity, color, and artiodactyl (1 = Yes, 0 = No): ";
            cin >> velocity >> color >> artiodactyl;
            creature.setInfo(velocity, color, Creature::cattle, artiodactyl);
        }
        else if (choice == 2)
        {
            int iq;
            cout << "Enter velocity, color, and IQ level: ";
            cin >> velocity >> color >> iq;
            creature.setInfo(velocity, color, Creature::human, iq);
        }
        else
            cout << "Error occurred..." << endl;
    }
    void printAll(const Creature array[], int size)
    {
        for (int i = 0; i < size; ++i)
        {
            cout << "Creature " << i + 1 << ":" << endl;
            array[i].printFunc();
            cout << endl;
        }
    }
    void searchFunc(const Creature array[], int size, float velocity)
    {
        bool found = false;
        for (int i = 0; i < size; ++i)
        {
            if (array[i].velocity == velocity)
            {
                cout << "Found creature with velocity " << velocity << ":" << endl;
                cout << "It's creature with " << i + 1 << " index" << endl;
                array[i].printFunc();
                found = true;
            }
        }
        if (!found)
            cout << "No creature found with velocity " << velocity << endl;
    }
};