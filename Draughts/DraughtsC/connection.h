#ifndef CONNECTION_H
#define CONNECTION_H

#endif // CONNECTION_H
#pragma once
#include <iostream>

class Connection
{
public:
    static int client_sd;

    void receive_descriptor(const int& arg)
    {
        client_sd = arg;
    }
};
