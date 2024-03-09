#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "ActivityLog.h" // Include if ActivityLog is used within User
#include "Goal.h"        // Include if Goal is used within User

class User {
public:
    std::string name;
    int age;
    double initialWeight;
    double currentWeight;
    std::vector<ActivityLog> activities;
    std::vector<Goal*> goals;

    User(std::string name, int age, double initialWeight);
    void addActivity(const ActivityLog& activity);
    void addGoal(Goal* goal);
    void updateWeight(double newWeight); // Method to update current weight
};

#endif // USER_H
