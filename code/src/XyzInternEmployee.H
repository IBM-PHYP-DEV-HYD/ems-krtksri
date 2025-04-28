#ifndef __XYZ_INTERN_EMPLOYEE__
#define __XYZ_INTERN_EMPLOYEE__

#include "XyzEmployeeImpl.H"

class XyzInternEmployee : public XyzEmployeeImpl {
    private:
    Colleges mCollege;
    Branch mBranch;

    public:
    XyzInternEmployee();
    XyzInternEmployee(const std::string& sEmpIdParm, const std::string& sNameParm, EmpGender sGenderParm, 
        const Date& sDOBParm, EmpStatus sStatusParm, EmpType sTypeParm, const Date& sDOJParm,
        const Date& sDOLParm, Colleges sCollegeParm, Branch sBranchParm);
    ~XyzInternEmployee();

    void setCollege(Colleges collegeParm );
    Colleges getCollege();

    void setBranch(Branch collegeParm );
    Branch getBranch();

    virtual void printEmployeeSummary(size_t maxColumnLenParm, bool printAll = true);
    virtual void printEmployeeDetails();
};

#endif