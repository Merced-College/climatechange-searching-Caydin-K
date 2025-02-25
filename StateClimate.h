#ifndef STATECLIMATE_H
#define STATECLIMATE_H

#include <iostream>
#include <string>

class StateClimate {
private:
    std::string stateName;
    int fips;
    int year;
    double temp;
    double tempc;

public:
    // Constructor
    StateClimate(std::string state, int f, int y, double t, double tc);

    // Getters
    std::string getStateName() const;
    int getFips() const;
    int getYear() const;
    double getTemp() const;
    double getTempC() const;

    // Display function
    void display() const;

    // Convert to lowercase for case-insensitive search
    static std::string toLower(const std::string& str);
};

// Sorting function for `std::sort`
bool compareByStateName(const StateClimate& a, const StateClimate& b);

#endif // STATECLIMATE_H
