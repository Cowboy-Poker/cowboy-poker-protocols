#pragma once

enum class PacketType
{
    // login 100
    C_LOGIN    = 100,
    S_LOGIN    = 101,
    C_REGISTER = 102,
    S_REGISTER = 103,

    // poker 200
    C_GET_ROOM_LIST        = 200,
    S_GET_ROOM_LIST        = 201,
    C_CREATE_ROOM          = 202,
    S_CREATE_ROOM          = 203,
    C_JOIN_ROOM            = 204,
    S_JOIN_ROOM            = 205,
    C_LEAVE_ROOM           = 206,
    S_LEAVE_ROOM           = 207,
    C_START_GAME           = 208,
    S_START_GAME           = 209,
    C_BET_ACTION           = 210,
    S_BET_TURN             = 211,
    S_BET_RESULT           = 212,
    S_OPEN_COMMUNITY_CARDS = 213,
    S_GAME_RESULT          = 214,
    S_NOTICE               = 215,

    // UDP — 로비 동기화 300
    //
    // C_UDP_HELLO (300)  클라이언트 → 서버
    //   헤더  : [uint64 sessionId=0][uint32 seq=1][uint16 id=300]
    //   페이로드 (raw LE):
    //     [0..1]  uint16  userId_len
    //     [2.. ?] utf8    userId     (로그인 시 Node.js 서버에서 받은 user_id)
    //
    // S_UDP_HANDSHAKE_ACK (350)  서버 → 클라이언트
    //   헤더  : [uint64 sessionId(서버발급)][uint32 seq][uint16 id=350]
    //   페이로드 (raw LE, 8바이트 고정):
    //     [0..7]  uint64  sessionId  (헤더와 동일 값)
    //
    // S_PLAYER_INFO (354)  서버 → 클라이언트
    //   핸드셰이크 완료 후 Redis 조회 결과 전송. 총기 구매 등 상태 변경 시에도 재전송됨.
    //   헤더  : [uint64 sessionId][uint32 seq][uint16 id=354]
    //   페이로드 (raw LE, 최소 50바이트 + 문자열):
    //     [ 0.. 7]  uint64  sessionId
    //     [ 8..11]  int32   hp
    //     [12..19]  int64   balance
    //     [20..23]  int32   char_type
    //     [24..27]  float   pos_x
    //     [28..31]  float   pos_y
    //     [32..35]  float   pos_z
    //     [36..39]  float   rot
    //     [40..43]  int32   weapon
    //     [44..47]  int32   ammo_type
    //     [48..49]  uint16  nickname_len
    //     [50.. ?]  utf8    nickname
    //     [  .. +1] uint16  scene_len
    //     [  .. +?] utf8    scene
    //
    C_UDP_HELLO          = 300, // 핸드셰이크 — payload: [uint16 userIdLen][utf8 userId]
    C_LOBBY_MOVE         = 301, // 로비 캐릭터 이동 (TransformInfo)
    C_LOBBY_HEARTBEAT    = 302, // 연결 유지 핑
    // C_BUY_WEAPON (303)  클라이언트 → 서버
    //   payload (raw LE):
    //     [0..1]   uint16  userId_len
    //     [2.. ?]  utf8    userId
    //     [?+0..3] int32   weapon_type  (WeaponType enum: 1=PISTOL, 2=RIFLE)
    C_BUY_WEAPON         = 303, // 총기 구매 요청
    // C_BATTLE_ENTER (304)  클라이언트 → 서버 (결투 성사)
    //   payload (raw LE):
    //     [0..1]   uint16  player1_len
    //     [2.. ?]  utf8    player1UserId
    //     [?+0..1] uint16  player2_len
    //     [?+2..]  utf8    player2UserId
    C_BATTLE_ENTER       = 304,
    S_UDP_HANDSHAKE_ACK  = 350, // 핸드셰이크 응답 — payload: [uint64 sessionId] (8B)
    S_LOBBY_PLAYER_MOVE  = 352, // 플레이어 이동 브로드캐스트
    S_LOBBY_PLAYER_LEAVE = 353, // 플레이어 퇴장 — 해당 sessionId 캐릭터 제거
    S_PLAYER_INFO        = 354, // 내 플레이어 정보 (Redis 조회 결과, raw LE)
    // S_BUY_WEAPON_RESULT (355)  서버 → 클라이언트
    //   페이로드 (raw LE, 21바이트 고정):
    //     [ 0.. 7]  uint64  sessionId
    //     [ 8.. 8]  uint8   success    (1=성공, 0=실패)
    //     [ 9..12]  int32   weaponType
    //     [13..20]  int64   balance    (갱신된 잔액, 실패 시 현재 잔액)
    S_BUY_WEAPON_RESULT  = 355, // 총기 구매 결과
    // S_BATTLE_ENTER_RESULT (356)  서버 → 클라이언트
    //   payload (raw LE, 9바이트 고정):
    //     [0..7]  uint64  sessionId
    //     [8..8]  uint8   success (1=성공)
    S_BATTLE_ENTER_RESULT = 356,
    //
    // weaponType enum (WeaponType):
    //   0 = NONE
    //   1 = RIFLE         $10,000   pellets=1  fireRate=0.3s  mag=8   head/body/limb=150/60/30
    //   2 = SHOTGUN_LV1   $300      pellets=10 fireRate=0.2s  mag=2   30/10/5 per pellet
    //   3 = SHOTGUN_LV2   $3,000    pellets=10 fireRate=0.2s  mag=2   30/10/5 per pellet
    //   4 = REVOLVER_LV1  $500      pellets=1  fireRate=0.5s  mag=6   head/body/limb=120/40/20
    //   5 = REVOLVER_LV2  $5,000    pellets=1  fireRate=0.5s  mag=6   head/body/limb=120/40/20
};
