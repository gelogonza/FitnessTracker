#include "User.h"

User::User(std::string name, int age, double initialWeight) 
    : name(name), age(age), initialWeight(initialWeight), currentWeight(initialWeight) {}

void User::addActivity(const ActivityLog& activity) {
    activities.push_back(activity);
}

void User::addGoal(Goal* goal) {
    goals.push_back(goal);
}

void User::updateWeight(double newWeight) {
    this->currentWeight = newWeight;
}
