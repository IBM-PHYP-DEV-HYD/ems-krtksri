#include "XyzContractEmployee.H"

using namespace EMS;
XyzContractEmployee::XyzContractEmployee() {

}

XyzContractEmployee::XyzContractEmployee(const std::string& sEmpIdParm,
                                         const std::string& sNameParm,
                                         EmpGender sGenderParm,
                                         const Date& sDOBParm,
                                         EmpStatus sStatusParm,
                                         EmpType sTypeParm,
                                         const Date& sDOJParm,
                                         const Date& sDOLParm,
                                         Agency agencyParm)
:XyzEmployeeImpl::XyzEmployeeImpl(sEmpIdParm, 
                                  sNameParm,
                                  sGenderParm,
                                  sDOBParm,
                                  sStatusParm,
                                  sTypeParm,
                                  sDOJParm,
                                  sDOLParm)
,mAgency(agencyParm)
{
}

XyzContractEmployee::~XyzContractEmployee() {

}

void XyzContractEmployee::setAgency(Agency agencyParm) {
    mAgency = agencyParm;
}

Agency XyzContractEmployee::getAgency() {
    return mAgency;
}

void XyzContractEmployee::printEmployeeDetails() {
    XyzEmployeeImpl::printEmployeeDetails();
    std::cout << "Agency Name      : " << empAgencyNames[mAgency] << std::endl;
}

void XyzContractEmployee::getEmpRecord(XyzEmployeeRecord &empRecordParm) {
    XyzEmployeeImpl::getEmpRecord(empRecordParm);
    empRecordParm.sEmpAgency = empAgencyNames[mAgency];
}