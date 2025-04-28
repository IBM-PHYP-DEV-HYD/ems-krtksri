#ifndef __XYZ__CONTRACTOR_EMPLOYEE__
#define __XYZ__CONTRACTOR_EMPLOYEE__

#include "XyzEmployeeImpl.H"
#include "Utilities.H"

class XyzContractEmployee : public XyzEmployeeImpl {
    private:
    Agency mAgency;
    
    public:
    XyzContractEmployee();
    XyzContractEmployee(const std::string& sEmpIdParm, const std::string& sNameParm, EmpGender sGenderParm, const Date& sDOBParm, 
        EmpStatus sStatusParm, EmpType sTypeParm, const Date& sDOJParm, const Date& sDOLParm, Agency agencyParm);
    ~XyzContractEmployee();

    void setAgency(Agency agencyParm);
    Agency getAgency();

    virtual void printEmployeeSummary(size_t maxColumnLenParm, bool printAll = true);
    virtual void printEmployeeDetails();
};

#endif