#include <print>
#include <string>

class Vehicle
{
protected:
    std::string type;

private:
    std::string model;
    int wheels;
    int doors;
    int color; // 0 - black, 1 - red, 2 - blue, 3 - green, 4 - white

public:
    Vehicle(std::string _model, int _wheels, int _doors, int _color, std::string _type = "Vehicle")
        : type(std::move(_type)), model(std::move(_model)), wheels(_wheels), doors(_doors), color(_color)
    {
        std::print("{} : {} with {} wheels, {} doors and color of {}\n", type, model, wheels, doors, color);
    }
    auto get_type() const { return type; }
    auto get_doors() const { return doors; }
};

/* Starship uses constructrs from the bsae Vehicle class.
 */
class Starship : public Vehicle
{
public:
    using Vehicle::Vehicle;
};

/* Car can have aditional ifno about gear type.
 */
class Automobile : public Vehicle
{
private:
    bool has_automatic_gear{false};

public:
    Automobile(std::string _model, int _wheels, int _doors, int _color, bool _has_automatic_gear,
               std::string _type = "Automobile")
        : Vehicle(_model, _wheels, _doors, _color, _type), has_automatic_gear(_has_automatic_gear)
    {
        std::print("  Does it have automatic gear? {}\n", has_automatic_gear ? "Yes, it has!" : "No, it hasn't.");
    }
};

/* Bike can have gear or not.
 */
class Bike : public Vehicle
{
private:
    bool has_gears{false};

public:
    Bike(std::string _model, int _color, bool _has_gears) : Vehicle(_model, 2, 0, _color, "Bike"), has_gears(_has_gears)
    {
        std::print("  Does it have gears? {}\n", has_gears ? "Yes, it has!" : "No, it hasn't.");
    }
    Bike(std::string _model, bool _has_gears) : Bike(_model, 1, _has_gears) {}
};

/* Base abstract class for the engine kind.
 */
class Engine
{
public:
    virtual auto start_engine() const -> std::string = 0;
};

/* Diesel engine.
 */
class Diesel : public Engine
{
};

/* Gasoline engine.
 */
class Gasoline : public Engine
{
};

/* Electric engine.
 */
class Electric : public Engine
{
};

class Truck : public Automobile, public Diesel
{
};

class Car : public Automobile, public Gasoline
{
};

class ElectricCar : public Automobile, public Electric
{
};

class HybridCar : public Car, public ElectricCar
{
};

/*
 * Dla kazdego zadania przypisana jest jedna dyrektywa preprocesora. Zmień jej wartosć z 0 na 1 aby ją aktywować.
 * Następnie wykonaj odpowiednie zadania.
 */

/* Zadanie 1
 * Zaimplementuj brakujące funkcje i konstruktory. Zapoznaj się z błędami, jakie pokazuje kompilator aby uzyskać
 * wskazówki.
 */
#define ENABLE_TASK_1 0

/* Task 2
 * Implement functions allowing code to compile.
 */
#define ENABLE_TASK_2 0

auto runime_assert_msg(auto given, auto expected, auto line) -> void
{
    if (given != expected)
    {
        std::print("Abort at line {} with {} != {}\n", line, given, expected);
        abort();
    }
}

int main()
{
    Vehicle v1("Unknown", 4, 4, 0);
    runime_assert_msg(v1.get_type(), "Vehicle", __LINE__);

    Starship s1("USS Enterprise NX-01", 0, 0, 0);
    runime_assert_msg(s1.get_type(), "Vehicle", __LINE__);

    Automobile a1("Classic car", 4, 2, 1, true);
    runime_assert_msg(a1.get_type(), "Automobile", __LINE__);

    Bike b1("Gazelle Arroyo C5", 2);
    runime_assert_msg(b1.get_type(), "Bike", __LINE__);

    runime_assert_msg(v1.get_doors(), 4, __LINE__);
    runime_assert_msg(b1.get_doors(), 0, __LINE__);

#if ENABLE_TASK_1
    Truck truck_1("MAN TGX", 16, 2, 4);
    runime_assert_msg(truck_1.get_type(), "Truck", __LINE__);
    runime_assert_msg(truck_1.get_doors(), 2, __LINE__);
    runime_assert_msg(truck_1.get_wheels(), 16, __LINE__);
    runime_assert_msg(truck_1.get_color(), 4, __LINE__);
#endif

#if ENABLE_TASK_2
    ElectricCar electric_car_1("Tesla S", 4, 16, 4);
#endif
}
