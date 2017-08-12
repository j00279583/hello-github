package main

import (
	"fmt"
	"net"
)

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
			fmt.Println(err2)
		}

		msg := make([]byte, n)
		copy(msg, readMsg)

		fmt.Println(n)
		fmt.Println(msg)
		fmt.Println(string(msg))

		l.WriteToUDP([]byte("hello,client"),remoteAddr)

	}

}
