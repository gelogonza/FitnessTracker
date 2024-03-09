#include "FitnessTracker.h"
#include <iostream>

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
    // More personalized insights based on activity patterns can be provided here
}

