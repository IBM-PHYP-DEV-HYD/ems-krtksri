#include "XyzInternEmployee.H"

using namespace EMS;

XyzInternEmployee::XyzInternEmployee(): 
mCollege (IIT_Delhi), 
mBranch(ECE) {

}

XyzInternEmployee::XyzInternEmployee(const std::string& sEmpIdParm, 
                                     const std::string& sNameParm, 
                                     EmpGender sGenderParm, 
                                     const Date& sDOBParm,
                                     EmpStatus sStatusParm,
                                     EmpType sTypeParm,
                                     const Date& sDOJParm,
                                     const Date& sDOLParm,
                                     Colleges sCollegeParm,
                                     Branch sBranchParm)
:XyzEmployeeImpl::XyzEmployeeImpl(sEmpIdParm, 
                                  sNameParm, 
                                  sGenderParm, 
                                  sDOBParm, 
                                  sStatusParm, 
                                  sTypeParm, 
                                  sDOJParm, 
                                  sDOLParm)
,mCollege (sCollegeParm)
,mBranch(sBranchParm) {
}

XyzInternEmployee::~XyzInternEmployee() {

}

void XyzInternEmployee::setCollege(Colleges collegeParm) {
    mCollege = collegeParm;
}

Colleges XyzInternEmployee::getCollege() {
    return mCollege;
}

void XyzInternEmployee::setBranch(Branch branchParm ) {
    mBranch = branchParm;
}

Branch XyzInternEmployee::getBranch() {
    return mBranch;
}

void XyzInternEmployee::getEmpRecord(XyzEmployeeRecord &empRecordParm) {
    XyzEmployeeImpl::getEmpRecord(empRecordParm);
    empRecordParm.sEmpBranch = empBranchNames[mBranch];
    empRecordParm.sEmpCollege = empCollegeNames[mCollege];
}

void XyzInternEmployee::printEmployeeDetails() {
    XyzEmployeeImpl::printEmployeeDetails();
    std::cout << "College Name     : " << empCollegeNames[mCollege] << std::endl;
    std::cout << "Branch Name      : " << empBranchNames[mBranch] << std::endl;
}