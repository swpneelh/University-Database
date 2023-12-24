#ifndef PAIR_H_
#define PAIR_H_

template <typename T1, typename T2>
class Pair {
public:

    T1 first;
    T2 second;

    Pair(T1 f, T2 s) : first(f), second(s) {

    }

    Pair() {}

};
#endif 
