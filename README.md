# Fitness Tracker and Goal Setter - README

## Overview
The **Fitness Tracker and Goal Setter** is a console-based application designed to help users log physical activities, set fitness goals, and track their progress. It provides a simple interface to input data, monitor goals, and generate progress reports.

---

## Features
1. **Log Activity**  
   Users can log physical activities, specifying details such as date, type of activity, duration, intensity, calories burned, and distance.
   
2. **Set Goals**  
   Users can set personalized fitness goals, including target weight, daily step count, and weekly workout frequency.

3. **View Progress**  
   Generates a progress report that includes total calories burned, weight changes, and an assessment of goal achievements.

4. **User Management**  
   Supports multiple users, allowing each user to track their individual progress and goals.

---

## Technical Details
### Core Functionalities
- **Activity Logging**: Users input detailed activity data stored in an `ActivityLog` structure.
- **Goal Management**: Users create and manage fitness goals stored in a `Goal` structure.
- **Progress Report**: Provides insights into caloric burn, weight changes, and goal tracking.

### User Data
- User data is loaded from a file (`userdata.txt`) at runtime.
- Each user has:
  - **Name**
  - **Initial Weight**
  - **Current Weight**
  - A list of activities
  - A list of goals

### Dependencies
- **FitnessTracker.h**: Header file containing class definitions for `FitnessTracker`, `User`, `ActivityLog`, and `Goal`.

---

## How to Use
1. Run the program in a C++ environment.
2. Upon startup, the application loads user data from `userdata.txt`.
3. Use the main menu to select an action:
   - `1`: Log a physical activity.
   - `2`: Set a new fitness goal.
   - `3`: View progress reports.
   - `4`: Exit the application.
4. Follow on-screen prompts to input necessary data.

---

## Example Workflow
### Log Activity
1. Select option `1` from the menu.
2. Input details such as date, activity type, duration, intensity, calories burned, and distance.
3. The activity is added to the user's activity log.

### Set Goals
1. Select option `2` from the menu.
2. Input target weight, daily step count, and weekly workout frequency.
3. The goal is added to the user's profile.

### View Progress
1. Select option `3` from the menu.
2. View a detailed progress report, including total calories burned and weight change.
3. Compare current progress against set goals.

---

## Compilation and Execution
### Prerequisites
- C++ Compiler (e.g., GCC, Clang)
- Standard C++ Library

### Compile
```bash
g++ FitnessTrackerMain.cpp -o FitnessTracker
```

### Run
```bash
./FitnessTracker
```

---

## Future Improvements
1. **Data Persistence**: Enable saving updates to `userdata.txt` for persistent storage.
2. **Enhanced Reporting**: Add graphical progress visualization.
3. **Activity Types**: Expand the list of predefined activities and allow custom activity creation.
4. **Mobile Integration**: Create a mobile app for on-the-go tracking.

---

## Author
**[Your Name]**  
_Last Updated_: [Date]  
_For questions or improvements, feel free to contribute._  

---

Start achieving your fitness goals today with the Fitness Tracker and Goal Setter! 💪
