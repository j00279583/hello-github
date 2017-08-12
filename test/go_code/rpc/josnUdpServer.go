package main

import (
	"fmt"
	"encoding/json"
	"net"
)


type Msgdata struct{
	MsgType uint32 `json:"msg_type"`
	Data    uint32
}



func main() {
	fmt.Println("server running")

	localAddr, err := net.ResolveUDPAddr("udp", "127.0.0.1:8889")
	if err != nil {
		fmt.Println(err)
	}

	l, err1 := net.ListenUDP("udp", localAddr)
	if err1 != nil {
		fmt.Println(err1)
	}
	defer l.Close()

	fmt.Println("listen udp come in")

	var readMsg = make([]byte, 2048)
	for {
		fmt.Println("begin read")
		n, remoteAddr,err2 := l.ReadFromUDP(readMsg)
		if err2 != nil {
			fmt.Println(err2,n)

		}
		fmt.Println(readMsg[:n])

		fmt.Println(remoteAddr)
		var msg = Msgdata{}
		json.Unmarshal(readMsg[:n],&msg)

		fmt.Println(msg)
	}

}
