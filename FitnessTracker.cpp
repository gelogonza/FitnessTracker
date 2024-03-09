#include "FitnessTracker.h"
#include <iostream>

// Add a User to the FitnessTracker
void FitnessTracker::addUser(User* user) {
    users.push_back(user);
}

// Track an activity for a user
void FitnessTracker::trackActivity(User* user, const ActivityLog& activity) {
    // Assuming User class has a method to add an ActivityLog to its activity logs
    for (auto& usr : users) {
        if (usr == user) {
            usr->addActivity(activity);
            std::cout << "Activity tracked for user: " << user->name << std::endl;
            return;
        }
    }
    std::cout << "User not found." << std::endl;
}

// Set a goal for a user
void FitnessTracker::setGoal(User* user, Goal* goal) {
    // Assuming User class has a method to add a Goal to its goals
    for (auto& usr : users) {
        if (usr == user) {
            usr->addGoal(goal);
            std::cout << "Goal set for user: " << user->name << std::endl;
            return;
        }
    }
    std::cout << "User not found." << std::endl;
}

// Placeholder for monitoring progress
void FitnessTracker::monitorProgress(User* user) {
    // Future implementation
}

// Placeholder for providing insights
void FitnessTracker::provideInsights(User* user) {
    // Future implementation
}
