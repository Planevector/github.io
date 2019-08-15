package main

import (
	"fmt"
	"time"
)

func main(){
	{
		s :="a"
	switch s{
	case "a":
	fmt.Println("yes")
	case "b":
	fmt.Println("no")
	}
	}
	{
t :=time.Now()
switch{
case t.Hour()<12:
	fmt.Println("good monrning")
case t.Hour()<17:
	fmt.Println("good afternoon")
default:fmt.Println("good evening")
}
}
}