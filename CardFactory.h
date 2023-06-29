#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "CCard.h"
#include "CStudent.h"
#include "CPlagiarismHearing.h"
#include "CCourseAccreditation.h"
#include "CFeedbackForum.h"
#include "CIndustrialPlacement.h"
#include "CPassLeader.h"
#include "CGraduateStudent.h"
#include "CSerialOffender.h"

using namespace std;

enum class ECardType : int {
    Student = 1,
    PlagiarismHearing = 2,
    CourseAccreditation = 3,
    FeedbackForum = 4,
    SIndustrialPlacement = 5,
    SPassLeader = 6,
    MResearchFunding = 7,
    MMitigatingCircumstances = 8,
    SEasyTarget = 9,
    SSerialOffender = 10,
    SGraduateStudent = 11
};

shared_ptr<CCard> NewCard(ECardType card, istream& file);