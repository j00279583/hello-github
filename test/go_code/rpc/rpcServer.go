package main

import (
	"fmt"
	"net"
	"net/rpc"
	"errors"
	"net/http"
)

type Hello struct {

}



func (h *Hello)Echo(args string, resp *string)  error{


	*resp = args + "world"

	fmt.Println("Echo come in")
	return nil

}

func main()  {

	var err = errors.New(" ")
	err = rpc.Register(new(Hello))
	if err != nil{
		fmt.Println("register failed,err is ", err)
	}

	fmt.Println("server listening: ")

	l, e := net.Listen("tcp","127.0.0.1:8810")
	if e != nil {
		fmt.Println("listen failed, err is ", e)
		return
	}

	rpc.HandleHTTP()

	//defer l.Close()

	//con, e2 := l.Accept()
	//if e2 != nil{
	//	fmt.Println(e)
	//}
	http.Serve(l,nil)
	//hand(con)
}

func hand(c net.Conn) error{
	fmt.Println("hand come in ")

	var aa int

	fmt.Scanln("&aa")

	fmt.Println("hand come out",aa)

	return nil

}