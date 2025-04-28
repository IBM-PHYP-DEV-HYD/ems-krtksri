#include "XyzFullTimeEmployee.H"

XyzFullTimeEmployee::XyzFullTimeEmployee() {

}

XyzFullTimeEmployee::XyzFullTimeEmployee(XyzEmployeeImpl& empImplParm, uint32_t sLeavesAvailed, uint32_t sLeavesLeft) :
XyzEmployeeImpl::XyzEmployeeImpl(empImplParm),
mNumOfLeavesAvailed(sLeavesAvailed), mNumOfLeavesLeft(sLeavesLeft){

}

XyzFullTimeEmployee::XyzFullTimeEmployee(const std::string& sEmpIdParm, const std::string& sNameParm, EmpGender sGenderParm, 
    const Date& sDOBParm, EmpStatus sStatusParm, EmpType sTypeParm, const Date& sDOJParm,
    const Date& sDOLParm, uint32_t sLeavesAvailed, uint32_t sLeavesLeft):
XyzEmployeeImpl::XyzEmployeeImpl(sEmpIdParm, sNameParm, sGenderParm, sDOBParm, sStatusParm, sTypeParm, sDOJParm, sDOLParm),
mNumOfLeavesAvailed(sLeavesAvailed),
mNumOfLeavesLeft(sLeavesLeft)
{
}

XyzFullTimeEmployee::~XyzFullTimeEmployee() {

}

void XyzFullTimeEmployee::setNumOfLeavesAvailed(uint32_t numOfLeaves) {
    mNumOfLeavesAvailed = numOfLeaves;
}

uint32_t XyzFullTimeEmployee::getNumOfLeavesAvailed() {
     return mNumOfLeavesAvailed;
}

void XyzFullTimeEmployee::setNumOfLeavesLeft(uint32_t numOfLeaves) {
    mNumOfLeavesLeft = numOfLeaves;
}

uint32_t XyzFullTimeEmployee::getNumOfLeavesLeft() {
     return mNumOfLeavesLeft;
}

void XyzFullTimeEmployee::updateNumOfLeavesLeft(uint32_t leavesParm) {
    mNumOfLeavesLeft += leavesParm; 
}

void XyzFullTimeEmployee::printEmployeeSummary(size_t maxColumnLenParm, bool printAll) {
    //employee summary as a row in a table
    std::stringstream sRow;
    size_t collegeLen = empCollegeNames[IIIT_Hyderabad].length();
    size_t agencyLen = empAgencyNames[Justice_League].length();
    XyzEmployeeImpl::getEmployeeSummary(maxColumnLenParm, sRow);
    sRow << "| " << std::left << std::setw(12) << getNumOfLeavesAvailed();
    sRow << "| " << std::left << std::setw(12) << getNumOfLeavesLeft();
    if (printAll) {
        sRow << "| " << std::left << std::setw(7) << "N/A ";
        sRow << "| " << std::left << std::setw(collegeLen+1) << "N/A ";
        sRow << "| " << std::left << std::setw(agencyLen+1) << "N/A ";
    }
    sRow << std::left << "|";
    std::cout << sRow.str() << std::endl;
}

void XyzFullTimeEmployee::printEmployeeDetails() {
    XyzEmployeeImpl::printEmployeeDetails();
    std::cout << "Leaves Availed   : " << mNumOfLeavesAvailed << std::endl;
    std::cout << "Leaves Left      : " << mNumOfLeavesLeft << std::endl;
}