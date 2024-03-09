#include "ActivityLog.h"

ActivityLog::ActivityLog(std::string date, std::string typeOfActivity, double duration, std::string intensity) :
    date(date), typeOfActivity(typeOfActivity), duration(duration), intensity(intensity) {}
