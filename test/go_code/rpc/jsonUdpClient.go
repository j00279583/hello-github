package main

import (
	"fmt"
	"net"
	"encoding/json"
)

const (
	MsgTypeAdd = iota
	MsgTypeDel
	MsgTypeUpdate
)

type Msgdata struct{
	MsgType uint32 `json:"msg_type"`
	Data    uint32
}

func main() {

	var msg = make([]byte,1000)
	localAddr, err := net.ResolveUDPAddr("udp","127.0.0.1:8888")
	if err != nil {
		fmt.Println(err)
	}

	remoterAddr, err1 := net.ResolveUDPAddr("udp","127.0.0.1:8889")
	if err1 != nil {
		fmt.Println(err1)
	}

	fmt.Println("wait dialudp")
	con, err2 := net.DialUDP("udp",localAddr,remoterAddr)
	if err2 != nil {
		fmt.Printf("dial failed, err2 is %v",err2)
	}

	fmt.Printf("dialudp success \r\n")



	var msgData = Msgdata{
		MsgType:MsgTypeAdd,
		Data:5,}

	sendData, err4 := json.Marshal(msgData)
	if err4 != nil{
		fmt.Println(err4)
	}

	nWrite,err := con.Write(sendData)
	if err!= nil{
		fmt.Printf("write failed.",nWrite)

	}

	for {

		nRead, addr, err3 := con.ReadFromUDP(msg)
		if err3 != nil {
			fmt.Println("read failed.", addr, nRead)
		}

		var Readmsg = make([]byte, nRead)
		copy(Readmsg, msg)

		fmt.Println(Readmsg)

		fmt.Println(string(Readmsg))
	}
}
