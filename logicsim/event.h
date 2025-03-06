#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
    //operator() that compares Events by time (min-heap)
    bool operator()(const Event* one, const Event* two) const {
        return one->time < two->time;
    }
} EventLess;
	
#endif
