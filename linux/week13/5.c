#include<tmp.h>

int client_fds[MAXCONCURRENTCONNECT];
int main(int argc, const char * argv[])
{
    char input_msg[MAXDATASIZE];
    char recv_msg[MAXDATASIZE];
    //本地地址
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVPORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(&(server_addr.sin_zero), 8);
    //创建socket
    int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock_fd == -1)
    {
        perror("socket error");
        return 1;
    }
    //绑定socket
    int bind_result = bind(server_sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(bind_result == -1)
    {
        perror("bind error");
        return 1;
    }
    //listen
    if(listen(server_sock_fd, BACKLOG) == -1)
    {
        perror("listen error");
        return 1;
    }
    //fd_set
    fd_set server_fd_set;
    int max_fd = -1;
    struct timeval tv;  //超时时间设置
    while(1)
    {
        tv.tv_sec = 20;
        tv.tv_usec = 0;
        FD_ZERO(&server_fd_set);
        FD_SET(STDIN_FILENO, &server_fd_set);
        if(max_fd <STDIN_FILENO)
        {
            max_fd = STDIN_FILENO;
        }
    //服务器端socket
        FD_SET(server_sock_fd, &server_fd_set);
       // printf("server_sock_fd=%d\n", server_sock_fd);
        if(max_fd < server_sock_fd)
        {
            max_fd = server_sock_fd;
        }
    //客户端连接
        for(int i =0; i < MAXCONCURRENTCONNECT; i++)
        {
            //printf("client_fds[%d]=%d\n", i, client_fds[i]);
            if(client_fds[i] != 0)
            {
                FD_SET(client_fds[i], &server_fd_set);
                if(max_fd < client_fds[i])
                {
                    max_fd = client_fds[i];
                }
            }
        }
        int ret = select(max_fd + 1, &server_fd_set, NULL, NULL, &tv);
        if(ret < 0)
        {
            perror("select 出错\n");
            continue;
        }
        else if(ret == 0)
        {
            printf("select 超时\n");
            continue;
        }
        else
        {
            //ret 为未状态发生变化的文件描述符的个数
            if(FD_ISSET(STDIN_FILENO, &server_fd_set))
            {
                printf("发送消息：\n");
                bzero(input_msg, MAXDATASIZE);
                fgets(input_msg, MAXDATASIZE, stdin);
                //输入 end 则退出服务器
                if(strncmp(input_msg, "end", 3) == 0)
                    exit(0);
                for(int i = 0; i < MAXCONCURRENTCONNECT; i++)
                {
                    if(client_fds[i] != 0)
                    {
                        printf("client_fds[%d]=%d\n", i, client_fds[i]);
                        send(client_fds[i], input_msg, MAXDATASIZE, 0);
                    }
                }
            }
            if(FD_ISSET(server_sock_fd, &server_fd_set))
            {
                struct sockaddr_in client_address;
                socklen_t address_len;
                int client_sock_fd = accept(server_sock_fd, (struct sockaddr *)&client_address, &address_len);
                printf("new connection client_sock_fd = %d\n", client_sock_fd);
                if(client_sock_fd > 0)
                {
                    int index = -1;
                    for(int i = 0; i < MAXCONCURRENTCONNECT; i++)
                    {
                        if(client_fds[i] == 0)
                        {
                            index = i;
                            client_fds[i] = client_sock_fd;
                            break;
                        }
                    }
                    if(index >= 0)
                        printf("新客户端(%d)加入成功 %s:%d\n", index,
                        inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    else
                    {
                        bzero(input_msg, MAXDATASIZE);
                        strcpy(input_msg, "服务器加入的客户端数达到最大值,无法加入!\n");
                        send(client_sock_fd, input_msg, MAXDATASIZE, 0);
                        printf("客户端连接数达到最大值，新客户端加入失败 %s:%d\n",
                        inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    }
                }
            }
            for(int i =0; i < MAXCONCURRENTCONNECT; i++)
            {
                if(client_fds[i] !=0)
                {
                    if(FD_ISSET(client_fds[i], &server_fd_set))
                    {
                        //处理某个客户端过来的消息
                        bzero(recv_msg, MAXDATASIZE);
                        long byte_num = recv(client_fds[i], recv_msg, MAXDATASIZE, 0);
                        if (byte_num > 0)
                        {
                            if(byte_num > MAXDATASIZE)
                                byte_num = MAXDATASIZE;
                            recv_msg[byte_num] = '\0';
                            printf("客户端(%d):%s\n", i, recv_msg);
                        }
                        else if(byte_num < 0)
                            printf("从客户端(%d)接受消息出错.\n", i);
                        else
                        {
                            FD_CLR(client_fds[i], &server_fd_set);
                            client_fds[i] = 0;
                            printf("客户端(%d)退出了\n", i);
                        }
                    }
                }
            }
        }
    }
    return 0;
}