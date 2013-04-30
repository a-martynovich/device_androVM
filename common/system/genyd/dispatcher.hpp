#ifndef DISPATCHER_HPP_
#define DISPATCHER_HPP_

#include "global.hpp"

class Dispatcher {

public:
    Dispatcher(void);
    ~Dispatcher(void);

private:
    Dispatcher(const Dispatcher &);
    Dispatcher operator=(const Dispatcher &);

private:
    typedef void (Dispatcher::*t_get_callback)(const Request &, Reply *);
    std::map<int, t_get_callback> getCallbacks;

    typedef void (Dispatcher::*t_set_callback)(const Request &, Reply *);
    std::map<int, t_set_callback> setCallbacks;

    /********************\
    // Generic requests \\
    \********************/

    // Answer "Ping" request
    void treatPing(const Request &request, Reply *reply);

    // Answer "GetParam" requests
    void treatGetParam(const Request &request, Reply *reply);

    // Answer "SetParam" requests
    void treatSetParam(const Request &request, Reply *reply);

    // Fallback for unknown requests
    void unknownRequest(const Request &request, Reply *reply);

    // Answer "GetParam AndroidVersion" requests
    void getAndroidVersion(const Request &request, Reply *reply);

    /********************\
    // Battery requests \\
    \********************/

    // Answer "SetParam Battery Status"
    void setBatteryStatus(const Request &request, Reply *reply);

public:
    // Switch among requests
    Reply *dispatchRequest(const Request &request);

};

#endif
