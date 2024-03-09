#ifndef FITNESSTRACKER_H
#define FITNESSTRACKER_H

#include <vector>
#include "User.h"
#include "ActivityLog.h"

class FitnessTracker {
public:
    std::vector<User*> users;
    std::vector<ActivityLog> activityLogs;

    void trackActivity(ActivityLog& activity);
    void setGoal(User& user, Goal* goal);
    // Placeholder for additional methods
};

#endif // FITNESSTRACKER_H
