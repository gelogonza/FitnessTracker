#include <iostream>
#include "FitnessTracker.h"

void displayMainMenu() {
    std::cout << "Fitness Tracker and Goal Setter\n";
    std::cout << "1. Log Activity\n";
    std::cout << "2. Set Goal\n";
    std::cout << "3. View Progress\n";
    std::cout << "4. Exit\n";
    std::cout << "Select an option: ";
}

int getUserSelection() {
    int selection;
    std::cin >> selection;
    return selection;
}

void logActivity(FitnessTracker& tracker, User* currentUser) {
    std::string date, typeOfActivity, intensity;
    double duration, caloriesBurned, distance;
    
    std::cout << "Enter activity date (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "Enter type of activity: ";
    std::cin >> typeOfActivity;
    std::cout << "Enter duration (in minutes): ";
    std::cin >> duration;
    std::cout << "Enter intensity (Low, Medium, High): ";
    std::cin >> intensity;
    std::cout << "Enter calories burned: ";
    std::cin >> caloriesBurned;
    std::cout << "Enter distance (in kilometers): ";
    std::cin >> distance;

    ActivityLog newActivity(date, typeOfActivity, duration, intensity, caloriesBurned, distance);
    currentUser->addActivity(newActivity);

    std::cout << "Activity logged successfully!\n";
}

void setGoal(FitnessTracker& tracker, User* currentUser) {
    double targetWeight;
    int targetStepCount, targetWorkoutFrequency;
    // Assuming goals can be weight, step count, and workout frequency for simplicity

    std::cout << "Enter target weight (kg): ";
    std::cin >> targetWeight;
    std::cout << "Enter daily target step count: ";
    std::cin >> targetStepCount;
    std::cout << "Enter weekly target workout frequency: ";
    std::cin >> targetWorkoutFrequency;

    Goal* newGoal = new Goal(targetWeight, targetStepCount, targetWorkoutFrequency);
    currentUser->addGoal(newGoal);

    std::cout << "Goal set successfully!\n";
}

void viewProgress(const User& user) {
    double totalCaloriesBurned = 0.0;
    double totalWeightChange = user.initialWeight - user.currentWeight; // Assume these properties exist
    // Calculate total calories burned from activities
    for (const auto& activity : user.activities) {
        totalCaloriesBurned += activity.caloriesBurned; // Assume caloriesBurned is a property of ActivityLog
    }

    std::cout << "Progress Report for " << user.name << ":\n";
    std::cout << "Total Calories Burned: " << totalCaloriesBurned << "\n";
    std::cout << "Weight Change: " << totalWeightChange << " kg\n";

    // Compare against goals
    for (const auto& goal : user.goals) {
        if (goal->targetCalorieIntake > 0) {
            std::cout << "Target Calorie Intake: " << goal->targetCalorieIntake << " - ";
            if (totalCaloriesBurned >= goal->targetCalorieIntake) {
                std::cout << "Goal met or exceeded!\n";
            } else {
                std::cout << "Below goal.\n";
            }
        }

        if (goal->targetWeight > 0) {
            std::cout << "Target Weight: " << goal->targetWeight << " kg - ";
            if (totalWeightChange <= (user.initialWeight - goal->targetWeight)) {
                std::cout << "Goal met or on track!\n";
            } else {
                std::cout << "Above goal.\n";
            }
        }
    }
}


int main() {
    FitnessTracker tracker;
    bool runApp = true;

    while (runApp) {
        displayMainMenu();
        int selection = getUserSelection();

        switch (selection) {
            case 1:
                logActivity(tracker);
                break;
            case 2:
                setGoal(tracker);
                break;
            case 3:
                viewProgress(tracker);
                break;
            case 4:
                std::cout << "Exiting application.\n";
                runApp = false;
                break;
            default:
                std::cout << "Invalid selection. Please try again.\n";
        }
    }

    return 0;
}
