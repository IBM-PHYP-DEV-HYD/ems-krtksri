#ifndef __UTILITIES__
#define __UTILITIES__

#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <cstdlib>
#include <random>
#include <iostream>

enum EmpStatus{
    Active,
    Inactive,
    Resigned,
    InvalidEmpStatus
};

enum EmpType {
    FullTime,
    Contract,
    Intern,
    InvalidEmpType
};

enum EmpColumns {
    FullTimeEmpColumns = 0,
    ContractEmpColumns,
    InternEmpColumns,
    BasicEmpColumns,
    AllEmpColumns
};

enum EmpGender {
    Male,
    Female,
    TransGender,
    InvalidEmpGender
};

enum Leaves{
    MinLeaves = 0,
    MaxLeaves = 22,
    InvalidLeaves
};

enum Agency {
    Avengers = 0,
    Justice_League,
    X_Men,
    InvalidAgency
};

enum Colleges {
    IIT_Delhi = 0,
    IIT_Mumbai,
    IIT_Kanpur,
    IIT_Hyderabad,
    NIT_Warangal,
    NIT_Tiruchi,
    IIIT_Hyderabad,
    InvalidColleges
};

enum Branch {
    CSE = 0,
    CSIT,
    ECE,
    InvalidBranch
};

enum EmpSurName{
    Adom,
    Lee,
    Waugh,
    Ponting,
    Pandya,
    Arya,
    Tendulkar,
    Kohli,
    Sharma,
    Verma,
    Joshi,
    Singh,
    Gupta,
    Roy,
    Shaw,
    Patel,
    Agarwal,
    Bachan,
    Khan,
    Pathan,
    Ganguly,
    Sehwag,
    Kumble,
    InvalidEmpSurName
};

enum EmpName{
    Ramesh,
    Hardik,
    Jason,
    Arjun,
    Virat,
    Rohit,
    Krunal,
    Ricky,
    Steve,
    Mark,
    Travis,
    Sachin,
    Rahul,
    Sourav,
    Laxman,
    Virendhar,
    Irfan,
    Yousuf,
    Axar,
    Anil,
    Yuvraj,
    InvalidEmpName
};

enum monthRange {
    startMonth = 1,
    endMonth = 12
};

enum DayRange {
    startDay = 1,
    endDay = 28
};

enum YearRange {
    startYear = 1991,
    endYear = 2025
};

enum MenuOptions {
    Menu_exit = -1,
    Menu_option_0 = 0,
    Menu_option_1,
    Menu_option_2,
    Menu_option_3,
    Menu_option_4
};

enum ReturnType {
    Rc_Failure = -1,
    Rc_Success = 0
};

enum ColumnNames {
    Column_EmpName = 0,
    Column_EmpId,
    Column_EmpType,
    Column_EmpStatus,
    Column_EmpGender,
    Column_EmpDOB,
    Column_EmpDOJ,
    Column_EmpDOL
    //EmpLeaves,
    //EmpAgency,
    //EmpCollege,
    //EmpBranch
};

struct Date
{
    uint32_t mDay;
    uint32_t mMonth;
    uint32_t mYear;
    //Default constructor
    Date(): mDay(01), mMonth(01), mYear(1970) {}
    //Parameter constructor
    Date(uint32_t dayParm, uint32_t monthParm, uint32_t yearParm): mDay(dayParm), mMonth(monthParm), mYear(yearParm) {}
    //Copy constructor
    Date(const Date& dateParm) {
        mDay = dateParm.mDay;
        mMonth = dateParm.mMonth;
        mYear = dateParm.mYear;
    }
    //Distructor
    ~Date() {}
    Date& operator=(const Date& dateParm) {
        if (this != &dateParm) {
            mDay = dateParm.mDay;
            mMonth = dateParm.mMonth;
            mYear = dateParm.mYear;
        }
        return *this;
    }

    Date operator+(const Date& dateParm) {
        uint32_t sYearDelta = (mMonth + dateParm.mMonth) / 12;
        Date tempDate;
        tempDate.mYear = mYear + dateParm.mYear + sYearDelta;
        tempDate.mMonth = (mMonth + dateParm.mMonth) % 12;
        tempDate.mDay = mDay + dateParm.mDay;
        return tempDate;
    }

    /*
    bool operator>(Date& dateParm) {
        bool sRetVal = false;

        if (mYear > dateParm.mYear) {
            sRetVal = true;
        }
        else if (mYear == dateParm.mYear) {
            if (mMonth > dateParm.mMonth) {
                sRetVal = true;
            }
            else if (mMonth == dateParm.mMonth) {
                if (mDay > dateParm.mDay) {
                    sRetVal = true;
                }
            }
        }
        return sRetVal;
    }*/

    std::string toString() {
        std::string sDate;
        std::stringstream ss;
        ss << std::setw(2) << std::setfill('0') << mMonth;
        sDate = std::to_string(mYear) + "-" + ss.str() + "-" ;
        ss.str("");
        ss << std::setw(2) << std::setfill('0') << mDay;
        sDate += ss.str();
        return sDate;
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date)  {
        os << date.mYear << "-" << date.mMonth << "-" << date.mDay;
        return os;
    }
};

typedef struct Date Date;

extern std::string empTypeNames[];
extern std::string empStatusNames[];
extern std::string empGenderNames[]; 
extern std::string empAgencyNames[];
extern std::string empCollegeNames[];
extern std::string empBranchNames[];

EmpStatus getRandomEmpStatus();
EmpType getRandomEmpType();
EmpGender getRandomEmpGender();
Leaves getRandomLeaves();
Agency getRandomAgency();
Colleges getRandomColleges();
Branch getRandomBranch();
std::string getRandomEmployeeName();
std::string getRandomEmpID(EmpType empType);
int getRandomNumber(int startNumParm, int endNumParm);

Date getRandomDate(uint32_t yearParm);

std::string& getEmployeeTypeName(EmpType typeParm);
std::string& getEmployeeStatusName(EmpStatus statusParm);
std::string& getEmployeeGenderName(EmpGender genderParm);

std::string& getEmployeeAgencyName(Agency agencyParm);
std::string& getEmployeeCollegeName(Colleges collegeParm);
std::string& getEmployeeBranchName(Branch branchParm);

ReturnType IsInputValid();

#endif