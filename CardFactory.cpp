#include "CardFactory.h"

shared_ptr<CCard> NewCard(ECardType card, istream& file)
{
    shared_ptr<CCard> pCard = nullptr;
    switch (card)
    {
    case ECardType::Student:
        pCard = make_shared<CStudent>(file);
        break;
    case ECardType::PlagiarismHearing:
        pCard = make_shared<CPlagiaristHearing>(file);
        break;
    case ECardType::CourseAccreditation:
        pCard = make_shared<CCourseAccreditation>(file);
        break;
    case ECardType::FeedbackForum:
        pCard = make_shared<CFeedbackForum>(file);
        break;
    case ECardType::SIndustrialPlacement:
        pCard = make_shared<CIndustrialistPlacement>(file);
        break;
    case ECardType::SPassLeader:
        pCard = make_shared<CPassLeader>(file);
        break;
    case ECardType::SSerialOffender:
        pCard = make_shared<CSerialOffender>(file);
        break;
    case ECardType::SGraduateStudent:
        pCard = make_shared<CGraduateStudent>(file);
        break;
    default:
        pCard = make_shared<CCard>(file);
        break;
    }
    return pCard;
}
