#include "User.h"

User::User(std::string name, int age, double weight, double height) : name(name), age(age), weight(weight), height(height) {}

void User::addActivity(const ActivityLog& activity) {
    activities.push_back(activity);
}

void User::addGoal(Goal* goal) {
    goals.push_back(goal);
}
