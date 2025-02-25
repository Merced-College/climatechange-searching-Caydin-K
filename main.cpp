#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "StateClimate.h"

// Function prototypes
int binarySearch(const std::vector<StateClimate>& states, const std::string& query);
void searchStates(const std::vector<StateClimate>& states);

int main() {
    std::vector<StateClimate> climateData;
    std::ifstream file("climdiv_state_year.csv");

    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string stateName;
        int fips, year;
        double temp, tempc;
        char comma;

        // Read CSV values
        std::getline(ss, stateName, ',');  // Read state name
        ss >> fips >> comma >> year >> comma >> temp >> comma >> tempc;

        // Add entry to vector
        climateData.emplace_back(stateName, fips, year, temp, tempc);
    }

    file.close();

    // Sort the data by state name
    std::sort(climateData.begin(), climateData.end(), compareByStateName);

    // Start user search loop
    searchStates(climateData);

    std::cout << "Goodbye!\n";
    return 0;
}

// Binary search function
int binarySearch(const std::vector<StateClimate>& states, const std::string& query) {
    int left = 0, right = states.size() - 1;
    std::string queryLower = StateClimate::toLower(query);

    while (left <= right) {
        int mid = left + (right - left) / 2;
        std::string midStateLower = StateClimate::toLower(states[mid].getStateName());

        if (midStateLower == queryLower) {
            return mid; // Found
        } else if (midStateLower < queryLower) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }

    return -1; // Not found
}

// Search loop for user input
void searchStates(const std::vector<StateClimate>& states) {
    std::string input;
    
    while (true) {
        std::cout << "\nEnter a state name to search (or 'exit' to quit): ";
        std::getline(std::cin, input);

        // Exit condition
        if (StateClimate::toLower(input) == "exit") {
            break;
        }

        // Perform binary search
        int index = binarySearch(states, input);

        if (index != -1) {
            states[index].display();
        } else {
            std::cout << "State not found. Please try again.\n";
        }
    }
}
