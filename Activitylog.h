#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include <string>

class ActivityLog {
public:
    std::string date;
    std::string typeOfActivity;
    double duration; // Duration of the activity in minutes
    std::string intensity; // Intensity of the activity (e.g., Low, Medium, High)
    double caloriesBurned; // Calories burned during the activity
    double distance; // Distance covered during the activity, if applicable

    ActivityLog(std::string date, std::string typeOfActivity, double duration, std::string intensity, double caloriesBurned, double distance);
};

#endif // ACTIVITYLOG_H
