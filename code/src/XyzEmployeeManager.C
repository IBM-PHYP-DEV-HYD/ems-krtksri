#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "XyzEmployeeManager.H"
#include "Utilities.H"
#include "XyzEmployeeRecord.H"

using namespace EMS;

XyzEmployeeManager::XyzEmployeeManager()
: mMaxEmpNameLength(0)
{
    mEmpColumnsSupported.empCommonDetailsBit = 0;
    mEmpColumnsSupported.empFullTimeBit = 0;
    mEmpColumnsSupported.empContractBit = 0;
    mEmpColumnsSupported.empInternBit = 0;
}

XyzEmployeeManager::~XyzEmployeeManager() {
    mEmpList.clear();
}

size_t XyzEmployeeManager::getMaxNameColumnWidth() {
    return mMaxEmpNameLength;
}

XyzEmployeeIF* XyzEmployeeManager::createEmployeeObject(EmpType baseEmpParm) {
    XyzEmployeeIF* empObj = nullptr;
    EmpType sEmpType = baseEmpParm;

    int sBirthYear = getRandomNumber(1981, 1995);
    std::string sEmpName = getRandomEmployeeName();
    std::string sEmpID = getRandomEmpID(sEmpType);
    Date sEmpDOB = getRandomDate(sBirthYear);
    EmpGender sEmpGender = getRandomEmpGender();
    EmpStatus sEmpStatus = getRandomEmpStatus();
    Date sEmpDOJ = getRandomDate(sBirthYear + 21);
    Date sEmpDOL;

    mMaxEmpNameLength = std::max(mMaxEmpNameLength, sEmpName.length());
    mEmpColumnsSupported.empCommonDetailsBit = 1;

    if (Contract == sEmpType) {
        Date sDate(0,0,1); // 1 year contract
        sEmpDOL = sEmpDOJ + sDate;
    }
    else if (Intern == sEmpType) {
        Date sDate(0,6,0); // 6 months internship
        sEmpDOL = sEmpDOJ + sDate;
    }

    if (Resigned == sEmpStatus) {//For employees who resigned will be maintining only basic details.
        empObj = new XyzEmployeeImpl(sEmpID, sEmpName, sEmpGender, sEmpDOB, sEmpStatus, sEmpType, sEmpDOJ, sEmpDOL);
    }
    else {
        if (FullTime == sEmpType) {
            uint32_t sLeavesAvailed = getRandomNumber(MinLeaves, MaxLeaves);
            uint32_t sLeavesLeft = MaxLeaves - sLeavesAvailed;
            empObj = new XyzFullTimeEmployee(sEmpID, sEmpName, sEmpGender, sEmpDOB, sEmpStatus, sEmpType, sEmpDOJ, sEmpDOL, sLeavesAvailed, sLeavesLeft);
            mEmpColumnsSupported.empFullTimeBit = 1;
        }
        else if (Contract == sEmpType) {
            Agency sEmpAgency = getRandomAgency();
            empObj = new XyzContractEmployee(sEmpID, sEmpName, sEmpGender, sEmpDOB, sEmpStatus, sEmpType, sEmpDOJ, sEmpDOL, sEmpAgency);
            mEmpColumnsSupported.empContractBit = 1;
        }
        else if (Intern == sEmpType){
            Colleges sCollege = getRandomColleges();
            Branch sBranch = getRandomBranch();
            empObj = new XyzInternEmployee(sEmpID, sEmpName, sEmpGender, sEmpDOB, sEmpStatus, sEmpType, sEmpDOJ, sEmpDOL, sCollege, sBranch);
            mEmpColumnsSupported.empInternBit = 1;
        }
        else {
            std::cout << "Invalid object type" << std::endl;
            return nullptr;
        }
    }
    return empObj;
}

void XyzEmployeeManager::addEmployee(EmpType baseEmpParm) {
    XyzEmployeeIF* empObj = createEmployeeObject(baseEmpParm);
    if (nullptr != empObj) {
        if (Resigned != empObj->getEmployeeStatus()) {
            mEmpList.pushBack(empObj);
        }
        else {
            mResignedEmpList.pushBack(empObj);
        }
    }
}

void XyzEmployeeManager::removeEmployee(std::string & empIdParm) {
    if (!empIdParm.empty()) {
        int pos = searchEmployeeById(empIdParm);
        if (pos >= 0) {
            XyzEmployeeIF* empObj = mEmpList[pos];
            std::cout << "Removing employee ID: " << empObj->getEmployeeID() << std::endl;
            XyzEmployeeIF* remObj = new XyzEmployeeImpl(empObj->getEmployeeID(), empObj->getEmployeeName(), empObj->getEmployeeGender()
                                                        ,empObj->getEmployeeDOB(), empObj->getEmployeeStatus(), empObj->getEmployeeType()
                                                        ,empObj->getEmployeeDOJ(), empObj->getEmployeeDOL());
            mResignedEmpList.pushBack(remObj);
            mEmpList.RemoveElementAt(pos);
        }
        else {
            std::cout << "The Employee ID: " << empIdParm << " not found in the data base" << std::endl;
        }
    }
}

void XyzEmployeeManager::processDetailsMenu(int sChoiceParm) {
    switch(sChoiceParm) {
        case Menu_option_1:
        {
            XyzEmployeeRecord sEmpRecord;
            size_t sLineLen = sEmpRecord.printAllHeader(mMaxEmpNameLength, mEmpColumnsSupported);
            for (int i = 0; i < mEmpList.size(); i++) {
                XyzEmployeeIF* empObj = mEmpList[i];
                empObj->getEmpRecord(sEmpRecord);
                sEmpRecord.printAllEmpData(mMaxEmpNameLength, mEmpColumnsSupported);
                sEmpRecord.clear();
            }
            sEmpRecord.printLine(sLineLen);
            break;
        }
        case Menu_option_2:
        {
            std::cout <<"Enter type of employee summary: 0 = FullTime, 1 = Contractor, 2 = Intern" << std::endl;
            int sEmpType = Rc_Failure;
            std::cin >> sEmpType;
            if (IsInputValid() == Rc_Success) {
                XyzEmployeeRecord sEmpRecord;
                size_t sLineLen = sEmpRecord.printHeader(mMaxEmpNameLength, mEmpColumnsSupported, sEmpType);
                for (int i = 0; i < mEmpList.size(); i++) {
                    XyzEmployeeIF* empObj = mEmpList[i];
                    if (sEmpType == empObj->getEmployeeType()) {
                        empObj->getEmpRecord(sEmpRecord);
                        sEmpRecord.printEmpData(mMaxEmpNameLength, sEmpType);
                        sEmpRecord.clear();
                    }
                }
                sEmpRecord.printLine(sLineLen);
            }
            break;
        }
        case Menu_option_3:
        {
            std::cout <<"Enter type of employee summary: 0 = Male, 1 = Female, 2 = Transgender" << std::endl;
            int empGender = Rc_Failure;
            std::cin >> empGender;
            if (IsInputValid() == Rc_Success) {
                XyzEmployeeRecord sEmpRecord;
                size_t sLineLen = sEmpRecord.printAllHeader(mMaxEmpNameLength, mEmpColumnsSupported);
                for (int i = 0; i < mEmpList.size(); i++) {
                    XyzEmployeeIF* empObj = mEmpList[i];
                    if (empGender == empObj->getEmployeeGender()) {
                        empObj->getEmpRecord(sEmpRecord);
                        sEmpRecord.printAllEmpData(mMaxEmpNameLength, mEmpColumnsSupported);
                        sEmpRecord.clear();
                    }
                }
                sEmpRecord.printLine(sLineLen);
            }
            break;
        }
        case Menu_option_4:
        {
            std::cout <<"Enter type of employee summary: 0 = Active, 1 = Inactive, 2 = Resigned" << std::endl;
            int sEmpStatus = Rc_Failure;
            // int sLines = 0;
            std::cin >> sEmpStatus;
            if (IsInputValid() == Rc_Success) {
                XyzEmployeeRecord sEmpRecord;
                if (Resigned == sEmpStatus) {
                    size_t sLineLen = sEmpRecord.printHeader(mMaxEmpNameLength, mEmpColumnsSupported);
                    for (int i = 0; i <  mResignedEmpList.size(); i++) {
                        XyzEmployeeIF* empObj = mResignedEmpList[i];
                        empObj->getEmpRecord(sEmpRecord);
                        sEmpRecord.printEmpData(mMaxEmpNameLength);
                        sEmpRecord.clear();
                    }
                    sEmpRecord.printLine(sLineLen);
                }
                else {
                    size_t sLineLen = sEmpRecord.printAllHeader(mMaxEmpNameLength, mEmpColumnsSupported);
                    for (int i = 0; i < mEmpList.size(); i++) {
                        XyzEmployeeIF* empObj = mEmpList[i];
                        if (sEmpStatus == empObj->getEmployeeStatus()) {
                            empObj->getEmpRecord(sEmpRecord);
                            sEmpRecord.printAllEmpData(mMaxEmpNameLength, mEmpColumnsSupported);
                            sEmpRecord.clear();
                        }
                    }
                    sEmpRecord.printLine(sLineLen);
                }
            }
            break;
        }
        case Menu_exit:
        {
            std::cout << "Going back to previous menu " << std::endl;
            break;
        }
        default:
        {
            std::cout << "Wrong input " << std::endl;
            break;
        }
    }
}

void XyzEmployeeManager::processAddMenu(int sChoiceParm) {
    switch(sChoiceParm) {
        case EMS::MenuOptions::Menu_option_1:
        {
            EmpType empType = (EmpType)getRandomNumber(FullTime, Intern);
            addEmployee(empType);
            break;
        }
        case EMS::MenuOptions::Menu_option_2:
        {
            std::cout << "Enter employee type 0 = FullTime, 1 = Contract, 2 = Intern " << std::endl;
            int empType = FullTime;
            std::cin >> empType;
            if (Rc_Failure == IsInputValid()) {
                std::cout << "Please enter valid employee type " << std::endl;
            }
            else {
                addEmployee((EmpType)empType);
            }
            break;
        }
        case EMS::MenuOptions::Menu_option_3:
        {
            int sNumOfEmp = 0;
            std::cout << "Enter the number of employees hired: " << std::endl;
            std::cin >> sNumOfEmp;
            if (Rc_Success == IsInputValid()) {
                for (int i = 0; i < sNumOfEmp; i++) {
                    EmpType empType = (EmpType)getRandomNumber(FullTime, Intern);
                    addEmployee(empType);
                }
            }
            break;
        }
        case EMS::MenuOptions::Menu_exit:
        {
            std::cout << "Going back to previous" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Wrong choice" << std::endl;
            break;
        }
    }
}

void XyzEmployeeManager::processOtherMenu(int sChoiceParm) {
    switch (sChoiceParm) {
        case EMS::MenuOptions::Menu_option_1:
        {
            std::cout << "Enter number of leaves to be added" << std::endl;
            uint16_t sNumOfLeaves = 0;
            std::cin >> sNumOfLeaves;
            for (int i = 0; i < mEmpList.size(); i++) {
                XyzEmployeeIF* empObj = mEmpList[i];
                if (FullTime == empObj->getEmployeeType()) {
                    empObj->updateNumOfLeavesLeft(sNumOfLeaves);
                }
            }
            break;
        }
        case EMS::MenuOptions::Menu_option_2:
        {
            std::string sEmpID;
            std::cout << "Enter employee id to convert to full time employee: " << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::getline(std::cin, sEmpID);
            if (Rc_Success == IsInputValid()) {
                convertToFullTimeEmployee(sEmpID);
            }
            break;
        }
        case EMS::MenuOptions::Menu_option_3:
        {
            //Search employee by Id
            std::string sEmpId;
            std::cout << "Enter employee Id: " << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::getline(std::cin, sEmpId);
            if (Rc_Success == IsInputValid()) {
                int pos = searchEmployeeById(sEmpId);
                if (pos >= 0) {
                    mEmpList[pos]->printEmployeeDetails();
                }
                else {
                    std::cout << "The Employee ID: " << sEmpId << " not found in the data base" << std::endl;
                }
            }
            
            break;
        }
        case EMS::MenuOptions::Menu_option_4:
        {
            //Search employee by Name
            std::string sEmpName;
            std::cout << "Enter employee name: " << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::getline(std::cin, sEmpName);
            if (Rc_Success == IsInputValid()) {
                Deque<XyzEmployeeIF*> empList;
                //Using list here since we may have multiple employees with the same name
                searchEmployeeByName(sEmpName, empList);
                std::cout << "empList.size: " << empList.size() << std::endl;
                for(int i = 0; i < empList.size(); i++) {
                    XyzEmployeeIF* empObj = empList[i];
                    empObj->printEmployeeDetails();
                }
            }
            break;
        }
    }
}

void XyzEmployeeManager::searchEmployeeByName(std::string& inputNameParm, Deque<XyzEmployeeIF*>& empList) {
    for (int i = 0; i < mEmpList.size(); i++) {
        XyzEmployeeIF* empObj = mEmpList[i];
        if (inputNameParm == empObj->getEmployeeName()) {
            empList.pushBack(empObj);
        }
    }
}

int XyzEmployeeManager::searchEmployeeById(std::string& inputIdParm) {
    int sRetVal = Rc_Failure;
    for (int i = 0; i < mEmpList.size(); i++) {
        XyzEmployeeIF* empObj = mEmpList[i];
        if (inputIdParm == empObj->getEmployeeID()) {
            sRetVal = i;
            break;
        }
    }
    return sRetVal;
}

void XyzEmployeeManager::searchResignedEmployeeByName(std::string& inputNameParm, Deque<XyzEmployeeIF*>& empList) {
    for (int i = 0; i < mResignedEmpList.size(); i++) {
        XyzEmployeeIF* empObj = mResignedEmpList[i];
        if (inputNameParm == empObj->getEmployeeName()) {
            empList.pushBack(empObj);
        }
    }
}

int XyzEmployeeManager::searchResignedEmployeeById(std::string& inputIdParm) {
    int sRetVal = Rc_Failure;
    for (int i = 0; i < mResignedEmpList.size(); i++) {
        XyzEmployeeIF* empObj = mResignedEmpList[i];
        if (inputIdParm == empObj->getEmployeeID()) {
            sRetVal = i;
            break;
        }
    }
    return sRetVal;
}

void XyzEmployeeManager::convertToFullTimeEmployee(std::string& empIdParm) {
    int idx = 0;
    for (idx = 0; idx < mEmpList.size(); idx++) {
        XyzEmployeeIF*  empObj= mEmpList[idx];
        if ((empIdParm == empObj->getEmployeeID()) && (FullTime != empObj->getEmployeeType())) {
            Date sDOL;
            std::string sEmpID = empObj->getEmployeeID();
            sEmpID.back() = 'F';
            XyzEmployeeIF* fullTimeEmp = new XyzFullTimeEmployee(sEmpID, empObj->getEmployeeName(), empObj->getEmployeeGender(), 
                                                                 empObj->getEmployeeDOB(), empObj->getEmployeeStatus(), FullTime, 
                                                                 empObj->getEmployeeDOJ(), sDOL, 0, (uint32_t)MaxLeaves);
            mEmpList.RemoveElementAt(idx);
            mEmpList.pushBack(fullTimeEmp);
            break;
        }
    }

    if(idx == mEmpList.size()) {
        std::cout << "Invalid employee Id" << std::endl;
    }
}
