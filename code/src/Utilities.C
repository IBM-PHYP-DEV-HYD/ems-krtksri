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

#if 0
std::string getRandomDate(int yearParm) {
    std::string sDate;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << getRandomNumber(1, 12);
    sDate = std::to_string(yearParm) + "-" + ss.str() + "-" ;
    ss.str("");
    ss << std::setw(2) << std::setfill('0') << getRandomNumber(1,28);
    sDate += ss.str();

    return sDate;
}
#endif

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
        std::cout << "Invlaid input, please enter valid value.." << std::endl;
        sRetValue = Rc_Failure;
    }
    return sRetValue;
}

void printEmployeeDetailsColumns() {

}