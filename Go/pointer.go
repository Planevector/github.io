package main

import "fmt"

func main(){

	i,j :=42,100
	p :=&i
	fmt.Println(*p)

	*p=21
	fmt.Println(i,p)

	p=&j
	*p=*p/23
	fmt.Println(j)

}