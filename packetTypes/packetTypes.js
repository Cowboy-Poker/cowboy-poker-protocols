export const PACKET_TYPE = {
  // login 100
  C_LOGIN:    100,
  S_LOGIN:    101,
  C_REGISTER: 102,
  S_REGISTER: 103,

  // poker 200
  C_GET_ROOM_LIST:        200,
  S_GET_ROOM_LIST:        201,
  C_CREATE_ROOM:          202,
  S_CREATE_ROOM:          203,
  C_JOIN_ROOM:            204,
  S_JOIN_ROOM:            205,
  C_LEAVE_ROOM:           206,
  S_LEAVE_ROOM:           207,
  C_START_GAME:           208,
  S_START_GAME:           209,
  C_BET_ACTION:           210,
  S_BET_TURN:             211,
  S_BET_RESULT:           212,
  S_OPEN_COMMUNITY_CARDS: 213,
  S_GAME_RESULT:          214,
  S_NOTICE:               215,

  // UDP — 로비 동기화 300
  C_UDP_HELLO:         300, // 첫 연결 핸드셰이크 (sessionId = 0으로 전송)
  C_LOBBY_MOVE:        301, // 로비 캐릭터 이동 (TransformInfo)
  C_LOBBY_HEARTBEAT:     302,
  C_BUY_WEAPON:          303,
  C_BATTLE_ENTER:        304,
  S_UDP_HANDSHAKE_ACK:   350,
  S_LOBBY_PLAYER_MOVE:   352,
  S_LOBBY_PLAYER_LEAVE:  353,
  S_PLAYER_INFO:         354,
  S_BUY_WEAPON_RESULT:   355,
  S_BATTLE_ENTER_RESULT: 356,
};
