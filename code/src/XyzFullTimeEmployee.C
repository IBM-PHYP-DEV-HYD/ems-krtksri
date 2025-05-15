#include "XyzFullTimeEmployee.H"

using namespace EMS;

XyzFullTimeEmployee::XyzFullTimeEmployee() {

}

XyzFullTimeEmployee::XyzFullTimeEmployee(XyzEmployeeImpl& empImplParm, uint32_t sLeavesAvailed, uint32_t sLeavesLeft) :
XyzEmployeeImpl::XyzEmployeeImpl(empImplParm),
mNumOfLeavesAvailed(sLeavesAvailed), mNumOfLeavesLeft(sLeavesLeft){

}

XyzFullTimeEmployee::XyzFullTimeEmployee(const std::string& sEmpIdParm,
                                         const std::string& sNameParm,
                                         EmpGender sGenderParm, 
                                         const Date& sDOBParm,
                                         EmpStatus sStatusParm,
                                         EmpType sTypeParm,
                                         const Date& sDOJParm,
                                         const Date& sDOLParm,
                                         uint32_t sLeavesAvailed,
                                         uint32_t sLeavesLeft)
:XyzEmployeeImpl::XyzEmployeeImpl(sEmpIdParm,
                                  sNameParm,
                                  sGenderParm,
                                  sDOBParm,
                                  sStatusParm,
                                  sTypeParm,
                                  sDOJParm,
                                  sDOLParm)
,mNumOfLeavesAvailed(sLeavesAvailed)
,mNumOfLeavesLeft(sLeavesLeft)
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

void XyzFullTimeEmployee::printEmployeeDetails() {
    XyzEmployeeImpl::printEmployeeDetails();
    std::cout << "Leaves Availed   : " << mNumOfLeavesAvailed << std::endl;
    std::cout << "Leaves Left      : " << mNumOfLeavesLeft << std::endl;
}

void XyzFullTimeEmployee::getEmpRecord(XyzEmployeeRecord &empRecordParm) {
    XyzEmployeeImpl::getEmpRecord(empRecordParm);
    empRecordParm.sEmpLeavesAvailed = std::to_string(mNumOfLeavesAvailed);
    empRecordParm.sEmpLeavesLeft = std::to_string(mNumOfLeavesLeft);
}