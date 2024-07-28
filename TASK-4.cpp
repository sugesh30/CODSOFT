#include <iostream>
#include <string>
using namespace std;

static int totalTasks, deleteCount = 0, completedTasks[10], index;
static string taskList[6];
int taskCounter = 0, taskNumber, taskIndex;
int i;

void addTasks() {
    cout << "Enter how many tasks to add:" ;
    cin >> totalTasks;
    cin.ignore();
    for (i = 0; i < totalTasks; i++) {
        cout << "Enter task " << i + 1 << " :";
        getline(cin, taskList[i]);
    }
}

void includeTask() {
    if (deleteCount >= 1) {
        cout << "Enter the new task to add" << endl;
        getline(cin, taskList[totalTasks + taskCounter - deleteCount - 1]);
    } else {
        cout << "Enter the new task to add" << endl;
        getline(cin, taskList[(totalTasks - 1) + taskCounter]);
    }
}

void viewTasks() {
    if (totalTasks > 0) {
        for (int j = 0; j < totalTasks + taskCounter - deleteCount; j++) {
            cout << taskList[j] << endl;
        }
    } else {
        cout << "Nothing stored in task list" << endl;
    }
}

void removeTask() {
    if (totalTasks > 0) {
        deleteCount++;
        cout << "Enter the number of the task to remove" << endl;
        cin >> taskNumber;
        for (taskIndex = 0; taskIndex < totalTasks + taskCounter - deleteCount; taskIndex++) {
            if (taskIndex >= taskNumber - 1) {
                string temp = taskList[taskIndex];
                taskList[taskIndex] = taskList[taskIndex + 1];
                taskList[taskIndex + 1] = temp;
            }
        }
    } else {
        cout << "Nothing stored in task list" << endl;
    }
}

void markTaskCompleted() {
    if (totalTasks > 0) {
        cout << "Enter the number of the completed task" << endl;
        cin >> taskNumber;
        completedTasks[taskNumber - 1] = 1;
        cout << "To see status enter [show] or else press [no]" << endl;
        string showStatus;
        cin >> showStatus;
        if (showStatus == "show") {
            for (int j = 0; j < totalTasks + taskCounter - deleteCount; j++) {
                if (completedTasks[j] == 1) {
                    cout << taskList[j] << " is completed" << endl;
                } else {
                    cout << taskList[j] << " is not completed yet" << endl;
                }
            }
        }
    } else {
        cout << "Nothing stored in task list" << endl;
    }
}

int main() {
    int run = 1;
    int option;
    while (run) {
        cout << "\nTo perform below tasks enter corresponding task number" << endl << endl;
        cout << "1. To add tasks enter 1" << endl;
        cout << "2. To view tasks enter 2" << endl;
        cout << "3. To remove task enter 3" << endl;
        cout << "4. To mark task as completed enter 4" << endl;
        cout << "5. To add task to existing task list enter 5" << endl;
        cout << "6. To end the process enter 6" << endl << endl;
        cin >> option;
        cin.ignore();
        switch (option) {
            case 1:
                addTasks();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                markTaskCompleted();
                break;
            case 5:
                taskCounter++;
                includeTask();
                break;
            case 6:
                run = 0;
                break;
            default:
                cout << "INVALID OPTION ";
        }
    }
    return 0;
}