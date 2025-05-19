#include "EDLL.H"
#include "XyzEmployeeIF.H"
#include "XyzEmployeeImpl.H"
#include "XyzEmployeeManager.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractEmployee.H"
#include "XyzInternEmployee.H"

using namespace EMS;

int main() {
    XyzEmployeeManager* sEmpManager = new XyzEmployeeManager();
    int sChoice = -1;
    while(true) {
        sChoice = displayMainMenu();
        switch (sChoice) {
            case MenuOptions::Menu_option_1:
            {
                sChoice = displayAddMenu();
                sEmpManager->processAddMenu(sChoice);
                break;
            }
            case MenuOptions::Menu_option_2:
            {
                std::string sEmpId;
                std::cout << "Enter employee ID: " << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::getline(std::cin, sEmpId);
                EMS::IsInputValid();
                sEmpManager->removeEmployee(sEmpId);
                break;
            }
            case MenuOptions::Menu_option_3:
            {
                sChoice = displayDetailsMenu();
                sEmpManager->processDetailsMenu(sChoice);
                break;
            }
            case MenuOptions::Menu_option_4:
            {
                sChoice = displayOthersMenu();
                sEmpManager->processOtherMenu(sChoice);
                break;
            }
            case MenuOptions::Menu_exit:
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