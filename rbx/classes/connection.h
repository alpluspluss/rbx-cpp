//
// Created by alplusplus on 22/9/2024 AD.
//

#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{
public:
    void disconnect();
};

class Signal
{
public:
    Connection connect();
    Connection connectParallel();
    Connection once();
};

#endif
