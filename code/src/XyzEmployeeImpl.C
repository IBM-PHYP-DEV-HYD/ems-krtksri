#include <sstream>
#include <iomanip>
#include <string>
#include "XyzEmployeeImpl.H"
#include "Utilities.H"

XyzEmployeeImpl::XyzEmployeeImpl() {

}

XyzEmployeeImpl::XyzEmployeeImpl (const std::string& sEmpIdParm, const std::string& sNameParm, EmpGender sGenderParm, const Date& sDOBParm, 
                EmpStatus sStatusParm, EmpType sTypeParm, const Date& sDOJParm, const Date& sDOLParm) :
mEmpId(sEmpIdParm),
mEmpName(sNameParm),
mEmpGender(sGenderParm),
mEmpDOB(sDOBParm),
mEmpStatus(sStatusParm),
mEmpType(sTypeParm),
mEmpDOJ(sDOJParm),
mEmpDOL(sDOLParm){
}

XyzEmployeeImpl::~XyzEmployeeImpl() {

}

XyzEmployeeImpl::XyzEmployeeImpl(const XyzEmployeeImpl& emp) {
    *this = emp;
}

XyzEmployeeImpl& XyzEmployeeImpl::operator=(const XyzEmployeeImpl& objParm) {
    if (this != &objParm) {
        this->mEmpId = objParm.mEmpId;
        this->mEmpDOB = objParm.mEmpDOB;
        this->mEmpDOJ = objParm.mEmpDOJ;
        this->mEmpDOL = objParm.mEmpDOL;
        this->mEmpName = objParm.mEmpName;
        this->mEmpGender = objParm.mEmpGender;
        this->mEmpStatus = objParm.mEmpStatus;
        this->mEmpType = objParm.mEmpType;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& osParm, XyzEmployeeImpl& empObjectTypeParm)
{
    osParm <<"Employee Name   : " <<empObjectTypeParm.getEmployeeName() << std::endl;
    osParm <<"Employee ID     : " <<empObjectTypeParm.getEmployeeID() << std::endl;
    osParm <<"Employee Type   : " << getEmployeeTypeName(empObjectTypeParm.getEmployeeType()) << std::endl;
    osParm <<"Employee Status : " << getEmployeeStatusName(empObjectTypeParm.getEmployeeStatus()) << std::endl;
    osParm <<"Employee Gender : " << getEmployeeGenderName(empObjectTypeParm.getEmployeeGender()) << std::endl;
    osParm <<"Employee DOB    : " <<empObjectTypeParm.getEmployeeDOB().toString() << std::endl;
    osParm <<"Employee DOJ    : " <<empObjectTypeParm.getEmployeeDOJ().toString() << std::endl;
    osParm <<"Employee DOL    : " <<empObjectTypeParm.getEmployeeDOL().toString() << std::endl;
    return osParm;
}

std::string XyzEmployeeImpl::getEmployeeID() {
    return mEmpId;
}

std::string XyzEmployeeImpl::getEmployeeName() {
    return mEmpName;
}

EmpGender XyzEmployeeImpl::getEmployeeGender() {
    return mEmpGender;
}

Date XyzEmployeeImpl::getEmployeeDOB() {
    return mEmpDOB;
}

Date XyzEmployeeImpl::getEmployeeDOJ() {
    return mEmpDOJ;
}

Date XyzEmployeeImpl::getEmployeeDOL() {
    return mEmpDOL;
}

EmpType XyzEmployeeImpl::getEmployeeType() {
    return mEmpType;
}

EmpStatus XyzEmployeeImpl::getEmployeeStatus() {
    return mEmpStatus;
}

void XyzEmployeeImpl::setEmployeeDOJ(Date& DOBParm) {
    mEmpDOB = DOBParm;
}

void XyzEmployeeImpl::setEmployeeDOL(Date& DOLParm) {
    mEmpDOL = DOLParm;
}

void XyzEmployeeImpl::setEmployeeType(EmpType typeParm) {
    mEmpType = typeParm;
}

void XyzEmployeeImpl::setEmployeeStatus(EmpStatus statusParm) {
    mEmpStatus = statusParm;
}

void XyzEmployeeImpl::updateNumOfLeavesLeft(uint32_t leaveParm) {
// The definition will be added by the Full-time class
}

void XyzEmployeeImpl::getEmployeeSummary(size_t maxColumnLenParm, std::stringstream& sEmpInfoParm) {
    sEmpInfoParm.str("");
    sEmpInfoParm.clear();
    sEmpInfoParm << "| " << std::left << std::setw(maxColumnLenParm + 1) <<  getEmployeeName();
    sEmpInfoParm << "| " << std::left << std::setw(9) << getEmployeeID();
    sEmpInfoParm << "| " << std::left << std::setw(11) << getEmployeeTypeName(getEmployeeType());
    sEmpInfoParm << "| " << std::left << std::setw(9) << getEmployeeStatusName(getEmployeeStatus());
    sEmpInfoParm << "| " << std::left << std::setw(13) << getEmployeeGenderName(getEmployeeGender());
    sEmpInfoParm << "| " << std::left << std::setw(14) << getEmployeeDOB().toString();
    sEmpInfoParm << "| " << std::left << std::setw(16) << getEmployeeDOJ().toString();
    
    std::string sDOL = getEmployeeDOL().toString();
    sEmpInfoParm << "| " << std::left << std::setw(16) << (((FullTime == getEmployeeType()) && (Resigned != getEmployeeStatus())) ? "N/A" : sDOL);
}

void XyzEmployeeImpl::printEmployeeSummary(size_t maxColumnLenParm, bool printAll) {
    std::stringstream sRow;
    getEmployeeSummary(maxColumnLenParm, sRow);
    sRow << std::left << "|";
    std::cout << sRow.str() << std::endl;
}

void XyzEmployeeImpl::printEmployeeDetails() {
    std::cout << "Employee Name    : " << getEmployeeName() << std::endl;
    std::cout << "Employee ID      : " << getEmployeeID() << std::endl;
    std::cout << "Employee Type    : " << getEmployeeTypeName(mEmpType) << std::endl;
    std::cout << "Employee Status  : " << getEmployeeStatusName(mEmpStatus) << std::endl;
    std::cout << "Gender           : " << getEmployeeGenderName(mEmpGender) << std::endl;
    std::cout << "Date of Birth    : " << getEmployeeDOB().toString() << std::endl;
    std::cout << "Date of Joining  : " << getEmployeeDOJ().toString() << std::endl;
    if (FullTime != mEmpType) {
        std::cout << "Date of Leaving  : " << getEmployeeDOL().toString() << std::endl;
    }
    else {
        std::cout << "Date of Leaving  : " << "N/A" << std::endl;
    }
}
