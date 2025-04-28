#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "XyzEmployeeManager.H"
#include "Utilities.H"

/* Lambda function to print the ---- lines */
auto printLine = [](int sLineLen) {
    for (int i = 0; i <sLineLen; i++) {
        std::cout<<"-"; 
    } 
    std::cout << std::endl;
};

XyzEmployeeManager::XyzEmployeeManager() {
    mColumns.pushBack(std::string(" Employee Name "));
    mColumns.pushBack(std::string(" ID       "));
    mColumns.pushBack(std::string(" Type       "));
    mColumns.pushBack(std::string(" Status   "));
    mColumns.pushBack(std::string(" Gender       "));
    mColumns.pushBack(std::string(" Date of Birth "));
    mColumns.pushBack(std::string(" Date of Joining "));
    mColumns.pushBack(std::string(" Date of Leaving "));
    mColumns.pushBack(std::string(" Leaves Used "));
    mColumns.pushBack(std::string(" Leaves Left "));
    mColumns.pushBack(std::string(" Branch "));
    mColumns.pushBack(std::string(" College "));
    mColumns.pushBack(std::string(" Agency "));

    mMaxEmpNameLength = mColumns[0].length();
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
        }
        else if (Contract == sEmpType) {
            Agency sEmpAgency = getRandomAgency();
            empObj = new XyzContractEmployee(sEmpID, sEmpName, sEmpGender, sEmpDOB, sEmpStatus, sEmpType, sEmpDOJ, sEmpDOL, sEmpAgency);
        }
        else if (Intern == sEmpType){
            Colleges sCollege = getRandomColleges();
            Branch sBranch = getRandomBranch();
            empObj = new XyzInternEmployee(sEmpID, sEmpName, sEmpGender, sEmpDOB, sEmpStatus, sEmpType, sEmpDOJ, sEmpDOL, sCollege, sBranch);
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
            int sLines = printColumns(AllEmpColumns);
            for (int i = 0; i < mEmpList.size(); i++) {
                XyzEmployeeIF* empObj = mEmpList[i];
                empObj->printEmployeeSummary(mMaxEmpNameLength);
            }
            printLine(sLines);
            break;
        }
        case Menu_option_2:
        {
            std::cout <<"Enter type of employee summary: 0 = FullTime, 1 = Contractor, 2 = Intern" << std::endl;
            int sEmpType = Rc_Failure;
            std::cin >> sEmpType;
            if (IsInputValid() == Rc_Success) {
                int sLines = printColumns((EmpColumns)sEmpType);
                for (int i = 0; i < mEmpList.size(); i++) {
                    XyzEmployeeIF* empObj = mEmpList[i];
                    if (sEmpType == empObj->getEmployeeType()) {
                        empObj->printEmployeeSummary(mMaxEmpNameLength, false);
                    }
                }
                printLine(sLines);
            }
            break;
        }
        case Menu_option_3:
        {
            std::cout <<"Enter type of employee summary: 0 = Male, 1 = Female, 2 = Transgender" << std::endl;
            int empGender = Rc_Failure;
            std::cin >> empGender;
            if (IsInputValid() == Rc_Success) {
                int sLines = printColumns(AllEmpColumns);
                for (int i = 0; i < mEmpList.size(); i++) {
                    XyzEmployeeIF* empObj = mEmpList[i];
                    if (empGender == empObj->getEmployeeGender()) {
                        empObj->printEmployeeSummary(mMaxEmpNameLength);
                    }
                }
                printLine(sLines);
            }
            break;
        }
        case Menu_option_4:
        {
            std::cout <<"Enter type of employee summary: 0 = Active, 1 = Inactive, 2 = Resigned" << std::endl;
            int sEmpStatus = Rc_Failure;
            int sLines = 0;
            std::cin >> sEmpStatus;
            if (IsInputValid() == Rc_Success) {
                if (Resigned == sEmpStatus) {
                    sLines = printColumns(BasicEmpColumns);
                    //std::cout << "Printing size: " << mResignedEmpList.size() << std::endl;
                    for (int i = 0; i <  mResignedEmpList.size(); i++) {
                        XyzEmployeeIF* empObj = mResignedEmpList[i];
                        empObj->printEmployeeSummary(mMaxEmpNameLength);
                    }
                    printLine(sLines);
                }
                else {
                    sLines = printColumns(AllEmpColumns);
                    for (int i = 0; i < mEmpList.size(); i++) {
                        XyzEmployeeIF* empObj = mEmpList[i];
                        if (sEmpStatus == empObj->getEmployeeStatus()) {
                            empObj->printEmployeeSummary(mMaxEmpNameLength);
                        }
                    }
                    printLine(sLines);
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
        case Menu_option_1:
        {
            EmpType empType = (EmpType)getRandomNumber(FullTime, Intern);
            addEmployee(empType);
            break;
        }
        case Menu_option_2:
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
        case Menu_option_3:
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
        case Menu_exit:
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
        case Menu_option_1:
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
        case Menu_option_2:
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
        case Menu_option_3:
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
        case Menu_option_4:
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

int XyzEmployeeManager::printColumns(EmpColumns empTypeParm) {
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //| Employee Name   | ID  | Type  | Status | Gender | Date of Birth | Date Of Joining | Date Of Leaving | Leaves Availed | Leaves Left | Branch | College | Agency |
    //------------------------------------------------------------------------------------------------------------------------------------------------------------------
    std::stringstream sColumns;
    size_t lineLen = mMaxEmpNameLength + 1;
    size_t collegeLen = std::string("IIIT_Hyderabad").length();
    size_t agencyLen = std::string("Jusice_League").length();
    sColumns.str("");
    sColumns.clear();
    sColumns << "|" << std::setw(mMaxEmpNameLength+2) << std::left << mColumns[0];
    for (int i = 1; i < mColumns.size()-5; i++) { //Left out 5 specific column names related to the type of employee; 2 for Fulltime, 1 for contractor, 2 for Intern
        sColumns << "|" << mColumns[i];
        lineLen += mColumns[i].length()+1;
    }

    if (BasicEmpColumns != empTypeParm) {
        switch(empTypeParm) {
            case FullTimeEmpColumns: {
                for (int i = 8; i < mColumns.size()-3; i++) {
                    sColumns << "|" << mColumns[i];
                    lineLen += mColumns[i].length()+1;
                }
                break;
            }
            case InternEmpColumns: {
                sColumns << "|" << mColumns[10]; //branch column name
                sColumns << "|" << std::setw( collegeLen + 2) << mColumns[11];
                lineLen += collegeLen + 2 + mColumns[10].length()+1;
                break;
            }
            case ContractEmpColumns: {
                sColumns << "|" << std::setw( agencyLen + 2) << mColumns[12];
                lineLen += agencyLen + 2 + 1;
                break;
            }
            case AllEmpColumns:
            default: {
                for (int i = 8; i < mColumns.size()-2; i++) {
                    sColumns << "|" << mColumns[i];
                    lineLen += mColumns[i].length()+1;
                }
                sColumns << "|" << std::setw(collegeLen + 2) << mColumns[11];
                sColumns << "|" << std::setw(agencyLen + 2) << mColumns[12];
                lineLen += collegeLen + agencyLen + 6;
                break;
            }
        }
    }

    lineLen += 3;

    printLine(lineLen);
    std::cout << sColumns.str() << "|"<< std::endl;
    printLine(lineLen);

    return lineLen;
}

