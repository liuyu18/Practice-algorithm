class TCPSocket{
    public:
    ~TCPSocket();
    int Connect(const SocketAddress &inAddress);
    int Bind(const SocketAddress &inToAddress);
    int Listen(int inBackLog = 32);
    shared_ptr<TCPSocket> Accpet(SocketAddress &inFromAddress);
    int32_t Send(const void *inData,size_t inLen);
    int32_t Receive(viod *inBuffer,size_t inLen);

    private:
    friend class SocketUtil;
    TCPSocket(SOCKET inSocket):mSocket(inSocket){}
    SOCKET mSocket;
};
typedef shared_ptr<TCPSocket> TCPSokcetPtr;