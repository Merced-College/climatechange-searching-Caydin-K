#include "StateClimate.h"
#include <algorithm>
#include <cctype>

// Constructor
StateClimate::StateClimate(std::string state, int f, int y, double t, double tc)
    : stateName(state), fips(f), year(y), temp(t), tempc(tc) {}

// Getters
std::string StateClimate::getStateName() const { return stateName; }
int StateClimate::getFips() const { return fips; }
int StateClimate::getYear() const { return year; }
double StateClimate::getTemp() const { return temp; }
double StateClimate::getTempC() const { return tempc; }

// Display function
void StateClimate::display() const {
    std::cout << "State: " << stateName
              << ", FIPS: " << fips
              << ", Year: " << year
              << ", Temp (F): " << temp
              << ", Temp (C): " << tempc
              << std::endl;
}

// Convert string to lowercase
std::string StateClimate::toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Sorting function
bool compareByStateName(const StateClimate& a, const StateClimate& b) {
    return StateClimate::toLower(a.getStateName()) < StateClimate::toLower(b.getStateName());
}
