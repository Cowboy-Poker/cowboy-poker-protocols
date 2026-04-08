public enum PacketType : ushort
{
    // login 100
    C_Login  = 100,
    S_Login  = 101,
    C_Register = 102,
    S_Register = 103,

    // poker 200
    C_GetRoomList       = 200,
    S_GetRoomList       = 201,
    C_CreateRoom        = 202,
    S_CreateRoom        = 203,
    C_JoinRoom          = 204,
    S_JoinRoom          = 205,
    C_LeaveRoom         = 206,
    S_LeaveRoom         = 207,
    C_StartGame         = 208,
    S_StartGame         = 209,
    C_BetAction         = 210,
    S_BetTurn           = 211,
    S_BetResult         = 212,
    S_OpenCommunityCards = 213,
    S_GameResult        = 214,
}
