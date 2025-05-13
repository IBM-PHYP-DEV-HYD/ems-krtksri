#include "XyzEmployeeRecord.H"
namespace EMS {
    XyzEmployeeRecord::XyzEmployeeRecord()
    : sEmpName("N/A")
    , sEmpID("N/A")
    , sEmpType("N/A")
    , sEmpStatus("N/A")
    , sEmpGender("N/A")
    , sEmpDOB("N/A")
    , sEmpDOJ("N/A")
    , sEmpDOL("N/A")
    , sEmpLeavesAvailed("N/A")
    , sEmpLeavesLeft("N/A")
    , sEmpBranch("N/A")
    , sEmpCollege("N/A")
    , sEmpAgency("N/A")
    {
        mColumns.pushBack(std::string(" Employee Name"));
        mColumns.pushBack(std::string(" ID       "));
        mColumns.pushBack(std::string(" Type      "));
        mColumns.pushBack(std::string(" Status   "));
        mColumns.pushBack(std::string(" Gender       "));
        mColumns.pushBack(std::string(" Date of Birth "));
        mColumns.pushBack(std::string(" Date of Joining "));
        mColumns.pushBack(std::string(" Date of Leaving "));
        mColumns.pushBack(std::string(" Leaves Used "));
        mColumns.pushBack(std::string(" Leaves Left "));
        mColumns.pushBack(std::string(" Branch "));
        mColumns.pushBack(std::string(" College  "));
        mColumns.pushBack(std::string(" Agency ")); 
    }

    void XyzEmployeeRecord::clear() {
        sEmpName = "N/A";
        sEmpID = "N/A";
        sEmpType = "N/A";
        sEmpStatus = "N/A";
        sEmpGender = "N/A";
        sEmpDOB = "N/A";
        sEmpDOJ = "N/A";
        sEmpDOL = "N/A";
        sEmpLeavesAvailed = "N/A";
        sEmpLeavesLeft = "N/A";
        sEmpBranch = "N/A";
        sEmpCollege = "N/A";
        sEmpAgency = "N/A";
    }

    void XyzEmployeeRecord::printLine (int sLineLen) {
        for (int i = 0; i <sLineLen; i++) {
            std::cout<<"-"; 
        } 
        std::cout << std::endl;
    };

    size_t XyzEmployeeRecord::getCommonEmpHeader(size_t maxColumnLenParm, std::stringstream& sEmpInfoParm) {
        size_t sLineLen = 0;
        sEmpInfoParm.clear();
        sEmpInfoParm.str("");
        sEmpInfoParm << "|" << std::setw(maxColumnLenParm + 2) << std::left << mColumns[0];
        sLineLen += maxColumnLenParm;

        for (int i = 1; i < mColumns.size()-5; i++) {
            sEmpInfoParm << "|" << mColumns[i];
            sLineLen += mColumns[i].length()+1;
        }
        return sLineLen;
    }

    size_t XyzEmployeeRecord::getFullTimeEmpHeader(std::stringstream& sEmpInfoParm) {
        size_t sLineLen = 0;
        for (int i = 8; i < mColumns.size()-3; i++) {
            sEmpInfoParm << "|" << mColumns[i];
            sLineLen += mColumns[i].length()+1;
        }
        return sLineLen;
    }

    size_t XyzEmployeeRecord::getContractEmpHeader(std::stringstream& sEmpInfoParm) {
        size_t agencyLen = std::string("Justice_League").length();
        size_t sLineLen = 0;
        sEmpInfoParm << "|" << std::setw(agencyLen + 2) << mColumns[12];
        sLineLen += agencyLen + 1;
        return sLineLen;
    }

    size_t XyzEmployeeRecord::getInternEmpHeader(std::stringstream& sEmpInfoParm) {
        size_t collegeLen = std::string("IIIT_Hyderabad").length();
        size_t sLineLen = 0;
        sEmpInfoParm << "|" << mColumns[10]; //branch column name
        sEmpInfoParm << "|" << std::setw(collegeLen + 1) << mColumns[11];
        sLineLen += collegeLen + 2 + mColumns[10].length() + 1;
        return sLineLen;
    }

    size_t XyzEmployeeRecord::printAllHeader(size_t maxColumnLenParm, const EmpColumnBits &empCoulmnToPrintParm) {
        std::stringstream sHeader;
        size_t sLineLen = 0;
        sLineLen = getCommonEmpHeader(maxColumnLenParm, sHeader);

        if (empCoulmnToPrintParm.empFullTimeBit) {
            sLineLen += getFullTimeEmpHeader(sHeader);
            sLineLen += 2;
        }

        if (empCoulmnToPrintParm.empInternBit) {
            sLineLen += getInternEmpHeader(sHeader);
            sLineLen += 2;
        }

        if (empCoulmnToPrintParm.empContractBit) {
            sLineLen += getContractEmpHeader(sHeader);
            sLineLen += 1;
        }
        sHeader << "|";
        sLineLen += 1;
        printLine(sLineLen);
        std::cout << sHeader.str() << std::endl;
        printLine(sLineLen);
        return sLineLen;
    }

    size_t XyzEmployeeRecord::printHeader(size_t maxColumnLenParm, const EmpColumnBits &empCoulmnToPrintParm, int empTypeParm) {
        std::stringstream sHeader;
        size_t sLineLen = 0;
        sLineLen = getCommonEmpHeader(maxColumnLenParm, sHeader);

        if (FullTime == empTypeParm) {
            sLineLen += getFullTimeEmpHeader(sHeader);
            sLineLen += 2;
        }
        else if (Contract == empTypeParm) {
            sLineLen += getContractEmpHeader(sHeader);
            sLineLen += 1;
        }
        else if (Intern == empTypeParm) {
            sLineLen += getInternEmpHeader(sHeader);
            sLineLen += 2;
        }
        sHeader << "|";
        sLineLen += 2;
        printLine(sLineLen);
        std::cout << sHeader.str() << std::endl;
        printLine(sLineLen);
        return sLineLen;
    }

    void XyzEmployeeRecord::printAllEmpData(size_t maxColumnLenParm, const EmpColumnBits &empCoulmnToPrintParm) {
        size_t collegeLen = std::string("IIIT_Hyderabad").length();
        size_t agencyLen = std::string("Justice_League").length();
        std::cout << "| " << std::left << std::setw(maxColumnLenParm+1) << sEmpName;
        std::cout << "| " << std::left << std::setw(9) << sEmpID ;
        std::cout << "| " << std::left << std::setw(10) << sEmpType ;
        std::cout << "| " << std::left << std::setw(9) << sEmpStatus;
        std::cout << "| " << std::left << std::setw(13) << sEmpGender;
        std::cout << "| " << std::left << std::setw(14) << sEmpDOB;
        std::cout << "| " << std::left << std::setw(16) << sEmpDOJ;
        std::cout << "| " << std::left << std::setw(16) << sEmpDOL;
        if (empCoulmnToPrintParm.empFullTimeBit) {
            std::cout << "| " << std::left << std::setw(12) << sEmpLeavesAvailed;
            std::cout << "| " << std::left << std::setw(12) << sEmpLeavesLeft;
        }
        if (empCoulmnToPrintParm.empInternBit) {
            std::cout << "| " << std::left << std::setw(7) << sEmpBranch;
            std::cout << "| " << std::left << std::setw(collegeLen) << sEmpCollege;
        }
        if (empCoulmnToPrintParm.empContractBit) {
            std::cout << "| " << std::left << std::setw(agencyLen) << sEmpAgency;
        }
        std::cout << " |" << std::endl;
    }

    void XyzEmployeeRecord::printEmpData(size_t maxColumnLenParm, int sEmpTypeParm) {
        size_t collegeLen = std::string("IIIT_Hyderabad").length();
        size_t agencyLen = std::string("Justice_League").length();
        std::cout << "| " << std::left << std::setw(maxColumnLenParm+1) << sEmpName;
        std::cout << "| " << std::left << std::setw(9) << sEmpID ;
        std::cout << "| " << std::left << std::setw(10) << sEmpType ;
        std::cout << "| " << std::left << std::setw(9) << sEmpStatus;
        std::cout << "| " << std::left << std::setw(13) << sEmpGender;
        std::cout << "| " << std::left << std::setw(14) << sEmpDOB;
        std::cout << "| " << std::left << std::setw(16) << sEmpDOJ;
        std::cout << "| " << std::left << std::setw(16) << sEmpDOL;
        if (FullTime == sEmpTypeParm) {
            std::cout << "| " << std::left << std::setw(12) << sEmpLeavesAvailed;
            std::cout << "| " << std::left << std::setw(12) << sEmpLeavesLeft;
        }
        else if (Intern == sEmpTypeParm) {
            std::cout << "| " << std::left << std::setw(7) << sEmpBranch;
            std::cout << "| " << std::left << std::setw(collegeLen) << sEmpCollege;
        }
        else if (Contract == sEmpTypeParm) {
            std::cout << "| " << std::left << std::setw(agencyLen) << sEmpAgency;
        }
        std::cout << "|" << std::endl;
    }
}