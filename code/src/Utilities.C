#include <sstream>
#include <iomanip>
#include "Utilities.H"

std::string empNames[] = 
{   "Ramesh",
    "Hardik",
    "Jason",
    "Arjun",
    "Virat",
    "Rohit",
    "Krunal",
    "Ricky",
    "Steve",
    "Mark",
    "Travis",
    "Sachin",
    "Rahul",
    "Sourav",
    "Laxman",
    "Virendhar",
    "Irfan",
    "Yousuf",
    "Axar",
    "Anil",
    "Yuvraj"
};

std::string empSurNames[] = 
{
    "Adom",
    "Lee",
    "Waugh",
    "Ponting",
    "Pandya",
    "Arya",
    "Tendulkar",
    "Kohli",
    "Sharma",
    "Verma",
    "Joshi",
    "Singh",
    "Gupta",
    "Roy",
    "Shaw",
    "Patel",
    "Agarwal",
    "Bachan",
    "Khan",
    "Pathan",
    "Ganguly",
    "Sehwag",
    "Kumble"
};

std::string empTypeNames[] =  {"FullTime", "Contractor", "Intern"};
std::string empStatusNames[] = {"Active", "Inactive", "Resigned"};
std::string empGenderNames[] = {"Male", "Female", "Transgender"};

std::string empAgencyNames[] = {"Avengers", "Jusice_League", "X_Men"};
std::string empCollegeNames[] = {"IIT_Delhi", "IIT_Mumbai", "IIT_Kanpur", "IIT_Hyderabad", "NIT_Warangal", "NIT_Tiruchi", "IIIT_Hyderabad"};
std::string empBranchNames[] = {"CSE", "CSIT", "ECE"};

int getRandomNumber(int startNumParm, int endNumParm)
{
    std::random_device sRandomDevice;
    std::mt19937 sRandomNumberGenerator(sRandomDevice());
    std::uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}

EmpStatus getRandomEmpStatus() {
    return (EmpStatus)getRandomNumber(Active, Resigned);
}

EmpType getRandomEmpType() {
    return (EmpType)getRandomNumber(FullTime, Intern);
}

EmpGender getRandomEmpGender() {
    return (EmpGender)getRandomNumber(Male, TransGender);
}

Leaves getRandomLeaves() {
    return (Leaves)getRandomNumber(MinLeaves, MaxLeaves);
}

Agency getRandomAgency() {
    return (Agency)getRandomNumber(Avengers, X_Men);
}

Colleges getRandomColleges() {
    return (Colleges)getRandomNumber(IIT_Delhi, IIT_Hyderabad);
}

Branch getRandomBranch() {
    return (Branch)getRandomNumber(CSE, ECE);
}

std::string getRandomEmployeeName() {
    EmpSurName empSurName = (EmpSurName)getRandomNumber(Adom, Kumble);
    EmpName empName = (EmpName)getRandomNumber(Ramesh, Yuvraj);
    return (empNames[empName] +" "+ empSurNames[empSurName]);
}

std::string getRandomEmpID(EmpType empType) {
    std::stringstream ss;
    std::string empID = "Xyz";
    uint16_t code = getRandomNumber(1,9999);
    ss << std::setw(4) << std::setfill('0') << code;
    empID += ss.str();
    empID += (empType == FullTime) ? "F" : (empType == Contract) ? "C" : "I";
    return empID;
}

Date getRandomDate(uint32_t yearParm) {
    uint32_t sDay = getRandomNumber(1, 28);
    uint32_t sMonth = getRandomNumber(1, 12);
    uint32_t sYear = yearParm;
    return Date(sDay, sMonth, sYear);
}

std::string& getEmployeeStatusName(EmpStatus sStatusParm) {
    return empStatusNames[sStatusParm];
}

std::string& getEmployeeGenderName(EmpGender sGenderParm) {
    return empGenderNames[sGenderParm];
}

std::string& getEmployeeTypeName(EmpType sTypeParm) {
    return empTypeNames[sTypeParm];
}

std::string& getEmployeeAgencyName(Agency sAgency) {
    return empAgencyNames[sAgency];
}

std::string& getEmployeeCollegeName(Colleges sCollegeParm) {
    return empCollegeNames[sCollegeParm];
}

std::string& getEmployeeBranchName(Branch sBranchParm) {
    return empBranchNames[sBranchParm];
}

ReturnType IsInputValid() {
    ReturnType sRetValue = Rc_Success;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); /* discard the invalid input */
        std::cout << "Invalid input, please enter valid value.." << std::endl;
        sRetValue = Rc_Failure;
    }
    return sRetValue;
}


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