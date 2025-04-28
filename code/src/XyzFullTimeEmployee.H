#ifndef __XYZ_FULL_TIME_EMPLOYEE__
#define __XYZ_FULL_TIME_EMPLOYEE__

#include "XyzEmployeeImpl.H"

class XyzFullTimeEmployee : public XyzEmployeeImpl {
    private:
    uint32_t mNumOfLeavesAvailed;
    uint32_t mNumOfLeavesLeft;
    
    public:

    XyzFullTimeEmployee();
    XyzFullTimeEmployee(XyzEmployeeImpl& empImplParm, uint32_t sLeavesAvailed, uint32_t sLeavesLeft);
    XyzFullTimeEmployee(const std::string& sEmpIdParm, const std::string& sNameParm, EmpGender sGenderParm, const Date& sDOBParm, 
        EmpStatus sStatusParm, EmpType sTypeParm, const Date& sDOJParm, const Date& sDOLParm, uint32_t sLeavesAvailed, uint32_t sLeavesLeft);
    ~XyzFullTimeEmployee();

    void setNumOfLeavesAvailed(uint32_t numOfLeavesParm);
    uint32_t getNumOfLeavesAvailed();

    void setNumOfLeavesLeft(uint32_t numOfLeavesParm);
    uint32_t getNumOfLeavesLeft();

    virtual void updateNumOfLeavesLeft(uint32_t leavesParm);
    virtual void printEmployeeSummary(size_t maxColumnLenParm, bool printAll = true);
    virtual void printEmployeeDetails();
};

#endif