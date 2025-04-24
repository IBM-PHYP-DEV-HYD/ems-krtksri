#include "EDeque.H"
#include "XyzEmployeeIF.H"
#include "XyzEmployeeImpl.H"
#include "XyzEmployeeManager.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractEmployee.H"
#include "XyzInternEmployee.H"

#if 0
void XyzEmployeeImpl::generateRandomEmployeeDetails() {
    int year = getRandomNumber(1981, 1995);
    
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << getRandomNumber(1, 12);
    mDOB = std::to_string(year) + "-" + ss.str() + "-" ;
    ss.str("");
    ss << std::setw(2) << std::setfill('0') << getRandomNumber(1,28);
    mDOB += ss.str();

    mName = getRandomEmployeeName();
    mGender = getRandomEmpGender();
    mStatus = (EmpStatus)getRandomNumber(Active, Inactive);
    mEmpId = getRandomEmpID(mType);

    year = getRandomNumber(year+20, 2025);
    mDOJ = std::to_string(year) + "-";

    ss.str("");
    ss << std::setw(2) << std::setfill('0') << getRandomNumber(1, 12);
    mDOJ += ss.str() + "-";

    ss.str("");
    ss << std::setw(2) << std::setfill('0') << getRandomNumber(1,28);
    mDOJ += ss.str();
}
#endif

int DisplayMainMenu() {
    int choice = -1;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "|                 Employee Management System              |" <<std::endl;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "|               1. Add an Employee                        |" <<std::endl;
    std::cout << "|               2. Remove an Employee                     |" <<std::endl;
    std::cout << "|               3. Get Employee Details                   |" <<std::endl;
    std::cout << "|               4. Do Something else                      |" <<std::endl;
    std::cout << "|                 (Enter -1 to exit)                      |" <<std::endl;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "Your Choice:" <<std::endl;
    std::cin >> choice;
    IsInputValid();
    return choice;
}

int DisplayRemoveMenu() {
    int choice = -1;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "|                 Employee Management System              |" <<std::endl;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "|               1. Enter Employee ID                      |" <<std::endl;
    std::cout << "|               2. Enter Employee name                    |" <<std::endl;
    std::cout << "|                 (Enter -1 to go back to main menu)      |" <<std::endl;
    std::cin >> choice;
    IsInputValid();
    return choice;
}

int DisplayAddMenu() {
    int choice = -1;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "|                 Employee Management System              |" <<std::endl;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "| Add an Employee :                                       |" <<std::endl;
    std::cout << "|               1. Add an Employee at Random              |" <<std::endl;
    std::cout << "|               2. Add an Employee (F/C/I)                |" <<std::endl;
    std::cout << "|               3. Add n number of Employees at once      |" <<std::endl;
    std::cout << "|                 (Enter -1 to go back to main menu)      |" <<std::endl;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "Your Choice:" <<std::endl;
    std::cin >> choice;
    IsInputValid();
    return choice;
}

int DisplayDetailsMenu() {
    int choice = -1;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "|                 Employee Management System              |" <<std::endl;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "| Get Employee Details :                                  |" <<std::endl;
    std::cout << "|               1. All Employees Summary NA               |" <<std::endl;
    std::cout << "|               2. Employee Summary (F/C/I) Type          |" <<std::endl;
    std::cout << "|               3. Employee Summary (M/F/T) Gender        |" <<std::endl;
    std::cout << "|               4. Employee Summary (A/I/R) Status        |" <<std::endl;
    std::cout << "|               5. Display Employee Details               |" <<std::endl;
    std::cout << "|                 (Enter -1 to go back to main menu)      |" <<std::endl;
    std::cout << "-----------------------------------------------------------" <<std::endl;
    std::cout << "Your Choice:" <<std::endl;
    std::cin >> choice;
    IsInputValid();
    return choice;
}

int DisplayOthersMenu() {
    int choice = -1;
    std::cout << "---------------------------------------------------------------------------" <<std::endl;
    std::cout << "|                      Employee Management System                         |" <<std::endl;
    std::cout << "---------------------------------------------------------------------------" <<std::endl;
    std::cout << "|               1. Add n number of leaves to all the Full-Time employees  |" <<std::endl;
    std::cout << "|               2. Convert an employee to Full-Time.                      |" <<std::endl;
    std::cout << "|               3. Search an Employee by ID                               |" <<std::endl;
    std::cout << "|               4. Search an Employee by Name                             |" <<std::endl;
    std::cout << "|                 (Enter -1 to go back to previous menu)                  |" <<std::endl;
    std::cout << "---------------------------------------------------------------------------"<<std::endl;
    std::cout << "Your Choice:" <<std::endl;
    std::cin >> choice;
    IsInputValid();
    return choice;
}

int main() {
    XyzEmployeeManager* sEmpManager = new XyzEmployeeManager();
    int sChoice = -1;
    while(true) {
        sChoice = DisplayMainMenu();
        switch (sChoice) {
            case Menu_option_1:
            {
                sChoice = DisplayAddMenu();
                sEmpManager->processAddMenu(sChoice);
                break;
            }
            case Menu_option_2:
            {
                std::string sEmpId;
                std::cout << "Enter employee ID: " << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::getline(std::cin, sEmpId);
                IsInputValid();
                sEmpManager->removeEmployee(sEmpId);
                break;
            }
            case Menu_option_3:
            {
                sChoice = DisplayDetailsMenu();
                sEmpManager->processDetailsMenu(sChoice);
                break;
            }
            case Menu_option_4:
            {
                sChoice = DisplayOthersMenu();
                sEmpManager->processOtherMenu(sChoice);
                break;
            }
            case Menu_exit:
            {
                exit(0);
            }
            default: {
                std::cout << "Wrong input given" << std::endl;
                break;
            }
        }
    }
    return 0;
}