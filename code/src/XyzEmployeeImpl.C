#include <sstream>
#include <iomanip>
#include <string>
#include "XyzEmployeeImpl.H"
#include "Utilities.H"

using namespace EMS;
XyzEmployeeImpl::XyzEmployeeImpl() {

}

XyzEmployeeImpl::XyzEmployeeImpl (const std::string& sEmpIdParm, 
                                  const std::string& sNameParm,
                                  EmpGender sGenderParm,
                                  const Date& sDOBParm,
                                  EmpStatus sStatusParm,
                                  EmpType sTypeParm,
                                  const Date& sDOJParm,
                                  const Date& sDOLParm)
:mEmpId(sEmpIdParm)
,mEmpName(sNameParm)
,mEmpGender(sGenderParm)
,mEmpDOB(sDOBParm)
,mEmpStatus(sStatusParm)
,mEmpType(sTypeParm)
,mEmpDOJ(sDOJParm)
,mEmpDOL(sDOLParm){
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

void XyzEmployeeImpl::getEmpRecord(XyzEmployeeRecord &empRecordParm) {
    empRecordParm.sEmpName = mEmpName;
    empRecordParm.sEmpID = mEmpId;
    empRecordParm.sEmpType = empTypeNames[mEmpType];
    empRecordParm.sEmpStatus = empStatusNames[mEmpStatus];
    empRecordParm.sEmpGender = empGenderNames[mEmpGender];
    empRecordParm.sEmpDOB = mEmpDOB.toString();
    empRecordParm.sEmpDOJ = mEmpDOJ.toString();
    empRecordParm.sEmpDOL = mEmpDOL.toString();
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
