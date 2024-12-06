#include <iostream>
#include <map>
#include <string>
#include <cmath>

float findClosestDate(const std::map<std::string, float>& dateMap, const std::string& target) {
    if (dateMap.empty()) {
        return 0.0f; // Handle empty map case
    }
    std::map<std::string, float>::const_iterator it = dateMap.lower_bound(target);
    return it->second;
}

int main() {
    // Sample map with date strings as keys
    std::map<std::string, float> dateMap;
    dateMap["2023-12-01"] = 1.0f;
    dateMap["2023-12-05"] = 3.0f;
    dateMap["2023-12-10"] = 9.0f;
    dateMap["2023-12-20"] = 9.5f;

    std::string target = "2023-12-04";
    float closestValue = findClosestDate(dateMap, target);

    std::cout << "Closest value to " << target << " is " << closestValue << std::endl;

    return 0;
}