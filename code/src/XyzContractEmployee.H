#ifndef __XYZ__CONTRACTOR_EMPLOYEE__
#define __XYZ__CONTRACTOR_EMPLOYEE__

#include "XyzEmployeeImpl.H"
#include "Utilities.H"

namespace EMS {
    class XyzContractEmployee : public XyzEmployeeImpl {
        private:
        Agency mAgency;
        
        public:
        XyzContractEmployee();
        XyzContractEmployee(const std::string& sEmpIdParm,
                            const std::string& sNameParm,
                            EmpGender sGenderParm,
                            const Date& sDOBParm, 
                            EmpStatus sStatusParm,
                            EmpType sTypeParm,
                            const Date& sDOJParm,
                            const Date& sDOLParm,
                            Agency agencyParm);
        ~XyzContractEmployee();

        void setAgency(Agency agencyParm);
        Agency getAgency();

        virtual void getEmpRecord(XyzEmployeeRecord &empRecordParm);
        virtual void printEmployeeDetails();
    };
}
#endif