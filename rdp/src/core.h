#ifndef CORE_H
#define CORE_H
 
#include "../include/lint.h"
#include "../include/platform.h"
#include "../include/rdp_def.h"
#include "config.h"

i32 core_startup(rdp_startup_param* param);
i32 core_startup_get_param(rdp_startup_param* param);
i32 core_cleanup();
i32 core_getsyserror();
i32 core_getsyserrordesc(i32 err, char* desc, ui32* desc_len);

i32 core_socket_create(rdp_socket_create_param* param, RDPSOCKET* sock);
i32 core_socket_get_create_param(RDPSOCKET sock, rdp_socket_create_param* param);
i32 core_socket_get_state(RDPSOCKET sock, ui32* state);
i32 core_socket_close(RDPSOCKET sock);
i32 core_socket_bind(RDPSOCKET sock, const char* ip, ui32 port);
i32 core_socket_listen(RDPSOCKET u);
i32 core_socket_connect(RDPSOCKET sock, const char* ip, ui32 port, ui32 timeout, const ui8* buf, ui16 buf_len, RDPSESSIONID* session_id);
i32 core_socket_recv(ui32 timeout);

i32 core_session_close(RDPSOCKET sock, RDPSESSIONID session_id, i32 reason);
i32 core_session_get_state(RDPSOCKET sock, RDPSESSIONID session_id, ui32* state);
i32 core_session_send(RDPSOCKET sock, RDPSESSIONID session_id, const ui8* buf, ui16 buf_len,ui32 flags);
bool core_session_is_in_come(RDPSESSIONID session_id);

i32 core_udp_send(RDPSOCKET sock, const char* ip, ui32 port, const ui8* buf, ui16 buf_len);

i32 core_addr_to(const sockaddr* addr, ui32 addrlen, char* ip, ui32* iplen, ui32* port);
#endif