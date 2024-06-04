#include <print>
#include <string>

class Vehicle
{
private:
    std::string model;
    int wheels;
    int doors;
    int color; // 0 - black, 1 - red, 2 - blue, 3 - green, 4 - white

public:
    Vehicle(std::string _model, int _wheels, int _doors, int _color)
        : model(std::move(_model)), wheels(_wheels), doors(_doors), color(_color)
    {
        std::print("{} with {} wheels, {} doors and color of {}\n", model, wheels, doors, color);
    }
    auto get_doors() const { return doors; }
};

/* Starship uses constructrs from the base Vehicle class.
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
    bool automatic_gear{false};

public:
    Automobile(std::string _model, int _wheels, int _doors, int _color, bool _automatic_gear)
        : Vehicle(_model, _wheels, _doors, _color), automatic_gear(_automatic_gear)
    {
        std::print("  Does it have automatic gear? {}\n", automatic_gear ? "Yes, it has!" : "No, it hasn't.");
    }

    auto has_automatic_gear() const { return automatic_gear; }
};

/* Bike can have gear or not.
 */
class Bike : public Vehicle
{
private:
    bool gears{false};

public:
    Bike(std::string _model, int _color, bool _gears) : Vehicle(_model, 2, 0, _color), gears(_gears)
    {
        std::print("  Does it have gears? {}\n", gears ? "Yes, it has!" : "No, it hasn't.");
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

/* Zadanie 2
 * Zaimplementuj brakujące funkcje i konstruktory. Zapoznaj się z błędami, jakie pokazuje kompilator aby uzyskać
 * wskazówki.
 */
#define ENABLE_TASK_2 0

/* Zadanie 3
 * Zaimplementuj brakujące funkcje i konstruktory. Zapoznaj się z błędami, jakie pokazuje kompilator aby uzyskać
 * wskazówki.
 */
#define ENABLE_TASK_3 0

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

    Starship s1("USS Enterprise NX-01", 0, 0, 0);

    Automobile a1("Automobile concept", 4, 2, 1, true);

    Bike b1("Gazelle Arroyo C5", 2);

    runime_assert_msg(v1.get_doors(), 4, __LINE__);
    runime_assert_msg(b1.get_doors(), 0, __LINE__);

    Car c1("Classic car", 4, 2, 1, true);

#if ENABLE_TASK_1
    Truck truck_1("MAN TGX", 16, 2, 4);
    runime_assert_msg(truck_1.get_doors(), 2, __LINE__);
    runime_assert_msg(truck_1.get_wheels(), 16, __LINE__);
    runime_assert_msg(truck_1.get_color(), 4, __LINE__);
#endif

#if ENABLE_TASK_2
    ElectricCar electric_car_1("Tesla S", 4, 4);
    runime_assert_msg(electric_car_1.get_doors(), 4, __LINE__);
    runime_assert_msg(electric_car_1.get_wheels(), 4, __LINE__);
    runime_assert_msg(electric_car_1.get_color(), 4, __LINE__);
    runime_assert_msg(electric_car_1.has_automatic_gear(), true, __LINE__);
#endif

#if ENABLE_TASK_3
    HybridCar hybrid_1("Hybryda", 4, 4);
    // runime_assert_msg(hybrid_1.get_doors(), 4, __LINE__);
    // runime_assert_msg(hybrid_1.get_wheels(), 4, __LINE__);
    // runime_assert_msg(hybrid_1.get_color(), 4, __LINE__);
    // runime_assert_msg(hybrid_1.has_automatic_gear(), true, __LINE__);
#endif
}
