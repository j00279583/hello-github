package main

import (
	"fmt"
	"time"
	"net/rpc"
)


func main()  {

	l, err := rpc.DialHTTP("tcp","127.0.0.1:8810")
	if err != nil{
		fmt.Println("Dial failed :",err)
	}
	//defer l.Close()

	var Resp string

	fmt.Println("dial success")

	//var arg string = "Hello"
	e := l.Call("Hello.Echo","gogo",&Resp)
	if e != nil{
		fmt.Println(e)
	}

	fmt.Printf("rsp is %s \r\n",Resp)

	fmt.Println("call success!")

	//fmt.Println(Resp)


	timer := time.After(time.Minute *1)
	select {
		case <-timer:
	}
	fmt.Println("1 minute come out")
}