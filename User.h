#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "ActivityLog.h"
#include "Goal.h"

class User {
public:
    std::string name;
    int age;
    double weight;
    double height;
    std::vector<ActivityLog> activities;
    std::vector<Goal*> goals;

    User(std::string name, int age, double weight, double height);
    void addActivity(const ActivityLog& activity);
    void addGoal(Goal* goal);
};

#endif // USER_H
