#ifndef __XYZ_EMPLOYEE_MANAGER__
#define __XYZ_EMPLOYEE_MANAGER__

#include "XyzEmployeeImpl.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractEmployee.H"
#include "XyzInternEmployee.H"

#include "Deque.H"
#include "Utilities.H"
#include "EDLL.H"

namespace EMS {
    class XyzEmployeeManager {
        public:
        EDLL<XyzEmployeeIF*> mEmpList;
        //TODO - Here we no need to maintain all the details like current employee, Try to cut down the data which is not needed
        EDLL<XyzEmployeeIF*> mResignedEmpList;
        size_t mMaxEmpNameLength;
        EmpColumnBits mEmpColumnsSupported;

        XyzEmployeeManager();
        ~XyzEmployeeManager();

        XyzEmployeeIF* createEmployeeObject(EmpType baseEmpParm);
        void addEmployee(EmpType empTypeParm);
        void removeEmployee(std::string& empId);
        void convertToFullTimeEmployee(std::string& empId);
        void processAddMenu(int sChoiceParm);
        void processDetailsMenu(int sChoiceParm);
        void processOtherMenu(int sChoiceParm);
        void searchEmployeeByName(std::string& inputNameParm, Deque<XyzEmployeeIF*>& empList);
        void searchResignedEmployeeByName(std::string& inputNameParm, Deque<XyzEmployeeIF*>& empList);
        int  searchEmployeeById(std::string& inputParm);
        int  searchResignedEmployeeById(std::string& inputIdParm);
        size_t getMaxNameColumnWidth();
    };
}

#endif