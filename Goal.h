#ifndef GOAL_H
#define GOAL_H

class Goal {
public:
    double targetWeight;
    int targetStepCount;
    int targetWorkoutFrequency;
    double targetCalorieIntake;

    Goal(double targetWeight = 0, int targetStepCount = 0, int targetWorkoutFrequency = 0, double targetCalorieIntake = 0);
};

#endif // GOAL_H
