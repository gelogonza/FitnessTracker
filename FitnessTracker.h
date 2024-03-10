#ifndef FITNESSTRACKER_H
#define FITNESSTRACKER_H

#include <vector>
#include <string>
#include "User.h" // Ensure this includes the User class definition
#include "Activitylog.h" // Include if using ActivityLog directly
#include "Goal.h" // Include if using Goal directly

class FitnessTracker {
public:
    std::vector<User*> users; // Holds the list of users

    FitnessTracker(); // Constructor
    ~FitnessTracker(); // Destructor to deallocate memory used by users
    void loadUsers(const std::string& filename); // Loads users from a file
    void addUser(User* user); // Adds a new user to the list
    User* selectUser(); // Allows selection of a user from the list
    void trackActivity(User* user, const ActivityLog& activity); // Track an activity for a user
    void setGoal(User* user, Goal* goal); // Set a goal for a user
    void monitorProgress(User* user); // Monitor progress of a user
    void provideInsights(User* user); // Provide insights for a user
};

#endif // FITNESSTRACKER_H
