#include "ActivityLog.h"

ActivityLog::ActivityLog(std::string date, std::string typeOfActivity, double duration, std::string intensity, double caloriesBurned, double distance)
: date(date), typeOfActivity(typeOfActivity), duration(duration), intensity(intensity), caloriesBurned(caloriesBurned), distance(distance) {}
