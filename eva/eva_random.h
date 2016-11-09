// eva_random.h

#ifndef _EVA_RANDOM_H_
#define _EVA_RANDOM_H_

namespace eva {
    
class Random
{
public:
    Random();
    virtual ~Random();

    int data();

private:
    int m_rand;
};

}

#endif /* _EVA_RANDOM_H_ */

