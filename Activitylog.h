#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include <string>

class ActivityLog {
public:
    std::string date;
    std::string typeOfActivity;
    double duration;
    std::string intensity;

    ActivityLog(std::string date, std::string typeOfActivity, double duration, std::string intensity);
};

#endif // ACTIVITYLOG_H
