// max.hpp

#ifndef _MAX_H_
#define _MAX_H_

/**
 * Return the max of two values.
 * @param v1 -- The first value.
 * @param v2 -- The second value.
 * @return   -- The max.
 */
template<typename T>
inline T man(T v1, T v2)
{
    return (v1 > v2) ? v1 : v2;
}

#endif /* _MAX_H_ */

