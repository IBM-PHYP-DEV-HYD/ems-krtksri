#ifndef __XYZ_EMPLOYEE_IMPL__
#define __XYZ_EMPLOYEE_IMPL__

#include "XyzEmployeeIF.H"
#include "Deque.H"

using namespace standardTemplates;
namespace EMS {
    class XyzEmployeeImpl: public XyzEmployeeIF {
        protected:
            std::string mEmpId;
            std::string mEmpName;
            EmpGender mEmpGender;
            Date mEmpDOB;//The dates used in this class are in "Y-m-d" format
            
            EmpStatus mEmpStatus;
            EmpType mEmpType;
            Date mEmpDOJ;
            Date mEmpDOL;

        public:

            //Constructor
            XyzEmployeeImpl();
            XyzEmployeeImpl(const std::string& sEmpIdParm, 
                            const std::string& sNameParm,
                            EmpGender sGenderParm,
                            const Date& sDOBParm, 
                            EmpStatus sStatusParm,
                            EmpType sTypeParm,
                            const Date& sDOJParm,
                            const Date& sDOLParm);
            
            //Distructor
            ~XyzEmployeeImpl();
            
            //copy constructor
            XyzEmployeeImpl(const XyzEmployeeImpl& emp);
            
            //Assignment operator overloading
            XyzEmployeeImpl& operator=(const XyzEmployeeImpl& emp);

            virtual std::string getEmployeeID();
            virtual std::string getEmployeeName();
            virtual EmpGender getEmployeeGender(); 
            virtual Date getEmployeeDOB();
            virtual Date getEmployeeDOJ();
            virtual Date getEmployeeDOL();
            virtual EmpType getEmployeeType(); 
            virtual EmpStatus getEmployeeStatus();

            virtual void setEmployeeDOJ(Date& DOBParm);
            virtual void setEmployeeDOL(Date& DOLParm);
            virtual void setEmployeeType(EmpType typeParm);
            virtual void setEmployeeStatus(EmpStatus statusParm);
            virtual void getEmpRecord(XyzEmployeeRecord &empRecordParm);
            virtual void printEmployeeDetails();
            virtual void updateNumOfLeavesLeft(uint32_t leaveParm);
    };
}
#endif