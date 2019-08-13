package main

import "fmt"

func main(){
	{
	var a int
	var c bool 
	var b string
	fmt.Println(a,b,c)
	}

	{
	var i,j int =1,2
	var a,b,c = false,"1",12.2
	fmt.Println(i,j)
	fmt.Println(a,b,c)
	}
	{
		//short variable statement
		a,b,c := 1,"a",true
	fmt.Println(a,b,c)
	}
}
