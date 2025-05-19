#ifndef __XYZ_EMPLOYEE_RECORD__
#define __XYZ_EMPLOYEE_RECORD__
#include <string>
#include "EDLL.H"
#include "Utilities.H"

namespace EMS {
    struct XyzEmployeeRecord {
        std::string sEmpName;
        std::string sEmpID;
        std::string sEmpType;
        std::string sEmpStatus;
        std::string sEmpGender;
        std::string sEmpDOB;
        std::string sEmpDOJ;
        std::string sEmpDOL;
        std::string sEmpLeavesAvailed;
        std::string sEmpLeavesLeft;
        std::string sEmpBranch;
        std::string sEmpCollege;
        std::string sEmpAgency;

        Deque<std::string> mColumns;

        XyzEmployeeRecord();
        void printLine (int sLineLen);
        size_t getCommonEmpHeader(size_t maxColumnLenParm, std::stringstream& sEmpInfoParm);
        size_t getFullTimeEmpHeader(std::stringstream& sEmpInfoParm);
        size_t getContractEmpHeader(std::stringstream& sEmpInfoParm);
        size_t getInternEmpHeader(std::stringstream& sEmpInfoParm);
        void clear();
        size_t printAllHeader(size_t maxColumnLenParm, const EmpColumnBits &empCoulmnToPrintParm);
        size_t printHeader(size_t maxColumnLenParm, int empType = -1);
        void printAllEmpData(size_t maxColumnLenParm, const EmpColumnBits &empCoulmnToPrintParm);
        void printEmpData(size_t maxColumnLenParm, int sEmpType = -1);
    };
}
#endif