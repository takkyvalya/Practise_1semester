#include <iostream>
#include <vector>

class Animal {
private:
    std::string a_type;
    std::string a_name;
    int a_age;
    int a_number_aviary;
public:
    Animal(std::string type, std::string name, int age) 
    {
        a_type = type;
        a_name = name;
        a_age = age;
    }

    ~Animal() { }

    std::string Name()
    {
        return a_name;
    }

    void SetAnimal(int number_aviary) {
        a_number_aviary = number_aviary;
    }

    int NumberAviary() 
    {
        return a_number_aviary;
    }
};

class Zoo {
private:
    std::string z_Name;
    int z_aviary;
    std::vector<Animal*> z_animals;

public:
    Zoo(std::string name, int aviary) 
    {
        z_Name = name;
        z_aviary = aviary;
    }

    ~Zoo() { }

    void AddAnimal(Animal*& animal)
    {
        z_animals.push_back(animal);	
    }

    void PrintAnimal()
    {
        for (size_t i = 0; i < z_animals.size(); i++)
            std::cout << z_animals[i]->Name() << std::endl;
    }

    void Put_Animal_in_cage(int n, Animal*& animal)
    {
        animal->SetAnimal(n);
    }

    void Animals_in_cage(int n) 
    {
        std::cout << n << " aviary: ";
        for (size_t i = 0; i < z_animals.size(); i++)
            if (z_animals[i]->NumberAviary() == n)
                std::cout << z_animals[i]->Name() << ", ";
        std::cout << std::endl;
    }

};

int main()
{
    setlocale(LC_ALL, "RUS");

    Zoo zoo("Safari", 3);

    Animal* animal_1 = new Animal("line", "Jack", 2);
    zoo.AddAnimal(animal_1);
    zoo.Put_Animal_in_cage(1, animal_1);

    Animal* animal_2 = new Animal("monkye", "Liza", 2);
    zoo.AddAnimal(animal_2);
    zoo.Put_Animal_in_cage(2, animal_2);

    Animal* animal_3 = new Animal("line", "Kitten", 2);
    zoo.AddAnimal(animal_3); 
    zoo.Put_Animal_in_cage(1, animal_3);

    zoo.Animals_in_cage(1);

    zoo.Animals_in_cage(2);


    zoo.PrintAnimal();

    return 0;
}
