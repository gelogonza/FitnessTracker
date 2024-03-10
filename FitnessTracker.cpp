#include "FitnessTracker.h"
#include <fstream>
#include <sstream>
#include <iostream>

FitnessTracker::FitnessTracker() {
   
}

FitnessTracker::~FitnessTracker() {
    for (auto* user : users) {
        delete user; // Properly delete user objects to avoid memory leaks
    }
}

void FitnessTracker::loadUsers(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, token;
        int age = 0;
        double initialWeight = 0.0;
        getline(iss, name, ',');
        iss >> std::ws;
        getline(iss, token, ',');
        try {
            age = std::stoi(token);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument for age encountered: " << token << std::endl;
            continue; // Skip this user and move to the next line
        } catch (const std::out_of_range& e) {
            std::cerr << "Age out of range: " << token << std::endl;
            continue; // Skip this user and move to the next line
        }
        iss >> std::ws;
        getline(iss, token, ',');
        initialWeight = std::stod(token); // Assuming the weight is always valid double
        User* newUser = new User(name, age, initialWeight);
        users.push_back(newUser);
    }
    file.close();
}



void FitnessTracker::addUser(User* user) {
    users.push_back(user);
    std::cout << "User added: " << user->name << std::endl;
}

void FitnessTracker::trackActivity(User* user, const ActivityLog& activity) {
    for (auto& usr : users) {
        if (usr == user) {
            usr->addActivity(activity);
            std::cout << "Activity tracked for user: " << user->name << std::endl;
            return;
        }
    }
    std::cout << "User not found." << std::endl;
}

void FitnessTracker::setGoal(User* user, Goal* goal) {
    for (auto& usr : users) {
        if (usr == user) {
            usr->addGoal(goal);
            std::cout << "Goal set for user: " << user->name << std::endl;
            return;
        }
    }
    std::cout << "User not found." << std::endl;
}

void FitnessTracker::monitorProgress(User* user) {
    std::cout << "Progress for " << user->name << ":\n";
    // Example: Calculate total distance covered in all running activities
    double totalDistance = 0;
    for (const auto& activity : user->activities) {
        if (activity.typeOfActivity == "Running") {
            totalDistance += activity.distance; // Assuming distance is a member of ActivityLog
        }
    }
    std::cout << "Total Running Distance: " << totalDistance << " km\n";
    // Additional calculations and comparisons to goals can be done here
}

void FitnessTracker::provideInsights(User* user) {
    std::cout << "Insights for " << user->name << ":\n";
    // Example: Suggest more rest if high-intensity activities are frequent
    int highIntensityCount = 0;
    for (const auto& activity : user->activities) {
        if (activity.intensity == "High") {
            highIntensityCount++;
        }
    }
    if (highIntensityCount > 5) { // Arbitrary threshold
        std::cout << "Consider more rest days to prevent burnout.\n";
    }
    // More personalized insights based on activity patterns can be provided here in case I want to expand this project later on
}

User* FitnessTracker::selectUser() {
    if (users.empty()) {
        std::cout << "No users available." << std::endl;
        return nullptr;
    }
    
    std::cout << "Select a user by number:" << std::endl;
    for (size_t i = 0; i < users.size(); ++i) {
        std::cout << i + 1 << ": " << users[i]->name << std::endl;
    }

    size_t choice;
    std::cin >> choice;
    
    // Validate input
    if (choice < 1 || choice > users.size()) {
        std::cout << "Invalid selection." << std::endl;
        return nullptr;
    }

    // Return the selected user
    return users[choice - 1];
}
