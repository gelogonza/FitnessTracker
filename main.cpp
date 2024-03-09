#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

// Forward declarations
class Activity;
class User;
class ActivityLog;
class Goal;
class FitnessTracker;

// Class representing a fitness activity
class Activity {
public:
    std::string name;
    int duration_minutes;
    int intensity; // Assuming some scale for intensity

    Activity(const std::string& name, int duration, int intensity) : name(name), duration_minutes(duration), intensity(intensity) {}
};

// Class representing a user
class User {
public:
    std::string name;
    int age;
    double weight_kg;
    double height_cm;
    std::vector<Goal> goals;

    User(const std::string& name, int age, double weight, double height) : name(name), age(age), weight_kg(weight), height_cm(height) {}

    // Method to add a goal
    void addGoal(const Goal& goal) {
        goals.push_back(goal);
    }
};

// Class representing an activity log
class ActivityLog {
public:
    std::vector<Activity> activities;

    // Method to add an activity
    void addActivity(const Activity& activity) {
        activities.push_back(activity);
    }
};

// Class representing a fitness goal
class Goal {
public:
    double target_weight_kg;
    int target_step_count;
    int target_workout_frequency;

    Goal(double weight, int steps, int frequency) : target_weight_kg(weight), target_step_count(steps), target_workout_frequency(frequency) {}
};

// Class representing the fitness tracker
class FitnessTracker {
public:
    std::vector<User> users;
    std::vector<ActivityLog> activityLogs;

    // Method to add a user
    void addUser(const User& user) {
        users.push_back(user);
    }

    // Method to log an activity for a user
    void logActivity(const User& user, const Activity& activity) {
        // Find the user in the users vector
        for (auto& u : users) {
            if (u.name == user.name) {
                // Add activity to the user's activity log
                ActivityLog log;
                log.addActivity(activity);
                activityLogs.push_back(log);
                return;
            }
        }
        // If user is not found
        throw std::invalid_argument("User not found!");
    }

    // Method to save user data to a file
    void saveUserData(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& user : users) {
                file << "Name: " << user.name << ", Age: " << user.age << ", Weight: " << user.weight_kg << ", Height: " << user.height_cm << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Error: Unable to open file for writing!" << std::endl;
        }
    }

    // Method to load user data from a file
    void loadUserData(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                // Parse each line to extract user data
                // Example: Name: John, Age: 25, Weight: 70.5, Height: 175.0
                // Extract name, age, weight, and height
                // Create a User object and add it to the users vector
            }
            file.close();
        } else {
            std::cerr << "Error: Unable to open file for reading!" << std::endl;
        }
    }
};

int main() {
    // Create FitnessTracker object
    FitnessTracker tracker;

    // Add users
    User user1("John", 30, 75.0, 180.0);
    tracker.addUser(user1);

    // Define an activity
    Activity walk("Walking", 30, 5);

    // Log activity for a user
    tracker.logActivity(user1, walk);

    // Save user data to a file
    tracker.saveUserData("userdata.txt");

    // Load user data from a file
    tracker.loadUserData("userdata.txt");

    return 0;
}
