#include "EDeque.H"
#include "XyzEmployeeIF.H"
#include "XyzEmployeeImpl.H"
#include "XyzEmployeeManager.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractEmployee.H"
#include "XyzInternEmployee.H"

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