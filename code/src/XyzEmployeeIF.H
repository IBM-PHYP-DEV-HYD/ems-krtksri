#ifndef __XYZ_EMPLOYEE_IF__
#define __XYZ_EMPLOYEE_IF__

#include <string>
#include <sstream>
#include <iomanip>
#include "Utilities.H"

class XyzEmployeeIF {
    public:
    //Common employee detail getters
    virtual std::string getEmployeeID() = 0;
    virtual std::string getEmployeeName() = 0;
    virtual EmpGender getEmployeeGender() = 0; 
    virtual Date getEmployeeDOB() = 0;
    virtual Date getEmployeeDOJ() = 0;
    virtual Date getEmployeeDOL() = 0;
    virtual EmpType getEmployeeType() = 0; 
    virtual EmpStatus getEmployeeStatus() = 0;

    //Common employee detail gettters
    virtual void setEmployeeDOJ(Date& DOBParm) = 0;
    virtual void setEmployeeDOL(Date& DOLParm) = 0;
    virtual void setEmployeeType(EmpType typeParm) = 0;
    virtual void setEmployeeStatus(EmpStatus statusParm) = 0;
    
    virtual void printEmployeeSummary(size_t maxColumnLenParm, bool printAll = true) = 0;
    virtual void printEmployeeDetails() = 0;
    virtual void updateNumOfLeavesLeft(uint32_t leavesParm) = 0;
};

#endif