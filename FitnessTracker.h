#ifndef FITNESSTRACKER_H
#define FITNESSTRACKER_H

#include <vector>
#include "User.h" // Make sure this includes the User class definition
#include "ActivityLog.h" // Include if using ActivityLog directly
#include "Goal.h" // Include if using Goal directly

class FitnessTracker {
public:
    std::vector<User*> users; // Assuming you manage users in the tracker

    void addUser(User* user); // Correctly declare the addUser method
    void trackActivity(User* user, const ActivityLog& activity); // Ensure parameters match intended usage
    void setGoal(User* user, Goal* goal); // Ensure parameters match intended usage
    void monitorProgress(User* user); // Declare if this functionality is desired
    void provideInsights(User* user); // Declare if this functionality is desired
};

#endif // FITNESSTRACKER_H
