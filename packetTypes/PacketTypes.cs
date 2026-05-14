public enum PacketType : ushort
{
    // login 100
    C_Login    = 100,
    S_Login    = 101,
    C_Register = 102,
    S_Register = 103,

    // poker 200
    C_GetRoomList        = 200,
    S_GetRoomList        = 201,
    C_CreateRoom         = 202,
    S_CreateRoom         = 203,
    C_JoinRoom           = 204,
    S_JoinRoom           = 205,
    C_LeaveRoom          = 206,
    S_LeaveRoom          = 207,
    C_StartGame          = 208,
    S_StartGame          = 209,
    C_BetAction          = 210,
    S_BetTurn            = 211,
    S_BetResult          = 212,
    S_OpenCommunityCards = 213,
    S_GameResult         = 214,
    S_Notice             = 215,

    // UDP — 로비 동기화 300
    C_UdpHello        = 300, // 첫 연결 핸드셰이크 (sessionId = 0으로 전송)
    C_LobbyMove       = 301, // 로비 캐릭터 이동 (TransformInfo)
    C_LobbyHeartbeat  = 302, // 연결 유지 핑
    S_UdpHandshakeAck = 350, // proto lobby_response.S_UDP_HELLO 와 동일 (sessionId 응답)
    S_LobbyPlayerMove = 352, // 특정 플레이어 이동 브로드캐스트
}
