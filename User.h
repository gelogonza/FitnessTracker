#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Activitylog.h" 
#include "Goal.h"        
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
    void updateWeight(double newWeight); 
};

#endif // USER_H
