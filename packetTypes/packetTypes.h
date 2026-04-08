#pragma once

enum class PacketType : uint16_t
{
    // login 100
    C_LOGIN  = 100,
    S_LOGIN  = 101,
    C_REGISTER = 102,
    S_REGISTER = 103,

    // poker 200
    C_GET_ROOM_LIST      = 200,
    S_GET_ROOM_LIST      = 201,
    C_CREATE_ROOM        = 202,
    S_CREATE_ROOM        = 203,
    C_JOIN_ROOM          = 204,
    S_JOIN_ROOM          = 205,
    C_LEAVE_ROOM         = 206,
    S_LEAVE_ROOM         = 207,
    C_START_GAME         = 208,
    S_START_GAME         = 209,
    C_BET_ACTION         = 210,
    S_BET_TURN           = 211,
    S_BET_RESULT         = 212,
    S_OPEN_COMMUNITY_CARDS = 213,
    S_GAME_RESULT        = 214,
};
