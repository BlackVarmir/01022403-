#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;
class Monster {
public:
    string name;
    int health;
    int damage;
    Monster() {

    }
};
class Orc : public Monster {
public:
    Orc() {
        this->name = "Орк";
        this->health = 100;
        this->damage = 20;
    }
};

class Trol : public Monster {
public:
    Trol() {
        this->name = "Троль";
        this->health = 90;
        this->damage = 15;
    }
};

class Zombie : public Monster {
public:
    Zombie() {
        this->name = "Зомбі";
        this->health = 80;
        this->damage = 10;
    }
};

class Goblin : public Monster {
public:
    Goblin() {
        this->name = "Гоблін";
        this->health = 70;
        this->damage = 5;
    }
};

template <typename T>
void printMonster(T& name) {
    cout << "Монстр: " << name.name << endl;
    cout << "Здоровья: " << name.health << endl;
    cout << "Сила: " << name.damage << endl;
}

void MySortMin(vector <Monster>& name) {
    for (int i = 0; i < name.size(); i++) {
        for (auto j = i + 1; j < name.size(); j++) {
            if (name[i].health > name[j].health) {
                swap(name[i], name[j]);
            }
            else continue;
        }
    }
}

void MySortMax(vector <Monster>& name) {
    for (int i = 0; i < name.size(); i++) {
        for (auto j = i + 1; j < name.size(); j++) {
            if (name[i].health < name[j].health) {
                swap(name[i], name[j]);
            }
            else continue;
        }
    }
}

void printVec(vector <Monster>& name) {
    for (auto i = name.begin(); i != name.end(); i++) {
        cout << endl << "Монстр: " << i->name << endl;
        cout << "Здоровья: " << i->health << endl;
        cout << "Сила: " << i->damage << endl;
    }
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector <Monster> vec;
    Orc орк;
    Trol троль;
    Zombie зомбі;
    Goblin гоблін;
    vec.push_back(орк);
    vec.push_back(троль);
    vec.push_back(зомбі);
    vec.push_back(гоблін);
    cout << "Монстри, які є в наявності:" << endl;
    printVec(vec);
    while (true) {
        cout << "Виберіть з якого монстра необхідно почати:" << endl;
        cout << "1 - Найсильніший монстр" << endl;
        cout << "2 - Найслабкіший монстр" << endl;
        cout << "0 - вихід" << endl;
        int x;
        cin >> x;
        switch (x) {
        case 1: {
            cout << "Монстр готовий до бою:" << endl;
            MySortMax(vec);
            printMonster(vec[0]);
        }
        case 2: {
            cout << "Монстр готовий до бою:" << endl;
            MySortMin(vec);
            printMonster(vec[0]);
        }
        }
        if (x == 0) {
            break;
        }
    }
}