#include <string>
#include <vector>
#include <iostream>

#pragma region Creatures

class GenericCreature
{
protected:
    std::string _name;
public:
    void eat() const { std::cout << _name << " is eating" << std::endl; }
};

class OceanCreature : public GenericCreature
{
public:
    void swim() const { std::cout << _name << " swimming" << std::endl; }
};


class Amphibious : public OceanCreature
{
public:
    void walk() const { std::cout << _name << " walking" << std::endl; }
};


class TerrestrialCreature : public Amphibious
{
public:
protected:
    using Amphibious::swim;
};


class Bird : public TerrestrialCreature
{
public:
    void fly() const { std::cout << _name << " flying" << std::endl; }
protected:
    using TerrestrialCreature::swim;
};


class Waterfowl : public Bird
{
public:
    using Bird::swim;
    using Bird::walk;
};

#pragma endregion

#pragma region SpecificCreatures

class Carp : public OceanCreature
{
public:
    Carp() { _name = "Carp"; }
};

class ClownFish : public OceanCreature
{
public:
    ClownFish() { _name = "ClownFish"; }
};

class Alligator : public Amphibious
{
public:
    Alligator() { _name = "Alligator"; }
};

class Crocodile : public Amphibious
{
public:
    Crocodile() { _name = "Crocodile"; }
};

class Cat : public TerrestrialCreature
{
public:
    Cat() { _name = "Cat"; }
};

class Dog : public TerrestrialCreature
{
public:
    Dog() { _name = "Dog"; }
};

class Pigeon : public Bird
{
public:
    Pigeon() { _name = "Pigeon"; }
};

class Parrot : public Bird
{
public:
    Parrot() { _name = "Parrot"; }
};

class Seagull : public Waterfowl
{
public:
    Seagull() { _name = "Seagull"; }
};

class Duck : public Waterfowl
{
public:
    Duck() { _name = "Duck"; }
};

#pragma endregion

class ZooFactory
{
public:
    virtual OceanCreature*       ProduceOceanCreature()       = 0;
    virtual Amphibious*          ProduceAmphibious()          = 0;
    virtual TerrestrialCreature* ProduceTerrestrialCreature() = 0;
    virtual Bird*                ProduceBird()                = 0;
    virtual Waterfowl*           ProduceWaterfowl()           = 0;
};

class Zoo1 : public ZooFactory
{
    virtual OceanCreature*       ProduceOceanCreature()       { return new Carp(); }
    virtual Amphibious*          ProduceAmphibious()          { return new Crocodile(); }
    virtual TerrestrialCreature* ProduceTerrestrialCreature() { return new Cat(); }
    virtual Bird*                ProduceBird()                { return new Pigeon(); }
    virtual Waterfowl*           ProduceWaterfowl()           { return new Duck(); }
};

class Zoo2 : public ZooFactory
{
    virtual OceanCreature*       ProduceOceanCreature()       { return new ClownFish(); }
    virtual Amphibious*          ProduceAmphibious()          { return new Alligator(); }
    virtual TerrestrialCreature* ProduceTerrestrialCreature() { return new Dog(); }
    virtual Bird*                ProduceBird()                { return new Parrot(); }
    virtual Waterfowl*           ProduceWaterfowl()           { return new Seagull(); }
};

int main()
{
    ZooFactory* zoo1 = new Zoo1();
    ZooFactory* zoo2 = new Zoo2();

    std::vector<GenericCreature*> horde;
    horde.push_back(zoo1->ProduceOceanCreature());
    horde.push_back(zoo1->ProduceAmphibious());
    horde.push_back(zoo1->ProduceTerrestrialCreature());
    horde.push_back(zoo1->ProduceBird());
    horde.push_back(zoo1->ProduceWaterfowl());
    horde.push_back(zoo2->ProduceOceanCreature());
    horde.push_back(zoo2->ProduceAmphibious());
    horde.push_back(zoo2->ProduceTerrestrialCreature());
    horde.push_back(zoo2->ProduceBird());
    horde.push_back(zoo2->ProduceWaterfowl());

    for (auto iter = horde.begin(); iter != horde.end(); iter++)
        (*iter)->eat();

    return 0;
}