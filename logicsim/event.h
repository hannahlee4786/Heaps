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
    bool operator()(Event& one, Event& two) {
        if (one.time < two.time) {
            return true;
        }
        return false;
    }
} EventLess;
	
#endif
