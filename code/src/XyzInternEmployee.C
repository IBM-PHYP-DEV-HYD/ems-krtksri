#include "XyzInternEmployee.H"

XyzInternEmployee::XyzInternEmployee(): 
mCollege (IIT_Delhi), 
mBranch(ECE) {

}

XyzInternEmployee::XyzInternEmployee(const std::string& sEmpIdParm, const std::string& sNameParm, EmpGender sGenderParm, 
    const Date& sDOBParm, EmpStatus sStatusParm, EmpType sTypeParm, const Date& sDOJParm,
    const Date& sDOLParm, Colleges sCollegeParm, Branch sBranchParm): 
XyzEmployeeImpl::XyzEmployeeImpl(sEmpIdParm, sNameParm, sGenderParm, sDOBParm, sStatusParm, sTypeParm, sDOJParm, sDOLParm),
mCollege (sCollegeParm), 
mBranch(sBranchParm) {
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

void XyzInternEmployee::printEmployeeSummary(size_t maxColumnLenParm, bool printAll) {
    //employee summary as a row in a table
    std::stringstream sRow;
    size_t collegeLen = empCollegeNames[IIIT_Hyderabad].length();
    size_t agencyLen = empAgencyNames[Justice_League].length();
    XyzEmployeeImpl::getEmployeeSummary(maxColumnLenParm, sRow);
    if (printAll) {
        sRow << "| " << std::left << std::setw(12) << "N/A";
        sRow << "| " << std::left << std::setw(12) << "N/A";
    }
    sRow << "| " << std::left << std::setw(7) << empBranchNames[mBranch];
    sRow << "| " << std::left << std::setw(collegeLen+1) << empCollegeNames[mCollege];
    if (printAll) {
        sRow << "| " << std::left << std::setw(agencyLen+1) << "N/A ";
    }
    sRow << std::left << "|";
    std::cout << sRow.str() << std::endl;
}

void XyzInternEmployee::printEmployeeDetails() {
    XyzEmployeeImpl::printEmployeeDetails();
    std::cout << "College Name     : " << empCollegeNames[mCollege] << std::endl;
    std::cout << "Branch Name      : " << empBranchNames[mBranch] << std::endl;
}