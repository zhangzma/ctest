// person.h

#ifndef _PERSON_H_
#define _PERSON_H_



class CPerson
{
public:
    CPerson();
    virtual ~CPerson();

private:
    std::string _name;
    std::string _addr;
    std::string _phone;
};


#endif /* _PERSON_H_ */
