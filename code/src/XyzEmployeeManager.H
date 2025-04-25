#ifndef __XYZ_EMPLOYEE_MANAGER__
#define __XYZ_EMPLOYEE_MANAGER__

#include "XyzEmployeeImpl.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractEmployee.H"
#include "XyzInternEmployee.H"

#include "Deque.H"
#include "Utilities.H"
#include "EDeque.H"

class XyzEmployeeManager {
    public:
    EDeque<XyzEmployeeIF*> mEmpList;
    //TODO - Here we no need to maintain all the details like current employee, Try to cut down the data which is not needed
    EDeque<XyzEmployeeIF*> mResignedEmpList; 

    Deque<std::string> mColumns;
    
    size_t mMaxEmpNameLength;

    XyzEmployeeManager();
    ~XyzEmployeeManager();

    XyzEmployeeIF* createEmployeeObject(EmpType baseEmpParm);
    void addEmployee(EmpType empTypeParm);
    void removeEmployee(std::string& empId);
    void searchEmployeeByName(std::string& inputNameParm, Deque<XyzEmployeeIF*>& empList);
    int  searchEmployeeById(std::string& inputParm); //This will return the index of the employee object in the list
    void searchResignedEmployeeByName(std::string& inputNameParm, Deque<XyzEmployeeIF*>& empList);
    int searchResignedEmployeeById(std::string& inputIdParm);
    void convertToFullTimeEmployee(std::string& empId);
    void processAddMenu(int sChoiceParm);
    void processDetailsMenu(int sChoiceParm);
    void processOtherMenu(int sChoiceParm);


    size_t getMaxNameColumnWidth();
    int printColumns(EmpColumns empColumnsParm = BasicEmpColumns);
};


#endif