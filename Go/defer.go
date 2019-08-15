package main

import "fmt"
//The defer statement defers the function until the outer function returns.
func main(){
{
	defer fmt.Println("world")
	fmt.Println("hello")
}
{/*
	Defer stack

Delayed function calls are pushed into a stack. When the outer function returns, the deferred function is called in the last-in, first-out order.
	*/
	fmt.Println("counting")

	for i := 0; i < 10; i++ {
		defer fmt.Println(i)
	}

	fmt.Println("done")
}
}