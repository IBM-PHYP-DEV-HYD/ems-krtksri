#include "XyzContractEmployee.H"

XyzContractEmployee::XyzContractEmployee() {

}

XyzContractEmployee::XyzContractEmployee(const std::string& sEmpIdParm, const std::string& sNameParm, EmpGender sGenderParm, 
    const Date& sDOBParm, EmpStatus sStatusParm, EmpType sTypeParm, const Date& sDOJParm,
    const Date& sDOLParm, Agency agencyParm) : 
XyzEmployeeImpl::XyzEmployeeImpl(sEmpIdParm, sNameParm, sGenderParm, sDOBParm, sStatusParm, sTypeParm, sDOJParm, sDOLParm),
mAgency(agencyParm)
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

void XyzContractEmployee::printEmployeeSummary(size_t maxColumnLenParm, bool printAll) {
    //employee summary as a row in a table
    std::stringstream sRow;
    size_t collegeLen = empCollegeNames[IIIT_Hyderabad].length();
    size_t agencyLen = empAgencyNames[Justice_League].length();
    XyzEmployeeImpl::getEmployeeSummary(maxColumnLenParm, sRow);
    if (printAll) {
        sRow << "| " << std::left << std::setw(12) << "N/A";
        sRow << "| " << std::left << std::setw(12) << "N/A";
        sRow << "| " << std::left << std::setw(7) << "N/A";
        sRow << "| " << std::left << std::setw(collegeLen+1) << "N/A";
    }
    sRow << "| " << std::left << std::setw(agencyLen+1) << empAgencyNames[mAgency]<< "|";
    std::cout << sRow.str() << std::endl;
}

void XyzContractEmployee::printEmployeeDetails() {
    XyzEmployeeImpl::printEmployeeDetails();
    std::cout << "Agency Name      : " << empAgencyNames[mAgency] << std::endl;
}